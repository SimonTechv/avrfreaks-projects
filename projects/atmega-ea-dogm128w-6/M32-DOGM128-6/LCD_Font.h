#ifndef LCD_FONT_H
#define LCD_FONT_H

prog_uint8_t ASCII5_7[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00,// (space)   
	0x00, 0x00, 0x5F, 0x00, 0x00,// !         
	0x00, 0x07, 0x00, 0x07, 0x00,// "         
	0x14, 0x7F, 0x14, 0x7F, 0x14,// #         
	0x24, 0x2A, 0x7F, 0x2A, 0x12,// $         
	0x23, 0x13, 0x08, 0x64, 0x62,// %         
	0x36, 0x49, 0x55, 0x22, 0x50,// &         
	0x00, 0x05, 0x03, 0x00, 0x00,// '         
	0x00, 0x1C, 0x22, 0x41, 0x00,// (         
	0x00, 0x41, 0x22, 0x1C, 0x00,// )         
	0x08, 0x2A, 0x1C, 0x2A, 0x08,// *         
	0x08, 0x08, 0x3E, 0x08, 0x08,// +         
	0x00, 0x50, 0x30, 0x00, 0x00,// ,         
	0x08, 0x08, 0x08, 0x08, 0x08,// -         
	0x00, 0x60, 0x60, 0x00, 0x00,// .         
	0x20, 0x10, 0x08, 0x04, 0x02,// /         
	0x3E, 0x51, 0x49, 0x45, 0x3E,// 0         
	0x00, 0x42, 0x7F, 0x40, 0x00,// 1         
	0x42, 0x61, 0x51, 0x49, 0x46,// 2         
	0x21, 0x41, 0x45, 0x4B, 0x31,// 3         
	0x18, 0x14, 0x12, 0x7F, 0x10,// 4         
	0x27, 0x45, 0x45, 0x45, 0x39,// 5         
	0x3C, 0x4A, 0x49, 0x49, 0x30,// 6         
	0x01, 0x71, 0x09, 0x05, 0x03,// 7         
	0x36, 0x49, 0x49, 0x49, 0x36,// 8         
	0x06, 0x49, 0x49, 0x29, 0x1E,// 9         
	0x00, 0x36, 0x36, 0x00, 0x00,// :         
	0x00, 0x56, 0x36, 0x00, 0x00,// ;         
	0x00, 0x08, 0x14, 0x22, 0x41,// <         
	0x14, 0x14, 0x14, 0x14, 0x14,// =         
	0x41, 0x22, 0x14, 0x08, 0x00,// >         
	0x02, 0x01, 0x51, 0x09, 0x06,// ?         
	0x32, 0x49, 0x79, 0x41, 0x3E,// @         
	0x7E, 0x11, 0x11, 0x11, 0x7E,// A         
	0x7F, 0x49, 0x49, 0x49, 0x36,// B         
	0x3E, 0x41, 0x41, 0x41, 0x22,// C         
	0x7F, 0x41, 0x41, 0x22, 0x1C,// D         
	0x7F, 0x49, 0x49, 0x49, 0x41,// E         
	0x7F, 0x09, 0x09, 0x01, 0x01,// F         
	0x3E, 0x41, 0x41, 0x51, 0x32,// G         
	0x7F, 0x08, 0x08, 0x08, 0x7F,// H         
	0x00, 0x41, 0x7F, 0x41, 0x00,// I         
	0x20, 0x40, 0x41, 0x3F, 0x01,// J         
	0x7F, 0x08, 0x14, 0x22, 0x41,// K         
	0x7F, 0x40, 0x40, 0x40, 0x40,// L         
	0x7F, 0x02, 0x04, 0x02, 0x7F,// M         
	0x7F, 0x04, 0x08, 0x10, 0x7F,// N         
	0x3E, 0x41, 0x41, 0x41, 0x3E,// O         
	0x7F, 0x09, 0x09, 0x09, 0x06,// P         
	0x3E, 0x41, 0x51, 0x21, 0x5E,// Q         
	0x7F, 0x09, 0x19, 0x29, 0x46,// R         
	0x46, 0x49, 0x49, 0x49, 0x31,// S         
	0x01, 0x01, 0x7F, 0x01, 0x01,// T         
	0x3F, 0x40, 0x40, 0x40, 0x3F,// U         
	0x1F, 0x20, 0x40, 0x20, 0x1F,// V         
	0x7F, 0x20, 0x18, 0x20, 0x7F,// W         
	0x63, 0x14, 0x08, 0x14, 0x63,// X         
	0x03, 0x04, 0x78, 0x04, 0x03,// Y         
	0x61, 0x51, 0x49, 0x45, 0x43,// Z         
	0x00, 0x00, 0x7F, 0x41, 0x41,// [         
	0x02, 0x04, 0x08, 0x10, 0x20,// "\"       
	0x41, 0x41, 0x7F, 0x00, 0x00,// ]         
	0x04, 0x02, 0x01, 0x02, 0x04,// ^         
	0x40, 0x40, 0x40, 0x40, 0x40,// _         
	0x00, 0x01, 0x02, 0x04, 0x00,// `         
	0x20, 0x54, 0x54, 0x54, 0x78,// a         
	0x7F, 0x48, 0x44, 0x44, 0x38,// b         
	0x38, 0x44, 0x44, 0x44, 0x20,// c         
	0x38, 0x44, 0x44, 0x48, 0x7F,// d         
	0x38, 0x54, 0x54, 0x54, 0x18,// e         
	0x08, 0x7E, 0x09, 0x01, 0x02,// f         
	0x08, 0x14, 0x54, 0x54, 0x3C,// g         
	0x7F, 0x08, 0x04, 0x04, 0x78,// h         
	0x00, 0x44, 0x7D, 0x40, 0x00,// i         
	0x20, 0x40, 0x44, 0x3D, 0x00,// j         
	0x00, 0x7F, 0x10, 0x28, 0x44,// k         
	0x00, 0x41, 0x7F, 0x40, 0x00,// l         
	0x7C, 0x04, 0x18, 0x04, 0x78,// m         
	0x7C, 0x08, 0x04, 0x04, 0x78,// n         
	0x38, 0x44, 0x44, 0x44, 0x38,// o         
	0x7C, 0x14, 0x14, 0x14, 0x08,// p         
	0x08, 0x14, 0x14, 0x18, 0x7C,// q         
	0x7C, 0x08, 0x04, 0x04, 0x08,// r         
	0x48, 0x54, 0x54, 0x54, 0x20,// s         
	0x04, 0x3F, 0x44, 0x40, 0x20,// t         
	0x3C, 0x40, 0x40, 0x20, 0x7C,// u         
	0x1C, 0x20, 0x40, 0x20, 0x1C,// v         
	0x3C, 0x40, 0x30, 0x40, 0x3C,// w         
	0x44, 0x28, 0x10, 0x28, 0x44,// x         
	0x0C, 0x50, 0x50, 0x50, 0x3C,// y         
	0x44, 0x64, 0x54, 0x4C, 0x44,// z         
	0x00, 0x08, 0x36, 0x41, 0x00,// {         
	0x00, 0x00, 0x7F, 0x00, 0x00,// |         
	0x00, 0x41, 0x36, 0x08, 0x00,// }         
	0x08, 0x08, 0x2A, 0x1C, 0x08,// ->        
	0x08, 0x1C, 0x2A, 0x08, 0x08 // <-        

};

