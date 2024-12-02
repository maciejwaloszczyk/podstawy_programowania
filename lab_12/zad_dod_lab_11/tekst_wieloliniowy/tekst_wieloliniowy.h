#ifndef TEKST_WIELOLINIOWY_H
#define TEKST_WIELOLINIOWY_H

#define MAX_DL_L 100 // maksymalna liczba znaków w jednej linii tekstu
#define MAX_N_L    3 // maksymalna liczba linii tekstu

typedef struct linia_tekstu {
    char* znaki;
    int dlugosc_linii;
} linia_tekstu;

int wczytaj_linie(char* linia, int max_dlugosc_linii);
void wydrukuj_linie(char* linia, int dlugosc_linii);

#endif // TEKST_WIELOLINIOWY_H