#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 0. numeracja kolejnych kroków ćwiczeń odpowiada numeracji w temacie laboratorium
//    - początek modyfikacji kodu (po wstępnym uruchomieniu programu za pomocą
//      utworzonego pliku Makefile) -> p.4 w funkcji power_int_rekur

// funkcja pomocnicza przekształcająca napis (liczbę zapisaną literowo) w liczbę całkowitą
int my_atoi(char s[])
{
  int sign=1; // = (s[0]=='-') ? -1 : 1;
  if(s[0]=='-') sign=-1;
  int i=0;
  if (s[0]=='+' || s[0]=='-') i++;  
  int n = 0;
  while( s[i] >= '0' && s[i] <= '9' ) {
    n = 10 * n + (s[i] - '0');
    i++;
  }
  return sign*n;
}


// obliczanie n-tej potegi (całkowitej) liczby całkowitej base
int power_int(int base, int n);

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base w sposób rekurencyjny
int power_int_rekur(int m, int n);

// int main (void)
  
// 5. modyfikacja programu polegająca na podawaniu argumentów w linii komend
int main (int argc, char** argv) 
  
{
  
  // cd. 5 - sprawdzenie poprawności wywołania (np. modyfikując poniższy kod)
  if(argc<=2) { printf( "Usage: argc has to be at least 2 \n"); exit(0); }
  
  // cd. 5 uzyskanie argumentów liczbowych z przesłanych napisów w linii komend
  //
  int base = my_atoi(argv[1]);
  int exp = my_atoi(argv[2]);
  //
  // sprawdzająca asercja?
  assert(base != 0 || exp != 0);
  // sprawdzenie, czy podstawa i wykładnik nie są jednocześnie zerowe
  //
  // wykonanie operacji na przesłanych argumentach
  printf("Dane z linii poleceń: %d^%d=%d\n", base, exp, power_int(base,exp));

  // koniec p. 5 -> p. 6 w funkcji power_int_rekur

  int i;
  for (i = 0; i < 10; ++i){
    printf("iteracyjnie:   \t%d^%d = %3d \t%d^%d = %6d\n",
	   2, i, power_int(2,i), -3, i, power_int(-3,i));
    
    // 4.1.a 
    printf("rekurencyjnie: \t%d^%d = %3d \t%d^%d = %6d\n",
            2, i, power_int_rekur(2,i), -3, i, power_int_rekur(-3,i));
    
  }

  int base_f=0, exp_f=0;
  // 7. wczytywanie argumentów z pliku (i ewentualny zapis do pliku)
  //
  // 7.a definicja wskaźnika do pliku
  FILE *file;
  // 7.b otwarcie pliku (sciezka np. ./dane.txt, tryb odczytu)
  file = fopen("./dane.txt", "r");
  if (file == NULL) {
    printf("Nie można otworzyć pliku.\n");
    exit(1);
  }
  // 7.c wczytanie argumentów z pliku
  fscanf(file, "%d %d", &base_f, &exp_f);
  // 7.d zamknięcie pliku
  fclose(file);
  // 7.e wykonanie operacji na argumentach
  printf("Dane z pliku: %d^%d=%d\n", base_f, exp_f, power_int(base_f, exp_f));

  // ewentualnie:
  // 7.g otwarcie pliku (tryb dopisywania)
  file = fopen("./dane.txt", "a");
  if (file == NULL) {
    printf("Nie można otworzyć pliku.\n");
    exit(1);
  }
  // 7.h dopisanie wyniku do pliku
  fprintf(file, "\nWynik: %d^%d=%d\n", base_f, exp_f, power_int(base_f, exp_f));
  // 7.i zamknięcie pliku
  fclose(file);

  // koniec p.7 ------------------------- 3.0 -------------------------
  
  return 0;
}

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base
int power_int(int base, int n)
{
  int i, p;
  p=1;
  for (i = 1; i <= n; ++i){
    p = p * base;
  }
  return p;
}

// obliczanie n-tej potegi (całkowitej) liczby całkowitej base w sposób rekurencyjny
int power_int_rekur(int m, int n){

  int potega=1;
  // 4.1 napisanie wersji rekurencyjnej dla funkcji obliczania potęgi
  // 4.2. umieszczenie wewnątrz funkcji makra assert sprawdzającego n>=0
  assert(n >= 0); // sprawdzenie, czy wykładnik jest liczbą dodatnią
  if (n == 0) {
      return 1;
  } else {
        return m * power_int_rekur(m, n - 1);
  }

  // 6. wprowadzenie zmiennej statycznej zliczającej liczbę wywołań funkcji power_int_rekur
  //
  // - definicja z inicjowaniem
  static int call_count = 0;
  // - zwiększanie wartości
  call_count++;
  // - wydruk informacyjny
  printf("Wywołanie nr %d funkcji power_int_rekur\n", call_count);
  //
  // koniec p. 6

  return(potega);
}
