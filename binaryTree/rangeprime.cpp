#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(n); i++) { // only go up to sqrt(n)
        if (n % i == 0) return false; // if n is divisible by i, it is not prime
    }
    return true; // if no divisors found, n is prime
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++) {
        if (isPrime(i)) {
            cout << "prime: " << i << endl;
        } else {
            cout << "not prime: " << i << endl;
        }
    }
    return 0;
}
