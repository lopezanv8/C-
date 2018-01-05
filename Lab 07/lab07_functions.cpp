#include<string>
using std::string;
#include<vector>
using std::vector;
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <iomanip>
using std::setw;
#include <sstream>
using std::ostringstream;
#include "lab07_functions.h"
string matrix_to_str(const matrix &m1, size_t width) {
    ostringstream res;
    for (unsigned int i = 0; i < m1.size(); i++) {
        matrix_row r = m1[i];
        for(unsigned int j = 0; j < r.size(); j++) {
            res << setw(width) << r[j];
        }
        res << '\n';
        //cout << "Current Res: " << res << endl;
    }
    string s = res.str();
    return s.substr(0,s.size()-1);
}
bool same_size(matrix &m1, matrix &m2) {
    if(m1.size() != m2.size()) {
        return false;
    }
    for(int i = 0; i < m1.size(); i++) {
        matrix_row r1 = m1[i];
        matrix_row r2 = m2[i];
        if (r1.size() != r2.size()) {
            return false;
        }
    }
    return true;
}
matrix add(matrix &m1, matrix &m2) {
    matrix res;
    if (same_size(m1, m2)) {
        for (int i = 0; i < m1.size(); i++) {
            matrix_row r1 = m1[i];
            matrix_row r2 = m2[i];
            matrix_row r;
            for (int j = 0; j < r1.size(); j++) {
                r.push_back(r1[j] + r2[j]);
            }
            res.push_back(r);
        }
    }
    return res;
}

matrix scalar_multiply(matrix &m, long val) {
    matrix res;
    for (int i = 0; i < m.size(); i++) {
        matrix_row r1 = m[i];
        matrix_row r;
        for (int j = 0; j < r1.size(); j++) {
            r.push_back(val*r1[j]);
        }
        res.push_back(r);
    }
    return res;
}
