#pragma once
#include <fstream>

#define DELIMITOR '|'
#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'
#define STRING_ENDL '\0'
#define SPACE ' '
#define IN_CODE_TABLE {\
/* 0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  A  |  B  |  C  |  D  |  E  |  F  |    */\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::S,  '|',IN::F,IN::F,IN::F,IN::F,IN::F, /*0*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*1*/\
 IN::S,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::K,IN::Z,IN::Z,IN::Z,IN::Z,IN::Z,IN::Z,IN::F,IN::Z, /*2*/\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::F,IN::Z,IN::Z,IN::Z,IN::Z,IN::F, /*3*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*4*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*5*/\
 IN::F,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T, /*6*/\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::Z,IN::F,IN::Z,IN::F,IN::F, /*7*/\
     																								   \
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*8*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*9*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*A*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::T,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*B*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*C*/\
 IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F,IN::F, /*D*/\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T, /*E*/\
 IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T,IN::T, /*F*/\
}


namespace In
{
	struct flags
	{
		//флаги для рассмотрения разнообразных частных случаев
		bool spaceMore = true;
		bool specSymbol = false;
		bool string = false;
		bool end = false;

		void spaceReshaffl();
		void specSymbolReshaffl();
		void stringReshaffl();
		void endReshaffl();
	};

	struct IN
	{
		enum { T = 1024, F = 2048, I = 4096 , S = 3072, Z = 6144, K = 7168};
		int size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;

	};

	IN getin(wchar_t infile[]);
	void inTextOut(wchar_t infile[], unsigned char* text);
};
