#define _CRT_SECURE_NO_WARNINGS // pentru Visual Studio (ca sa ne lase sa folosim strcpy/strcat)
#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cstdlib>

int Math::Add(int a, int b) { return a + b; }
int Math::Add(int a, int b, int c) { return a + b + c; }
int Math::Add(double a, double b) { return (int)(a + b); }
int Math::Add(double a, double b, double c) { return (int)(a + b + c); }

int Math::Mul(int a, int b) { return a * b; }
int Math::Mul(int a, int b, int c) { return a * b * c; }
int Math::Mul(double a, double b) { return (int)(a * b); }
int Math::Mul(double a, double b, double c) { return (int)(a * b * c); }

// Funcție variadică (cu număr necunoscut de argumente)
int Math::Add(int count, ...) {
    va_list args;
    va_start(args, count); // Inițializăm lista de argumente

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int); // Extragem argumentele unul câte unul (de tip int)
    }

    va_end(args); // Închidem lista
    return sum;
}

char* Math::Add(const char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) {
        return nullptr;
    }

    // Calculăm lungimea pentru noul șir: len(s1) + len(s2) + 1 (pentru caracterul nul '\0')
    int totalLen = strlen(s1) + strlen(s2) + 1;
    char* result = new char[totalLen]; // Alocare dinamică

    strcpy(result, s1); // Copiem primul șir
    strcat(result, s2); // Lipim (concatenăm) al doilea șir

    return result;
}