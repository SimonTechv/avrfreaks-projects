/*********************************************
This program was produced by the
CodeWizardAVR V1.24.0 Standard
Automatic Program Generator
� Copyright 1998-2003 HP InfoTech s.r.l.
http://www.hpinfotech.ro
e-mail:office@hpinfotech.ro

Project :roll-down shutters
Version :3.7c : 
Date    : 09/01/2002
Author  : Johan Cardoen                   
Company : 8920 Poelkapelle (BELGIUM)      
Comments: with LCD support on PORT C                                                        12/05/2003
          now with powerdown function incorporated                                          28/11/2003
          with Version 1.24.0 automatic detection of LCD on startup (new lcd_init function) 24/12/2003
          relais drivers with  PCF8574 & ULN2803                                            26/12/2003

Chip type           : AT90S8515
Clock frequency     : 4,000000 MHz
Memory model        : Small
External SRAM size  : 0
Data Stack size     : 128
*********************************************/

#include <90s8515.h> 
#include <delay.h>
#include <sleep.h> 
#include <lcd.h>   
#include <i2c.h>
#include <stdio.h>

// Alphanumeric LCD Module functions
#asm
   .equ __lcd_port=0x15
#endasm



// I2C Bus functions
#asm
   .equ __i2c_port=0x12
   .equ __sda_bit=1
   .equ __scl_bit=3
#endasm


#define lowbyte(int)                     (unsigned char) (*((char*)&(int)+0))
#define highbyte(int)                    (unsigned char) (*((char*)&(int)+1))     

#define stop(x)                          (!(rolluik[x].status_reg & 0x03))
#define up(x)                            (rolluik[x].status_reg & 0x01)
#define down(x)                          (rolluik[x].status_reg & 0x02)
#define previous_state_up(x)             (rolluik[x].status_reg & 0x04)
#define previous_state_down(x)           (rolluik[x].status_reg & 0x08)
#define blocked(x)                       (rolluik[x].status_reg & 0x10)
#define reverse(x)                       (rolluik[x].status_reg & 0x20)
#define going_up(x)                      (rolluik[x].status_reg & 0x40)
#define going_down(x)                    (rolluik[x].status_reg & 0x80)
#define set_stop(x)                      (rolluik[x].status_reg & 0x3c)
#define set_up(x)                        ((rolluik[x].status_reg & 0xf0)| 0x05)
#define set_down(x)                      ((rolluik[x].status_reg & 0xf0)| 0x0a)
#define set_blocked(x)                   ((rolluik[x].status_reg & 0x0c)| 0x10)
#define reset_blocked(x)                 (rolluik[x].status_reg & 0xef)
#define set_reverse(x)                   ((rolluik[x].status_reg & 0xdf)| 0x20)
#define reset_reverse(x)                 (rolluik[x].status_reg & 0xdf)
#define set_going_up(x)                  ((rolluik[x].status_reg & 0x3f)| 0x40) 
#define set_going_down(x)                ((rolluik[x].status_reg & 0x3f)| 0x80)
                                   
#define nr_of_shutters                   16         // number of implemented roll-down shutters

#define PCF8574_1     0b01110010       // adress of PCF8574P managing the outputs 1 to 4
#define PCF8574_2     0b01111110       // adress of PCF8574P managing the outputs 4 to 8
#define PCF8574_3     0b01110100       // adress of PCF8574P managing the outputs 8 to 12
#define PCF8574_4     0b01111000       // adress of PCF8574P managing the outputs 12 to 16 
#define PCF8574_5     0b01110110       // adress of PCF8574P managing the outputs 16 to 20
#define PCF8574_6     0b01111010       // adress of PCF8574P managing the outputs 20 to 24

#define PCF8574A_1     0b01001110       // adress of PCF8574AP managing the inputs 1 to 8
#define PCF8574A_2     0b01001100       // adress of PCF8574AP managing the inputs 8 to 16
#define PCF8574A_3     0b01000100       // adress of PCF8574AP managing the inputs 16 to 24    

#define LCD_ATTACHED

// Declare your global variables here 

  
typedef unsigned char byte;

// table for the user defined characters

eeprom byte char0[8]={
0b0011111,
0b0010001,
0b0010001,
0b0010001,             // char code for "open window"
0b0010001,
0b0010001,
0b0010001,
0b0011111};     

