#ifndef __usart_h_included__
#define __usart_h_included__ 

#include <mega162.h> 

//USART Control and Status Register A � UCSRA 
#define UPE   2
#define OVR   3
#define FE    4
#define UDRE  5
#define RXC   7

#define FRAMING_ERROR        (1<<FE)
#define PARITY_ERROR         (1<<UPE)
#define DATA_OVERRUN         (1<<OVR) 
#define DATA_REGISTER_EMPTY  (1<<UDRE) 
#define RX_COMPLETE          (1<<RXC) 

//USART Control and Status Register B � UCSRB 
#define TXB8  0
#define RXB8  1
#define TXEN  3
#define RXEN  4
#define RXCIE 7  

#define AKTIFKAN_TRANSMITTER_IR()           UCSR0B|= (1<<TXEN)
#define MATIKAN_TRANSMITTER_IR()	        UCSR0B&= ~(1<<TXEN)

#define AKTIFKAN_RECEIVER_IR()			    UCSR0B|= (1<<RXEN)
#define MATIKAN_RECEIVER_IR()			    UCSR0B&= ~(1<<RXEN)

#define AKTIFKAN_RECEIVER_INTERRUPT_IR()	UCSR0B|= (1<<RXCIE)
#define MATIKAN_RECEIVER_INTERRUPT_IR()	    UCSR0B&= ~(1<<RXCIE)

void inisialisasiUSART(void); 
//Pengiriman data serial menggunakan IR
void kirimDataSerialIR(unsigned char data); 
//Pengiriman data serial untuk debugging program
void kirimDataSerial(unsigned char data);

#endif     