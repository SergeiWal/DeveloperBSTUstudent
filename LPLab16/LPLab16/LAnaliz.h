#pragma once

#include <vector>

#include "stdafx.h"
#include "FST.h"
#include "IT.h"
#include "LT.h"

#define GLOBAL_REGION '$'
#define MAIN_REGION '@'

#define SPACE ' '
#define STAR '*'
#define DEL '/'
#define ADD '+'
#define MIN '-'
#define KV '\''
#define DELIMITOR '|'
#define EQUEL '='

#define STR_LT_2	FST::RELATION('à', 1), FST::RELATION('á', 1), FST::RELATION('â', 1), FST::RELATION('ã', 1),\
					FST::RELATION('ä', 1), FST::RELATION('å', 1), FST::RELATION('¸', 1), FST::RELATION('æ', 1), FST::RELATION('ç', 1), FST::RELATION('è', 1), FST::RELATION('é', 1), FST::RELATION('ê', 1), FST::RELATION('ë', 1), \
					FST::RELATION('ì', 1), FST::RELATION('í', 1), FST::RELATION('î', 1), FST::RELATION('ï', 1), FST::RELATION('ð', 1), FST::RELATION('ñ', 1), FST::RELATION('ò', 1), FST::RELATION('ó', 1), FST::RELATION('ô', 1), FST::RELATION('õ', 1), FST::RELATION('ö', 1), FST::RELATION('÷', 1), FST::RELATION('ø', 1), \
					FST::RELATION('ù', 1), FST::RELATION('Ú', 1), FST::RELATION('û', 1), FST::RELATION('ü', 1), FST::RELATION('ý', 1), FST::RELATION('þ', 1), FST::RELATION('ÿ', 1),\
					FST::RELATION('À', 1), FST::RELATION('Á', 1), FST::RELATION('Â', 1), FST::RELATION('Ã', 1), \
					FST::RELATION('Ä', 1), FST::RELATION('Å', 1), FST::RELATION('¨', 1), FST::RELATION('Æ', 1), FST::RELATION('Ç', 1), FST::RELATION('È', 1), FST::RELATION('É', 1), FST::RELATION('Ê', 1), FST::RELATION('Ë', 1), \
					FST::RELATION('Ì', 1), FST::RELATION('Í', 1), FST::RELATION('Î', 1), FST::RELATION('Ï', 1), FST::RELATION('Ð', 1), FST::RELATION('Ñ', 1), FST::RELATION('Ò', 1), FST::RELATION('Ó', 1), FST::RELATION('Ô', 1), FST::RELATION('Õ', 1), FST::RELATION('Ö', 1), FST::RELATION('×', 1), FST::RELATION('Ø', 1), \
					FST::RELATION('Ù', 1), FST::RELATION('Ú', 1), FST::RELATION('Û', 1), FST::RELATION('Ü', 1), FST::RELATION('Ý', 1), FST::RELATION('Þ', 1), FST::RELATION('ß', 1) \

#define STR_LT_3    FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(':', 1), FST::RELATION(';', 1),\
					FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('+', 1), FST::RELATION('-', 1),\
					FST::RELATION('/', 1), FST::RELATION('*', 1), FST::RELATION('(', 1), FST::RELATION(')', 1), FST::RELATION('0', 1), \
					FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), \
					FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1),FST::RELATION(' ', 1), FST::RELATION('\'', 2)),\
					FST::NODE()

#define TYPE		11,\
					FST::NODE(2, FST::RELATION('i', 1), FST::RELATION('s', 2)),\
					FST::NODE(1, FST::RELATION('n', 2)),\
					FST::NODE(1, FST::RELATION('t', 3)),\
					FST::NODE(2, FST::RELATION('e', 4), FST::RELATION('r', 7)),\
					FST::NODE(1, FST::RELATION('g', 5)),\
					FST::NODE(1, FST::RELATION('e', 6)),\
					FST::NODE(1, FST::RELATION('r', 10)),\
					FST::NODE(1, FST::RELATION('i', 8)),\
					FST::NODE(1, FST::RELATION('n', 9)),\
					FST::NODE(1, FST::RELATION('g', 10)), FST::NODE()

#define IND			2, FST::NODE(52, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('c', 0), FST::RELATION('d', 0),\
					FST::RELATION('e', 0),  FST::RELATION('f', 0),  FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('i', 0), FST::RELATION('j', 0), FST::RELATION('k', 0), FST::RELATION('l', 0), FST::RELATION('m', 0),\
					FST::RELATION('n', 0),FST::RELATION('o', 0),FST::RELATION('p', 0),FST::RELATION('q', 0),FST::RELATION('r', 0), FST::RELATION('s', 0), FST::RELATION('t', 0), FST::RELATION('u', 0), FST::RELATION('v', 0), FST::RELATION('w', 0),\
					FST::RELATION('x', 0),FST::RELATION('y', 0),FST::RELATION('z', 0),\
					FST::RELATION('a', 1),FST::RELATION('b', 1),FST::RELATION('c', 1),FST::RELATION('d', 1),\
					FST::RELATION('e', 1),FST::RELATION('f', 1), FST::RELATION('g', 1),FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1),FST::RELATION('k', 1),FST::RELATION('l', 1),FST::RELATION('m', 1),\
					FST::RELATION('n', 1),FST::RELATION('o', 1),FST::RELATION('p', 1),FST::RELATION('q', 1),FST::RELATION('r', 1), FST::RELATION('s', 1),FST::RELATION('t', 1),FST::RELATION('u', 1),FST::RELATION('v', 1),FST::RELATION('w', 1),FST::RELATION('x', 1),FST::RELATION('y', 1),FST::RELATION('z', 1)),FST::NODE()
		   