eeprom byte char1[8]={
0b0011111,
0b0011111,
0b0011111,
0b0011111,            // char code for "closed window"
0b0011111,
0b0011111,
0b0011111,
0b0011111};

eeprom byte char2[8]={
0b0011111,
0b0011111,
0b0011111,
0b0011111,            // char code for "half-open window"
0b0010001,
0b0010001,
0b0010001,
0b0011111}; 

eeprom byte char3[8]={
0b0000100,
0b0001110,
0b0011111,
0b0000100,            // char code for "going up"
0b0000100,
0b0000100,
0b0000100,
0b0000100};

eeprom byte char4[8]={
0b0000100,
0b0000100,
0b0000100,
0b0000100,            // char code for "going down"
0b0000100,
0b0011111,
0b0001110,
0b0000100}; 

eeprom byte char5[8]={
0b0000100,
0b0001110,
0b0011111,
0b0000000,            // char code for "reverse"
0b0000000,
0b0011111,
0b0001110,
0b0000100}; 

eeprom byte char6[8]={
0b0010001,
0b0010001,
0b0001010,
0b0000100,            // char code for "blocked"
0b0001010,
0b0010001,
0b0010001,
0b0010001};

//function used to define user characters

void define_char ( byte eeprom *pc,byte char_code)
{
 byte i,a;
 a=(char_code<<3) | 0x40;
 for (i=0; i<8; i++) lcd_write_byte(a++,*pc++);
}



const char message1[]="ROLLUIKMODULE";  
const char message2[]="XF 16";
const char message3[]="version 3.7c";    
const char error_message[]=" Internal Error";   
char reversetimer,aux,nr,k,x,y,z,output_changed; 
unsigned char lcd_attached;
unsigned long int edgemarker_1,edgemarker_2,rising_edge_mask,falling_edge_mask,debounced_input;  
unsigned long int blockmask, temp;                                                              
unsigned int timerruns_to_go;
int max_pos[nr_of_shutters],mask; 

union datastruct {
   
        char      fraction[4];
        long int  entire;
                 }downwards, upwards,copy_downwards,copy_upwards;
                 
char PCF8574[8];
                 
struct device {
       
        int position;
        char frametimer;
        char keypresses_in_frame;
        char status_reg;
        char level[15];
               };
               
struct device rolluik [nr_of_shutters];

eeprom struct device_def {
                 int position_def;
                 char frametimer_def;
                 char keypresses_in_frame_def;
                 char status_reg_def;
                 char level_def[15];
                         };
// position_def = time needed for roll-down shutter to open en close
// time = position_def * 64 msec      500 * 64msec = 46.912 sec

eeprom struct device_def rolluik_def [nr_of_shutters] =
   
   {{ 500,0,0,4,{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}},  //rolluik voordeur
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik bureau beneden  
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik schuifraam living NOORD
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik raam living
   {  500,0,0,4,{1,2,3,4,6,7,8,9,10,11,12,13,14,15,16}},  //rolluik schuifraam living OOST 
   {  500,0,0,4,{1,2,3,4,5,7,8,9,10,11,12,13,14,15,16}},  //rolluik schuifraam keuken
   {  500,0,0,4,{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16}},  //rolluik raam keuken 
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik achterdeur
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik raam washok
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik slaapkamer ouders 
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik slaapkamer 1 NOORD 
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik slaapkamer 2 OOST
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik slaapkamer 3 VOORDEUR 
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //rolluik badkamer 
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}},         //not implemented 
   {  500,0,0,4,{6,7,8,9,9,0,0,0,0,0,1,9,0,0,0}}};        //not implemented
   
                 

 void set_output (unsigned char adress, unsigned char data )
 {
  i2c_start();
  i2c_write(adress);
  i2c_write(data);
  i2c_stop();
 }

int read_input ( unsigned char adress)
{
 int data;
 
 i2c_start();
 i2c_write(adress | 1);
 data=i2c_read(0);
 i2c_stop();
 return data;
}

void init_i2c_devices(void)
{   
 set_output(PCF8574A_1,0xff);       //set I/O to 1 for input mode
 set_output(PCF8574A_2,0xff);       //set I/O to 1 for input mode
 set_output(PCF8574A_3,0xff);       //set I/O to 1 for input mode

}
 
