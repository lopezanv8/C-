#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<string>
using std::string;
#include <iomanip>
#include <sstream>
using std::ostringstream;
#include<algorithm>
using std::sort;

#include "proj10_package.h"

ostream& operator<<(ostream& out, Package &p) {
    out << p.weight_ << ":" << p.priority_;
    
    return out;
}

bool package_compare(const Package& lhs, const Package& rhs) {
    //int n = static_cast<int>(3.14); 
    
    double lhs1 = static_cast<double>(lhs.priority_)/static_cast<double>(lhs.weight_);
    double rhs2 = static_cast<double>(rhs.priority_)/static_cast<double>(rhs.weight_);
    if (lhs1 > rhs2) {
        return true;
    }
    else if (lhs.priority_/lhs.weight_ == rhs.priority_/rhs.weight_) {
        if (rhs2 > lhs1) 
            return false;
    }
    return false;
}








