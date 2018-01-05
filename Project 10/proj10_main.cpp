#include<iostream>
using std::cout; using std::endl;

#include<vector>
using std::vector;
#include<algorithm>
using std::copy;
#include<iterator>
using std::ostream_iterator;
#include<string>
using std::string; using std::to_string;
#include<iomanip>
using std::boolalpha;
#include<cassert>
#include "proj10_package.h"
#include "proj10_knapsack.h"

int main(){
    
    long l;
    long l1, l2;
    Knapsack ks(51,3);
    solve_KS("packages.txt", ks);
    l1 = ks.weight();
//ASSERT_EQ(l,26);
    l2 = ks.priority();
//ASSERT_EQ(l,35);
    //try{
        //solve_KS("badfilename", ks);
    //ASSERT_FALSE(true);
    //}
    //catch (runtime_error& e){
  //ASSERT_TRUE(true);
    //}
    cout << l1 << endl;
    cout << l2 << endl;
    
    /*
    long l1,l2,l3,l4,l5;
    bool b1,b2;
    Knapsack ks(25,3);
    b1 = ks.add({10,10});
    cout << "b1: " << b1 << endl;
    b2 = ks.add({10,10});
    cout << "b2: " << b2 << endl;
    l1 = ks.capacity();
    cout << "l1: " << l1 << endl;
    ks.add({1,10});
    ks.add({1,10});
    l2 = ks.capacity();
    cout << "l2: " << l2 << endl;
    l3 = ks.weight();
    cout << "l3: " << l3 << endl;
    l4 = ks.priority();
    cout << "l4: " << l4 << endl;
    l5 = ks.size();
    cout << "l5: " << l5 << endl;
    */
    
/*

  cout << boolalpha;

  Package p(1,1);
  assert(p.weight_ == 1);
  assert(p.priority_ == 1);

  Knapsack ks(25,2);
  assert(ks.empty() == true);
  cout << ks.empty() <<endl;
  cout << ks.add(Package(10,10)) << endl;
  cout << ks.add(Package(10,10)) << endl;  
  cout << ks.add(Package(10,10)) << endl;
  cout << "Size:" << ks.size() << endl;
  cout << "Weight:" << ks.weight() << endl;
  cout << "Capacity:" << ks.capacity() << endl;
  cout << "Priority:" << ks.priority() << endl;
  cout << ks << endl;
  cout << ks.add(Package(2,10)) << endl;  
  cout << "Size:" << ks.size() << endl;
  cout << "Weight:" << ks.weight() << endl;
  cout << "Capacity:" << ks.capacity() << endl;
  cout << "Priority:" << ks.priority() << endl;
  
  cout << ks << endl;


  Knapsack copy_ks(ks);
  cout << "Copy: "<< copy_ks << endl;

  Knapsack ks2(15, 3);
  solve_KS("packages.txt", ks2);
  cout << ks2 << endl;
  cout << "Weight:"<<ks2.weight() << endl;
  cout << "Priority:"<<ks2.priority() << endl; */
}
