
_7:
	.DB  0x80,0xC0
	.DEF __lcd_x=R4
	.DEF __lcd_y=R5
	.DEF __lcd_maxx=R6
__fround_G3:
	.DB  0x48,0xE1,0xFA,0x3E,0xCD,0xCC,0x4C,0x3D
	.DB  0xA,0xD7,0xA3,0x3B,0x6F,0x12,0x3,0x3A
	.DB  0x17,0xB7,0x51,0x38,0xAC,0xC5,0xA7,0x36
_0:
	.DB  0x66,0x3D,0x25,0x35,0x2E,0x34,0x66,0x20
	.DB  0x0

__GLOBAL_INI_TBL:
	.DW  0x02
	.DW  __base_y_G2
	.DW  _7*2

	.DW  0
_0xC1: