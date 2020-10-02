#include "LAnaliz.h"

namespace LA
{
	void wordArray::addNewWord(word wd)
	{
		if (wd.value.size() != 0)
		{
			Array.push_back(wd);
			
		}
	}


	wordArray* wordHighliter(unsigned char* text, int len)
	{
		wordArray* wdArr = new wordArray;
		int wordArray_it = 0;

		int position = -1;
		int line = 0;

		unsigned char * beginWord = text;
		unsigned char* endWord = text;
		
		bool strLtFlag = false;

		for (int i = 0; i < len; ++i)
		{
			if ((text[i]== DELIMITOR || text[i] == SPACE || text[i] == LEX_SEMICOLON || text[i] == STAR || text[i] == ADD ||
				text[i] == DEL || text[i] == MIN || text[i]==KV || text[i]==LEX_COMA || text[i] == LEX_LEFTBRACE ||
				text[i] == LEX_RIGHTHESIS || text[i] == LEX_LEFTHESIS || text[i]  == LEX_BRACELET || text[i] == EQUEL) && !strLtFlag)
			{
				word* newWord = new word;
				endWord = &text[i];
				std::vector<unsigned char> vc(beginWord, endWord);
				newWord->value = vc;
				newWord->line = line;
				wdArr->addNewWord(*newWord);
				if (text[i] != SPACE && text[i] != DELIMITOR && text[i]!= KV)
				{
					word* nextWord = new word;
					std::vector<unsigned char> nvc(endWord, endWord+1);
					nextWord->value = nvc;
					nextWord->line = line;
					wdArr->addNewWord(*nextWord);
				}
				if (text[i] == DELIMITOR)line++;
				beginWord = endWord + 1;
				if (text[i] == KV)
				{
					strLtFlag = true;
					beginWord = endWord;
				}
			}
			else if (strLtFlag)
			{
				if (text[i] == KV)
				{
					word* newWord = new word;
					endWord = &text[i+1];
					std::vector<unsigned char> vc(beginWord, endWord);
					newWord->value = vc;
					newWord->line = line;
					newWord->isStrLT = true;
					beginWord = endWord;
					wdArr->addNewWord(*newWord);
					strLtFlag = false;
				}
			}
		}
		return wdArr;
	}

	lexType analiz(word* wrd)
	{
		unsigned char* word = new unsigned char[wrd->value.size()];
		word = &wrd->value[0];
		word[wrd->value.size()] = STRING_ENDL;

		FST::FST fst_type
		{
			word,
			TYPE
		};
		if (FST::execute(fst_type))return LA::T;

		FST::FST fst_func
		{
			word,
			FUNC
		};
		if (FST::execute(fst_func))return LA::F;

		FST::FST fst_declare
		{
			word,
			DECLARE
		};
		if (FST::execute(fst_declare))return LA::D;

		FST::FST fst_main
		{
			word,
			MAIN
		};
		if (FST::execute(fst_main))return LA::M;

		FST::FST fst_print
		{
			word,
			PRINT
		};
		if (FST::execute(fst_print))return LA::P;

		FST::FST fst_ret
		{
			word,
			RET
		};
		if (FST::execute(fst_ret))return LA::R;

		FST::FST fst_opr
		{
			word,
			OPERATOR
		};
		if (FST::execute(fst_opr))return LA::V;

		FST::FST fst_id
		{
			word,
			IND
		};
		if (FST::execute(fst_id))return LA::I;

		FST::FST fst_int_lt
		{
			word,
			INT_LT
		};
		if (FST::execute(fst_int_lt))return LA::L;

		FST::FST fst_str_lt
		{
			word,
			STR_LT_1,
			STR_LT_2,
			STR_LT_3
		};
		if (FST::execute(fst_str_lt))return LA::L;

		throw ERROR_THROW_IN(123, wrd->line, 0);
	}

	void LAnalyzis(wordArray* words, IT::IdTable& it, LT::LexTable& lt)
	{
		lexType lextype;

		visibility vsblRgn;
		vsblRgn.type = LA::GL;
		

		for (int i =0; i<words->Array.size(); ++i)
		{
			LT::Entry* ltNewEntry = new LT::Entry;
			ltNewEntry->sn = words->Array[i].line;
			ltNewEntry->idxTI = LT_IT_NULLIDX;

			IT::Entry* itNewEntry = new IT::Entry;


			if (words->Array[i].value.size() == 1 && (words->Array[i].value[0] == LEX_SEMICOLON || words->Array[i].value[0] == LEX_BRACELET ||
				words->Array[i].value[0] == LEX_COMA || words->Array[i].value[0] == LEX_LEFTBRACE || words->Array[i].value[0] == LEX_LEFTHESIS ||
				words->Array[i].value[0] == LEX_RIGHTHESIS || words->Array[i].value[0] == LEX_EQUALL))
			{
				ltNewEntry->lexema[0] = words->Array[i].value[0];
				ltNewEntry->lexema[1] = STR_END;
				if (words->Array[i].value[0] == LEX_BRACELET)vsblRgn.type = LA::GL;

				if (words->Array[i].value[0] == LEX_LEFTHESIS && lt.table[i + 1].lexema[0] != LEX_LEFTBRACE && vsblRgn.type == LA::FN &&
					(vsblRgn.prevType == LA::FN || vsblRgn.prevType == LA::MN))
				{
					vsblRgn.type = vsblRgn.prevType;
					if (vsblRgn.prevType == LA::FN)
					{
						for (int k = 0; k < vsblRgn.prevLn; ++k)vsblRgn.region[k] = vsblRgn.prevRegion[k];
						vsblRgn.ln = vsblRgn.prevLn;
					}

				}
			}
			else
			{
				lextype = analiz(&words->Array[i]);
				switch (lextype)
				{
				case LA::T:
					ltNewEntry->lexema[0] = LEX_TYPE;
					ltNewEntry->lexema[1] = STR_END;
					break;
				case LA::I:
					ltNewEntry->lexema[0] = LEX_ID;
					ltNewEntry->lexema[1] = STR_END;

					
					for (int j = 0; j < words->Array[i].value.size() && j < ID_MAXSIZE; ++j)
					{
						itNewEntry->id[j] = words->Array[i].value[j];
						if ((j + 1) == words->Array[i].value.size() || (j + 1) == ID_MAXSIZE)itNewEntry->id[j + 1] = STRING_ENDL;
					}
					
					
					switch (vsblRgn.type)
					{
					case LA::FN:
						for (int j = 0; j < ID_MAXSIZE; ++j)itNewEntry->visibilityRegion[j] = vsblRgn.region[j];
						itNewEntry->visibilityRegion[vsblRgn.ln] = STRING_ENDL;
						break;
					case LA::GL:
						itNewEntry->visibilityRegion[0] = GLOBAL_REGION;
						itNewEntry->visibilityRegion[1] = STRING_ENDL;
						break;
					case LA::MN:
						itNewEntry->visibilityRegion[0] = MAIN_REGION;
						itNewEntry->visibilityRegion[1] = STRING_ENDL;
						break;
					default:
						break;
					}
					
					
					if (words->Array[i + 1].value[0] == LEX_LEFTHESIS)
					{
						
						itNewEntry->idtype = IT::F;

						if (words->Array[i - 2].value[0] == LEX_ID)itNewEntry->iddatatype = IT::INT;
						else if (words->Array[i - 2].value[0] == 's')itNewEntry->iddatatype = IT::STR;

						vsblRgn.prevLn = 0;
						vsblRgn.prevType = vsblRgn.type;
						if (vsblRgn.prevType == LA::FN)for (int k = 0; k < vsblRgn.ln; ++k)
						{
							vsblRgn.prevRegion[k] = vsblRgn.region[k];
							vsblRgn.prevLn++;
						}

						vsblRgn.ln = 0;
						vsblRgn.type = LA::FN;
						for (int j = 0; j < words->Array[i].value.size() && j < ID_MAXSIZE; ++j)
						{
							vsblRgn.region[j] = words->Array[i].value[j];
							vsblRgn.ln++;
						}

					}
					else
					{
						if (lt.table[lt.size - 2].lexema[0] == LEX_DECLARE)itNewEntry->idtype = IT::V;
						else if (lt.table[lt.size - 2].lexema[0] == LEX_LEFTHESIS || lt.table[lt.size - 2].lexema[0] == LEX_COMA)itNewEntry->idtype = IT::P;

						if (words->Array[i - 1].value[0] == LEX_ID)itNewEntry->iddatatype = IT::INT;
						else if (words->Array[i - 1].value[0] == 's')itNewEntry->iddatatype = IT::STR;
					}
					
					if (itNewEntry->iddatatype == IT::INT)itNewEntry->value.vint = TI_INT_DEFAULT;
					else if (itNewEntry->iddatatype == IT::STR)
					{
						itNewEntry->value.vstr.len = TI_STR_DEFAULT;
						itNewEntry->value.vstr.str[0] = TI_STR_DEFAULT;
					}

					
					ltNewEntry->idxTI = IT::IsId(it, *itNewEntry);

					if (ltNewEntry->idxTI == TI_NULLIDX)
					{
						itNewEntry->idxfirstLE = lt.size;
						ltNewEntry->idxTI = it.size;
						IT::Add(it, *itNewEntry);
					}
					
					
					break;
				case LA::F:
					ltNewEntry->lexema[0] = LEX_FUNCTION;
					ltNewEntry->lexema[1] = STR_END;
					break;
				case LA::D:
					ltNewEntry->lexema[0] = LEX_DECLARE;
					ltNewEntry->lexema[1] = STR_END;
					break;
				case LA::L:
					ltNewEntry->lexema[0] = LEX_LITERAL;
					ltNewEntry->lexema[1] = STR_END;
					break;
				case LA::M:
					ltNewEntry->lexema[0] = LEX_MAIN;
					ltNewEntry->lexema[1] = STR_END;

					vsblRgn.prevType = vsblRgn.type;
					vsblRgn.type = LA::MN;

					break;
				case LA::P:
					ltNewEntry->lexema[0] = LEX_PRINT;
					ltNewEntry->lexema[1] = STR_END;
					break;
				case LA::R:
					ltNewEntry->lexema[0] = LEX_RETURN;
					ltNewEntry->lexema[1] = STR_END;
					break;
				case LA::V:
					ltNewEntry->lexema[0] = LEX_OPERATOR;
					ltNewEntry->lexema[1] = STR_END;
					break;
				default:
					break;
				}
			}

			LT::Add(lt, *ltNewEntry);
		}
	}

