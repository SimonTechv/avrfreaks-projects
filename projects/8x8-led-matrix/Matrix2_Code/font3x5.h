//*! \file font3x5.h \brief Graphic LED Matrix Font (Small Characters). */
//*****************************************************************************
//
// File Name	: 'font5x7.h'
// Title		: Graphic LCD Font (Ascii Charaters)
// Author		: Joe Clark
// Date			: 05/20/2007
// Revised		: 05/20/2007
// Version		: 0.1
// Target MCU	: Atmel AVR
// Editor Tabs	: 4
//
//*****************************************************************************

#ifndef FONT3x5_H
	#define FONT3x5_H
#endif

	#include <avr/pgmspace.h>

// 3x5 font
static uint8_t font3x5[] PROGMEM = {
0x00, 0x00, 0x00,	//space
0x1F, 0x11, 0x1F,	//0
0x09, 0x1F, 0x01,	//1
0x1C, 0x14, 0x16,	//2
0x14, 0x14, 0x1F,	//3
0x06, 0x04, 0x1F,	//4
0x17, 0x14, 0x1D,	//5
0x1F, 0x14, 0x1C,	//6
0x19, 0x04, 0x02,	//7
0x1E, 0x14, 0x1F,	//8
0x07, 0x14, 0x1F,	//9
0x01, 0x0A, 0x01,	//:
0x0A, 0x0B, 0x0A,	//=
0x01, 0x01, 0x01,	//blank
0x1E, 0x04, 0x1E,	//A
0x1F, 0x14, 0x0F,	//B
0x1F, 0x10, 0x11,	//C
0x1F, 0x10, 0x0E,	//D
0x1F, 0x14, 0x15,	//E
0x1F, 0x04, 0x04,	//F
0x1F, 0x10, 0x18,	//G
0x1F, 0x04, 0x1E,	//H
0x11, 0x1E, 0x11,	//I
0x18, 0x11, 0x1E,	//J
0x1E, 0x0C, 0x13,	//K
0x1F, 0x10, 0x11,	//L
0x1F, 0x06, 0x1E,	//M
0x1F, 0x03, 0x1D,	//N
0x0F, 0x11, 0x0E,	//O
0x1F, 0x04, 0x07,	//P
0x0F, 0x18, 0x1F,	//Q
0x1F, 0x0C, 0x1B,	//R
0x17, 0x14, 0x1D,	//S
0x01, 0x1E, 0x00,	//T
0x1E, 0x11, 0x1E,	//U
0x0F, 0x10, 0x0F,	//V
0x1F, 0x0C, 0x1F,	//W
0x13, 0x0C, 0x13,	//X
0x03, 0x1C, 0x03,	//Y
0x19, 0x14, 0x13,	//Z
};