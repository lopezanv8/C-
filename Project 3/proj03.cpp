#include<iostream>
using std::cout; using std::cin; using std::endl;  using std::boolalpha;
#include<cmath>

/*
9/25/17
Ana Lopez 
Section 11 Project 3 

Introducing the use of functions. 
Continue use of loops and conditionals. 
*/

long biggest_prime(long n) {
    long lgst_prime = 1;
    long i = 2; //beginning of divisors to go through
    //takes the input of n, and as long as i is less than or equal to n, loop will continue, each time around i is increased by 1.
    for (i = 2; i <= n; i++) {
        while (n%i == 0) { // I must be a factor of n, meaning there will be no remainder when divided.
            n = n/i; // each time n is divided by the divisor i, n will be assigned a new value from being divided
            if (n == 1) { //when the new value becomes one that is then the largest prime.
                lgst_prime = i;
                break;
            }
        }
    }
    return lgst_prime;
}

long sum_of_divisors(long n) {
    long sum = 0;
    long i = 1;
    //I realized that doing the sqrt is better because it helps decrease running time and prevents it from getting stuck since its only to half of n. but still shows all of its divisors
    while (i<=sqrt(n)) {
        if (n%i==0){
            sum = sum +i; //sum begins at zero, and each number that divides evenly into n is added into the sum, changing the value of the sum each time it loops through. 
            sum = sum + (n/i);
        }
        i++;
    }
    return sum;
}

long k_hyperperfect(long n, long k_max){
    //sum all the divisors together, then subtract the number inputed and a 1. 
    //will be perfect numbers
    for (long k = 1; k <= k_max; k++) {
        if (n == 1 + k * (sum_of_divisors(n) - n - 1)) {
            return k;
        }
    }
    return 0;
}

bool b_smooth(long n, long b){
    //none of the prime factors of n will be greater than the value of the number b inputted for it to be b smooth. else will result in a false value. 
    if (biggest_prime(n) <= b) {
        bool bt = true;
        return bt;
    }
    else {
        bool bf = false;
        return bf;
    }
}

int main(){
    //takes input for n, k_max, and b. and then uses those numbers inputted to run the functions called. 
    long n;
    long k_max;
    long b;
    cin >> n;
    cin >> k_max;
    cin >> b;
    biggest_prime(n);
    sum_of_divisors(n);
    k_hyperperfect(n, k_max);
    cout << biggest_prime(n) << " " << sum_of_divisors(n) << " " << k_hyperperfect(n, k_max) << " ";
    std::cout << std::boolalpha << b_smooth(n, b) << endl;
}

