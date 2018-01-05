#include <iostream>
using std::cout; using std::endl; using std::cin; using std::fixed;
#include <iomanip>
#include <cmath>
using std::setprecision;

double fn(double x) {
     double function;
     function = -6*pow(x,2) + 5*(x) + 3;
     return function;
}

double integral(double x) {
    double function2;
    function2 = -2*pow(x,3) +(5.0/2.0)*pow(x,2) + 3*(x);
    return function2;
}
double trapezoid(double a, double b, long n) {
    //double traparea;
    double interval;
  
    double area=0.0;
  
    interval = (b-a)/(n);
   
    double x=a;
    double y=a+interval;
  
    while(y <= b)
    {
        area += (fn(x)+fn(y))*(interval/2.0);
        x=y;
        y+=interval;
       
    }
    return area;
       
}

int main() {
    long n;
    double exact;
    float tolerance;
    double a=0.0;
    double b=1.0;
    double area;
    float diff=10.0;
    a = 0;
    b = 1;
    exact = integral(1);
   
    cin >> tolerance;
    cin >> n;
    cout<< fixed << setprecision(6);
    //cout<<trapezoid(a, b , 16)<<endl;
   
    diff = (exact - trapezoid(a,b,n));
    //cout << n << " " <<
   
    while(diff >= tolerance) {
        n = n*2;
        area = trapezoid(a,b,n);
        //cout << area << endl;
        diff = exact - area;
        //cout << "difference" << " " << diff<<" "<<area<<" exact: "<<exact<< endl;
        //cout << diff<<" "<<area<<" "<<exact<< endl;
        //cout << "Result:" << area << endl;
        //if (diff == tolerance) {
          //  break;
        //}
    }
    cout<<n<<" "<<area<<" "<<exact<<" "<<tolerance<<endl;

}


