#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char propozitie[500];
    char cuvinte[50][100]; // Putem stoca maxim 50 de cuvinte a cate 100 de litere
    int nrCuvinte = 0;

    printf("Introdu propozitia: ");
    // Citim toata linia pana cand apesi Enter
    scanf("%[^\n]", propozitie);

    // Taiem propozitia in bucati (cuvinte) oriunde gasim spatiu " "
    char* p = strtok(propozitie, " ");
    while (p != NULL) {
        strcpy(cuvinte[nrCuvinte], p);
        nrCuvinte++;
        p = strtok(NULL, " ");
    }

    // Sortam cuvintele (metoda Bubble Sort)
    for (int i = 0; i < nrCuvinte - 1; i++) {
        for (int j = i + 1; j < nrCuvinte; j++) {
            int len1 = strlen(cuvinte[i]);
            int len2 = strlen(cuvinte[j]);
            bool faSchimbul = false;

            // Regula 1: Dupa lungime (cel mai lung primul)
            if (len1 < len2) {
                faSchimbul = true;
            }
            // Regula 2: Daca lungimile sunt egale, alfabetic
            else if (len1 == len2) {
                if (strcmp(cuvinte[i], cuvinte[j]) > 0) {
                    faSchimbul = true;
                }
            }

            // Daca trebuie, inversam cele doua cuvinte in matrice
            if (faSchimbul) {
                char aux[100];
                strcpy(aux, cuvinte[i]);
                strcpy(cuvinte[i], cuvinte[j]);
                strcpy(cuvinte[j], aux);
            }
        }
    }

    // Afisam rezultatul
    printf("\nCuvintele sortate:\n");
    for (int i = 0; i < nrCuvinte; i++) {
        printf("%s\n", cuvinte[i]);
    }

    return 0;
}