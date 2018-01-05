
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);
    int days;
    double kMspeed = 14.24;
    double Mspeed = 8.85;
    cin >> days;
    int seconds = 86400;
    double MawayE = days * seconds * Mspeed;
    double MawayS = 3655951614 + MawayE;
    double KMawayE = days * seconds * kMspeed;
    double KMawayS = 5883689340 + KMawayE;
    double Radio = KMawayS / 1079252848.8;
    double radioTrip = Radio * 2;
    std::cout << KMawayS << std::endl;
    std::cout << MawayS << std::endl;
    std::cout << radioTrip << std::endl;
    
}
