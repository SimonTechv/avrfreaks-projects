/*****************************************************
This program was produced by the
CodeWizardAVR V2.04.8b Evaluation
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 9/6/2010
Author  : Freeware, for evaluation and non-commercial use only
Company : 
Comments: 


Chip type               : AT90S8515
AVR Core Clock frequency: 8,000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*****************************************************/

#include <90s8515.h>
#include <math.h>
// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x12 ;PORTD
#endasm
#include <lcd.h>
#include <delay.h>
#include <stdio.h>
// Declare your global variables here
char lcd_buffer [33];
unsigned char wpm;
int spc;
int timing;
void main(void)
{
// Declare your local variables here
#define Keyon PORTC.0=0;   //CW Keyer Line
#define Keyoff PORTC.0=1;  //   PortC Pin 1
#define dot PINA.7    //Keyer - Dot  Port A Pin 7
#define dash PINA.6   //Keyer - Dash Port A Pin 6
#define sup PINA.0    //Speed Up - Port A Pin 0
#define sud PINA.1    //Speed Down - Port A Pin 1
spc=1200;  // Constant for calculating Char speed in Mil Seconds
wpm=10;     // Words per minute Default Keyer Speed

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=P State6=P State5=P State4=P State3=P State2=P State1=P State0=P 
PORTA=0xFF;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=P State6=P State5=P State4=P State3=P State2=P State1=P State0=P 
PORTB=0xFF;
DDRB=0x00;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0xFF;
DDRC=0xFF;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=P State6=P State5=P State4=P State3=P State2=P State1=P State0=P 
PORTD=0xFF;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
TCCR0=0x00;
TCNT0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
GIMSK=0x00;
MCUCR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;
ACSR=0x80;

// LCD module initialization
lcd_init(16);

// Keyer Loop                                                

do {
timing = spc/wpm; //Calculate Diming delay 
sprintf(lcd_buffer,"%d Dly-%d",wpm,timing); //Push Delay to LCD Buffer
lcd_gotoxy(0,0); //Position LCD
lcd_putsf("V1.2 CW Keyer"); // Line 1 of lcd
lcd_gotoxy(0,1);  // Line 2 of LCD - WPM and Delay
lcd_putsf("WPM-");
lcd_gotoxy(5,1);
lcd_puts(lcd_buffer);  // End of LCD Setup
if (dot!=1) {
do  { 
Keyon;
delay_ms(timing);
Keyoff;
delay_ms(timing);
   }
while (dot!=1);
      }
else {Keyoff;    
    };
if (dash!=1) {
do  { 
Keyon;
delay_ms(timing);
delay_ms(timing);
delay_ms(timing);
Keyoff;
delay_ms(timing);
   }
while (dash!=1);
      }
else {Keyoff;    
    };
 if (sup!=1) {
do  { 

wpm = wpm + 1;

delay_ms(100);
lcd_gotoxy(12,1);
lcd_putsf("     ");
   }
while (sup!=1);
      }
if (sud!=1) {
do  { 

wpm = wpm - 1;

delay_ms(100);
lcd_gotoxy(12,1);
lcd_putsf("     ");
   }
while (sud!=1);
      }
// stop here
}


while (1);



}

