#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false; // 0 și 1 nu sunt prime

    for (int tr = 2; tr <= n / 2; tr++) {
        if ((n % tr) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n; // Aici am completat citirea

    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";

    return 0;
}