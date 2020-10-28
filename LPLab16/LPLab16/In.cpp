#include "In.h"
#include "Error.h"

namespace In {

	IN getin(wchar_t infile[])
	{
		IN in;
		std::ifstream input;
		input.open(infile);
		if (!input.is_open())throw ERROR_THROW(110);

		in.lines = 0;
		in.size = 0;
		in.ignor = 0;

		in.text = new unsigned char[IN_MAX_LEN_TEXT];

		int position = 0;
		unsigned char symbol;
		char buf;

		flags flg;

		while (true)
		{ 
			input.get(buf);

			if (input.eof())
			{
				in.lines++;
				break;
			}

			symbol = (unsigned char)buf;

			
			switch (in.code[symbol])
			{
			case  IN::F:
				throw ERROR_THROW_IN(111, in.lines, position);
				break;
			case IN::I:
				in.ignor++;
				break;
			case IN::S:
				if (!flg.end && !flg.spaceMore && !flg.specSymbol)
				{
					in.text[in.size] = symbol;
					in.size++;
				}
				if(!flg.spaceMore)flg.spaceReshaffl();
				break;
			case IN::Z:
				if (flg.string)
				{
					in.text[in.size] = symbol;
					in.size++;
				}
				else
				{
					if(!flg.specSymbol)flg.specSymbolReshaffl();
					if (flg.end)flg.endReshaffl();

					if (in.text[in.size - 1] == SPACE)
					{
						in.text[in.size - 1] = symbol;
						flg.spaceReshaffl();
					}
					else 
					{
						in.text[in.size] = symbol;
						in.size++;
					}
				}
				break;
			case IN::K:
				flg.stringReshaffl();
				in.text[in.size] = symbol;
				in.size++;
				break;
			case IN::T:
				if(flg.spaceMore)flg.spaceReshaffl();
				if (flg.specSymbol)flg.specSymbolReshaffl();
				if (flg.end)flg.endReshaffl();

				in.text[in.size] = symbol;
				in.size++;
				break;
			default:
				if(in.text[in.size-1] == SPACE)in.text[in.size-1] = in.code[symbol];
				else if(!flg.end)
				{
					flg.endReshaffl();
					in.text[in.size] = in.code[symbol];
					in.size++;
				}

				
				in.lines++;

				break;
			}
			position++;
		}
		in.text[in.size-1] = STRING_ENDL;
		
		input.close();
		return in;
	}

	void inTextOut(wchar_t infile[], unsigned char* text)
	{
		std::ofstream out;
		out.open(infile);
		if (!out.is_open())throw ERROR_THROW(110);
		out << text;
		out.close();
	}



	void flags::spaceReshaffl()
	{
		if (this->spaceMore)this->spaceMore = false;
		else this->spaceMore = true;
	}
	void flags::specSymbolReshaffl()
	{
		if (this->specSymbol)this->specSymbol = false;
		else this->specSymbol = true;
	}
	void flags::stringReshaffl()
	{
		if (this->string)this->string = false;
		else this->string = true;
	}
	void flags::endReshaffl()
	{
		if (this->end)this->end = false;
		else this->end = true;
	}

};