#include <stdio.h>
#include "../include/tekst_wieloliniowy.h"

int main(void) {
    char tekst_wieloliniowy_tab_2D[MAX_N_L][MAX_DL_L];
    int i, dlugosc_linii;

    // Wczytywanie linii tekstu
    for (i = 0; i < MAX_N_L; i++) {
        dlugosc_linii = wczytaj_linie(tekst_wieloliniowy_tab_2D[i], MAX_DL_L);
        if (dlugosc_linii == 0) {
            break;
        }
    }

    // Drukowanie wczytanych linii tekstu
    for (int j = 0; j < i; j++) {
        wydrukuj_linie(tekst_wieloliniowy_tab_2D[j], MAX_DL_L);
    }

    return 0;
}