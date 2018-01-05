#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<string>
using std::string;
#include <algorithm> 
#include <utility>
using std::swap;
using std::copy;
#include<sstream>
using std::ostringstream;
#include <fstream>
using std::ifstream; using std::ofstream;
using std::runtime_error;
#include<vector>
using std::vector;
#include<istream>
#include<iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "proj10_knapsack.h"
#include "proj10_package.h"

/*Project 10
Project focuses on the use of container class using dynamically allocated memory

Ana Lopez 
Section 11
11/29/17
*/


/* Knapsack constructor 
wlimit is the maximum weight the Knapsack can take
creates underlying array data_, by dynamically allocating memory
*/
Knapsack::Knapsack(size_t wlimit) {
    capacity_ = 10;
    size_ = 0;
    weight_limit_ = wlimit;
    data_ = new Package [capacity_];
}

/* Knapsack constructor 
wlimit is the maximum weight the Knapsack can take
cap is the capacity_
creates underlying array data_, by dynamically allocating memory
*/
Knapsack::Knapsack(size_t wlimit, size_t cap) {
    capacity_ = cap;
    size_ = 0;
    weight_limit_ = wlimit;
    data_ = new Package [capacity_];
}

/*copy constructor 
creates underlying array data_, by dynamically allocating memory
copies everything into the new data_
*/
Knapsack::Knapsack(const Knapsack& ks) {
    capacity_ = ks.capacity_;
    size_ = ks.size_;
    weight_limit_ = ks.weight_limit_;
    data_ = new Package[capacity_];
    std::copy(ks.data_, ks.data_ + size_, data_);
}
/*Knapsack deconstructor */
Knapsack::~Knapsack() {
    delete [] data_;
}

/* returns the present capacity_
the number of packages the array can hold before having to grow
*/
long Knapsack::capacity() const 
{
    return capacity_;
}

/* returns the present size
the number of packages in the array
*/
long Knapsack::size() const 
{
    return size_;
}

/* returns the present weight limit that is set fo the Knapsack
*/
long Knapsack::weight_limit() const 
{
    return weight_limit_; 
}

/* returns true if the knapsack is empty
false otherwise
*/
bool Knapsack::empty() const {
    if (size_ == 0) {
        return true;
    }
    else {
        return false; 
    }
    return false;
}

/* returns 0 if the Knapsack is empty
if not empty, sums the weight of the packages the knapsack holds
*/
long Knapsack::weight() const {
    long sum = 0;
    if (empty()) {
        sum = 0;
    }
    else {
        for (size_t i = 0; i < size_; i++) {
            sum += data_[i].weight_;
        }
    }
    //cout << "sum: " << sum << endl;
    return sum;
}

/* returns 0 if the Knapsack is empty
if not empty, sums the priorities of the packages the knapsack holds
*/
long Knapsack::priority() const {
    long sum = 0;
    if (empty()) {
        sum = 0;
    }
    else {
        for (size_t i = 0; i < size_; i++) {
            sum += data_[i].priority_;
        }
    }
    return sum;
}

/*if adding the package to the Knapsack exceeds the weight limit then doesnt add packages, and returns false.
if adding the package to the Knapsack does not exceeds the weight limit then add packages, and returns ture.
if can add the package and not exceed weight limit but does exceed size of data then dynamically allocate new data to hold everything 
*/
bool Knapsack::add(const Package& p) {
    if ((weight() + p.weight_) > weight_limit_) {
        return false;
    }
    
    else {
        if (size_ >= capacity_) {
            capacity_ *= 2; //double the capacity_ of data_
            Package *new_data; //create new data to dynamically allocate memory
            new_data = new Package[capacity_];
            std::copy(data_, data_ + size_, new_data); 
            std::swap(data_, new_data); //swap what each data holds. 
            delete [] new_data; //delete the new data created
        }
        data_[size_] = p; //adds the package into data
        size_++; //increments the size
        return true;
    }
} 
/* prints the underlying contents array and other elements of the class.
*/
ostream& operator<<(ostream &out, Knapsack &ks) {
    ostringstream oss;
    for (size_t i = 0; i < ks.size_; i++) {
        //how to get weight and priority from the Package
        oss << ks.data_[i].weight_ << ":" << ks.data_[i].priority_ <<  ", ";
    }
    string temp = oss.str();
    temp = temp.substr(0, temp.size() - 2 ); //takes off the extra comma and        space at end
    out << temp;

    return out;
}
/*opens file provided by fstring.
    if file doesnt not open, throws a run time runtime_error
reads each line, space seperated, by the 
    */
void solve_KS(string fstr, Knapsack& ks) {
    std::ifstream input_file(fstr); 
    long weight1 = 0;
    long priority1 = 0;
    vector<Package> d_vect; //creates a vector
    if (!input_file.is_open()) { //file isnt open
        throw runtime_error("runtime_error");
    }
    
    if (input_file.is_open()){ //file is open
        while (input_file) { //while the file is open
            input_file >> weight1 >> priority1; //stops when it reaches a space
            //cout << "weight1: " << weight1;
            d_vect.push_back(Package(weight1, priority1)); //adds weight and                priority into the vector 
        }
    }   
    std::sort(d_vect.begin(), d_vect.end(), package_compare); //sorts the vector
        //std::sort(ks.begin(), ks.end(), package_compare);
    for (auto i = 0; i < d_vect.size(); i++) { //iterates through the vector
        if(ks.add(d_vect[i]) == false) 
        //couldnt add it, add function returned false
            break; 
            //d_vect.push_back(i);
    }
}



