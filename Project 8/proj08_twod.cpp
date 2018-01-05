#include<string>
using std::string;
#include <iostream>     
#include <iomanip>
#include <sstream>
using std::ostringstream;

#include "proj08_twod.h"
/*
Project 08
Project focuses on the use of structs and struct methods

Ana Lopez 
Section 11
11/1/17
*/

/*
constructor with x and y values stored in struct.
*/
TwoD::TwoD(double xval, double yval) {
    x=xval;
    y=yval;
}

/*
return the struct in the format of a string
*/
string TwoD::to_string() {
    ostringstream oss;
    oss << std::fixed << std::setprecision(2) <<"(" << this->x <<", "
    << this->y << ")"; //when using this it points to x and y. 
    return oss.str();
}

/*
Finds the difference between the two vectors
*/
TwoD TwoD::diff(TwoD v) {
    TwoD result;
    result.x = this->x - v.x;
    result.y = this->y - v.y;
    //when using this it points to x and y. 
    //v.x and v.y takes the x and y value from v
    return result;
}

/*
Multiplies the elements of a TwoD struct. 
*/
TwoD TwoD::mult(double s) { 
    //s provides the elements to multiply
    TwoD mult_elements;
    mult_elements.x = x*s;
    mult_elements.y = y*s;
    //mult_elements.x and mult_elements.y gets the values x and y when 
    //multiplying the elementsf from s to x and y. 
    return mult_elements;
}

/*
takes the dot product for two TwoDs. 
*/
double TwoD::dot_product(TwoD d) {
    //d provides the elements to do dot product
    double d_dot;
    d_dot = (x*d.x+ y*d.y);
    //multiplies x by the x from d and multiplies y by the y from d. 
    return d_dot;
}

/*
takes y and x coordinates and squares them
*/
double TwoD::magnitude_squared() {
    double magni;
    magni = (this->x * this->x) + (this->y * this->y);
    //squares value of x and value of y
    return magni;
}