void update_rolluik ( char nr,char pressed,char released)
{
 char i;
 temp=1;
 k=0;
   
  
 if (pressed)
     {
      if (!rolluik[nr].keypresses_in_frame)
           {rolluik[nr].frametimer = 50;}        // 50* 64 msec  = 3.2 sec timeframe  
      ++rolluik[nr].keypresses_in_frame;
      }
      
 if ((released) && (rolluik[nr].frametimer == 0) && ( rolluik[nr].keypresses_in_frame == 0))
 
     {
      if (blocked(nr))
        {
         rolluik[nr].status_reg = reset_blocked(nr);
         temp<<=nr;
         blockmask &= ~temp;
         released = 0;
        }
       else
        {
         rolluik[nr].status_reg = set_blocked(nr);
         temp<<=nr;
         blockmask |= temp;
         released = 0;
        }
      }
 if (released)
     {
      switch (rolluik[nr].keypresses_in_frame)
      {
      case 1 :
        {
         if (!blocked(nr))
          {
           if (up(nr) || down(nr))
            { 
             rolluik[nr].status_reg = set_stop(nr);}
            else
            {
             if (stop(nr) && previous_state_up(nr))
              {rolluik[nr].status_reg = set_down(nr);}
              else
              {rolluik[nr].status_reg = set_up(nr);}
            }
          } 
          break;
        }
       case 4 :
         { k+=5;}
       case 3 :
         { k+=5;}
       case 2 :
         { 
          for(i=k;((i<(k+5)) && (!(rolluik[nr].level[i] == 0)));++i)
           {
             aux = (rolluik[nr].level[i])-1;
             if (!blocked(aux))
              {
               if (stop(nr))
                {rolluik[aux].status_reg = set_stop(aux);}
                
               if (down(nr))
                {
                 if (going_up(aux))
                  {
                   rolluik[aux].status_reg = set_stop(aux);
                   rolluik[aux].status_reg = set_reverse(aux);
                   reversetimer = 25;     // 25 * 64 msec = 1.6 sec
                  }
                 else
                  {rolluik[aux].status_reg = set_down(aux);}
                }
               
               if (up(nr))
                {
                 if (going_down(aux))
                  {
                   rolluik[aux].status_reg = set_stop(aux);
                   rolluik[aux].status_reg = set_reverse(aux);
                   reversetimer = 25;     // 25 * 64 msec = 1.6 sec
                  }
                 else
                  {rolluik[aux].status_reg = set_up(aux);}
                }
              }
            }
           break;
           }
       }
      }
}
  
void process_input()               //takes 41�sec
{
 debounced_input = 0x0000;
 debounced_input |= (read_input(PCF8574A_3));
 debounced_input<<=8;
 debounced_input |= (read_input(PCF8574A_2)); 
 debounced_input<<=8;
 debounced_input |= (read_input(PCF8574A_1));  
 
 debounced_input = (~(debounced_input));  
 
 rising_edge_mask = ~edgemarker_1 & debounced_input;
 edgemarker_1 |= rising_edge_mask;
 edgemarker_1 = rising_edge_mask | debounced_input;
 
 falling_edge_mask = edgemarker_2 & ~debounced_input;
 edgemarker_2 = edgemarker_1 | debounced_input;
 edgemarker_2 |= debounced_input;   
 
 
}   
 
 
void serialise()                   // takes 0.1 sec
{
 int mask = 0x01;
 char i;
 for ( i=0;i<nr_of_shutters;++i)
    {
     if (falling_edge_mask & mask)
      { update_rolluik(i,0,1);}
     if (rising_edge_mask & mask)
      { update_rolluik(i,1,0);}
     mask <<= 1;
    }
}

                     

// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void)
{
 sleep_disable();
 delay_ms(10);
 process_input();
 serialise();
 timerruns_to_go = 600;   // > then the longest time to open or close greatest roll-down shutter
 TCCR0 = 0x05;             // Start timer T0 : interrupts every 64 msec
 TCNT0 = 0x06;

}

