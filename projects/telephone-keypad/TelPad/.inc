	.DEF _enter=R4
_3:
	.DB  0xD
_TelPad_LUT:
	.DB  0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38
	.DB  0x39,0x2A,0x30,0x23
_tbl10_G2:
	.DB  0x10,0x27,0xE8,0x3,0x64,0x0,0xA,0x0
	.DB  0x1,0x0
_tbl16_G2:
	.DB  0x0,0x10,0x0,0x1,0x10,0x0,0x1,0x0
_0:
	.DB  0x25,0x63,0x0,0x4B,0x65,0x79,0x20,0x50
	.DB  0x72,0x65,0x73,0x73,0x65,0x64,0x20,0x49
	.DB  0x73,0x3A,0x25,0x63,0x0,0x4E,0x6F,0x20
	.DB  0x6B,0x65,0x79,0x20,0x69,0x73,0x20,0x50
	.DB  0x72,0x65,0x73,0x73,0x65,0x64,0x0,0x49
	.DB  0x73,0x20,0x74,0x68,0x65,0x20,0x6B,0x65
	.DB  0x79,0x5B,0x25,0x64,0x5D,0x5B,0x25,0x64
	.DB  0x5D,0x20,0x70,0x72,0x65,0x73,0x73,0x65
	.DB  0x64,0x3F,0x28,0x59,0x2F,0x4E,0x29,0x0

__GLOBAL_INI_TBL:
	.DW  0x01
	.DW  0x04
	.DW  _3*2

	.DW  0