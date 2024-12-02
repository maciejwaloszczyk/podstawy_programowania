
#include <stdlib.h>
#include <stdio.h>
#include "lista_powiazana.h"

int wstaw_na_poczatek( /* funkcja zwraca kod sukcesu lub bledu */
  el_list** Glowa_wsk, /* lista - identyfikowana przez wskaznik */
  el_list* Element_wsk     /* wskaznik do elementu wstawianego na liste */
               )
{
  
  //printf("Glowa %lu, Element_wsk %lu\n", *Glowa_wsk, Element_wsk);
  
  Element_wsk->nastepny_wezel=*Glowa_wsk;
  *Glowa_wsk=Element_wsk;
  
  //printf("Glowa %lu, Element_wsk %lu\n", *Glowa_wsk, Element_wsk);
  return 0;
  
}

void drukuj_lista( /* funkcja zwraca kod sukcesu lub bledu */
  el_list* Glowa   /* lista - identyfikowana przez wskaznik */
           )
{
  el_list* Element_wsk=Glowa;
  printf("wydruk listy:   ");
  while(Element_wsk!=NULL){
    //printf("%s: ", Element_wsk->nazwa_wezla); // napis!
    printf("%d  , ", Element_wsk->klucz);
    Element_wsk = Element_wsk->nastepny_wezel;
  }
  printf("koniec\n");
}

int usun_lista(     /* procedura zwraca kod sukcesu lub bledu */
  el_list** Glowa_wsk,   /* lista - identyfikowana przez wskaznik */
  el_list*  Element_wsk  /* wskaznik do elementu usuwanego z listy */
            )
{
  
  if(*Glowa_wsk==Element_wsk){
    *Glowa_wsk=Element_wsk->nastepny_wezel;
  }
  else{
    el_list* poprzedni_wezel = *Glowa_wsk;
    while(poprzedni_wezel->nastepny_wezel != Element_wsk){
      poprzedni_wezel = poprzedni_wezel->nastepny_wezel;
    }
    poprzedni_wezel->nastepny_wezel = Element_wsk->nastepny_wezel;
  }
  return 0;
}


el_list* wyszukaj_lista( /* procedura zwraca wskaźnik do wyszukanego elementu */
  el_list* Glowa,   /* lista - identyfikowana przez wskaznik */
  int  klucz         /* in: klucz do wyszukiwania */
  )
{
  el_list* Element_wsk = Glowa;
  while(Element_wsk!=NULL){
    if(Element_wsk->klucz == klucz) break;
    Element_wsk = Element_wsk->nastepny_wezel;
  }
  return Element_wsk;
}