	void lexTableOut(LT::LexTable lt)
	{
		std::ofstream out;
		out.open("LexTable.txt");
		if (!out.is_open())throw ERROR_THROW(123);
		int line = 1;
		out << "001 ";
		for (int i = 0; i < lt.size; ++i)
		{
			if (lt.table[i].sn >= line)
			{
				out << "\n";
				line++;
				if (line < 10)out << "00";
				if (line < 100 && line>=10)out << "0";
					
				out << line << " ";
			}
			out << lt.table[i].lexema;
		}
		out.close();
	}

	void idTableOut(IT::IdTable it)
	{
		std::ofstream out;
		out.open("IdTable.txt");
		if (!out.is_open())throw ERROR_THROW(123);
		out << "\t" << "NAME" << "\t" << "DATATYPE" << "\t" << "TYPE" << "\t\t\t" << "REFERENCE" << "\t" << "VISIBILITY\n";
		for (int i = 0; i < it.size; ++i)
		{
			if (i < 10)out << "00";
			if (i < 100 && i >= 10)out << "0";
			out << i << "\t" << it.table[i].id << "\t";

			switch (it.table[i].iddatatype)
			{
			case IT::INT:
				out << "integer" << "\t\t";
				break;
			case IT::STR:
				out << "string" << "\t\t";
				break;
			default:
				break;
			}

			switch (it.table[i].idtype)
			{
			case IT::F:
				out << "function name" << "\t\t";
				break;
			case IT::V:
				out << "variable name" << "\t\t";
				break;
			case IT::P:
				out << "parameter" << "\t\t";
				break;
			default:
				break;
			}

			out << it.table[i].idxfirstLE << "\t\t";

			if (it.table[i].visibilityRegion[0] == GLOBAL_REGION)out << "global\n";
			else if (it.table[i].visibilityRegion[0] == MAIN_REGION)out << "main\n";
			else out << it.table[i].visibilityRegion << "\n";

		}
		out.close();
	}
}

