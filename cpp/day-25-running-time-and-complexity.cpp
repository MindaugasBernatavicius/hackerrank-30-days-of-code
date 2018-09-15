#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    // AKS algorithm

    // Corner cases
    if (n <= 1) return false;
    if (n <= 3) return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
           return false;
    
    return true;
}

int main() {
    // Handle input
    int cases = 0; cin >> cases; cin.ignore();
    int number = 0;
    while(cases-- != 0){
        cin >> number; cin.ignore();
        cout << (isPrime(number) ? "Prime" : "Not prime"  ) << std::endl;
    }
    return 0;
}
