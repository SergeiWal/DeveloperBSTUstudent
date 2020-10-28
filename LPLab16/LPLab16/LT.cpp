#include "LT.h"
#include "Error.h"


namespace LT
{
	Entry::Entry(){}

	Entry::Entry(char* plex, int nline)
	{
		lexema[0] = plex[0];
		lexema[1] = '\0';
		sn = nline;
	}

	LexTable Create(int size)
	{
		LexTable* lt = new LexTable;
		if (size > LT_MAXSIZE)throw ERROR_THROW(117);
		lt->maxsize = size;
		lt->size = 0;
		lt->table = new Entry[size];
		return *lt;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size == lextable.maxsize)throw ERROR_THROW(118);
		lextable.table[lextable.size] = entry;
		lextable.size++;
	}
	Entry GetAntry(LexTable& lextable, int n)
	{
		if (n >= lextable.size)throw ERROR_THROW(119);
		return lextable.table[n];
	}

	void Delete(LexTable& lextable)
	{
		delete[] &lextable;
	}
}