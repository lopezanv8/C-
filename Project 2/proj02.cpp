#include <iostream>
using std::cout; using std::endl; using std::cin;


int count_divisor (int n){
    int cnt = 0;
    for (int i=1; i<=n;i++){
        if (n%i==0){
            cnt++;
        }
    }
        
    return cnt;
}



int main() {
    int n;
    //cout << "Single positive integer: ";
    cin >> n;
    int HCN=0;
    if (n <= 0) 
        cout << "Error" << endl;
    else{
        int count = count_divisor(n);
        HCN = n;
        int num=0;
        int count2=0;
        for(num = 1; num < n; num++ ){
            count2 = count_divisor(num);
            if (count2 == count){
                HCN = num;
                break;
            }
        }
        
        if (HCN == n) cout << "True " << n << " " << count << endl;
        else cout << "False "<< n << " " << num << " " /*<< count2 */<< endl;
    }
    //cout << n << endl;
    
    
}