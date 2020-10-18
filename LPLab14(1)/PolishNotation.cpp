#include "PolishNotation.h"

namespace PN
{
	bool PolishNotation(int pos, LT::LexTable lt, IT::IdTable it)
	{
		std::stack<char> stack;
		std::string  result;

		std::map<char, int> operators = { {'(', 0 }, {')',0} ,{',', 1} , {'+', 2}, {'-', 2}, {'*', 3}, {'/', 3} };

		LT::Entry* it_in_table = &lt.table[pos];

		IT::IDTYPE idtype = IT::N;
		int seqLen = 0;

		while (it_in_table->lexema[0] != LEX_SEMICOLON)
		{
			char opr = NONE_OPERATOR;

			if (it_in_table->lexema[0] == LEX_OPERATOR)opr = it.table[it_in_table->idxTI].id[0];
			else if (it_in_table->lexema[0] == LEX_LEFTHESIS || it_in_table->lexema[0] == LEX_RIGHTHESIS ||
				it_in_table->lexema[0] == LEX_COMA)opr = it_in_table->lexema[0];

			std::map<char, int>::iterator map_it = operators.find(opr);

			if (map_it == operators.end() )
			{
				if (it_in_table->idxTI != LT_IT_NULLIDX)
				{
					if (it.table[it_in_table->idxTI].idtype != IT::L)
					{
						result += std::string(it.table[it_in_table->idxTI].id);
						result.push_back(SPACE);

					}
					else if (it.table[it_in_table->idxTI].iddatatype == IT::STR)
					{
						result += std::string((char*)it.table[it_in_table->idxTI].value.vstr.str);
						result.push_back(SPACE);
					}
					else if (it.table[it_in_table->idxTI].iddatatype == IT::INT)
					{
						result += std::to_string(it.table[it_in_table->idxTI].value.vint);
						result.push_back(SPACE);
					}

					if (it.table[it_in_table->idxTI].idtype == IT::F)
					{
						idtype = IT::F;
						seqLen++;
					}
				}

			}
			else if (opr == LEX_LEFTHESIS)
			{
				 stack.push(opr);
			}
			else if (opr == LEX_RIGHTHESIS)
			{
				
				while (!stack.empty() && stack.top() != LEX_LEFTHESIS)
				{
					result.push_back(stack.top());
					result.push_back(SPACE);
					stack.pop();
				}
				if(!stack.empty())stack.pop();

				if (idtype == IT::F)
				{
					result.push_back(SEQ);
					result += std::to_string(seqLen);
					result.push_back(SPACE);
					seqLen = 0;
				}
				
			}
			else if (opr == LEX_COMA)
			{
				while (!stack.empty() && operators[stack.top()] >= operators[opr])
				{
					result.push_back(stack.top());
					result.push_back(SPACE);
					stack.pop();
				}

				seqLen++;
			}
			else if ((stack.empty() || stack.top() == LEX_LEFTHESIS) && opr != LEX_COMA)
			{
				stack.push(opr);
			}
			else
			{
				while (!stack.empty() && operators[stack.top()] >= operators[opr])
				{
					result.push_back(stack.top());
					result.push_back(SPACE);
					stack.pop();
				}
				stack.push(opr);

			}

			it_in_table++;

		}


		while (!stack.empty())
		{
			result.push_back(stack.top());
			stack.pop();
		}

		std::cout << result << std::endl;
		return true;
	}
 }