// Timer 0 overflow interrupt service routine
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
   
 // Reinitialise Timer 0 value
 TCNT0 = 0x06; 
 
 output_changed=0;
 if ( timerruns_to_go)
     { timerruns_to_go--;}
 else
     {
      TCCR0 = 0x00;              // Stop timer
      sleep_enable();
     }
     
 if(reversetimer > 0)
    { reversetimer--;}
 temp=1;
 for ( nr=0 ; nr <nr_of_shutters ; ++nr)
     { 
     
      if(rolluik[nr].frametimer > 0)
       {rolluik[nr].frametimer--;}
       else
       {rolluik[nr].keypresses_in_frame =0;}
       
      if (!(reversetimer) && ( reverse(nr)))
        {
         rolluik[nr].status_reg = reset_reverse(nr);
         if (rolluik[nr].status_reg == previous_state_up(nr))
          {rolluik[nr].status_reg = set_down(nr);}
         else
          {rolluik[nr].status_reg = set_up(nr) ;}
        }
        
      if (going_up(nr))
        {
         if(rolluik[nr].position < max_pos[nr])
          {rolluik[nr].position++;}
         else
          {rolluik[nr].status_reg = set_stop(nr);}
        }
        
      if (going_down(nr))
        {
         if (rolluik[nr].position > 0)
          {rolluik[nr].position--;}
         else
          {rolluik[nr].status_reg = set_stop(nr);}
        }
        
      if (up(nr) && (!(going_up(nr))))
        {
         rolluik[nr].status_reg = set_going_up(nr) ;
         upwards.entire |=temp; 
         output_changed=1;
        }
        
      if (down(nr) && (!(going_down(nr))))
        {
         rolluik[nr].status_reg = set_going_down(nr);
         downwards.entire |= temp;
         output_changed=1;
        }
      
      if (stop(nr))
        {
          upwards.entire   &=~temp;
          downwards.entire &=~temp; 
          output_changed=1;
        }
#ifdef LCD_ATTACHED     
if (lcd_attached)
    { 
      if (blocked(nr))
       {
        lcd_gotoxy(nr+2,1);
        lcd_putchar(6);
       }
      else
       {
         if (stop(nr))
          {
            if (rolluik[nr].position == 0)
             {
              lcd_gotoxy(nr+2,1);
              lcd_putchar(1);
             }
            else
             {
              if (rolluik[nr].position == max_pos[nr])
                 {
                   lcd_gotoxy(nr+2,1);
                   lcd_putchar(0);
                 }
              else
                 {
                   lcd_gotoxy(nr+2,1);
                   lcd_putchar(2);
                              
                 }
             } 
           }
         if (reverse(nr))
          { 
           lcd_gotoxy(nr+2,1);
           lcd_putchar(5);
          }
         if (going_up(nr))
          {
           lcd_gotoxy(nr+2,1);
           lcd_putchar(3); 
          }
         if (going_down(nr))
          {
           lcd_gotoxy(nr+2,1);
           lcd_putchar(4); 
          }
         }
      }
#endif
 temp <<=1;
   }
  upwards.entire    &= ~blockmask;
  downwards.entire  &= ~blockmask;
 
  
#ifdef LCD_ATTACHED   
  if (upwards.entire & downwards.entire)
      {
       while(1)
        {
         lcd_gotoxy(9,2);
         lcd_putsf(error_message);  
        }
       }  
#endif      
  
  if (output_changed)
   {
    copy_downwards = downwards;
    copy_upwards = upwards;
    mask=0x0001;
    x=0;
    for ( z=0; z<4; z++ )
       {
         mask = 0x0001;
         k=0;
         for ( y=0; y<8 ; y++ )
              {
                if (y==4)
                  {
                    x++;
                    mask=0x0001;
                    copy_downwards.fraction[z]>>=4;
                    copy_upwards.fraction[z]>>=4;
                    k=0;
                  } 
                PCF8574[x] |= ((copy_downwards.fraction[z] << k) & mask);
                mask <<= 1;
                PCF8574[x] |= ((copy_upwards.fraction[z] << (k+1)) & mask);
                mask <<= 1;                                         
                k++;
              }
             x++;
         }
         
         set_output(PCF8574_1,PCF8574[0]);   
         set_output(PCF8574_2,PCF8574[1]); 
         set_output(PCF8574_3,PCF8574[2]); 
         set_output(PCF8574_4,PCF8574[3]);
         set_output(PCF8574_5,PCF8574[4]);
         set_output(PCF8574_6,PCF8574[5]);
            
         PCF8574[0]=0x00;
         PCF8574[1]=0x00;
         PCF8574[2]=0x00;
         PCF8574[3]=0x00;
         PCF8574[4]=0x00;
         PCF8574[5]=0x00;
  
   }     
      
       
}       

