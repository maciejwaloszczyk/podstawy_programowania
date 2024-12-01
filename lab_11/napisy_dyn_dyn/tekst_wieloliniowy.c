#define MAX_DL_L 100 // maksymalna liczba znaków w jednej linii tekstu

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typ danych do p. 5 laboratorium
typedef struct linia_tekstu {
  char* znaki;
  int dlugosc_linii;
} linia_tekstu;

// funkcje wczytywania linii ze standardowego wejścia i drukowania linii
// opis z kontraktem na końcu pliku
int wczytaj_linie(char* linia, int max_dlugosc_linii);
void wydrukuj_linie(char* linia, int dlugosc_linii);

// nowa funkcja wczytaj_linie_dyn
int wczytaj_linie_dyn(char** linia_wsk, int max_dlugosc_linii) {
  char linia_max[MAX_DL_L + 1];
  int dlugosc = wczytaj_linie(linia_max, max_dlugosc_linii);
  *linia_wsk = (char*)malloc((dlugosc + 1) * sizeof(char));
  strcpy(*linia_wsk, linia_max);
  return dlugosc;
}

// nowa funkcja wczytaj_linie_dyn_str
int wczytaj_linie_dyn_str(linia_tekstu* linia_str_wsk, int max_dlugosc_linii) {
  char linia_max[MAX_DL_L + 1];
  linia_str_wsk->dlugosc_linii = wczytaj_linie(linia_max, max_dlugosc_linii);
  linia_str_wsk->znaki = (char*)malloc((linia_str_wsk->dlugosc_linii + 1) * sizeof(char));
  strcpy(linia_str_wsk->znaki, linia_max);
  return linia_str_wsk->dlugosc_linii;
}

int main(void) {
  int liczba_linii;
  printf("Podaj liczbe linii: ");
  scanf("%d", &liczba_linii);

  // podstawowa struktura danych do przechowywania tekstu
  char (*tekst_wieloliniowy_tab_2D)[MAX_DL_L] = (char (*)[MAX_DL_L])malloc(liczba_linii * MAX_DL_L * sizeof(char));

  int zakres = MAX_DL_L - 1; // w napisie jako tablicy znaków miejsce na \0
  int* dlugosc_linii = (int*)malloc(liczba_linii * sizeof(int)); // tablica do przechowywania długości linii tekstu

  // wczytanie i drukowanie liczba_linii pojedynczych linii
  for(int nr_linii=0; nr_linii<liczba_linii; nr_linii++){
    char* linia = tekst_wieloliniowy_tab_2D[nr_linii];
    dlugosc_linii[nr_linii] = wczytaj_linie(linia, zakres);
    wydrukuj_linie(linia, dlugosc_linii[nr_linii]);
  }

  printf("Rozmiar struktury danych (tablica 2D):\t\t %lu B\n",
     liczba_linii * MAX_DL_L * sizeof(char) );

  // 4. nowa struktura danych
  // a) definicja
  char** tekst_wieloliniowy_tab_wsk = (char**)malloc(liczba_linii * sizeof(char*));

  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie_dyn
  // d) wydrukowanie linii

  for(int nr_linii=0; nr_linii<liczba_linii; nr_linii++){
    dlugosc_linii[nr_linii] = wczytaj_linie_dyn(&tekst_wieloliniowy_tab_wsk[nr_linii], zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], dlugosc_linii[nr_linii]);
  }

  printf("Rozmiar struktury danych (tablica wskaźników):\t %lu B\n",
     liczba_linii * sizeof(char*) );

  // 6. nowa struktura danych
  // a) definicja
  linia_tekstu* tekst_wieloliniowy_tab_str = (linia_tekstu*)malloc(liczba_linii * sizeof(linia_tekstu));

  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie_dyn_str
  // d) wydrukowanie linii

  for(int nr_linii=0; nr_linii<liczba_linii; nr_linii++){
    dlugosc_linii[nr_linii] = wczytaj_linie_dyn_str(&tekst_wieloliniowy_tab_str[nr_linii], zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, tekst_wieloliniowy_tab_str[nr_linii].dlugosc_linii);
  }

  printf("Rozmiar struktury danych (tablica struktur):\t %lu B\n",
     liczba_linii * sizeof(linia_tekstu) );

  // zwolnienie pamięci
  for(int nr_linii=0; nr_linii<liczba_linii; nr_linii++){
    free(tekst_wieloliniowy_tab_wsk[nr_linii]);
    free(tekst_wieloliniowy_tab_str[nr_linii].znaki);
  }
  free(tekst_wieloliniowy_tab_2D);
  free(tekst_wieloliniowy_tab_wsk);
  free(tekst_wieloliniowy_tab_str);
  free(dlugosc_linii);

  return 0;
}