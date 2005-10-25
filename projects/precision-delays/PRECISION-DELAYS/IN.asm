

;**********************************************************
;   PRECISION DELAY ROUTINES(FUNCTION FORMAT MACROS)                       
;   ASSEMBLER:AVR ASM1
;   IDE:AVR STUDIO 4.12
;   AUTHOR: OMID KOMPANI    
;           TEHRAN-IRAN
;           30/10/05  ---- 1384/8/8
;**********************************************************



;***********************************************************************************************
;  THE MOST USAGE OF CYCLIC FOR-LOOP STYLE DELAYS ARE INITIATION PROCEDURES(LCDS-KEYBOARDS,..)
;   THESE FUNCTIONS ALSO WASTE THE CPU RESOURCES SO USING THIS METHOD IS NOT RECOMMENDED
;   FOR LONG TIME WAITINGS.INSTEAD YOU SHOULD USE THE TIMER INTERRUPTS FOR LONG TIME WAITINGS.
;   FOR EXAMPLE YOU NEED A 4mS AND A 100uS DELAY FOR INITIATION OF A LCD.U CAN USE THESE MACROS.
;   BUT IF YOU NEED 100mS YOU SHOULD NOT LOOP FOR 100mS .IT'S A GREAT TIME AND YOU CAN DO A BUNCH 
;   OF THINGS DURING IT.
;   YOU CAN USE THESE ROUTINES JUST BY SIMPLY SETTING THE CPU FREQUENCY-CONSTANT  AND THE
;   DELAY-VALUE ACCORDING TO DELAY TIME BASE.
;   THERE ARE 5 DIFFERENT TIME-BASES  :   uS - 5uS - 10uS - mS - 10mS
;   YOU CAN CALL EACH MACRO BY PASSING ITS PARAMETERS TO THE MACRO. AS FOLLOWING
;   _WAIT_(TIME BASE)       CPU_FREQUENCY,DELAY_VALUE
;
;   FOR EXAMPLE     IN 8MHz OPERATION YOU NEED A 20uS DELAY. JUST FOLLOW THE NEXT STEPS:
;   **********************************************
;   .EQU    CPU_FREQUENCY=8000000
;   _WAIT_uS        CPU_FREQUENCY,20        LOOPS FOR 20 uS        
;   OR
;   _WAIT_5uS        CPU_FREQUENCY,4        LOOPS FOR 20 uS
;   OR
;   _WAIT_10uS      CPU_FREQUENCY,2        LOOPS FOR 20 uS
;***********************************************
;
;   **EACH DELAY FUNCTION HAS A LIMITATION IN DELAY-VALUE THAT DEPENDS ON
;       CPU FREQUENCY.IF YOUR DELAY DOES NOT MATCH  A FUNCTION, THEN USE A GREATER 
;       TIME-BASE.
;       
;   NOW LET'S TAKE A LOOK AT EACH DELAY ROUTINE! 

