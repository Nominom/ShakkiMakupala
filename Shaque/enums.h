#pragma once
#include <cstdint>

enum POSITION : uint_least8_t {
	A8 = 0, B8, C8, D8, E8, F8, G8, H8,
	A7, B7, C7, D7, E7, F7, G7, H7,
	A6, B6, C6, D6, E6, F6, G6, H6,
	A5, B5, C5, D5, E5, F5, G5, H5,
	A4, B4, C4, D4, E4, F4, G4, H4,
	A3, B3, C3, D3, E3, F3, G3, H3,
	A2, B2, C2, D2, E2, F2, G2, H2,
	A1, B1, C1, D1, E1, F1, G1, H1
};

enum PIECE : uint_least8_t
{
	WROOK = 0, WKNIGHT, WBISHOP, WQUEEN, WKING, WPAWN,
	BROOK, BKNIGHT, BBISHOP, BQUEEN, BKING, BPAWN,
	EMPTY
};

enum COLOR : bool {
	WHITE = false,
	BLACK = true
};

enum OUTCOME : int_least8_t {
	WIN_WHITE = 1,
	WIN_BLACK = -1,
	DRAW = 0
};

enum DIRECTION : uint_least16_t {
	UP =		0b000000001,
	DOWN =		0b000000010,
	LEFT =		0b000000100,
	RIGHT =		0b000001000,
	UPLEFT =	0b000010000,
	UPRIGHT =	0b000100000,
	DOWNLEFT =	0b001000000,
	DOWNRIGHT = 0b010000000,
	DIAGONAL =	0b011110000, // has the bits of diagonal basic movements set
	STRAIGHT =	0b000001111, // has the bits of straight basic movements set
	ANY =		0b011111111,
	KNIGHT =	0b100000000 // if KNIGHT direction is used in movegeneration, every other direction is ignored
};