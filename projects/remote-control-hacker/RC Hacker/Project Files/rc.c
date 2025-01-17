/*****************************************************
This program was produced by the
CodeWizardAVR V1.24.7b Evaluation
Automatic Program Generator
� Copyright 1998-2005 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com
e-mail:office@hpinfotech.com

Project : RC Hacker
Version : 1.0
Date    : 3/16/2006
Author  : Devinder Saini
Company : 
Comments: 


Chip type           : ATmega8515L
Program type        : Application
Clock frequency     : 8.000000 MHz
Memory model        : Small
External SRAM size  : 0
Data Stack size     : 128
*****************************************************/

#include <mega8515.h>

// Standard Input/Output functions
#include <stdio.h> 
#include <delay.h>


// ******** Following are user definable constants which 
// ******** can be set according to the application

#define START_EDGE FALL             // If the transducer is initially at high level 
                                    // or first edge is high to low
                                    // then leave this at it is otherwise set RISE
                                    
#define PRESCALER 0x02              // Default prescaler is divide by 8

#define NUMBER_OF_FUNCTIONS 4       // Total number of functions that can be recorded
#define NUMBER_OF_POINTS 28         // Maximum number of transitions allowed in a function
                                    // This number must be greater than the expected number

#define LED_IDLE PORTC.7            // Indicators
#define LED_LISTEN PORTC.6
#define LED_TRANSMIT PORTC.5  

//********* End of user options



enum mode { IDLE, LISTEN, TRANSMIT } rc; 
enum edge { FALL=1, RISE=0 } e;
enum level{ LOW, HIGH  };
enum input_state {ACTIVE,DISABLED} switches;

bit first_fall=0;
static char counter=0;
char function_index=0;

void set_edge(enum edge x)
{
    if(x==FALL)
        TCCR1B&=0b10111111;
    else
        TCCR1B|=0b01000000;
}

// Struct representing a point of transition
eeprom struct wave_point {             
              int time_stamp; 
              enum level logic;
            };
                         

// Struct representing a complete code           
eeprom struct code_space {             
              struct wave_point point[NUMBER_OF_POINTS];
             };

eeprom struct code_space *code_ptr;                     // Pointer to currently accessed function
eeprom struct code_space function[NUMBER_OF_FUNCTIONS]; // Actual functions





/* This function sets the device in a mode-IDLE,LISTEN or TRANSMIT
IDLE-       TIMER1 stopped
LISTEN-     TIMER1 on, overflow interrupt on and input capture interrupt on
TRANSMIT-   TIMER1 on, overflow interrupt on and output compare match A interrupt on*/
void set_mode ( enum mode z )  
{       
    TCCR1B&=0xF8;
    switch(z)
    {
        case IDLE   :  TIMSK=0x00;          // All timer interrupts off
                       rc=IDLE;
                       LED_IDLE=0;          // Indicators
                       LED_LISTEN=1; 
                       LED_TRANSMIT=1;
                       break;
        case LISTEN :  TCNT1=0;             // Start timer from 0
                       e=START_EDGE;              
                       set_edge(e);
                       first_fall=0;
                       counter=0;
                       TIFR^=0x88;          // Clear interrupt flags
                       TIMSK=0x88;          // Set overflow and input capture interrupts
                       rc=LISTEN;                       
                       LED_IDLE=1;
                       LED_LISTEN=0;
                       LED_TRANSMIT=1;
                       break;
        case TRANSMIT: TCNT1=0;
                       rc=TRANSMIT;          
                       counter=1;
                       TIMSK=0b11000000;    // Set overflow and output compare match interrupts
                       LED_IDLE=1;
                       LED_LISTEN=1;
                       LED_TRANSMIT=0;
                       TCCR1B|=PRESCALER;   // Start timer
                       break;
    }
} 
              

// Timer 1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
// Place your code here
    int i;
    enum mode rctemp;
    rctemp=rc;
    
    set_mode(IDLE);             // Set IDLE mode
    
    if(rctemp==LISTEN)          // If just listened to a new function, then log the data to computer
    {      
        putsf("\nTIMEOUT. Code written\nListing");    
        for(i=0;i<=NUMBER_OF_POINTS;i++)
        {
           printf("\nPoint %d: Time- %d, Logic Time+- %d",i,code_ptr->point[i].time_stamp,code_ptr->point[i].logic);
        }
    }
    if(rctemp==TRANSMIT)        // If just transmitted, then notify computer
    {
        printf("\nTransmitted function %c",function_index);
         
    }
    switches=ACTIVE;            // Reactivate switches

}

// Timer 1 input capture interrupt service routine
interrupt [TIM1_CAPT] void timer1_capt_isr(void)
{
// Place your code here
    if(!first_fall)             // If first capture has occured, then start timer
    {
        TCCR1B|=PRESCALER;
        first_fall=1;
    }
  
    code_ptr->point[counter].time_stamp=ICR1;       // Record the current timer value     
    code_ptr->point[counter].logic=PINE.0;          // Record current pin state
    set_edge(PINE.0);                               // Set other edge
    
    counter++;     

}

// Timer 1 output compare match interrupt service routine
interrupt [TIM1_COMPA] void timer1_compareA(void)
{     
    PORTD.5=code_ptr->point[counter].logic;         // Set the pin value to output
    OCR1A=code_ptr->point[++counter].time_stamp;    // Set OCR1A register to the next time stamp
}

// Declare your global variables here

void main(void)
{
// Declare your local variables here
char temp;

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
// Func7=In Func6=In Func5=Out Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=P State6=P State5=1 State4=P State3=P State2=P State1=P State0=P 
PORTD=0xFF;
DDRD=0x20;

// Port E initialization
// Func2=In Func1=In Func0=In 
// State2=P State1=P State0=P 
PORTE=0x07;
DDRE=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=FFh
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Normal top=FFFFh
// OC1A output: Toggle
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: On
// Input Capture Interrupt: On
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x40;
TCCR1B=0x02;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;



// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Low level
// INT1: Off
// INT2: Off
GICR|=0b00000000;
MCUCR=0x00;
EMCUCR=0x00;
GIFR=0b00000000;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x88;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: Off
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud rate: 9600
UCSRA=0x00;
UCSRB=0x08;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;

// Global enable interrupts
#asm("sei")

set_mode(IDLE);
e=FALL;
code_ptr=&function[0];

while (1)
      {
      // Place your code here 
/*      #asm
        nop
        nop
      #endasm
*/
    #asm("nop");
    if((PINA!=0xFF)&&(switches==ACTIVE))
    {
        switches=DISABLED;
        temp=PINA;
        delay_ms(1000);  
        switch(temp)
        {
            case 0b11111110 :   function_index=++function_index%NUMBER_OF_FUNCTIONS;    // Change Function
                                PORTC=PORTC&0xF0;
                                PORTC|=function_index^0xFF;
                                code_ptr=&function[function_index]; 
                                switches=ACTIVE;   
                                break;
            case 0b11111101 :   set_mode(TRANSMIT);                   //Transmit
                                break;
            case 0b11111011 :   putsf("\n\n-----------Listening ...\n");   
                                set_mode(LISTEN);
                                break;
        } 
   

      };
    } 
}
