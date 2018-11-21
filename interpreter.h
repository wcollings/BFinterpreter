#ifndef __INTERPRETER_H_
#define __INTERPRETER_H_
#include <string>
#include "parser.h"

void interpret_from_file(parser);
void interpret_from_input();
void eval_string(std::string);
struct state{
	int tape[1000]={0};
	int ptr=500;
}s;
#endif
