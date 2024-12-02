#ifndef _LISTA_POWIAZANA_H_
#define _LISTA_POWIAZANA_H_

typedef struct element_listy* wsk_el_list;

typedef struct element_listy {
  char* nazwa_wezla;
  int klucz;
  wsk_el_list nastepny_wezel;
} el_list;

int wstaw_na_poczatek(el_list** Glowa_wsk, el_list* Element_wsk);
void drukuj_lista(el_list* Glowa);
int usun_lista(el_list** Glowa_wsk, el_list* Element_wsk);
el_list* wyszukaj_lista(el_list* Glowa, int klucz);

#endif // _LISTA_POWIAZANA_H_
