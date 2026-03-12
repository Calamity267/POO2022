#pragma once
#include <initializer_list>

class Sort {
private:
    // Datele noastre membre
    int* elemente;
    int count;

    // Functii ajutatoare pentru QuickSort (sunt private pt ca le folosim doar intern)
    void QuickSortRec(int low, int high, bool ascendent);
    int Partition(int low, int high, bool ascendent);

public:
    // 1. Constructor cu valori random
    Sort(int numar_elemente, int min_value, int max_value);

    // 2. Constructor dintr-un initialization list
    Sort(std::initializer_list<int> list);

    // 3. Constructor dintr-un vector existent
    Sort(int* vector, int numar_elemente);

    // 4. Constructor cu parametri variadici
    Sort(int count, ...);

    // 5. Constructor dintr-un string
    Sort(const char* string);

    // Destructor (pentru a elibera memoria)
    ~Sort();

    // Metodele cerute
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};