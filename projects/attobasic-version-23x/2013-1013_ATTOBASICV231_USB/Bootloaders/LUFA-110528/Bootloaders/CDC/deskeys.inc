//==============================================================================
// File:           deskeys.inc
// Compiler:       IAR Atmel AVR C/EC++ Compiler
// Output Size:    288
// Created:        03/25/11
//
// Description:    This file is generated by 'create' tool and is to be included
//                 in the 'bootldr' project. It contains a DES key table for
//                 a proper decryption of the file encrypted using the same
//                 configurations.
//
// Keys used:      KEY1 = CE987F2C688C9162
//                 KEY2 = C1DCD04F3DE67654
//                 KEY3 = 8349F42C3D98DC38
//==============================================================================

#include <avr/pgmspace.h>

PROGMEM unsigned char kTable[48 * 6] = 
{
	0xc3, 0xf0, 0xcd, 0x89, 0xd4, 0x34,
	0x2b, 0xa9, 0xb8, 0xdc, 0x16, 0x38,
	0x7f, 0x48, 0x07, 0xc0, 0xde, 0x0a,
	0x26, 0x85, 0xdf, 0xe8, 0xc1, 0x68,
	0x5d, 0xf1, 0x1a, 0x4e, 0x75, 0x40,
	0x7a, 0xce, 0xd1, 0x0e, 0xc5, 0x0b,
	0xe7, 0x35, 0xc2, 0x7a, 0x85, 0xc3,
	0x25, 0xfe, 0x3b, 0x26, 0xa6, 0xc5,
	0xfb, 0x42, 0x76, 0x75, 0x21, 0x89,
	0x96, 0x94, 0xe3, 0x52, 0x23, 0x96,
	0x75, 0xb3, 0xb4, 0xb2, 0x0b, 0x05,
	0xc1, 0x4e, 0x97, 0x93, 0x23, 0xa1,
	0xb1, 0xa5, 0x65, 0x83, 0x52, 0x95,
	0x70, 0x79, 0xab, 0x98, 0x48, 0x9d,
	0x19, 0xcf, 0xc6, 0x49, 0x4e, 0xa4,
	0x9c, 0x24, 0xbf, 0x99, 0x5a, 0x68,

	0xd4, 0xd6, 0x5b, 0x1b, 0x12, 0x5f,
	0xfc, 0x4b, 0xf2, 0xf8, 0x07, 0x66,
	0xb6, 0xf3, 0x39, 0x1c, 0xea, 0x8e,
	0x8f, 0x17, 0x57, 0x74, 0x74, 0xd1,
	0x6f, 0x5a, 0xdd, 0xab, 0xa0, 0x6b,
	0x1f, 0xf1, 0xe8, 0xa6, 0xff, 0x02,
	0x9a, 0x4d, 0xfb, 0x3c, 0x07, 0x76,
	0xfd, 0x6b, 0x0d, 0xdd, 0xc8, 0xc2,
	0x3f, 0x3d, 0xae, 0x41, 0xab, 0xec,
	0xfa, 0x24, 0xcd, 0xf0, 0x9c, 0x99,
	0x59, 0xce, 0x3c, 0x4b, 0x16, 0x3f,
	0xc4, 0xb9, 0xbe, 0x1f, 0x79, 0xa8,
	0xb6, 0xae, 0x67, 0x20, 0x59, 0x75,
	0xeb, 0x7e, 0x22, 0xc3, 0xa8, 0xb6,
	0xe8, 0xb7, 0xfc, 0xe5, 0x0f, 0x99,
	0xa3, 0xd4, 0xf6, 0xb7, 0xb6, 0x00,

	0xc2, 0x22, 0xf5, 0xcc, 0x9e, 0x9e,
	0x42, 0xb9, 0x4a, 0x57, 0xd5, 0x58,
	0x7c, 0xde, 0x04, 0x5e, 0xca, 0x5b,
	0xc2, 0x26, 0xda, 0xec, 0x0f, 0xe3,
	0x9d, 0xbc, 0x28, 0xa6, 0xb5, 0xa6,
	0x6a, 0x2a, 0xb1, 0x22, 0xf1, 0x4f,
	0x87, 0x0d, 0x0e, 0x7f, 0x60, 0xc9,
	0x2c, 0xe0, 0x3d, 0x5d, 0x26, 0x97,
	0x43, 0x6a, 0xf1, 0x97, 0x31, 0xcc,
	0x95, 0x1d, 0x41, 0x57, 0x42, 0x1f,
	0x20, 0x73, 0xbd, 0xf9, 0x4a, 0x93,
	0x89, 0x4b, 0x4a, 0xa9, 0x2f, 0xb4,
	0xba, 0xd0, 0x65, 0x82, 0xfd, 0x34,
	0x46, 0x13, 0xea, 0x1b, 0xd8, 0x69,
	0x9d, 0xd6, 0x14, 0x5d, 0x56, 0xf9,
	0x28, 0xe4, 0x77, 0x89, 0xb5, 0x68
};