#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

#ifndef __PARSE_H_
#define __PARSE_H_

int max(int a, int b);
int min(int, int);
struct location{
	int open, close, line_number;
};

class parser{
	std::vector<struct location > brackets;
	int size_of_tape;
	int start_point;
	std::vector<std::string> contents;
	public:
	parser();
	void parse(std::ifstream&);
	int get_size();
	int get_num_brackets();
	std::string get_line_number(int);
	int get_num_lines();
	int get_start_point();
	struct location get_bracket_info(int);
} p;

#endif
