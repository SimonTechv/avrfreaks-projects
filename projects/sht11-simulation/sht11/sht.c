/*****************************************************
This program was produced by the
CodeWizardAVR V2.03.4 Standard
Automatic Program Generator
� Copyright 1998-2008 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 30/03/2013
Author  : 
Company : 
Comments: 


Chip type           : ATmega8535
Program type        : Application
Clock frequency     : 11,059200 MHz
Memory model        : Small
External RAM size   : 0
Data Stack size     : 128
*****************************************************/

#include <mega8535.h>
#include <stdio.h>
#include <delay.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x15 ;PORTC
#endasm
#include <lcd.h>
sfrb PORTA=0x1b;
sfrb PINA=0x19;
#define SDAOut PORTA.0
#define SDAIn PINA.0
#define SCLK PORTA.1
#define out PORTB.0

// Declare your global variables here
unsigned char TimeOut,AckBit,buf[33];  //Ackbit : '0' (ACK), '1' (NOACK)
unsigned int DataTempSHT,DataRHSHT,DataRead;
float RH,Temp; 

/*Membuat kondisi "start" ke SHT11 ("Transmission Start" sequence)
          _____         _____
 ShtData       |_______|
              ___     ___
 ShtClock ___|   |___|   |___
 Clock         1       2         */
 
 void StartSignal (void)
{        
unsigned char DDRATemp;
    DDRATemp = DDRA;    
    DDRA |= 0x01;       // PortA.0 sbg Output
    SDAOut = 1;
    SCLK = 0;
    SCLK = 1;           //Clock pertama
    SDAOut = 0;
    SCLK = 0;
    SCLK = 1;           //Clock kedua
    SDAOut = 1;
    SCLK = 0;           //Pin Clock = '0'
    DDRA = DDRATemp;        
}

//Reset komunikasi: 9 clock cyle dengan ShtData '1', lalu kondisi start 
void ResetSHT (void)
{
unsigned char i,DDRATemp;
    DDRATemp = DDRA;
    DDRA |= 0x01;
    SDAOut = 1;
    SCLK = 0;
    for (i=0; i<=8; i++)
      {
        SCLK = 1;     //Kirim Data (ShtClock rising edge), 9 kali
        SCLK = 0;
      }
    StartSignal();        //Transmission Start
    DDRA = DDRATemp;
}

//Tunggu sampai SHT11 selesai melakukan pengukuran (pin Data = '0')
//Timeout pengukuran sekitar 1/4 detik (TimeOut = '0' --> measure OK)
void SHTWait (void)
{
    unsigned char i,DDRATemp;
    DDRATemp = DDRA;
    DDRA |= 0x01;
    SDAOut=1;          //Pin ShtData sebagai input
    DDRA &= 0xFE;
    for (i=0; i<250; i++)
      {
        TimeOut=SDAIn;        //Jika pin ShtData = '0' --> pengukuran selesai
        if (TimeOut==0) goto ExitSHT_Wait;
        delay_ms(1);
      }       
    ExitSHT_Wait:        
    DDRA = DDRATemp;  
} 

// Transmit Data dan ambil bit Acknowledge
void SHTWriteByte (unsigned char data)
{
    unsigned char i,DDRATemp;
    DDRATemp = DDRA;
    DDRA |= 0x01;
    for (i=0; i<8; i++)
      {
        if ((data>>7)==1) SDAOut = 1;    //Kirim MSB first
        else SDAOut = 0;
        SCLK = 1;                 //Kirim Data (ShtClock rising edge)
        SCLK = 0;
        data <<= 1;             // geser data kekiri 1 bit
      }
    SDAOut = 1;                  //Pin ShtData sebagai input
    SCLK = 1;
    DDRA &= 0xFE;
    AckBit = SDAIn;             //Ambil sinyal acknowledge
    SCLK = 0;
    DDRA = DDRATemp; 
}

//Receive Data dan kirim bit "AckBit" ('0' untuk ACK atau '1' untuk NACK)
void SHTReadByte (void)
{
    unsigned char i,DDRATemp;
    DataRead = 0x00;
    DDRATemp = DDRA;
    DDRA |= 0x01;
    SDAOut = 1;          //Pin ShtData sebagai input
    DDRA &= 0xFE;
    for (i=0; i<8; i++)
      {
        DataRead<<=1;
        SCLK = 1;
        DataRead |= SDAIn;  //Ambil Data (MSB first)
        SCLK = 0;
      }
    DDRA |= 0x01;    
    if (AckBit==1) SDAOut = 1;   //Kirim Noacknowledge
    else SDAOut = 0;             //Kirim Acknowledge
    SCLK = 1;
    SCLK = 0;
    SDAOut = 1;          //Pin ShtData sebagai input
    DDRA = DDRATemp;
}

// Pembacaan Temperature dari SHt11
void SHTReadTemp (void)
{        
    StartSignal();
    SHTWriteByte(0x03);    		//Command Measure Temperature
    if (AckBit==0)
      {
        SHTWait();         		//Tunggu sampai pengukuran selesai
        if (TimeOut==0)
          {
           AckBit=0;                    //Kirim ACK untuk menerima byte berikutnya
            SHTReadByte();              // Ambli Byte MSB
            DataTempSHT = DataRead;
            DataTempSHT <<= 8;
            AckBit=1;                   //Kirim NACK untuk mengakhiri pengambilan data
            SHTReadByte();
            DataTempSHT |= DataRead;   //Ambil byte LSB
            
            DataRead = DataTempSHT;            
          }
      }
}

void SHTReadHumidity (void)
{
    StartSignal();
    SHTWriteByte(0x05);   //Command Measure Humidity
    if (AckBit==0)
      {
        SHTWait();
        if (TimeOut==0)
          {
            AckBit=0;
            SHTReadByte();
            DataRHSHT = DataRead;
            DataRHSHT <<= 8;
            AckBit=1;
            SHTReadByte();
            DataRHSHT |= DataRead;
            
            DataRead = DataRHSHT;
          }
      }
}


void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x02;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x08;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x04;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=FFh
// OC0 output: Disconnected
TCCR0=0x71;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer 1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer 2 Stopped
// Mode: Normal top=FFh
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// LCD module initialization
lcd_init(16);
delay_ms(1000);
ResetSHT();

while (1)
      {
      // Place your code here
      SHTReadHumidity();
      RH=((float)(DataRead*0.0405)-(DataRead*DataRead*0.0000028)-4);
      ResetSHT();
      SHTReadTemp();
      Temp=((float)(DataRead-4000))/100;
      ResetSHT();
      lcd_clear();
      lcd_gotoxy (0,0);
      lcd_putsf(" RH : Temp");
      lcd_gotoxy(0,1); 
      sprintf(buf,"%0.2f %0.2f",RH,Temp);
      lcd_puts(buf);
      delay_ms(1000);

      };
}
