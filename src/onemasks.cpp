#include "myutils.h"

uint32 g_OneMasks[16*3] =
	{
	0x00000001, // 00000000000000000000000000000001
	0x00000002, // 00000000000000000000000000000010
	0x00000003, // 00000000000000000000000000000011
	0x00000004, // 00000000000000000000000000000100
	0x00000008, // 00000000000000000000000000001000
	0x0000000c, // 00000000000000000000000000001100
	0x00000010, // 00000000000000000000000000010000
	0x00000020, // 00000000000000000000000000100000
	0x00000030, // 00000000000000000000000000110000
	0x00000040, // 00000000000000000000000001000000
	0x00000080, // 00000000000000000000000010000000
	0x000000c0, // 00000000000000000000000011000000
	0x00000100, // 00000000000000000000000100000000
	0x00000200, // 00000000000000000000001000000000
	0x00000300, // 00000000000000000000001100000000
	0x00000400, // 00000000000000000000010000000000
	0x00000800, // 00000000000000000000100000000000
	0x00000c00, // 00000000000000000000110000000000
	0x00001000, // 00000000000000000001000000000000
	0x00002000, // 00000000000000000010000000000000
	0x00003000, // 00000000000000000011000000000000
	0x00004000, // 00000000000000000100000000000000
	0x00008000, // 00000000000000001000000000000000
	0x0000c000, // 00000000000000001100000000000000
	0x00010000, // 00000000000000010000000000000000
	0x00020000, // 00000000000000100000000000000000
	0x00030000, // 00000000000000110000000000000000
	0x00040000, // 00000000000001000000000000000000
	0x00080000, // 00000000000010000000000000000000
	0x000c0000, // 00000000000011000000000000000000
	0x00100000, // 00000000000100000000000000000000
	0x00200000, // 00000000001000000000000000000000
	0x00300000, // 00000000001100000000000000000000
	0x00400000, // 00000000010000000000000000000000
	0x00800000, // 00000000100000000000000000000000
	0x00c00000, // 00000000110000000000000000000000
	0x01000000, // 00000001000000000000000000000000
	0x02000000, // 00000010000000000000000000000000
	0x03000000, // 00000011000000000000000000000000
	0x04000000, // 00000100000000000000000000000000
	0x08000000, // 00001000000000000000000000000000
	0x0c000000, // 00001100000000000000000000000000
	0x10000000, // 00010000000000000000000000000000
	0x20000000, // 00100000000000000000000000000000
	0x30000000, // 00110000000000000000000000000000
	0x40000000, // 01000000000000000000000000000000
	0x80000000, // 10000000000000000000000000000000
	0xc0000000, // 11000000000000000000000000000000
	};
