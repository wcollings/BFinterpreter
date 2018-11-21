#include "interpreter.h"

void interpret_from_file(parser p)
{
	std::string line;
	for (int i=0; i < p.get_num_lines(); ++i)
	{
		line=p.get_line_number(i);
		eval_string(line);
		evaluate(line);
	}
}

void interpret_from_input()
{
	std::string loop_body;
	bool loop_open=false;
	char input;
	cin >>input;
	while(input != 'q')
	{
		cin >>input;
		switch(input)
		{
			case '+': s.tape[s.ptr]++;
				break;
			case '-': s.tape[s.ptr]--;
				break;
			case '>': s.ptr++;
				break;
			case '<': s.ptr--;
				break;
			case '[': loop_open=true;
				break;
			case ']':
			{
				loop_open=false;
				eval_loop(loop_body);
			}
		}
	}
}

void eval_string(std::string line)
{
	bool inside_bracket=false;
	static int bracket_number=0;
	for (int j=0; j < line.size(); ++j)
	{
		switch(line[j])
		{
			case '+': s.tape[s.ptr]++;
				break;
			case '-': s.tape[s.ptr]--;
				break;
			case '>': s.ptr++;
				break;
			case '<': s.ptr--;
				break;
			case '.': std::cout <<s.tape[s.ptr] <<' ';
				break;
			case ',': std::cin >>s.tape[s.ptr];
				break;
			case '[':
			{
				if (s.tape[s.ptr] == 0)
				{
					s.ptr=p.get_bracket_info(bracket_number++).close+1;
				}
			}
				break;
			case ']': s.ptr=p.get_bracket_info(bracket_number).open;
				break;
		}
	}
}
