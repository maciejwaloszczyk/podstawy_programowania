
#include <stdio.h>
#include <stdlib.h>
#include "../include/lista_powiazana.h"
int main ()
{
  
  printf("\nZabawa z listą\n");
  printf(" - naciśnięcie klawisza ENTER powoduje zmianę listy\n");
  printf(" - CTRL+C kończy program\n");

  el_list* Glowa = NULL;

  int k=0;
  for(;;){

    getchar();
    if(drand48()<0.5) {

      el_list* element_wsk = malloc(sizeof(el_list));
      
      element_wsk->nazwa_wezla = malloc( 100*sizeof(char) );
      //element_wsk->nazwa_wezla = "Wezel";
      k++;
      sprintf(element_wsk->nazwa_wezla, "Węzeł %d", k);
      element_wsk->klucz = 10*drand48();
      element_wsk->nastepny_wezel = NULL;
      
      wstaw_na_poczatek(&Glowa, element_wsk);
      printf("wstawione - %d :  ", element_wsk->klucz);
      drukuj_lista(Glowa);
      
    }
    else {

      int j=10*drand48();
      el_list* Element_wsk = wyszukaj_lista(Glowa, j);
      printf("klucz %d",j);
      if(Element_wsk!=NULL) printf(" znaleziony !\n");
      else printf(" nie znaleziony\n");
      if(Element_wsk!=NULL) {
    usun_lista(&Glowa, Element_wsk);
    printf("po usunięciu :  ");
    drukuj_lista(Glowa);
    free(Element_wsk); // co stanie się jeśli nie będziemy pamiętac o zwolnieniu pamięci?
      }
    }
  }
  

}
