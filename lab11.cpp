#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Funcția noastră care înlocuiește atoi (convertește text în număr)
int string_to_int(const char* str) {
    int rezultat = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n' && str[i] != '\r'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            rezultat = rezultat * 10 + (str[i] - '0');
        }
    }
    return rezultat;
}

int main() {
    // Deschidem fișierul pentru citire ("r" de la read)
    FILE* fisier = fopen("in.txt", "r");

    if (fisier == NULL) {
        printf("Eroare: Nu am putut deschide fisierul in.txt. Verifica daca e in acelasi folder!\n");
        return 1;
    }

    char linie[200];
    int suma = 0;

    // Citim linie cu linie din fișier
    while (fgets(linie, sizeof(linie), fisier)) {
        suma += string_to_int(linie);
    }

    printf("Suma numerelor este: %d\n", suma);

    fclose(fisier);
    return 0;
}