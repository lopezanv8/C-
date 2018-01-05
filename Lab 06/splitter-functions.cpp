#include <iostream>
#include<string>
#include<vector>
#include <iterator>

using std::cout;using std::endl;using std::cin;
using std::vector;
using std::string;
using std::ostream;
using std::ostream_iterator; 

#include "splitter-functions.h"

vector<string> split (const string &s, char separator) {
	vector<string> result = {};
	string s_copy = s;
	while (s_copy.size() != 0) {
		//cout << s_copy << endl;
		string term = s_copy.substr(0, s_copy.find_first_of(separator));
		//cout << "term: " << term << endl;
		result.push_back(term);
		//cout << s_copy << endl;
		s_copy.erase(0, (term.size()+1));
		//cout << s_copy << endl;
	}
	return result;
	
}

void print_vector (ostream &out, const vector<string> &v) {
	copy(v.begin(), v.end(), ostream_iterator<string> (out, "\n"));

}

