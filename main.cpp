#include <iostream>
#include <fstream>
#include <string>

#include "parser.h"
#include "interpreter.h"
using namespace std;
int main()
{
	string file="bf";
	ifstream in;
	in.open(file);
	p.parse(in);
	cout <<"The parser found " <<p.get_num_brackets() <<" bracket pairs, and " <<p.get_size() <<" elements needed.\n";
	cout <<"Going to the interpreter now \n";
	interpret_from_file(p);
	cout <<"quitting.\n";
	return 0;

}
