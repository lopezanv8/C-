#include <iostream>
using std::cout; using std::cin; using std::endl;
long digit_sum(long number){
    long sum=0;
    while(number!=0){
                sum+=number%10;
                number/=10;
                
            }
    return sum;
}
int main(){
    long number;
    int ap=0;
    int ar=0;
    long sum=0;
    bool x = false;
    cin>>number;
    if(number <= 0){
        cout<<"Error"<<endl;
        return 0;
    }
    else{
        if (number < 10){
           cout<<0<<" "<<number<<endl;
        }
        else{
            while(!x){
                sum=digit_sum(number);
                ++ap;
                if (sum < 10){
                    ar=sum;
                    x= true;
                }
                else{
                    number=sum;
                }
            }
            cout<<ap<<" "<<ar<<endl;
        }
    return 0;
    }
    
}