_message1:
	.DB  0x52,0x4F,0x4C,0x4C,0x55,0x49,0x4B,0x4D
	.DB  0x4F,0x44,0x55,0x4C,0x45,0x0
_message2:
	.DB  0x58,0x46,0x20,0x31,0x36,0x0
_message3:
	.DB  0x76,0x65,0x72,0x73,0x69,0x6F,0x6E,0x20
	.DB  0x33,0x2E,0x37,0x63,0x0
_error_message:
	.DB  0x20,0x49,0x6E,0x74,0x65,0x72,0x6E,0x61
	.DB  0x6C,0x20,0x45,0x72,0x72,0x6F,0x72,0x0
	.DEF _reversetimer=R4
	.DEF _aux=R5
	.DEF _nr=R6
	.DEF _k=R7
	.DEF _x=R8
	.DEF _y=R9
	.DEF _z=R10
	.DEF _output_changed=R11
	.DEF _lcd_attached=R12
	.DEF _timerruns_to_go=R13
_117:
	.DB  0x80,0xC0

__GLOBAL_INI_TBL:
	.DW  0x02
	.DW  __base_y_G2
	.DW  _117*2

	.DW  0