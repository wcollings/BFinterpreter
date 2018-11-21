#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#ifndef __LEXER__
#define __LEXER
int lex(std::ifstream& in)
{
	int num_open_brackets=0;
	std::vector<int> brackets_open;
	std::string line;
	int line_count=1;
	getline(in, line);
	while(in.good())
	{
		for(int pos=0; pos < line.size(); ++pos)
		{
			switch(line[pos])
			{
				case '+':
				case '-':
				case '.':
				case ',':
				case '<':
				case '>': break;
				case '[':
				{
					num_open_brackets++;
					brackets_open.push_back(pos);
				}
					break;
				case ']':
				{
					num_open_brackets--;
					brackets_open.pop_back();
				}
					break;
				default:
				{
					std::cerr <<"Error: invalid token \"" <<line[pos] <<"\" on line " <<line_count <<'\n';
					return false;
				}
			}
		}
		if (num_open_brackets !=0)
		{
			std::cerr <<"Error: bracket open/close mismatch: " <<num_open_brackets <<" left open at end of line " <<line_count <<'\n';
			return false;
		}
		num_open_brackets=0;
		brackets_open.clear();
		getline(in, line);
		line_count++;
	}
	return true;
}
#endif
