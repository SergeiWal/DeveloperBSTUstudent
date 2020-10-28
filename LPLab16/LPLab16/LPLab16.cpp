#include <iostream>
#include <locale>
#include <tchar.h>
#include "MFST.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	char b = '\'';
	int s = 0;
	LEX::LEX lex;
	
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
		LA::wordArray* wA = LA::wordHighliter(in.text, in.size);
		lex.lextable = LT::Create(wA->Array.size());
		lex.idtable = IT::Create(wA->Array.size());
		LA::LAnalyzis(wA, lex.idtable, lex.lextable);
		LA::lexTableOut(lex.lextable);
		LA::idTableOut(lex.idtable);
		LA::ltTableOut(lex.idtable);
		MFST_TRACE_START
			MFST::Mfst mfst(lex, GRB::getGreibach());
		mfst.start();
		mfst.savededucation();
		mfst.printrules();
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	
	
	return 0;
}
   

