#include <iostream>
#include "NumberList.h"

int main() {
    NumberList myList;
    myList.Init();

    myList.Add(5);
    myList.Add(2);
    myList.Add(8);
    myList.Add(1);
    myList.Add(9);

    std::cout << "Lista inainte de sortare: ";
    myList.Print();

    myList.Sort();

    std::cout << "Lista dupa sortare: ";
    myList.Print();

    return 0;
}