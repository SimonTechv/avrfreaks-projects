#include "int.h"

void Init_INT0(void)
{
  PORTC_PIN1CTRL=PORT_OPC_PULLDOWN_gc|PORT_ISC_RISING_gc;
  PORTC_INTCTRL=PORT_INT0LVL_LO_gc;
  PORTC_INT0MASK=PIN1_bm;
  PMIC_CTRL=PMIC_LOLVLEX_bm;  
  sei();  
}

ISR(PORTC_INT0_vect)
{
  cli();  
  
  DISEN_EXCLK;
  DISEN_245;
  DATA_OUPUT();
  LCD_WR_REG(0x0020,0);
  LCD_WR_REG(0x0021,0);
  LCD_WR_REG(0x0050,0x00);
  LCD_WR_REG(0x0051,239);
  LCD_WR_REG(0x0052,0x00);
  LCD_WR_REG(0x0053,319);
  LCD_WR_REG(0x0003,0x1028); 
  LCD_WR_REG16(0x0022);	 
  LCD_CS_L();
  DATA_INPUT();
  LCD_RS_H();
  LCD_WR_L();
  EN_EXCLK;
  EN_245;	 
  sei();
}