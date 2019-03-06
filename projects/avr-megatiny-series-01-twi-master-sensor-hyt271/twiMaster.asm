;AVR-MEGA/TINY Series-0/1 TWI Master (Sensor-Slave: HYT271, I2C ADDRESS $28)
;FUSE: 16 MHz

;-------------
;INTERRUPT TAB

;		jmp	RESET			;00: RESET-vector
;		...
		jmp	I2CINT			;xx: TWI0_TWIM
;		...						

;----
;MAIN

RESET:		ldi	XH,1			;16 MHz / PRESCALER 2:
		ldi	XL,$d8
		out	CPU_CCP,XL
		sts	CLKCTRL_MCLKCTRLB,XH	;8 MHz fCKL_CPU = fCLK_PER	

		ldi	XL,$20			;IF AVAILABLE IN DEVICE:
		sts	PORTMUX_TWISPIROUTEA,XL ;TWIM-PIN SETUP PC2/3
		
		ldi	XL,35			;TWI CLOCK INIT: 
		sts	TWI0_MBAUD,XL		;8 MHz / (10+ 2*XL) = 100kHz

		sei

;----------------
TIMED SUBPROGRAMS

TWISTART:	clr	XL			;TWI ENABLE
		sts	I2CDATA1,XL
		sts	I2CDATA2,XL		;CLEAR I2C-DATA BUFFER
		sts	I2CDATA3,XL
		sts	I2CDATA4,XL
		ldi	XL,$c3			;ENABLE TWI MASTER INCLUDING
		sts	TWI0_MCTRLA,XL		;READ/WRITE INTERRUPT & SMARTMODE
		ldi	XL,1
		sts	TWI0_MSTATUS,XL		;FORCE I2C BUS IDLE
		ret

ADDRWRITE:	lds	XL,TWI0_MSTATUS		;INIT ADDR WRITE
		andi	XL,3
		breq	twioff			;UNKNOWN BUS STATE (ERROR)
		ldi	XL,$50			;HYT271 MR COMMAND (WRITE)
		sts	TWI0_MADDR,XL		;SEND START + SLAVE ADDR	
		ret

DATAREAD:	ldi	XL,4			;INIT DATA READ
		sts	I2CDATAC,XL
		clr	XL
		sts	TWI0_MCTRLB,XL		;SET (SMARTMODE-) MASTER ACK FOR
		ldi	XL,$51			;HYT271 DF COMMAND:
		sts	TWI0_MADDR,XL		;INIT 4BYTE READ CYCLE IN I2CINT
		ret

SAVE:		lds	XH,I2CDATA1		;SAVE READINGS
		lds	XL,I2CDATA2
		lds	YH,I2CDATA3
		lds	YL,I2CDATA4
		...				;MAYBE DATA PLAUSIBILITY TEST?
		sts	HYTHUMIH,XH
		sts	HYTHUMIL,XL
		sts	HYTTEMPH,YH
		sts	HYTTEMPL,YL

TWIOFF:		clr	XL
		sts	TWI0_MCTRLA,XL		;DISABLE TWI
		ret

;---------------------------
;HYT271 SENSOR I2C INTERRUPT

I2CINT:		push 	...			;all used cpu registers

		lds	XH,TWI0_MSTATUS
		sbrc	XH,7
		rjmp	i2cintR

i2cintW:	mov	XL,XH			;MASTER WRITE INTERRUPT
		andi	XH,$0c
		brne	itwioff			;ARBLOST/BUS ERROR
		sbrs	XL,4
		rjmp	i2cintR7		;MR COMMAND: ACK OK

itwioff:	clr	XL			;ERROR: DISABLE TWI
		sts	TWI0_MCTRLA,XL	
		rjmp	return

i2cintR:	ldi	YL,low(I2CDATAC)	;MASTER READ INTERRUPT
		ldi	YH,high(I2CDATAC)
		clr	XH
		ld	XL,Y
		add	YL,XL	
		adc	YH,XH			;Y-> CURRENT I2C DATA BYTE
		dec	XL
		sts	I2CDATAC,XL
		brne	i2cintR2
		ldi	XH,4			;FOR LAST BYTE TO BE READ
		sts	TWI0_MCTRLB,XH		;SET ACKNOWLEDGE ACTION = NACK		
i2cintR2:	lds	XH,TWI0_MDATA		;CURRENT/INITNEXT DATA-READ
		st	Y,XH			;SAVE DATA BYTE
		brne	return			;CYCLE NOT FINISHED
i2cintR7:	ldi	XL,7			;SEND NACK/STOP
		sts	TWI0_MCTRLB,XL

RETURN:		pop	...			;all used cpu registers
		reti

;---------
;SRAM DATA

I2CDATAC:	.BYTE 1		;I2C-DATA COUNTER (4->0)
I2CDATA4:	.BYTE 1		;I2C-DATA BYTE 4 (TEMPL)
I2CDATA3:	.BYTE 1		;I2C-DATA BYTE 3 (TEMPH)
I2CDATA2:	.BYTE 1		;I2C-DATA BYTE 2 (HUMIL)
I2CDATA1:	.BYTE 1		;I2C-DATA BYTE 1 (HUMIH)

HYTTEMPL:	.BYTE 1		;HYT271 TEMPERATURE LOW
HYTTEMPH:	.BYTE 1		;HYT271 TEMPERATURE HIGH
HYTHUMIL:	.BYTE 1		;HYT271 HUMIDITY LOW
HYTHUMIH:	.BYTE 1		;HYT271 HUMIDITY HIGH