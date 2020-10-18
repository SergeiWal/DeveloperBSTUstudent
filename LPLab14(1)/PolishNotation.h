#pragma once

#include "LAnaliz.h"
#include <stack>
#include <map>
#include <string>

#define NONE_OPERATOR 0xfff;
#define SEQ '@'

namespace PN
{
	bool PolishNotation(int pos, LT::LexTable lt, IT::IdTable it);
}