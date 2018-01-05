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
#include <iostream>
using std::cin; using std::cout; using std::endl;
// any other includes you need

//#include "proj06_functions.h"

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
            //remainders.push_back(remain);
            
            s[index] = '0' || '1';
            index--;
        }
    }
    return s;
}

int main(){
    int val;
    cin >> val;
    string binary;
    binary = to_binary(val);
    cout << binary << endl;

}

    
    if (rule = 7) {
        v[0] == 1 && v[1] == 1 && v[2] == 1;
        return s[0] - '0';
    }
    else if (rule = 6) {
        v[0] == 1 && v[1] == 1 && v[2] == 0;
        return s[0] - '0';
    }
    else if (rule = 5) {
        v[0] == 1 && v[1] == 0 && v[2] == 1;
        return s[0] - '0';
    }
    else if (rule = 4) {
        v[0] == 1 && v[1] == 0 && v[2] == 0;
        return s[0] - '1';
    }
    else if (rule = 3) {
        v[0] == 0 && v[1] == 1 && v[2] == 1;
        return s[0] - '1';
    }
    else if (rule = 2) {
        v[0] == 0 && v[1] == 1 && v[2] == 0;
        return s[0] - '1';
    }
    else if (rule = 1) {
        v[0] == 0 && v[1] == 0 && v[2] == 1;
        return s[0] - '1';
    }
    else if (rule = 0) {
        v[0] == 0 && v[1] == 0 && v[2] == 0;
        return s[0] - '0';
    }