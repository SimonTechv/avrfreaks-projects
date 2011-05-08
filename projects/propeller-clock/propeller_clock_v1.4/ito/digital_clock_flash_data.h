
#ifndef DIGITAL_CLOCK_DATA_H
#define DIGITAL_CLOCK_DATA_H

const unsigned char char_patterns[11][7] PROGMEM=
{
{0x04,0x0C,0x04,0x04,0x04,0x04,0x0E},//1
{0x0E,0x11,0x01,0x02,0x04,0x08,0x1F},//2
{0x1F,0x02,0x04,0x02,0x01,0x11,0x0E},//3
{0x02,0x06,0x0A,0x12,0x1F,0x02,0x02},//4
{0x1F,0x10,0x1E,0x01,0x01,0x11,0x0E},//5
{0x06,0x08,0x10,0x1E,0x11,0x11,0x0E},//6
{0x1F,0x11,0x01,0x02,0x04,0x04,0x04},//7
{0x0E,0x11,0x11,0x0E,0x11,0x11,0x0E},//8
{0x0E,0x11,0x11,0x0F,0x01,0x02,0x0C},//9
{0x0E,0x11,0x13,0x15,0x19,0x11,0x0E},//0																																																																																																																																																																																											
{0x00,0x0C,0x0C,0x00,0x0C,0x0C,0x00}//:			
};																																																																																																																																																																																													


 const char tab_chars[11] PROGMEM="1234567890:";	

//const char shift_message[] PROGMEM= {'SISTEMAS EMBARCADOS 2011',0x0D};
const unsigned int window_clock_map_x[40] PROGMEM={12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};																																							
const unsigned int window_clock_map_y[7] PROGMEM={13,14,15,16,17,18,19};
const unsigned int window_mensg_map_x[60] PROGMEM={};
const unsigned int window_mensg_map_y[7] PROGMEM={33,34,35,36,37,38,39};

const unsigned char shift_message[7][150] PROGMEM=
		{
			{0,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0},																																
			{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,1,0,0,0},																																
			{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0},																																
			{0,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,1,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0},																																
			{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0},																																
			{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0},																																
			{1,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0}																																
																																																																																																																																																																																																
		};
		
const int cosine[360] PROGMEM={
	128, 128, 128, 128, 128, 128, 127, 127, 127, 126, 
	126, 126, 125, 125, 124, 124, 123, 122, 122, 121, 
	120, 119, 119, 118, 117, 116, 115, 114, 113, 112, 
	111, 110, 109, 107, 106, 105, 104, 102, 101, 99, 
	98, 97, 95, 94, 92, 91, 89, 87, 86, 84, 
	82, 81, 79, 77, 75, 73, 72, 70, 68, 66, 
	64, 62, 60, 58, 56, 54, 52, 50, 48, 46, 
	44, 42, 40, 37, 35, 33, 31, 29, 27, 24, 
	22, 20, 18, 16, 13, 11, 9, 7, 4, 2, 
	0, -2, -4, -7, -9, -11, -13, -16, -18, -20, 
	-22, -24, -27, -29, -31, -33, -35, -37, -40, -42, 
	-44, -46, -48, -50, -52, -54, -56, -58, -60, -62, 
	-64, -66, -68, -70, -72, -73, -75, -77, -79, -81, 
	-82, -84, -86, -87, -89, -91, -92, -94, -95, -97, 
	-98, -99, -101, -102, -104, -105, -106, -107, -109, -110, 
	-111, -112, -113, -114, -115, -116, -117, -118, -119, -119, 
	-120, -121, -122, -122, -123, -124, -124, -125, -125, -126, 
	-126, -126, -127, -127, -127, -128, -128, -128, -128, -128, 
	-128, -128, -128, -128, -128, -128, -127, -127, -127, -126, 
	-126, -126, -125, -125, -124, -124, -123, -122, -122, -121, 
	-120, -119, -119, -118, -117, -116, -115, -114, -113, -112, 
	-111, -110, -109, -107, -106, -105, -104, -102, -101, -99, 
	-98, -97, -95, -94, -92, -91, -89, -87, -86, -84, 
	-82, -81, -79, -77, -75, -73, -72, -70, -68, -66, 
	-64, -62, -60, -58, -56, -54, -52, -50, -48, -46, 
	-44, -42, -40, -37, -35, -33, -31, -29, -27, -24, 
	-22, -20, -18, -16, -13, -11, -9, -7, -4, -2, 
	-0, 2, 4, 7, 9, 11, 13, 16, 18, 20, 
	22, 24, 27, 29, 31, 33, 35, 37, 40, 42, 
	44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 
	64, 66, 68, 70, 72, 73, 75, 77, 79, 81, 
	82, 84, 86, 87, 89, 91, 92, 94, 95, 97, 
	98, 99, 101, 102, 104, 105, 106, 107, 109, 110, 
	111, 112, 113, 114, 115, 116, 117, 118, 119, 119, 
	120, 121, 122, 122, 123, 124, 124, 125, 125, 126, 
	126, 126, 127, 127, 127, 128, 128, 128, 128, 128
	};
#endif