;       _WAIT_uS    
;       *********
;       1 micro SECOND TIME-BASE
;        THIS MACRO DOES NOT WORK GOOD IN 1.00 MHz AND 2.00 MHz CPU FREQ.IT WORKS WELL IN 4uS,8uS,12uS ADN...  
;       IF YOU WANT A 1 micro second DELAY IN YOUR 1.00MHz PROGRAM THEN YOU CAN USE A NOP!!!
;       BECAUSE OF ITS STRUCTURE IT IS SUITABLE FOR 4.00MHz ,8.00MHz AND 16MHz FREQUENCIES.
;       CALCULATING THE DELAY LIMITATION:
;               (CPU_FREQUENCY/1000000)*DELAY_VALUE/4 <= 255 
;               CPU_FREQ.=1.00MHz  MAX.DELAY VAL=1020 ->1020.00 uS
;               CPU_FREQ.=4.00MHz  MAX.DELAY VAL=255   -> 255.00 uS
;               CPU_FREQ.=8.00MHz  MAX.DELAY VAL=127   ->127.00 uS
;               CPU_FREQ.=16.00MHz  MAX.DELAY VAL=63   ->63.00 uS
;
;       _WAIT_5uS       
;       **********
;       5 micro SECONDS TIME-BASE
;       THIS FUNCTION LIKE uS FUNCTION DOES NOT HAVE A GOOD PERFORMANCE IN 1.00MHz AND 2.00MHz AND ALSO 4.00MHZ
;       CPU FREQUENCIES.IT DOES GOOD WITH THE DELAY-VALUES: 8,16,24 AND ...
;       CALCULATING THE DELAY LIMITATION:
;               (CPU_FREQUENCY/1000000)*DELAY_VALUE/8 <= 255
;               CPU_FREQ.=1.00MHz  MAX.DELAY VAL=2040 ->2040*5=10200.00 uS
;               CPU_FREQ.=4.00MHz  MAX.DELAY VAL=510   ->510*5= 2550.00 uS
;               CPU_FREQ.=8.00MHz  MAX.DELAY VAL=256   ->255*5=1275.00 uS
;               CPU_FREQ.=16.00MHz  MAX.DELAY VAL=127   ->127*5=635.00 uS

;       _WAIT_10uS   
;       ***********
;       10 micro SECONDS TIME-BASE
;       THIS FUNCTION LIKE OTHER uS FUNCTIONS DOES NOT HAVE A GOOD PERFORMANCE IN 1.00MHz AND 2.00MHz AND 
;       ALSO 4.00MHZ CPU FREQUENCIES.IT FUNCTIONS WELL WITH THE DELAY-VALUES: 8,16	,24 AND ... 
;       CALCULATING THE DELAY LIMITATION:
;       (CPU_FREQUENCY/1000000)*DELAY_VALUE/8 <= 255  
;               CPU_FREQ.=1.00MHz  MAX.DELAY VAL=2040 ->2048*10=20400.00 uS
;               CPU_FREQ.=4.00MHz  MAX.DELAY VAL=510   ->512*10= 5100.00 uS
;               CPU_FREQ.=8.00MHz  MAX.DELAY VAL=255   ->256*10=2550.00 uS
;               CPU_FREQ.=16.00MHz  MAX.DELAY VAL=127   ->128*10=1270.00 uS
;

;
;       _WAIT_mS   
;       ***********
;       1 mili SECOND TIME-BASE
;       THIS FUNCTION HAS A GOOD PERFORMANCE IN ALL FREQUENCIES(THERE ARE ALSO SOME EXCEPTIONS.I WILL
;       DESCRIBE THEM LATER IN THIS DOCUMENT)BUT BECAUSE YOUR DELAY-VALUE IS ONLY DIVIDED BY 1 THEREFORE
;		 YOUR DELAY IS VERY PRECISE IN ALL FREQUENCIES, AND ALL VALUES(LOWER THAN ITS LIMITATION)
;       CALCULATING THE DELAY LIMITATION:
;       (CPU_FREQUENCY/1000000)*DELAY_VALUE <= 255  
;               CPU_FREQ.=1.00MHz  MAX.DELAY VAL=255 ->255000.00 uS
;               CPU_FREQ.=4.00MHz  MAX.DELAY VAL=63    ->63000.00 uS
;               CPU_FREQ.=8.00MHz  MAX.DELAY VAL=31   ->31000.00 uS
;               CPU_FREQ.=16.00MHz  MAX.DELAY VAL=15  ->15000.00 uS


