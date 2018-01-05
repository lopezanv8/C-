#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;

#include "proj11_trimap.h"

int main() {
        
    TriMap<long,long> m1;
    m1.insert(1,20);
    m1.insert(2,10);
    m1.insert(3,40);
    m1.insert(4,30);
    cout << m1 << endl;
    
    TriMap<long, long> m2;
    m2 = m1;
    cout << "m2: " << m2 << endl;
    cout << "m2 size: " << m2.size() << endl;
    m2.insert(5,50);
    cout << m2 << endl;
    m2.remove(4);
    cout << m2 << endl;
    
    ostringstream oss1;
    oss1 << m1;
    string s1 = oss1.str();
    string ans1 = "1:10:1, 2:20:0, 3:30:3, 4:40:2";
    
    ostringstream oss2;
    oss2 << m2;
    string s2 = oss2.str();
    string ans2 = "1:10:1, 2:20:0, 3:30:2, 5:50:3";


    
    
    /*
    TriMap<long,long> m1;
    m1.insert(1,20);
    cout <<"1: " <<  m1 << endl;
    m1.insert(2,10);
    cout << "2: " << m1 << endl;
    m1.insert(3,40);
    cout << "3: " << m1 << endl;
    m1.insert(4,30);
    cout << "4: " << m1 << endl;
    //cout << "i1: " << index_ << endl;
    m1.insert(5,90);
    cout << "5: " << m1 << endl;
    //cout << "i2: " << index_ << endl
    m1.remove(3);
    cout << "6: " << m1 << endl;
    
    
    TriMap<long, long> m2(m1);
    m2.insert(5,50);
    cout << "m2 1: " << m2 << endl;
    m2.remove(4);
    cout << "m2: " << m2 << endl;
    
    ostringstream oss1;
    oss1 << m1;
    string s1 = oss1.str();
    string ans1 = "1:10:1, 2:20:0, 3:30:3, 4:40:2";
    //ASSERT_EQ(s1,ans1);
    
    ostringstream oss2;
    oss2 << m2;
    string s2 = oss2.str();
    string ans2 = "1:10:1, 2:20:0, 3:30:2, 5:50:3";
    //ASSERT_EQ(s2,ans2);
    */

    /*
    TriMap<string,string> m("key","value");
    ostringstream oss;
    oss << m;
    string s = oss.str();
    string ans = "key:value:0";
    
    TriMap<string, string> m;
    m.insert("w","x");
    cout << m << endl;
    m.insert("c", "d");
    cout << m << endl;
    m.insert("a","b");
    cout << m << endl;
    m.insert("y","z");
    cout << m << endl;
    Element<string, string>* result = m.find_key("y");

    ostringstream oss;
    oss << *result;
    string s = oss.str();
    string ans = "y:z:3";
    //ASSERT_EQ(s,ans);

    result = m.find_key("q");
    //ASSERT_EQ(result, nullptr);
    */


}



