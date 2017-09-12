#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>

int main() {
    cout << fixed << setprecision(2) << endl;

    double d1;

    double d2;

    double d3;
    
    double d4;

    //cout << "a real value of the first complex number: ";
    cin >> d1;
    //cout << "a imaginary value of the first complex number: ";
    cin >> d2;
    //cout << "a real value of the second  complex number: ";
    cin >> d3;
    //cout << "a imaginary value of the second complex number: ";
    cin >> d4;

    double Sum = (d1+d3);
    double Sum2 = (d2 + d4);
    double Diff = (d1 - d3);
    double Diff2 = (d2 - d4);
    double Prod = ((d1*d3)-(d2*d4));
    double Prod2 = ((d1*d4)+(d2*d3));
    double Quot = (((d1*d3)+(d2*d4))/((pow(d3,2))+(pow(d4,2))));
    double Quot2 = (((d2*d3)-(d1*d4))/((pow(d3,2))+(pow(d4,2))));
    
    
    cout << Sum << " + " << Sum2 << 'i' <<endl;
    cout << Diff << " + " << Diff2 << 'i' <<endl;
    cout << Prod << " + " << Prod2 << 'i' <<endl;
    cout << Quot << " + " << Quot2 << 'i' <<endl;
    
    
    
    return 0;
    
    
    
}