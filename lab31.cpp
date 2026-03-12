#include <iostream>
#include "Math.h"

int main() {
    std::cout << "Add(2, 3) = " << Math::Add(2, 3) << "\n";
    std::cout << "Add(2, 3, 5) = " << Math::Add(2, 3, 5) << "\n";
    std::cout << "Add(2.5, 3.5) = " << Math::Add(2.5, 3.5) << "\n";

    std::cout << "Mul(2, 3) = " << Math::Mul(2, 3) << "\n";
    std::cout << "Mul(2.5, 2.5) = " << Math::Mul(2.5, 2.5) << "\n";

    // Adunăm 5 numere (primul parametru indică de fapt CÂTE numere urmează)
    std::cout << "Add variadic (5 numere: 10,20,30,40,50) = " << Math::Add(5, 10, 20, 30, 40, 50) << "\n";

    char* concat = Math::Add("Laborator ", "POO C++");
    if (concat != nullptr) {
        std::cout << "Concatenare string: " << concat << "\n";
        delete[] concat; // FOARTE IMPORTANT: eliberăm memoria alocată dinamic din metoda Add!
    }

    return 0;
}