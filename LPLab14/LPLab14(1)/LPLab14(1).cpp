#include <tchar.h>
#include "stdafx.h"
#include "LAnaliz.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "ru");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Логический анализатор: ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		In::inTextOut(parm.out, in.text);
		Log::WriteIn(log, in);
		LA::wordArray* wA = LA::reading(in.text, in.size);
		LT::LexTable lexTable = LT::Create(wA->Array.size());
		IT::IdTable idTable = IT::Create(wA->Array.size());
		LA::LAnalyzis(wA, idTable, lexTable);
		LA::lexTableOut(lexTable);
		LA::idTableOut(idTable);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	return 0;
}

