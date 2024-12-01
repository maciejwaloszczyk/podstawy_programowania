#define MAX_DL_L 100 // maksymalna liczba znaków w jednej linii tekstu
#define MAX_N_L    3 // maksymalna liczba linii tekstu

#include <stdlib.h>

// typ danych do p. 5 laboratorium
typedef struct linia_tekstu {
  char* znaki;
  int dlugosc_linii;
} linia_tekstu;

// funkcje wczytywania linii ze standardowego wejścia i drukowania linii
// opis z kontraktem na końcu pliku
int wczytaj_linie(char* linia, int max_dlugosc_linii);
void wydrukuj_linie(char* linia, int dlugosc_linii);

int main( void )
{
  // podstawowa struktura danych do przechowywania tekstu
  char tekst_wieloliniowy_tab_2D[MAX_N_L][MAX_DL_L]; 

  int zakres = MAX_DL_L - 1; // w napisie jako tablicy znaków miejsce na \0
  int dlugosc_linii[MAX_N_L]; // tablica do przechowywania długości linii tekstu

  // wczytanie i drukowanie MAX_N_L pojedynczych linii
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    char* linia = tekst_wieloliniowy_tab_2D[nr_linii];
    dlugosc_linii[nr_linii] = wczytaj_linie(linia, zakres);
    wydrukuj_linie(linia, dlugosc_linii[nr_linii]);
  }

  printf("Rozmiar struktury danych (tablica 2D):\t\t %lu B\n",
     sizeof(tekst_wieloliniowy_tab_2D) );

  // 4. nowa struktura danych
  // a) definicja
  char* tekst_wieloliniowy_tab_wsk[MAX_N_L] = {NULL};

  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii

  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    tekst_wieloliniowy_tab_wsk[nr_linii] = (char*)malloc(MAX_DL_L * sizeof(char));
    dlugosc_linii[nr_linii] = wczytaj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_wsk[nr_linii], dlugosc_linii[nr_linii]);
  }

  printf("Rozmiar struktury danych (tablica wskaźników):\t %lu B\n",
     sizeof(tekst_wieloliniowy_tab_wsk) );

  // 6. nowa struktura danych
  // a) definicja
  linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];

  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii

  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    tekst_wieloliniowy_tab_str[nr_linii].znaki = (char*)malloc(MAX_DL_L * sizeof(char));
    tekst_wieloliniowy_tab_str[nr_linii].dlugosc_linii = wczytaj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, zakres);
    wydrukuj_linie(tekst_wieloliniowy_tab_str[nr_linii].znaki, tekst_wieloliniowy_tab_str[nr_linii].dlugosc_linii);
  }

  printf("Rozmiar struktury danych (tablica struktur):\t %lu B\n",
     sizeof(tekst_wieloliniowy_tab_str) );

  // zwolnienie pamięci
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    free(tekst_wieloliniowy_tab_wsk[nr_linii]);
    free(tekst_wieloliniowy_tab_str[nr_linii].znaki);
  }

  return 0;
}