#define FUNC		9,\
					FST::NODE(1, FST::RELATION('f', 1)),\
					FST::NODE(1, FST::RELATION('u', 2)),\
					FST::NODE(1, FST::RELATION('n', 3)),\
					FST::NODE(1, FST::RELATION('c', 4)),\
					FST::NODE(1, FST::RELATION('t', 5)),\
					FST::NODE(1, FST::RELATION('i', 6)),\
					FST::NODE(1, FST::RELATION('o', 7)),\
					FST::NODE(1, FST::RELATION('n', 8)),\
					FST::NODE()

#define DECLARE		8,\
					FST::NODE(1, FST::RELATION('d', 1)),\
					FST::NODE(1, FST::RELATION('e', 2)),\
					FST::NODE(1, FST::RELATION('c', 3)),\
					FST::NODE(1, FST::RELATION('l', 4)),\
					FST::NODE(1, FST::RELATION('a', 5)),\
					FST::NODE(1, FST::RELATION('r', 6)),\
					FST::NODE(1, FST::RELATION('e', 7)),\
					FST::NODE()

#define MAIN		5,\
					FST::NODE(1, FST::RELATION('m', 1)),\
					FST::NODE(1, FST::RELATION('a', 2)),\
					FST::NODE(1, FST::RELATION('i', 3)),\
					FST::NODE(1, FST::RELATION('n', 4)),\
					FST::NODE()	

#define PRINT		6,\
					FST::NODE(1, FST::RELATION('p', 1)),\
					FST::NODE(1, FST::RELATION('r', 2)),\
					FST::NODE(1, FST::RELATION('i', 3)),\
					FST::NODE(1, FST::RELATION('n', 4)),\
					FST::NODE(1, FST::RELATION('t', 5)),\
					FST::NODE()

#define RET			7,\
					FST::NODE(1, FST::RELATION('r', 1)),\
					FST::NODE(1, FST::RELATION('e', 2)),\
					FST::NODE(1, FST::RELATION('t', 3)),\
					FST::NODE(1, FST::RELATION('u', 4)),\
					FST::NODE(1, FST::RELATION('r', 5)),\
					FST::NODE(1, FST::RELATION('n', 6)),\
					FST::NODE()

#define OPERATOR	2,\
					FST::NODE(5, FST::RELATION('+', 1),FST::RELATION('/', 1),FST::RELATION('-', 1),FST::RELATION('*', 1), FST::RELATION('=', 1)),\
					FST::NODE()

#define INT_LT		2,\
					FST::NODE(20, FST::RELATION('0', 0),FST::RELATION('1', 0),FST::RELATION('2', 0),FST::RELATION('3', 0),FST::RELATION('4', 0), FST::RELATION('5', 0),\
					FST::RELATION('6', 0), FST::RELATION('7', 0),FST::RELATION('8', 0), FST::RELATION('9', 0),\
					FST::RELATION('0', 1),FST::RELATION('1', 1),FST::RELATION('2', 1),FST::RELATION('3', 1),FST::RELATION('4', 1), FST::RELATION('5', 1),\
					FST::RELATION('6', 1), FST::RELATION('7', 1),FST::RELATION('8', 1), FST::RELATION('9', 1)),\
					FST::NODE()

#define STR_LT_1    3,\
					FST::NODE(1, FST::RELATION('\'', 1)),\
					FST::NODE(142, FST::RELATION('a', 1),FST::RELATION('b', 1),FST::RELATION('c', 1),FST::RELATION('d', 1),\
					FST::RELATION('e', 1),FST::RELATION('f', 1), FST::RELATION('g', 1),FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1),FST::RELATION('k', 1),FST::RELATION('l', 1),FST::RELATION('m', 1),\
					FST::RELATION('n', 1),FST::RELATION('o', 1),FST::RELATION('p', 1),FST::RELATION('q', 1),FST::RELATION('r', 1), FST::RELATION('s', 1),FST::RELATION('t', 1),FST::RELATION('u', 1),FST::RELATION('v', 1),FST::RELATION('w', 1),FST::RELATION('x', 1),FST::RELATION('y', 1),FST::RELATION('z', 1),\
					FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), \
					FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1), FST::RELATION('M', 1), \
					FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1), FST::RELATION('Y', 1), FST::RELATION('Z', 1)					
					

namespace LA
{
	enum lexType { I = 1, L = 2, F = 3, D = 4, V = 5, T = 6, R = 7, P = 8, M = 9, S = 0 };
	enum visibilityType { MN = 3, FN = 6, GL = 9 };

	struct word
	{
		std::vector<unsigned char> value;
		bool isStrLT = false;
		int line;
	};

	struct wordArray
	{
		std::vector<word> Array;
		void addNewWord(word wd);
	};

	struct visibility
	{	
		char region[ID_MAXSIZE];
		char prevRegion[ID_MAXSIZE];
		int ln;
		int prevLn;
		visibilityType type;
		visibilityType prevType;
	};

	void LAnalyzis(wordArray* words, IT::IdTable& it, LT::LexTable& lt);
	lexType analiz(word* wrd);
	wordArray* wordHighliter(unsigned char* text, int len);
	void lexTableOut(LT::LexTable lt);
	void idTableOut(IT::IdTable it);
	void ltTableOut(IT::IdTable it);
};