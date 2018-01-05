#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include <algorithm>
using std::sort; 

/* 
10/2/17
Ana Lopez 
Section 11 Project 3 

Continue use of functions and working with strings.

*/

// metadrome, strictly increase
// plaindrome, non-strictly increase
// katadrome, strictly decrease
// nialpdrome, non-strictly decrease
// nondrome, none of the above

const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";

bool checkbase(string num, int base) {
   //i goes through the string num one by one
    for (int i = 0; i < num.size(); i++) {
        //searches for num string in the base vals and compares each chr and its value with the int base
        if(base_vals.find(num[i]) > base || base_vals.find(num[i]) == string::npos){ 
        //checks whether the value of the ch is larger than the base or if it is equal
            return false;
        }
    }
    return true; //returns true as long as the base value is larger than the value of the num string.
}

bool metadrome(string num, int base) {
    
    string validones = base_vals.substr(0,base);
    //string num = base_vals.substr(base, num);
    unsigned int index = 1;
    
    //checks whether the base is larger than the string num
    if(!checkbase(num, base)){
        return false; 
    }
    while (index < num.size()) {
        //index continues going through string num until it reaches the last ch.
        if (num[index] <= num[index-1]) {
            //compares the two characters of string num to make sure the numbers arent the same and that they are increasing
            //the two ch cannot have the same value
            validones.find(num[index]);
            //checks whether ch is in the base_vals
            
            return false;
        }
        index++; //continues incrementing index until it is bigger than the size of num. 
    }
    
    return true;
}


bool plaindrome(string num, int base) {
    string validones = base_vals.substr(0,base);
    unsigned int index = 1;
    
    //checks whether the base is larger than the string num
    if(!checkbase(num, base)){
        return false; 
    }
    while (index < num.size()) {
        //index will go through loop as long as its value is less than the size oof the string num
        if (num[index] < num[index-1]) {
            //compares two characters from num, and makes sure that the first one is less than the second one, has to be increasing
            validones.find(num[index]);
            //checks if ch is in base_vals
            return false;
        }
        //the two ch can have the same value as long as the string is increasing
        index++;
        //continues incrementing index until bigger than string num
    }
    
    return true;
}


bool katadrome(string num, int base) {
    
    string validones = base_vals.substr(0,base);
    unsigned int index = 1;
    //checks whether the base is larger than the string num
    if(!checkbase(num, base)){
        return false; 
    }
    while (index < num.size()) {
        //index will go through loop as long as its value is less than the size oof the string num
        if (num[index-1] <= num[index]) {
        //compares two characters from num at a time, and makes sure that the first one is more than the second one, has to be decreasing
        //the two ch cannot have the same value
            validones.find(num[index]);
            return false;
        }
        index++; //continues incrementing index until bigger than string num
    }
    
    return true;

}

bool nialpdrome(string num, int base) {
    
    string validones = base_vals.substr(0,base);
    unsigned int index = 1;
    //checks whether the base is larger than the string num
    if(!checkbase(num, base)){
        return false; 
    }
    while (index < num.size()) {
        //index will go through loop as long as its value is less than the size oof the string num
        if (num[index-1] < num[index]) {
            //compares two characters from num at a time, and makes sure that the first one is more than the second one
            //the two ch can have the same value as long the str is decreasing.
            validones.find(num[index]);
            return false;
        }
        index++; //continues incrementing index until bigger than string num
    }
    
    return true;

}

string classify(string num, int base) {
    //calls each function and checks whether function returns true or false
    //it returns whichever function it finds to be true first.
    //if all are false then will return nondrome
    if (metadrome(num, base)) {
        return "metadrome";
    } else if (plaindrome(num, base)) {
        return "plaindrome";
    } else if (katadrome(num, base)) {
        return "katadrome";
    } else if (nialpdrome(num, base)) {
        return "nialpdrome";
    } else {
        return "nondrome";
    }
}


int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base; //takes in two inputs, one a string and the other an integer
  //runs each function and returns true or false. 
  cout << metadrome (num, base) << " " 
       << plaindrome (num, base) << " " 
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}
    



  
