#include<iostream>
using std::cout;
using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
using std::make_pair;
#include<sstream>
using std::ostringstream; using std:: stringstream;
#include<stdexcept>
using std::range_error;
#include"lab08_functions.h"
using Collatz = pair<long, vector<long> >;

long collatz_next(long n){

  if(n <= 0) {
    throw range_error("Collatz only takes positive integers");
  }
  if((n % 2) == 0){
    return (n/2);
  }
  else {
    return ((3*n) + 1);
  }
}
 string Collatz_to_string(const Collatz &p) {
     ostringstream oss;
     string s;
     vector<long> v = p.second;
     oss << p.first << ": ";
     for(long element:v) {
         oss << element << ",";
     }
     s = oss.str();
     return s.substr(0,s.size()-1);
 }
 
 string sequence_in_map_to_string(map<long, vector<long>> &m, long number) {
     auto itr = m.find(number);
     string s = "";
     if(itr != m.end()) {
         return Collatz_to_string(*itr);
     }
     return s;
 }
 vector<long> collatz_sequence(map<long, vector<long> > &m, long number) {
     vector <long> result;
     while(number != 1){
        if(m.count(number) != 0) {
            result.pop_back();
             auto p = m[number];
            for(auto element : p){
                result.push_back(element);
            }
            return result;
        }
        else{
            number = collatz_next(number);
            result.push_back(number);
         }
  }
  return result;
}
void collatz_range(map<long, vector<long> > &m, long low, long high) {
    pair<long,vector<long>> p;
    for(long i=low; i<= high; i++) {
       // m[i] = collatz_sequence(m,i);
        m.insert({i, collatz_sequence(m,i)});
    }
}
 //int main() {
     //using Collatz = pair<long, vector<long> >;
     //Collatz c = {16, {8,4,2,1}};
    // string s = Collatz_to_string(c);
     //vector<long> v ={1,2,3,4};
     //Collatz p = make_pair(1, v);
     //cout << s << endl;
    // map<long, vector<long>> test = { {1, {1,2,3,4}} , {2, {1,2,3,4}} };;
     //vector <long> second = {1,2,3,4};
     //long number = 1;
     //map<number,second> test;
     //cout << sequence_in_map_to_string(test,number);
    
// }