#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
// any other includes you need

#include "proj06_functions.h"

// your functions after this

string to_binary(int val) {
    string s(8, '0');
    //string bin_str;
    int remain;
    string remainders = " ";
    int index;
    if (val >= 0 && int val <= 255) {
        index = 7;
        while (val >= 0) {
            remain = val % 2;
            /*
            remainders.push_back(remain);
            
            */
            s[index] = '0' || '1'
            index--;
        }
    }
    return s;
}
/*
int next_val (const vector<int> &v, const string &s) {
    
}

vector<int> one_iteration(const vector<int> &v, const string &s) {
    
}

string vector_to_string(const vector<int> &v) {
    
}

void read_vector(vector<int> &v, string file_str) {
    
}*/

// a freebie!
// takes in a vector of 0,1
// outputs a string of '_' or '*'
string pretty_print(vector<int> & v){
  ostringstream oss;
  transform(v.begin(), v.end(), ostream_iterator<char>(oss),
	    [] (int i) {
	      return (i==0) ? '_' : '*';
	    }
	    );
    return oss.str();
}
