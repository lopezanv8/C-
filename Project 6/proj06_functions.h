#ifndef PROJ06_AUTOMATA
#define PROJ06_AUTOMATA

#include<string>
using std::string;
#include<vector>
using std::vector;


string to_binary(int val);
//const string &s
int next_val (const vector<int> &v, const string &binary_rule_string);


vector<int> one_iteration(const vector<int> &v, const string &s);

string vector_to_string(const vector<int> &v);

void read_vector(vector<int> &v, string file_str);

string pretty_print(vector<int> & v);

#endif
