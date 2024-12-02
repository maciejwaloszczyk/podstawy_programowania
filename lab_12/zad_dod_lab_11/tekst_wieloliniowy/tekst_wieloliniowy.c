#include <stdlib.h>
#include <stdio.h>

#define MAX_DL_L 100 // maksymalna liczba znaków w jednej linii tekstu
#define MAX_N_L    3 // maksymalna liczba linii tekstu

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

  int rozmiar_str_danych = sizeof(tekst_wieloliniowy_tab_wsk);
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    rozmiar_str_danych += MAX_DL_L*sizeof(char);
    // dla wersji dynamicznej alokacji linii w nowej funkcji wczytaj_linie_dyn:
    // rozmiar_str_danych += dlugosc_linii[nr_linii]*sizeof(char);
  }
  printf("Rozmiar struktury danych (tablica wskaźników):\t %d B\n", rozmiar_str_danych);
  
  // 6. nowa struktura danych (typ struktury (p.5) - definicja na początku pliku)
  // a) definicja tablicy struktur 
  //    (mozna użyć notacji z typedef lub bez)
  struct linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];
  //linia_tekstu tekst_wieloliniowy_tab_str[MAX_N_L];
 
  // w pętli po liniach:
  // b) alokacja pojedynczej linii (rozmiar MAX_DL_L)
  // c) wypełnienie linii poprzez wysłanie do funkcji wczytaj_linie
  // d) wydrukowanie linii

  rozmiar_str_danych = sizeof(tekst_wieloliniowy_tab_str);
  for(int nr_linii=0; nr_linii<MAX_N_L; nr_linii++){
    rozmiar_str_danych += MAX_DL_L*sizeof(char);
    //rozmiar_str_danych += .....dlugosc_linii*sizeof(char);
  }
  printf("Rozmiar struktury danych (tablica struktur):\t %d B\n", rozmiar_str_danych);

}

//------------------------------------------------------------------------------

// po skopiowaniu do nowego katalogu
// 8. nowa funkcja - wczytywanie linii, połączone z alokowaniem miejsca dla znaków
//  dwa możliwe prototypy:
//     int wczytaj_linie_dyn(char** linia, int max_dlugosc_linii);
//     int wczytaj_linie_dyn(char* linia[], int max_dlugosc_linii);
//  jako argument przesłany wskaźnik do wskaźnika utożsamianego z tablicą
//  (adres komórki pamięci, do której mamy wpisać adres początku tablicy)

// po definicji nowej funkcji - przepisanie kodu z p. 4 i p. 6, tak żeby korzystać
// z nowej funkcji (teraz alokowane jest tylko tyle miejsca ile potrzeba na wpisane znaki,
// w funkcji obliczania rozmiaru danych należy użyć rzeczywistej liczby znaków)

//------------------------------------------------------------------------------

// funkcja wczytywania pojedynczej linii ze standardowego wejścia
// Uwaga na przykładowy kontrakt. W zadaniach dodatkowych można rozważyć inne kontrakty
// (może to oznaczac inne działanie funkcji i inne możliwe zwracane wartości)
int wczytaj_linie( // funkcja wypełnia tablicę znaków przekazaną poprzez wskaźnik
		   // wczytując znaki ze standardowego wejścia, bez przekroczenia
		   // maksymalnej liczby znaków przesłanej jako argument max_dlugosc_linii,
		   // umieszczając na końcu tablicy znak końca napisu \0
		   // (maksymalna liczba znaków nie obejmuje znaku końca napisu!)
		   // OUT: funkcja zwraca liczbę wczytanych znaków
		   // (uwaga: jeśli zwrócona liczba jest równa  max_dlugosc_linii
		   //  jest możliwe, że w buforze STDIN zostały jeszcze jakieś znaki,
		   //  co może stanowic problem przy kolejnym wywołaniu funkcji)
		  char* linia,           // IN/OUT: tablica znaków zadana poprzez wskaźnik
		  int max_dlugosc_linii  // IN: maksymalna liczba znaków w linii
		  )
{

  int zakres = max_dlugosc_linii;
  
  printf("\nWpisz zestaw maksymalnie %d znaków zakończony znakiem końca linii \\n\n",
	 zakres);
  
  int znak;
  int i;
  for (i=0; i<zakres && (znak=getchar()) != EOF && znak != '\n'; ++i){
    linia[i] = znak;
  }
  if (znak == '\n') {
    linia[i] = znak;
    ++i;
  }
  linia[i] = '\0'; // od 0 do i - czyli i+1 elementów tablicy
  // co stanie się w dalszej części programu jeśli nie umieścimy \0 w tablicy?
  
  return(i); // liczymy tylko znaki, bez \0 !!!

}

// funkcja drukowania pojedynczej linii jako tablicy znaków i jako napisu
void wydrukuj_linie(
		   char* linia,       // IN: tablica znaków zadana poprzez wskaźnik
		   int dlugosc_linii  // IN: liczba znaków w linii
		   )
{
  
  printf("\nLinia o długości %d wypisana jako tablica znaków:\n", dlugosc_linii);
  for(int i=0; i<dlugosc_linii; i++){
    printf("%c", linia[i]); // założenie: na końcu linii jest \n
  }
  
  printf("Linia o długości %d wypisana jako napis:\n", dlugosc_linii);
  printf("%s", linia);

}

