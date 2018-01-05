#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::boolalpha;
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;
#include <list>
using std::list;
#include<sstream>
using std::ostringstream;

#include "lab10_circbuf.h"

CircBuf::CircBuf(size_t sz)
{
    sz_ = sz;
    buf_ = vector<long>(sz);
    cnt_ = 0;
    head_ = 0;
    tail_ = 0;
    //everything else is set to zero (cnt_, head_, tail_)
}

//if the parameter size is smaller than initializationlist, throw a runtime_errr
CircBuf::CircBuf(initializer_list<long> li, size_t sz)
{
    if (sz < li.size()) {
        throw runtime_error("runtime error");
    }
    buf_ = vector<long> (sz);
    
    copy(li.begin(), li.end(), buf_.begin());
    cnt_ = li.size();
    tail_ = cnt_ + 1;
}

bool CircBuf::full() const
{
    if (cnt_ == sz_) {
        return true;
    }
    else {
        return false;
    }
}

bool CircBuf::empty() const
{
    if (cnt_ == 0) {
        return true;
    }
    else {
        return false;
    }
}

long CircBuf::front() const
{
    if (cnt_ == 0) {
        throw runtime_error("runtime error");
    }
    
    else {
        return buf_[head_];
    }
}

long CircBuf::back() const
{
    if (cnt_ == 0) {
        throw runtime_error("runtime error");
    }
    
    else {
        size_t bufindex = (tail_ -1);
        if (bufindex < 0) {
            return (buf_[sz_ -1]);
        }
        else {
            return buf_[tail_ -1];
        }
    }
}


void CircBuf::add(long ele)
{
    if (buf_.full()) {
        throw runtime_error("runtime error");
    }
    else {
        
        buf_[tail_] = ele;
        
    }
    
}

void CircBuf::remove()
{
    if (buf_.empty()) {
        throw runtime_error("runtime error");
    }
    else {
        head_ = head_  +1;
        if (head_ >= sz_) {
            head_ = 0;
            cnt_ = cnt_ -1;
        }
    }
}


//Front:3, Back:30, Cnt:4, Sz:5\n30, 2, 3, 4, 20
ostream& operator<<(ostream&, const CircBuf &cb) 
{
    ostringstream oss;
    
    if (cb.empty()) {
        cout << ("CircBuf empty") << endl;
    }
    
    else {
        oss << "Front:" << cb.front() << ", " << "Back:" << cb.back() << ", " << "Cnt:" << cb.cnt_ << ", " << "Sz:" << cb.sz_ << "\n" << endl;
    }
    
}


