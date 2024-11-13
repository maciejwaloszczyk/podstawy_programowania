#include <stdio.h>

// definicja typu strukturalnego (można podać obie postacie i korzystać później z jednej z nich)
// 3.a bez użycia typedef

// 3.b z użyciem typedef

// 5.1.a deklaracja funkcji fun_strukt

// 5.3.a deklaracja funkcji fun_strukt_out

// 5.5.a deklaracja funkcji fun_strukt_wsk

int main (void)
{

  // 4.1 definicja zmiennej (np. obiekt_1) typu strukturalnego

  // 4.2 nadanie wartości pól zmiennej obiekt_1 z pomocą operatora .

  // 4.3 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_1: ....", ....);

  // 5.2.1 wywołanie funkcji fun_strukt (po deklaracji w p. 5.1.a i definicji w p. 5.1.b)
  //      z obiektem 1 jako argumentem 

  // 5.2.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt - wartości pól obiekt_1: ....", ....);

  // 5.4.1 wywołanie funkcji fun_strukt_out (po deklaracji w p. 5.3.a i definicji w p. 5.3.b)
  //      z obiektem_1 jako argumentem i przepisaniem wyniku z powrotem do obiektu_1

  // 5.4.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
  //        printf("- wartości pól obiekt_1: ....", ....);

  
  // 4.4 definicja drugiej zmiennej typu strukturalnego  (np. obiekt_2)
  //    połączona z inicjowaniem za pomocą listy wartości

  // 4.5 definicja wskaźnika (np. obiekt_2_wsk) do struktury zainicjowanego adresem obiektu_2

  // 4.6 wypisanie wartości pól obiektu_2 z pomocą wskaźnika do obiektu i operatora ->
  //    np. printf("Początkowe wartości pól obiekt_2: ....", ....);

  // 5.6.1 wywołanie funkcji fun_strukt_wsk (po deklaracji w p. 5.5.a i definicji w p. 5.5.b)
  //      ze zmienną obiekt_2_wsk jako argumentem

  // 5.6.2 wypisanie wartości pól zmiennej obiekt_2 z pomocą wskaźnika do obiektu i operatora ->
  //    np. printf("Po wywołaniu fun_strukt_wsk - wartości pól obiekt_2: ....", ....);

  // 4.7 definicja trzeciej zmiennej typu strukturalnego  (np. obiekt_3)
  //    połączona z inicjowaniem za pomocą przepisania zawartości obiektu_2 w jednej
  //    operacji przypisania

  // 4.8 wypisanie wartości pól zmiennej obiekt_3 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_3: ....", ....);

  //-------------------------------- 3.0 ------------------------------------

  // 8. wywołanie funkcji fun_strukt_wsk_kopia (po odpowiedniej deklaracji i definicji)
  //    z adresem obiektu 3 jako argumentem oraz przypisanie (skopiowanie) zwracanej przez
  //    fun_strukt_wsk_kopia struktury (z całą zawartością) do nowej zmiennej obiekt_4
  //    zaprojektowanego typu w operacji inicjowania

  //    wypisanie wartości pól zmiennej obiekt_4 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_4: ....", ....);

  // 10. wywołanie funkcji fun_strukt_wsk_inout (po odpowiedniej deklaracji i definicji)
  //     z adresem obiektu 4 jako argumentem

  //    wypisanie wartości pól zmiennej obiekt_4 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt_wsk_inout - wartości pól obiekt_4: ....", ....);

  printf("Koniec programu.\n");
}

// 5.1.b definicja funkcji fun_strukt

//{

  // wypisanie wartości pól struktury przesłanej jako argument
  // np. printf("Wewnątrz fun_strukt - wartości pól obiektu argumentu: ...", ...);

  // modyfikacja wartości pól struktury

  // wypisanie zmodyfikowanych wartości pól struktury 
  // np. printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu: ...", ...);

//}


// 5.3.b definicja funkcji fun_strukt_out

//{

  // wypisanie wartości pól struktury przesłanej jako argument

  // modyfikacja wartości pól struktury

  // wypisanie zmodyfikowanych wartości pól struktury 

  // zwrócenie struktury ze zmodyfikowanymi wartościami pól do funkcji wywołującej

//}


// 5.5.b definicja funkcji fun_strukt_wsk

//{

  // wypisanie wartości pól struktury wskaźnik do której został przesłany jako argument

  // modyfikacja wartości pól struktury

  // wypisanie zmodyfikowanych wartości pól struktury 

//}

