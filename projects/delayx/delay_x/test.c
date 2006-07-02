#include <avr/io.h>
#include "delay_x.h"


//----------------------------------------------------------------------------
//
// Serial I/O functions
//
//----------------------------------------------------------------------------

#define UART_BAUD(baud) ((unsigned int)((F_CPU / (16.0 * (baud))) + 0.5) - 1)
#define uart_putchar(c) ( UDR=(c))
#define txrdy()         ( USR & (1<<UDRE) )

void uart_init( unsigned int baud )
{
  // disable and clear the UART
  UCR = 0x00;
  USR = USR;

  // load the baudrate divisor register
  UBRR = (unsigned char)(baud);

  // enable UART transmitter & receiver
  UCR = (1<<RXEN) | (1<<TXEN);
  UDR;
}

static void
put_char( unsigned char c )
{
    while( !txrdy() )
        ;
    uart_putchar( c );
}

static void
put_str( char *s )
{
    while( *s )  {
        put_char( *s );
        ++s;
    }
}

static void
puthex_c(unsigned char c)
{
    unsigned char x;
    x = c >> 4;         // most significant nibble
    put_char( x <= 9 ? x + '0' : x - 0xa + 'A' );
    x = c & 0x0f;       // least significant nibble
    put_char( x <= 9 ? x + '0' : x - 0xa + 'A' );
}

static void
puthex_i(unsigned int i)
{
    puthex_c( i >> 8 );
    puthex_c( i & 0xff );
}



//----------------------------------------------------------------------------
//
//   TIMER1  functions
//
//----------------------------------------------------------------------------

static inline void initTimer1(unsigned int, unsigned char) __attribute__((always_inline));
static inline void
initTimer1(unsigned int x, unsigned char prescaler)
{
    TCCR1B = 0;             // stop counter
    TCNT1 = x;              // preset
    TCCR1B = prescaler;     // start counter
}

static inline void stopTimer1(void) __attribute__((always_inline));
static inline void
stopTimer1(void)
{
    TCCR1B = 0;
}



//----------------------------------------------------------------------------
//
//   M A I N
//
//   Timer 1 is used for verifying the number of clock cycles
//   that are generated by the delay macros from "delay_x.h"
//
//----------------------------------------------------------------------------

int
main(void)
{
    uart_init(UART_BAUD(9600.0));
    put_str( "Hello World\n" );

    /*
     * Verify this in assembler listing
     */
    _delay_ns( (1.0/F_CPU)*1e9 );       // 1 nop
    _delay_ns( 2*(1.0/F_CPU)*1e9 );     // 2 nops
    _delay_ns( 3*(1.0/F_CPU)*1e9 );     // 3 nops
    _delay_ns( 4*(1.0/F_CPU)*1e9 );     // 4 nops
    _delay_ns( 5*(1.0/F_CPU)*1e9 );     // 5 nops
    _delay_ns( 6*(1.0/F_CPU)*1e9 );     // 6 nops
    _delay_ns( 7*(1.0/F_CPU)*1e9 );     // 7 nops
    _delay_ns( 8*(1.0/F_CPU)*1e9 );     // 8 nops
    _delay_ns( 9*(1.0/F_CPU)*1e9 );     // 9 nops
    _delay_ns( 10*(1.0/F_CPU)*1e9 );     // 10 nops
    _delay_ns( 11*(1.0/F_CPU)*1e9 );     // 11 nops
    _delay_ns( 12*(1.0/F_CPU)*1e9 );     // 12 nops
    _delay_ns( 13*(1.0/F_CPU)*1e9 );     // delay loop

    _delay_us( 1 );
    _delay_us( 1.0 + 125.e-3 );
    _delay_ms( 1.0 + 125.e-3 + 125.e-6 );
    _delay_s( 1.0 + 1.0e-3 + 1.0e-6 +6*125.0e-9 );


    /*
     * verify NOPs
     */
    initTimer1(0,1);
    _delay_cycles( 1 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 2 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 2 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 3 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 3 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 4 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 4 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 5 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 5 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 6 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 6 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 7 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 7 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 8 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 8 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 9 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 9 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 10 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 10 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 11 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 11 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 12 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 12 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 13 ? " OK\n" : " ERR\n" );

    /*
     * verify one byte counter
     */
    initTimer1(0,1);
    _delay_cycles( 13 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 14 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 0xa8 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0xa9 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 0xa9 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0xaa ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 0xaa );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0xab ? " OK\n" : " ERR\n" );


    /*
     * verify two byte counter
     */
    initTimer1(0,1);
    _delay_cycles( 0x55a8 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0x55a9 ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 0x55a9 );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0x55aa ? " OK\n" : " ERR\n" );

    initTimer1(0,1);
    _delay_cycles( 0x55aa );
    stopTimer1();   // takes one cycle
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0x55ab ? " OK\n" : " ERR\n" );

    /*
     * verify four byte counter
     */
    initTimer1(0,5);
    _delay_cycles( 1024.0*0x55aa - 1 );
    stopTimer1();
    puthex_i( TCNT1 );
    put_str( TCNT1 == 0x55aa ? " OK\n" : " ERR\n" );

}