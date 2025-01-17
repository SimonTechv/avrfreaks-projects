// Ansteuerung eines HD44780 kompatiblen LCD im 4-Bit-Interfacemodus
// http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial
//
void lcd_data(unsigned char temp1);
void lcd_string(char *data);
void lcd_command(unsigned char temp1);
void lcd_enable(void);
void lcd_init(void);
void lcd_home(void);
void lcd_clear(void);
void set_cursor(uint8_t x, uint8_t y);
 
// Hier die verwendete Taktfrequenz in Hz eintragen, wichtig!
 
 
// LCD Befehle
 
#define CLEAR_DISPLAY 0x01
#define CURSOR_HOME   0x02
 
// Pinbelegung f�r das LCD, an verwendete Pins anpassen
 
#define LCD_PORT      PORTC
#define LCD_DDR       DDRC
#define LCD_RS        PC6
#define LCD_EN        PC7
// DB4 bis DB7 des LCD sind mit PD0 bis PD3 des AVR verbunden 
