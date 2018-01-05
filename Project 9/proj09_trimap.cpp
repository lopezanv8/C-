#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;
#include<sstream>
using std::ostringstream;
#include<algorithm>
using std::upper_bound;
#include<iterator> 
using std::advance;

#include "proj09_trimap.h"
/*
Project 09
Project focuses on the use of classes. Searching a map for a key using TriMap

Ana Lopez 
Section 11
11/16/17

*/

/* Writes the Element to the ostream
 out - stream we're writing to
 e - Element to output
 */
ostream& operator<<(ostream &out, const Element& e) 
{
    out << "" << e.key_ << ":" 
    << "" << e.value_ << ":" 
    << "" << e.index_;

    return out;
}

// TriMap constructor that only takes in Element
TriMap::TriMap(const Element& el) 
{
    sz_ = 1;
    vec_.push_back(el);
}

/* TriMap Constructor with one args
 li - initializer list we will be copying into vec_
 sz_ - the size vec_ should be */
TriMap::TriMap(initializer_list<Element> li)
{
    // Copy the initializer_list to the vec_ vector
    copy( li.begin(), li.end(), back_inserter(vec_));
    sz_ = li.size();
}

/* Writes the TriMap to the ostream
 out - stream we're writing to
 tm - Element to output 
 substr to take out the comma and space after each element */
ostream& operator<<(ostream& out, const TriMap& tm)
{   
    ostringstream oss;
    for (auto e : tm.vec_) {
        oss << e << ", ";
    }
    string temp = oss.str();
    temp = temp.substr(0, temp.size() - 2 );
    out << temp;

    return out;
}

//returns the number of elements in the vector
size_t TriMap::size() 
{
    size_t result = sz_;
    return result;
}

/* if the key does exist in the vector, then no action is taken
   if the key does not exist in the vector, then it inserts an element into the     vector by key order.
   pos - an iterator */
bool TriMap::insert(string key, string value)
{
    //calls find key to check whether or not the key is in the vector
    if(find_key(key) != nullptr)
    {
        return false;
    }
    else
    {
        Element ele(key, value, sz_); //constructed an element
        //upper_bound requires a less than compare operator for each element in the vector
        auto pos = upper_bound(vec_.begin(), vec_.end(), key, [](const string                                   &str, const Element &e) {return str < e.key_;});
        vec_.insert(pos, ele); //inserts the iterator and element into the vector 
        sz_++; //increments the size
        return true;
    }
}

/* checks if element key is in the vector. if it is there, it removes it. 
    updates the the index values of elements 
    if element key is not in vector, nohthing is done and returns false
    pos - an iterator 
    upper_bound does a binary search 
*/
bool TriMap::remove(string key)
{
    //calls find key to check whether or not the key is in the vector
	if(find_key(key) == nullptr)
    {
        return false;
    }
    else
    {
        // upper_bound requires a lessthan compare operator for each element in the vector.
        auto pos = upper_bound(vec_.begin(), vec_.end(), key, [](const string                                   &str, const Element &e) {return str < e.key_;});
        advance(pos, -1); //advance the iterator pos by -1
        vec_.erase(pos); //removes that iterator
        for (auto &e : vec_) {
            if (e.index_ != 0) { //makes sure that index is not at position 0                   because then it cannot decrement 
                --e.index_;
            }
        }
        sz_ --; //decrements the size
        return true;
    }	  
}
/*checks to find the key inside the vector. if the key is found than Element* is returned. 
*/
Element* TriMap::find_key(const string& key)
{
    // upper_bound requires a lessthan compare operator for each element in the vector.
    auto pos = upper_bound(vec_.begin(), vec_.end(), key, [](const string &str, const Element &e) {return str < e.key_;});
    
    if (pos == vec_.begin()) { //if the iterator is the beginning it doesnt have         anything to compare it to
        return nullptr;
    }
    else if (vec_.empty()) { //vector must have elements in it. 
        return nullptr;
    }
    
    advance(pos, -1); //advance the iterator pos by -1
    if (pos->key_ == key) {
        return &(*pos); //converts the iterator to a pointer 
    }
    else {
        return nullptr;
    }
    return nullptr;
}

/* Uses linear search to locate the Element with the value and returns and Element* */
Element* TriMap::find_value(const string& value)
{
    // upper_bound requires a lessthan compare operator for each element in the vector.
    auto pos = upper_bound(vec_.begin(), vec_.end(), value, [](const string &str, const Element &e) {return str < e.value_;});
    
    if (pos == vec_.begin()) {//if the iterator is at the beginning it doesnt           have anyting to compare it to
        return nullptr;
    }
    else if (vec_.empty()) { //vector must have elements in it. 
        return nullptr;
    }
    advance(pos, -1); //advance the iterator pos by -1
    
    if (pos->value_ == value) {
        return &(*pos); //returns an element 
    }
    else {
        return nullptr;
    }
    return nullptr;

}
/* 
    Uses linear search to locate the Element with the index and returns and Element* 
*/
Element* TriMap::find_index(size_t index)
{
    //find_if does a linear search using an STL algorithm.
     auto find_pos = find_if(vec_.begin(), vec_.end(),
		[&index](Element e){
		  return index == e.index_;
		}
		);
    if (find_pos == vec_.end() ) //if the iterator is the end it cannot                 compare it to anything else
        return nullptr;
    else
        return &(*find_pos); //converts the iterator to a pointer 
}