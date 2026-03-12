#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

// 1. Constructor: valori random
Sort::Sort(int numar_elemente, int min_value, int max_value) {
    this->count = numar_elemente;
    this->elemente = new int[count]; // Alocam memorie
    srand((unsigned int)time(NULL));
    for (int i = 0; i < count; i++) {
        this->elemente[i] = min_value + rand() % (max_value - min_value + 1);
    }
}

// 2. Constructor: initialization list
Sort::Sort(std::initializer_list<int> list) {
    this->count = (int)list.size();
    this->elemente = new int[count];
    int i = 0;
    for (int val : list) {
        this->elemente[i++] = val;
    }
}

// 3. Constructor: vector existent
Sort::Sort(int* vector, int numar_elemente) {
    this->count = numar_elemente;
    this->elemente = new int[count];
    for (int i = 0; i < count; i++) {
        this->elemente[i] = vector[i];
    }
}

// 4. Constructor: parametri variadici
Sort::Sort(int count, ...) {
    this->count = count;
    this->elemente = new int[count];
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        this->elemente[i] = va_arg(args, int);
    }
    va_end(args);
}

// 5. Constructor: string
Sort::Sort(const char* string) {
    // Numaram cate virgule sunt pentru a afla cate numere avem
    int virgule = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ',') virgule++;
    }
    this->count = virgule + 1;
    this->elemente = new int[this->count];

    // Facem o copie a stringului pentru a folosi strtok
    char* copie = new char[strlen(string) + 1];
    strcpy(copie, string);

    char* p = strtok(copie, ",");
    int index = 0;
    while (p != NULL) {
        this->elemente[index++] = atoi(p);
        p = strtok(NULL, ",");
    }
    delete[] copie; // eliberam copia
}

// Destructor
Sort::~Sort() {
    delete[] elemente; // Eliberam memoria vectorului
}

// --- Algoritmi de Sortare ---

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < count; i++) {
        int key = elemente[i];
        int j = i - 1;
        while (j >= 0 && ((ascendent && elemente[j] > key) || (!ascendent && elemente[j] < key))) {
            elemente[j + 1] = elemente[j];
            j--;
        }
        elemente[j + 1] = key;
    }
}

void Sort::BubbleSort(bool ascendent) {
    bool swapped;
    for (int i = 0; i < count - 1; i++) {
        swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            if ((ascendent && elemente[j] > elemente[j + 1]) || (!ascendent && elemente[j] < elemente[j + 1])) {
                int temp = elemente[j];
                elemente[j] = elemente[j + 1];
                elemente[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortRec(0, count - 1, ascendent);
}

void Sort::QuickSortRec(int low, int high, bool ascendent) {
    if (low < high) {
        int pi = Partition(low, high, ascendent);
        QuickSortRec(low, pi - 1, ascendent);
        QuickSortRec(pi + 1, high, ascendent);
    }
}

int Sort::Partition(int low, int high, bool ascendent) {
    int pivot = elemente[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if ((ascendent && elemente[j] < pivot) || (!ascendent && elemente[j] > pivot)) {
            i++;
            int temp = elemente[i];
            elemente[i] = elemente[j];
            elemente[j] = temp;
        }
    }
    int temp = elemente[i + 1];
    elemente[i + 1] = elemente[high];
    elemente[high] = temp;
    return (i + 1);
}

// --- Functii Utilitare ---

void Sort::Print() {
    for (int i = 0; i < count; i++) {
        std::cout << elemente[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return count;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < count) {
        return elemente[index];
    }
    return -1; // Returnam -1 daca indexul e invalid
}