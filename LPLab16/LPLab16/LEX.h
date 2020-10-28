#pragma once

#include "LAnaliz.h"
#include "Error.h"
#include "IT.h"
#include "LT.h"

namespace LEX
{
	struct LEX
	{
		LT::LexTable lextable;
		IT::IdTable idtable;
	};
};