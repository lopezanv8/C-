#include<string>
using std::string;
#include<cmath>
#include<sstream>
using std::ostringstream;

#include "lab09_vector.h"
 
MathVector::MathVector(long a, long b)
{
    x= a;
    y= b;
}
 
MathVector MathVector::add (const MathVector& v2)
{
    MathVector v1;
    v1.x= v2.x + x;
    v1.y= v2.y + y;
    return v1;
}

MathVector MathVector::mult(long s)
{
    MathVector multiVector;
    multiVector.x= x*s;
    multiVector.y= y*s;
    return multiVector;
}

long MathVector::mult(const MathVector& v)
{
    long dot_product;
    dot_product= (x*v.x+ y*v.y);
    return dot_product;
}

double MathVector::magnitude()
{
    double magni;
    magni = sqrt(pow(x,2)+pow(y,2));
    return magni;
}
string vec_to_str(const MathVector& v1)
{
    ostringstream oss;
    oss<<v1.x<<":"<<v1.y;
    return oss.str();
    
}