void init_devices()
{  
 
 for (nr=0; nr<nr_of_shutters; ++nr)
  {
   rolluik[nr].position = rolluik_def.position_def;
   max_pos[nr] = rolluik[nr].position;
   rolluik[nr].frametimer = 0;
   rolluik[nr].keypresses_in_frame = 0;
   rolluik[nr].status_reg = rolluik_def[nr].status_reg_def;
   
    for(k=0;k<15;k++)
     {
      rolluik[nr].level[k] = rolluik_def[nr].level_def[k];
     }
   }
}

#ifdef LCD_ATTACHED
void init_screen(void)
{
 lcd_clear();
 define_char(char0,0);
 define_char(char1,1);
 define_char(char2,2);
 define_char(char3,3);
 define_char(char4,4);
 define_char(char5,5);
 define_char(char6,6); 
 
 lcd_gotoxy(2,1);
 for (k=0;k<nr_of_shutters;k++)
  {
   lcd_putchar(0);
  }
}
#endif

void initial_status(void)
{
 
 set_output(PCF8574_1,0b10101010);      // All shutters open for initialisation  
 set_output(PCF8574_2,0b10101010);  
 set_output(PCF8574_3,0b10101010); 
 set_output(PCF8574_4,0b10101010);
 set_output(PCF8574_5,0b10101010);
 set_output(PCF8574_6,0b10101010); 
 
 for (k=0;k<4;++k)                     // # seconds for the longest shutter to go up
  {
   delay_ms(999);
  } 
    
 set_output(PCF8574_1,0b00000000);    // stop all shutters 
 set_output(PCF8574_2,0b00000000); 
 set_output(PCF8574_3,0b00000000);
 set_output(PCF8574_4,0b00000000);
 set_output(PCF8574_5,0b00000000);
 set_output(PCF8574_6,0b00000000);   
}
#ifdef LCD_ATTACHED
void version(void)
{
 
 lcd_gotoxy(3,0);
 lcd_putsf(message1);
 lcd_gotoxy(7,1);
 lcd_putsf(message2);
 lcd_gotoxy(3,3);
 lcd_putsf(message3);   
 
}
#endif 
// Declare your global variables here

void main(void)
{

// Input/Output Ports initialization
// Port A initialization
// Func0=In Func1=In Func2=In Func3=In Func4=In Func5=In Func6=In Func7=In 
// State0=T State1=T State2=T State3=T State4=T State5=T State6=T State7=T 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func0=In Func1=In Func2=In Func3=In Func4=In Func5=In Func6=In Func7=In 
// State0=T State1=T State2=T State3=T State4=T State5=T State6=T State7=T 
PORTB=0xFF;
DDRB=0xFF;

// Port C initialization
// Func0=In Func1=In Func2=In Func3=In Func4=In Func5=In Func6=In Func7=In 
// State0=T State1=T State2=T State3=T State4=T State5=T State6=T State7=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func0=In Func1=In Func2=In Func3=In Func4=In Func5=In Func6=In Func7=In 
// State0=T State1=T State2=T State3=T State4=T State5=T State6=T State7=T 
PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 3,906 kHz
TCCR0=0x00;                    //Stop timer till after init_devices
TCNT0=0x06;                    // set timer to 10 msec

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer 1 Stopped
// Mode: Normal top=FFFFh
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Low level (changed from falling edge to be able to go in powerdown mode)
// INT1: Off
GIMSK=0x40;
MCUCR=0x00;
GIFR=0x40;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x02;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
// Analog Comparator Output: Off
ACSR=0x80;  

// I2C Bus initialization
i2c_init();

// LCD module initialization  
#ifdef LCD_ATTACHED
lcd_attached=lcd_init(20); 
#endif   
init_devices(); 
init_i2c_devices(); 
#ifdef LCD_ATTACHED
if (lcd_attached)
 {
  version(); 
 } 
#endif
initial_status();   
 

// Global enable interrupts

#asm("sei") 
 
#ifdef LCD_ATTACHED  
if (lcd_attached)
 {
  init_screen();
 }
#endif
sleep_enable();


while (1)
      {
       PORTB=0xFE;
       powerdown();
       PORTB=0B11111101;
      };
}
