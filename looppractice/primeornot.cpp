#include <iostream>
#include <cmath> // Include cmath for sqrt function
using namespace std;

int main() {
    int n;
    cout << "Enter the number to check: " << endl;
    cin >> n;
    bool is_prime = true;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }

    if (is_prime) {
        cout << "It is a prime number" << endl;
    } else {
        cout << "It is a composite number" << endl;
    }

    return 0;
}
