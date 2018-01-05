#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using std::sort; 
using std::string;
using std::cout; 
using std::cin; using std::endl;
string alpha = "abcdefghijklmnopqrstuvwxyz";
long loc_to_dec(string loc) {
    long sum = 0;
    long length_loc = loc.size();
    long length_alpha = alpha.size();
    
    for (int i = 0; i < length_loc; i++) {
         sum += pow(2,loc[i]-'a');
    }
    return sum;
}
string abbreviate(string loc) {
    string old_loc = "";
    string l = loc;
    unsigned int index=1;
    while (index<=l.size()) {
        sort(l.begin(), l.end());
        if (l[index -1] == l[index]) {
            old_loc = l;
            l = old_loc.substr(0, index-1);
            old_loc.push_back(static_cast<char>(old_loc[index] + 1));
            l += old_loc.substr(index+1);
        }
        else {
            index++;
        }
        
        //check whether l[index-1] and l[index] is same, if so then do something
        //else increase index by 1
        
    }
    return l;
}
string dec_to_loc(long dec) {
    string str = string(dec, 'a');
    str = abbreviate(str);
    return str;
}
long add_loc(string loc1, string loc2) {
    
    string total = loc1.append(loc2);
    sort(total.begin(),total.end());
    total = abbreviate(total);
    return loc_to_dec(total);
}
int main() {
    string loc;
    long dec;
    cin >> loc;
    cin >> dec;
    cout << loc_to_dec(loc) << " " << abbreviate(loc) << " " << dec_to_loc(dec) << " " << add_loc(loc,loc) << endl;
}