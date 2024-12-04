#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// 9.a znalezienie za pomocą: man 3 bsearch lub man 3 qsort typu funkcji porównującej
//     dwa elementy tablicy 
// 9.b deklaracja (za pomocą właściwego prototypu) funkcji porównującej
int compare(const void *a, const void *b);
// 9.c definicja funkcji - najlepiej na końcu pliku
int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}

// 9.d wywołanie funkcji sortowania qsort w funkcji main

#define ROZMIAR_TABLICY 10 // można potem zwiększyć do np. 1000 po wykomentowaniu wydruków

// funkcja wyszukiwania zadanej wartości (klucz) w tablicy (tab_int)
int* binsearch_iter(// funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		    // lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
	      int klucz,     // wyszukiwana wartość
	      int tab_int[], // tablica liczbowa
	      int n          // długość tablicy
	       );

// funkcja wyszukiwania zadanej wartości (klucz) w podtablicy tablicy (tab_int)
// od indeksu początkowego (pocz) do indeksu końcowego (kon)
int* binsearch_rekur(//funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		     //lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
	      int klucz,     // wyszukiwana wartość
	      int tab_int[], // tablica liczbowa
	      int pocz,      // indeks poczatkowego elementu podtablicy
	      int kon        // indeks końcowego elementu podtablicy
	       );

void zapisz_tablice_do_pliku(const char* nazwa_pliku, int* tablica, int rozmiar) {
    FILE* plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku do zapisu\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rozmiar; i++) {
        fprintf(plik, "%d\n", tablica[i]);
    }
    fclose(plik);
}

void odczytaj_tablice_z_pliku(const char* nazwa_pliku, int* tablica, int rozmiar) {
    FILE* plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        fprintf(stderr, "Nie można otworzyć pliku do odczytu\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rozmiar; i++) {
        if (fscanf(plik, "%d", &tablica[i]) != 1) {
            fprintf(stderr, "Błąd odczytu danych z pliku\n");
            fclose(plik);
            exit(EXIT_FAILURE);
        }
    }
    fclose(plik);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Użycie: %s <nazwa_pliku>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* nazwa_pliku = argv[1];
    int i;
    int* tablica_int = malloc(ROZMIAR_TABLICY * sizeof(int));
    srand(time(NULL)); // inicjowanie generatora liczb losowych aktualnym czasem

    for (i = 0; i < ROZMIAR_TABLICY; i++) {
        tablica_int[i] = rand() % 1000; // losowa liczba z zakresu 0-999
    }

    zapisz_tablice_do_pliku(nazwa_pliku, tablica_int, ROZMIAR_TABLICY);

    int* odczytana_tablica = malloc(ROZMIAR_TABLICY * sizeof(int));
    odczytaj_tablice_z_pliku(nazwa_pliku, odczytana_tablica, ROZMIAR_TABLICY);

    for (i = 0; i < ROZMIAR_TABLICY; i++) {
        if (tablica_int[i] != odczytana_tablica[i]) {
            fprintf(stderr, "Błąd: tablica_int[%d] = %d, odczytana_tablica[%d] = %d\n", i, tablica_int[i], i, odczytana_tablica[i]);
        }
    }

    free(tablica_int);
    free(odczytana_tablica);

    return EXIT_SUCCESS;
}

// funkcja wyszukiwania wartości (wyszukiwana_liczba) w tablicy (tab_int)
int* binsearch_iter(// funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		    // lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
		   int wyszukiwana_liczba,   // wyszukiwana wartość
		   int tab_int[], // tablica liczbowa
		   int n    // długość tablicy
		    )
{

  int low = 0; // dolny (lewy) indeks aktualnie przeszukiwanej pod-tablicy
  int high = n-1; // górny (prawy) indeks aktualnie przeszukiwanej pod-tablicy

  // dopóki jest jeszcze coś do przeszukania
  while (low <= high) {
    // znajdź środek przeszukiwanej tablicy
    int mid = (low+high) / 2;
    // jeśli element może być w lewej części
    if (wyszukiwana_liczba < tab_int[mid]){
      // zmień górny indeks na dotychczasowy środek 
      high = mid - 1;
    // jeśli element może być w prawej części
    } else if (wyszukiwana_liczba > tab_int[mid]) {
      // zmień dolny indeks na dotychczasowy środek 
      low = mid + 1;
    } else {
      // wartość znaleziona
      //return mid;
      return &tab_int[mid];
    }
  }
  // jeśli low > high - koniec przeszukiwania
  return NULL; // wartość nie znaleziona
}

