#include "parser.h"

parser::parser()
{
	start_point=0;
	size_of_tape=0;
}

void parser::parse(std::ifstream& in)
{
	int current_position=0, furthest_right=0, furthest_left=0;
	int current_line=1;
	std::string line;
	struct location temp;
	std::getline(in, line);
	while(in.good())
	{
		for (int i=0; i < line.size(); ++i)
		{
			switch(line[i])
			{
				case '>':{
					current_position++;
					furthest_right=max(current_position, furthest_right);
				}
					break;
				case '<':{
					current_position--;
					furthest_left=min(current_position, furthest_left);
				}
					break;
				case '[':{
					temp.open=i;
				}
					break;
				case ']':
				{
					temp.close=i;
					temp.line_number=current_line;
					brackets.push_back(temp);
				}
					break;
				default: break;
			}
		}
		current_line++;
		contents.push_back(line);
		std::getline(in, line);
	}
	start_point=(0-furthest_left);
	size_of_tape=furthest_right-furthest_left;
}

int parser::get_size()
{
	return size_of_tape;
}

int parser::get_num_brackets()
{
	return brackets.size();
}

std::string parser::get_line_number(int i)
{
	return contents[i];
}

int parser::get_num_lines()
{
	return contents.size();
}

int parser::get_start_point()
{
	return start_point;
}

struct location parser::get_bracket_info(int i)
{
	return brackets[i];
}
int max(int a, int b)
{
	return (a>b?a:b);
}

int min(int a, int b)
{
	return (a<b?a:b);
}
