#include<string>
using std::string;
#include<vector>
using std::vector;
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include "lab07_functions.h"
int main()
{
    matrix a= {{1,2,3},{4,5,6},{7,8,9}};
    matrix b= {{7,8,9},{1,2,3},{5,6,7}};
    long user_input;
    cin >> user_input;
    cout << same_size(a,b) << endl;
    matrix x = add(a,b);
    cout << matrix_to_str(x,3) << endl;
    matrix y = scalar_multiply(a,user_input);
    cout << matrix_to_str(y,3) << endl;
}