prog_uint8_t ASCII8_16[] =
{
/*	 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* ! */ 0x00,0x00,0x70,0xF8,0xF8,0x70,0x00,0x00,0x00,0x00,0x00,0x1B,0x1B,0x00,0x00,0x00,
/* " */ 0x00,0x1C,0x3C,0x00,0x00,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* # */ 0x40,0xF0,0xF0,0x40,0xF0,0xF0,0x40,0x00,0x04,0x1F,0x1F,0x04,0x1F,0x1F,0x04,0x00,
/* $ */ 0x70,0xF8,0x88,0x8E,0x8E,0x98,0x30,0x00,0x0C,0x18,0x10,0x70,0x70,0x1F,0x0F,0x00,
/* % */ 0x60,0x60,0x00,0x00,0x80,0xC0,0x60,0x00,0x18,0x0C,0x06,0x03,0x01,0x18,0x18,0x00,
/* & */ 0x00,0xB0,0xF8,0xC8,0x78,0xB0,0x80,0x00,0x0F,0x1F,0x10,0x11,0x0F,0x1F,0x10,0x00,
/* ' */ 0x00,0x20,0x3C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* ( */ 0x00,0x00,0xE0,0xF0,0x18,0x08,0x00,0x00,0x00,0x00,0x07,0x0F,0x18,0x10,0x00,0x00,
/* ) */ 0x00,0x00,0x08,0x18,0xF0,0xE0,0x00,0x00,0x00,0x00,0x10,0x18,0x0F,0x07,0x00,0x00,
/* * */ 0x00,0x40,0xC0,0x80,0x80,0xC0,0x40,0x00,0x01,0x05,0x07,0x03,0x03,0x07,0x05,0x01,
/* + */ 0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x01,0x01,0x07,0x07,0x01,0x01,0x00,
/* , */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3C,0x1C,0x00,0x00,0x00,
/* - */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
/* . */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,
/* / */ 0x00,0x00,0x00,0x00,0x80,0xC0,0x60,0x00,0x18,0x0C,0x06,0x03,0x01,0x00,0x00,0x00,
/* 0 */ 0xE0,0xF0,0x18,0x88,0x88,0x18,0xF0,0xE0,0x07,0x0F,0x18,0x11,0x11,0x18,0x0F,0x07,
/* 1 */ 0x00,0x20,0x30,0xF8,0xF8,0x00,0x00,0x00,0x00,0x10,0x10,0x1F,0x1F,0x10,0x10,0x00,
/* 2 */ 0x10,0x18,0x08,0x88,0xC8,0x78,0x30,0x00,0x1C,0x1E,0x13,0x11,0x10,0x18,0x18,0x00,
/* 3 */ 0x10,0x18,0x88,0x88,0x88,0xF8,0x70,0x00,0x08,0x18,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* 4 */ 0x80,0xC0,0x60,0x30,0xF8,0xF8,0x00,0x00,0x01,0x01,0x01,0x11,0x1F,0x1F,0x11,0x00,
/* 5 */ 0xF8,0xF8,0x88,0x88,0x88,0x88,0x08,0x00,0x08,0x18,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* 6 */ 0xE0,0xF0,0x98,0x88,0x88,0x80,0x00,0x00,0x0F,0x1F,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* 7 */ 0x18,0x18,0x08,0x08,0x88,0xF8,0x78,0x00,0x00,0x00,0x1E,0x1F,0x01,0x00,0x00,0x00,
/* 8 */ 0x70,0xF8,0x88,0x88,0x88,0xF8,0x70,0x00,0x0F,0x1F,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* 9 */ 0x70,0xF8,0x88,0x88,0x88,0xF8,0xF0,0x00,0x00,0x10,0x10,0x10,0x18,0x0F,0x07,0x00,
/* : */ 0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,
/* ; */ 0x00,0x00,0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x10,0x1C,0x0C,0x00,0x00,0x00,
/* < */ 0x00,0x00,0x80,0xC0,0x60,0x30,0x10,0x00,0x00,0x01,0x03,0x06,0x0C,0x18,0x10,0x00,
/* = */ 0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x00,
/* > */ 0x00,0x10,0x30,0x60,0xC0,0x80,0x00,0x00,0x00,0x10,0x18,0x0C,0x06,0x03,0x01,0x00,
/* ? */ 0x30,0x38,0x08,0x88,0xC8,0x78,0x30,0x00,0x00,0x00,0x00,0x1B,0x1B,0x00,0x00,0x00,
/* @ */ 0xE0,0xF0,0x10,0x90,0x90,0xF0,0xE0,0x00,0x0F,0x1F,0x10,0x17,0x17,0x17,0x03,0x00,
/* A */ 0xC0,0xE0,0x30,0x18,0x30,0xE0,0xC0,0x00,0x1F,0x1F,0x01,0x01,0x01,0x1F,0x1F,0x00,
/* B */ 0x08,0xF8,0xF8,0x88,0x88,0xF8,0x70,0x00,0x10,0x1F,0x1F,0x10,0x10,0x1F,0x0F,0x00,
/* C */ 0xE0,0xF0,0x18,0x08,0x08,0x18,0x30,0x00,0x07,0x0F,0x18,0x10,0x10,0x18,0x0C,0x00,
/* D */ 0x08,0xF8,0xF8,0x08,0x18,0xF0,0xE0,0x00,0x10,0x1F,0x1F,0x10,0x18,0x0F,0x07,0x00,
/* E */ 0x08,0xF8,0xF8,0x88,0xC8,0x18,0x38,0x00,0x10,0x1F,0x1F,0x10,0x11,0x18,0x1C,0x00,
/* F */ 0x08,0xF8,0xF8,0x88,0xC8,0x18,0x38,0x00,0x10,0x1F,0x1F,0x10,0x01,0x00,0x00,0x00,
/* G */ 0xE0,0xF0,0x18,0x08,0x08,0x18,0x30,0x00,0x07,0x0F,0x18,0x11,0x11,0x0F,0x1F,0x00,
/* H */ 0xF8,0xF8,0x80,0x80,0x80,0xF8,0xF8,0x00,0x1F,0x1F,0x00,0x00,0x00,0x1F,0x1F,0x00,
/* I */ 0x00,0x00,0x08,0xF8,0xF8,0x08,0x00,0x00,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,
/* J */ 0x00,0x00,0x00,0x08,0xF8,0xF8,0x08,0x00,0x0E,0x1E,0x10,0x10,0x1F,0x0F,0x00,0x00,
/* K */ 0x08,0xF8,0xF8,0x80,0xC0,0x78,0x38,0x00,0x10,0x1F,0x1F,0x01,0x03,0x1E,0x1C,0x00,
/* L */ 0x08,0xF8,0xF8,0x08,0x00,0x00,0x00,0x00,0x10,0x1F,0x1F,0x10,0x10,0x18,0x1C,0x00,
/* M */ 0xF8,0xF8,0x70,0xE0,0xE0,0x70,0xF8,0xF8,0x1F,0x1F,0x00,0x00,0x00,0x00,0x1F,0x1F,
/* N */ 0xF8,0xF8,0x70,0xE0,0xC0,0xF8,0xF8,0x00,0x1F,0x1F,0x00,0x00,0x01,0x1F,0x1F,0x00,
/* O */ 0xF0,0xF8,0x08,0x08,0x08,0xF8,0xF0,0x00,0x0F,0x1F,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* P */ 0x08,0xF8,0xF8,0x88,0x88,0xF8,0x70,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,0x00,0x00,
/* Q */ 0xF0,0xF8,0x08,0x08,0x08,0xF8,0xF0,0x00,0x0F,0x1F,0x10,0x1C,0x78,0x7F,0x4F,0x00,
/* R */ 0x08,0xF8,0xF8,0x88,0x88,0xF8,0x70,0x00,0x10,0x1F,0x1F,0x00,0x01,0x1F,0x1E,0x00,
/* S */ 0x30,0x78,0xC8,0x88,0x88,0x38,0x30,0x00,0x0C,0x1C,0x10,0x10,0x11,0x1F,0x0E,0x00,
/* T */ 0x38,0x18,0x08,0xF8,0xF8,0x08,0x18,0x38,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,
/* U */ 0xF8,0xF8,0x00,0x00,0x00,0xF8,0xF8,0x00,0x0F,0x1F,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* V */ 0xF8,0xF8,0x00,0x00,0x00,0x00,0xF8,0xF8,0x03,0x07,0x0C,0x18,0x18,0x0C,0x07,0x03,
/* W */ 0xF8,0xF8,0x00,0x00,0x00,0x00,0xF8,0xF8,0x07,0x1F,0x1C,0x07,0x07,0x1C,0x1F,0x07,
/* X */ 0x18,0x38,0x60,0xC0,0xC0,0x60,0x38,0x18,0x18,0x1C,0x06,0x03,0x03,0x06,0x1C,0x18,
/* Y */ 0x38,0x78,0xC0,0x80,0x80,0xC0,0x78,0x38,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,
/* Z */ 0x38,0x18,0x08,0x88,0xC8,0x68,0x38,0x18,0x1C,0x1E,0x13,0x11,0x10,0x10,0x18,0x1C,
/* [ */ 0x00,0x00,0xF8,0xF8,0x08,0x08,0x00,0x00,0x00,0x00,0x1F,0x1F,0x10,0x10,0x00,0x00,
/* \ */ 0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x00,
/* ] */ 0x00,0x00,0x08,0x08,0xF8,0xF8,0x00,0x00,0x00,0x00,0x10,0x10,0x1F,0x1F,0x00,0x00,
/* ^ */ 0x10,0x18,0x0C,0x06,0x0C,0x18,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* _ */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
/* ` */ 0x00,0x00,0x06,0x0E,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/* a */ 0x00,0x40,0x40,0x40,0xC0,0x80,0x00,0x00,0x0E,0x1F,0x11,0x11,0x0F,0x1F,0x10,0x00,
/* b */ 0x08,0xF8,0xF8,0x40,0xC0,0x80,0x00,0x00,0x00,0x1F,0x1F,0x10,0x10,0x1F,0x0F,0x00,
/* c */ 0x80,0xC0,0x40,0x40,0x40,0xC0,0x80,0x00,0x0F,0x1F,0x10,0x10,0x10,0x18,0x08,0x00,
/* d */ 0x00,0x80,0xC0,0x48,0xF8,0xF8,0x00,0x00,0x0F,0x1F,0x10,0x10,0x0F,0x1F,0x10,0x00,
/* e */ 0x80,0xC0,0x40,0x40,0x40,0xC0,0x80,0x00,0x0F,0x1F,0x11,0x11,0x11,0x19,0x09,0x00,
/* f */ 0x80,0xF0,0xF8,0x88,0x18,0x30,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,0x00,0x00,
/* g */ 0x80,0xC0,0x40,0x40,0x80,0xC0,0x40,0x00,0x4F,0xDF,0x90,0x90,0xFF,0x7F,0x00,0x00,
/* h */ 0x08,0xF8,0xF8,0x80,0x40,0xC0,0x80,0x00,0x10,0x1F,0x1F,0x00,0x00,0x1F,0x1F,0x00,
/* i */ 0x00,0x00,0x40,0xD8,0xD8,0x00,0x00,0x00,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,
/* j */ 0x00,0x00,0x00,0x00,0x40,0xD8,0xD8,0x00,0x00,0x60,0xE0,0x80,0x80,0xFF,0x7F,0x00,
/* k */ 0x08,0xF8,0xF8,0x00,0x80,0xC0,0x40,0x00,0x10,0x1F,0x1F,0x03,0x07,0x1C,0x18,0x00,
/* l */ 0x00,0x00,0x08,0xF8,0xF8,0x00,0x00,0x00,0x00,0x00,0x10,0x1F,0x1F,0x10,0x00,0x00,
/* m */ 0xC0,0xC0,0xC0,0x80,0x80,0xC0,0xC0,0x80,0x1F,0x1F,0x00,0x1F,0x1F,0x00,0x1F,0x1F,
/* n */ 0x40,0xC0,0x80,0x40,0x40,0xC0,0x80,0x00,0x00,0x1F,0x1F,0x00,0x00,0x1F,0x1F,0x00,
/* o */ 0x80,0xC0,0x40,0x40,0x40,0xC0,0x80,0x00,0x0F,0x1F,0x10,0x10,0x10,0x1F,0x0F,0x00,
/* p */ 0x40,0xC0,0x80,0x40,0x40,0xC0,0x80,0x00,0x80,0xFF,0xFF,0x90,0x10,0x1F,0x0F,0x00,
/* q */ 0x80,0xC0,0x40,0x40,0x80,0xC0,0x40,0x00,0x0F,0x1F,0x10,0x90,0xFF,0xFF,0x80,0x00,
/* r */ 0x40,0xC0,0x80,0xC0,0x40,0xC0,0x80,0x00,0x10,0x1F,0x1F,0x10,0x00,0x01,0x01,0x00,
/* s */ 0x80,0xC0,0x40,0x40,0x40,0xC0,0x80,0x00,0x08,0x19,0x13,0x12,0x16,0x1C,0x08,0x00,
/* t */ 0x40,0x40,0xF0,0xF8,0x40,0x40,0x00,0x00,0x00,0x00,0x0F,0x1F,0x10,0x18,0x08,0x00,
/* u */ 0xC0,0xC0,0x00,0x00,0xC0,0xC0,0x00,0x00,0x0F,0x1F,0x10,0x10,0x0F,0x1F,0x10,0x00,
/* v */ 0xC0,0xC0,0x00,0x00,0x00,0x00,0xC0,0xC0,0x03,0x07,0x0C,0x18,0x18,0x0C,0x07,0x03,
/* w */ 0xC0,0xC0,0x00,0x00,0x00,0x00,0xC0,0xC0,0x0F,0x1F,0x18,0x0E,0x0E,0x18,0x1F,0x0F,
/* x */ 0x40,0xC0,0x80,0x00,0x00,0x80,0xC0,0x40,0x10,0x18,0x0D,0x07,0x07,0x0D,0x18,0x10,
/* y */ 0xC0,0xC0,0x00,0x00,0x00,0xC0,0xC0,0x00,0x8F,0x9F,0x90,0x90,0xD0,0x7F,0x3F,0x00,
/* z */ 0xC0,0xC0,0x40,0x40,0xC0,0xC0,0x40,0x00,0x18,0x1C,0x16,0x13,0x11,0x18,0x18,0x00,
/* { */ 0x00,0x80,0x80,0xF0,0x78,0x08,0x08,0x00,0x00,0x00,0x00,0x0F,0x1F,0x10,0x10,0x00,
/* | */ 0x00,0x00,0x00,0x78,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F,0x00,0x00,0x00,
/* } */ 0x00,0x08,0x08,0x78,0xF0,0x80,0x80,0x00,0x00,0x10,0x10,0x1F,0x0F,0x00,0x00,0x00,
/* ~ */ 0x10,0x18,0x08,0x18,0x10,0x18,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif


typedef struct
{
	uint8_t Hz_Data[2];
	uint8_t Table[32];
} HZ_t;

//typedef HZ_t PROGMEM prog_Hz_t;

HZ_t  HZ_Table[] PROGMEM=
{
 {"环",{0x04, 0x44, 0x44, 0xFC, 0x44, 0x44, 0x00, 0x04,
 		0x04, 0x84, 0xE4, 0x1C, 0x84, 0x04, 0x04, 0x00,
		0x10, 0x30, 0x10, 0x1F, 0x08, 0x08, 0x00, 0x02,
		0x01, 0x00, 0xFF, 0x00, 0x00, 0x01, 0x06, 0x00 }},
 {"机",{0x10, 0x10, 0xD0, 0xFF, 0x90, 0x10, 0x00, 0xFC,
        0x04, 0x04, 0x04, 0xFC, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x03, 0x00, 0xFF, 0x80, 0x41, 0x20, 0x1F,
        0x00, 0x00, 0x00, 0x3F, 0x40, 0x40, 0x70, 0x00 }},
 {"立",{0x00, 0x10, 0x10, 0x90, 0x10, 0x10, 0x11, 0x16,
        0x10, 0x10, 0x10, 0xD0, 0x10, 0x10, 0x00, 0x00,
        0x40, 0x40, 0x40, 0x40, 0x43, 0x5C, 0x40, 0x40,
        0x50, 0x4C, 0x43, 0x40, 0x40, 0x40, 0x40, 0x00 }},
 {"绕",{0x20, 0x30, 0xAC, 0x63, 0x18, 0x00, 0x10, 0x10,
        0x9F, 0xA8, 0x48, 0xA8, 0x08, 0x08, 0xC0, 0x00,
        0x22, 0x67, 0x22, 0x12, 0x92, 0x85, 0x45, 0x3D,
        0x04, 0x04, 0x7C, 0x84, 0x85, 0x85, 0xE1, 0x00 }},
 {"声",{0x04, 0x04, 0xD4, 0x54, 0x54, 0x54, 0x54, 0xDF,
        0x54, 0x54, 0x54, 0x54, 0xD4, 0x04, 0x04, 0x00,
        0x80, 0x60, 0x1F, 0x02, 0x02, 0x02, 0x02, 0x03,
        0x02, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00 }},
 {"收",{0x00, 0xF8, 0x00, 0x00, 0xFF, 0x00, 0x80, 0x60,
        0xDF, 0x10, 0x10, 0x10, 0xF0, 0x10, 0x10, 0x00,
        0x00, 0x0F, 0x04, 0x02, 0xFF, 0x00, 0x80, 0x40,
        0x21, 0x16, 0x08, 0x16, 0x61, 0xC0, 0x40, 0x00 }},
 {"体",{0x80, 0x40, 0x20, 0xF8, 0x07, 0x10, 0x10, 0xD0,
        0x30, 0xFF, 0x30, 0xD0, 0x10, 0x10, 0x10, 0x00,
        0x00, 0x00, 0x00, 0xFF, 0x08, 0x04, 0x03, 0x04,
        0x04, 0xFF, 0x04, 0x04, 0x03, 0x0C, 0x04, 0x00 }},
 {"响",{0x00, 0xFC, 0x04, 0x04, 0xFC, 0x00, 0xF8, 0x08,
        0xCC, 0x4A, 0x49, 0xC8, 0x08, 0xF8, 0x00, 0x00,
        0x00, 0x0F, 0x04, 0x04, 0x0F, 0x00, 0xFF, 0x00,
        0x0F, 0x08, 0x08, 0x4F, 0x80, 0x7F, 0x00, 0x00 }},
 {"音",{0x40, 0x40, 0x44, 0x44, 0x4C, 0x74, 0x45, 0x46,
        0x44, 0x64, 0x5C, 0x44, 0x44, 0x40, 0x40, 0x00,
        0x00, 0x00, 0x00, 0xFF, 0x49, 0x49, 0x49, 0x49,
        0x49, 0x49, 0x49, 0xFF, 0x00, 0x00, 0x00, 0x00 }}
};