;		_WAIT_10mS
;		************
;		10 mili SECONDS TIME-BASE
;		
;		YEP! I HAVE FOUND A USAGE FOR THE T FLAG!I JUST NEEDED AN ADDITIONAL FLAG TO COMPLETE THE DELAY LOOP.
;		THEN I SAW IT IN A CORNER IN SREG! (READ THE SOURCE CODE) 
;		YOU HAD BETTER NEVER USE THIS MACRO AS A DELAY LOOP.(WHY SHOULD YOU USE A 500mS DELAY LOOP?)
;		BUT IF YOU WANT TO USE IT, I RECOMMEND TO DO IT AS A NORMAL ROUTINE IN YOUR PROGRAM AND USE
;		RCALL TO CALL IT.(IT IS TOO BIG TO USE IT FREQUENTLY AS A MACRO)
;       CALCULATING THE DELAY LIMITATION:
;       (CPU_FREQUENCY/1000000)*DELAY_VALUE <= 255  
;               CPU_FREQ.=1.00MHz  MAX.DELAY VAL=255 ->2550000.00 uS
;               CPU_FREQ.=4.00MHz  MAX.DELAY VAL=63    ->630000.00 uS
;               CPU_FREQ.=8.00MHz  MAX.DELAY VAL=31   ->310000.00 uS
;               CPU_FREQ.=16.00MHz  MAX.DELAY VAL=15  ->150000.00 uS
		

;******************************************************************************************************
;	HH      HH      OO      WW     WW     WW     
;	HH      HH     OOOO     WW     WW     WW
;	HH      HH   OO    OO    WW    WW    WW
;	HHHHHHHHHH  OOO    OOO    WW   WW   WW
;	HHHHHHHHHH  OOO    OOO     WW  WW  WW
;	HH      HH   OO    OO       WW WW WW
;	HH      HH     OOOO         WW WW WW
;	HH      HH      OO         WW  WW  WW
;*****************************************************************************************************
;*****************************************************************************************************
; HOW TO TEST THESE ROUTINES?
;******************************
; SIMPLY BY AVR STUDIO'S SIMULATOR IN FEW STEPS
; 1-IN YOUR PROGRAM DEFINE THE CPU_FREQUENCY
; 2-USE ONE THE DELAY MACRO IN YOUR MAIN ROUTINE BEFORE ANY INSTRUCTION
; 3-ASSEMBLE THE PROGRAM
; 4-START DEBUGGING
; 5-IN THE DEBUG MENU SELECT  AVR SIMULATION OPTIONS OR PRESS Alt+O
; 6-CHOOSE YOUR DEVICE AND SIMULATING FREQUENCY
; 7-PRESS F11(STEP INTO) AND WAIT UNTIL THE SIMULATOR EXECUTE THE MACRO
; 8-AT THE I/O VIEW OF SIMULATOR IN PROCESSOR SECTION YOU CAN SEE WHAT YOU WANT.STOP WATCH!
;   
;**NOTE: MAKE SURE THAT THE SIMULATOR'S FREQ. IS EQUAL TO YOUR CPU_FREQUENCY 
	
;*****************************************************************************************************
;*****************************************************************************************************
;
; NOTE:
; UNFORTUNATELY DOES NOT WORK WITH 14.7456MHz , 11.0592 AND.... FREQUENCIES.
; ANY IDEAS? ANY RECOMMENDATIONS?
;
;
;	LET'S START
;********************************************************************************************

.INCLUDE	"M32DEF.INC"


.EQU	CPU_FREQUENCY=1000000
;.EQU	CPU_FREQUENCY=2000000
;.EQU	CPU_FREQUENCY=4000000
;.EQU	CPU_FREQUENCY=8000000
;.EQU	CPU_FREQUENCY=12000000
;.EQU	CPU_FREQUENCY=14745600
;.EQU	CPU_FREQUENCY=16000000



.CSEG
.INCLUDE	"DELAY-MACRO.H"

MAIN:
	_WAIT_uS	CPU_FREQUENCY,8		;MAKES 8uS DELAY
;	_WAIT_5uS	CPU_FREQUENCY,8		;MAKES 40uS DELAY
;	_WAIT_10uS	CPU_FREQUENCY,8		;MAKES 80uS DELAY
;	_WAIT_mS	CPU_FREQUENCY,8		;MAKES 8mS DELAY
;	_WAIT_10mS	CPU_FREQUENCY,8		;MAKES 80mS DELAY
	
	RJMP MAIN