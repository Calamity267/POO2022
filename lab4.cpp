#include "Sort.h"
#include <iostream>

using namespace std;

int main() {
    cout << "1. Test random (5 elemente intre 10 si 50) + BubbleSort descrescator:" << endl;
    Sort s1(5, 10, 50);
    s1.Print();
    s1.BubbleSort(false);
    s1.Print();
    cout << "------------" << endl;

    cout << "2. Test initializer_list + InsertSort crescator:" << endl;
    Sort s2({ 10, 2, 5, 8, 1, 9 });
    s2.Print();
    s2.InsertSort(true);
    s2.Print();
    cout << "------------" << endl;

    cout << "3. Test vector existent + QuickSort descrescator:" << endl;
    int v[] = { 100, 20, 50, 30, 80 };
    Sort s3(v, 5);
    s3.Print();
    s3.QuickSort(false);
    s3.Print();
    cout << "------------" << endl;

    cout << "4. Test variadic (6 elemente) + BubbleSort crescator:" << endl;
    Sort s4(6, 14, 2, 5, 8, 3, 11); // Primul param e nr de elemente
    s4.Print();
    s4.BubbleSort(true);
    s4.Print();
    cout << "------------" << endl;

    cout << "5. Test string + QuickSort crescator:" << endl;
    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.QuickSort(true);
    s5.Print();

    cout << "\nNumar total elemente: " << s5.GetElementsCount() << endl;
    cout << "Elementul de la indexul 2: " << s5.GetElementFromIndex(2) << endl;

    return 0;
}