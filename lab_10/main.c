#include <stdio.h>
#include <string.h>

// 3.a bez użycia typedef
typedef struct {
    char nazwa[50];        
    char marka[20];
    char model[20];
    char rodzina[20];
    char najnizszy_dzwiek[3];
    char najwyzszy_dzwiek[3];
    int rok_produkcji;    

    int liczba_strun;    
    _Bool ma_smyczek;
    
    int liczba_tlokow;
    _Bool ma_suwak;

} Instrument;

// 3.b z użyciem typedef
struct UtworMuzyczny {
    char tytul[50];        
    char kompozytor[50];    
    char wydawca[50];
    int rok_wydania;
    char gatunek[20];      
    char epoka[20];
};

// 5.1.a deklaracja funkcji fun_strukt
void fun_strukt(Instrument *instr) {
    strcpy(instr->nazwa, "Trąbka z kwartwentylem in C");
    strcpy(instr->marka, "Yamaha");
    strcpy(instr->model, "9C-Q");
    strcpy(instr->rodzina, "Dęte blaszane");
    strcpy(instr->najnizszy_dzwiek, "a");
    strcpy(instr->najwyzszy_dzwiek, "d3");
    instr->rok_produkcji = 2023;
    instr->ma_smyczek = 0;
    instr->liczba_tlokow = 4;
    instr->ma_suwak = 0;

    printf("\nZmodyfikowane wartości pól instrumentu:\n");
    printf("Nazwa: %s\n", instr->nazwa);
    printf("Marka: %s\n", instr->marka);
    printf("Model: %s\n", instr->model);
    printf("Rodzina: %s\n", instr->rodzina);
    printf("Najniższy dźwięk: %s\n", instr->najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instr->najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instr->rok_produkcji);
    printf("Ma smyczek: %d\n", instr->ma_smyczek);
    printf("Liczba tłoków: %d\n", instr->liczba_tlokow);
    printf("Ma suwak: %d\n", instr->ma_suwak);
}

// 5.3.a deklaracja funkcji fun_strukt_out
Instrument fun_strukt_out(Instrument instr) {
    strcpy(instr.nazwa, "Fortepian");
    strcpy(instr.marka, "Steinway & Sons");
    strcpy(instr.model, "D-274");
    strcpy(instr.rodzina, "Strunowe uderzane");
    strcpy(instr.najnizszy_dzwiek, "A2");
    strcpy(instr.najwyzszy_dzwiek, "c5");
    instr.rok_produkcji = 1999;
    instr.liczba_strun = 243;
    instr.ma_smyczek = 0;
    instr.liczba_tlokow = 0;
    instr.ma_suwak = 0;

    printf("\nZmodyfikowane wartości pól instrumentu w fun_strukt_out:\n");
    printf("Nazwa: %s\n", instr.nazwa);
    printf("Marka: %s\n", instr.marka);
    printf("Model: %s\n", instr.model);
    printf("Rodzina: %s\n", instr.rodzina);
    printf("Najniższy dźwięk: %s\n", instr.najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instr.najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instr.rok_produkcji);
    printf("Ma smyczek: %d\n", instr.ma_smyczek);
    printf("Liczba tłoków: %d\n", instr.liczba_tlokow);
    printf("Ma suwak: %d\n", instr.ma_suwak);

    return instr;
}

// 5.5.a deklaracja funkcji fun_strukt_wsk
void fun_strukt_wsk(Instrument *instr) {
    strcpy(instr->nazwa, "Skrzypce");
    strcpy(instr->marka, "Stradivari");
    strcpy(instr->model, "1715");
    strcpy(instr->rodzina, "Smyczkowe");
    strcpy(instr->najnizszy_dzwiek, "G3");
    strcpy(instr->najwyzszy_dzwiek, "E7");
    instr->rok_produkcji = 1715;
    instr->liczba_strun = 4;
    instr->ma_smyczek = 1;
    instr->liczba_tlokow = 0;
    instr->ma_suwak = 0;

    printf("\nZmodyfikowane wartości pól instrumentu w fun_strukt_wsk:\n");
    printf("Nazwa: %s\n", instr->nazwa);
    printf("Marka: %s\n", instr->marka);
    printf("Model: %s\n", instr->model);
    printf("Rodzina: %s\n", instr->rodzina);
    printf("Najniższy dźwięk: %s\n", instr->najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instr->najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instr->rok_produkcji);
    printf("Liczba strun: %d\n", instr->liczba_strun);
    printf("Ma smyczek: %d\n", instr->ma_smyczek);
    printf("Liczba tłoków: %d\n", instr->liczba_tlokow);
    printf("Ma suwak: %d\n", instr->ma_suwak);
}

int main() {
    
    // 4.1 definicja zmiennej (np. obiekt_1) typu strukturalnego
    Instrument instrument1;

    strcpy(instrument1.nazwa, "Trąbka");
    strcpy(instrument1.marka, "Vincent Bach");
    strcpy(instrument1.model, "Stradivarius 43B");
    strcpy(instrument1.rodzina, "Strunowe");
    strcpy(instrument1.najnizszy_dzwiek, "g");
    strcpy(instrument1.najwyzszy_dzwiek, "c3");

    // 4.2 nadanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    instrument1.rok_produkcji = 2024;    
    instrument1.ma_smyczek = 0;
    instrument1.liczba_tlokow = 3;
    instrument1.ma_suwak = 0;

    // 4.3 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    printf("Początkowe wartości pól instrument1:\n");
    printf("Nazwa: %s\n", instrument1.nazwa);
    printf("Marka: %s\n", instrument1.marka);
    printf("Model: %s\n", instrument1.model);
    printf("Rodzina: %s\n", instrument1.rodzina);
    printf("Najniższy dźwięk: %s\n", instrument1.najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instrument1.najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instrument1.rok_produkcji);
    printf("Ma smyczek: %d\n", instrument1.ma_smyczek);
    printf("Liczba tłoków: %d\n", instrument1.liczba_tlokow);
    printf("Ma suwak: %d\n", instrument1.ma_suwak);
    
    // 5.2.1 wywołanie funkcji fun_strukt (po deklaracji w p. 5.1.a i definicji w p. 5.1.b)
    fun_strukt(&instrument1);
    
    // 5.2.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
    instrument1 = fun_strukt_out(instrument1);

    // 4.4 definicja drugiej zmiennej typu strukturalnego  (np. obiekt_2)
    struct UtworMuzyczny utwor1 = {
        "Symfonia fantastyczna",
        "Hector Berlioz",
        "Breitkopf & Härtel",
        1830,
        "Symfonia",
        "Romantyzm"
    };

    // 4.5 definicja wskaźnika (np. obiekt_2_wsk) do struktury zainicjowanego adresem obiektu_2
    struct UtworMuzyczny *wsk_utwor1 = &utwor1;

    // 4.6 wypisanie wartości pól obiektu_2 z pomocą wskaźnika do obiektu i operatora ->
    printf("\nWartości pól utwor1 przez wskaźnik:\n");
    printf("Tytuł: %s\n", wsk_utwor1->tytul);
    printf("Kompozytor: %s\n", wsk_utwor1->kompozytor);
    printf("Wydawca: %s\n", wsk_utwor1->wydawca);
    printf("Rok wydania: %d\n", wsk_utwor1->rok_wydania);
    printf("Gatunek: %s\n", wsk_utwor1->gatunek);
    printf("Epoka: %s\n", wsk_utwor1->epoka);

    // 5.6.1 wywołanie funkcji fun_strukt_wsk (po deklaracji w p. 5.5.a i definicji w p. 5.5.b)
    fun_strukt_wsk(&instrument1);

    // 5.6.2 wypisanie wartości pól zmiennej obiekt_2 z pomocą wskaźnika do obiektu i operatora ->
    printf("\nWartości pól instrument1 po powrocie z fun_strukt_wsk:\n");
    printf("Nazwa: %s\n", instrument1.nazwa);
    printf("Marka: %s\n", instrument1.marka);
    printf("Model: %s\n", instrument1.model);
    printf("Rodzina: %s\n", instrument1.rodzina);
    printf("Najniższy dźwięk: %s\n", instrument1.najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instrument1.najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instrument1.rok_produkcji);
    printf("Liczba strun: %d\n", instrument1.liczba_strun);
    printf("Ma smyczek: %d\n", instrument1.ma_smyczek);
    printf("Liczba tłoków: %d\n", instrument1.liczba_tlokow);
    printf("Ma suwak: %d\n", instrument1.ma_suwak);
    
    // 4.7 definicja trzeciej zmiennej typu strukturalnego  (np. obiekt_3)
    struct UtworMuzyczny utwor2 = utwor1;

    // 4.8 wypisanie wartości pól zmiennej obiekt_3 z pomocą operatora .
    printf("\nWartości pól utwor2:\n");
    printf("Tytuł: %s\n", utwor2.tytul);
    printf("Kompozytor: %s\n", utwor2.kompozytor);
    printf("Wydawca: %s\n", utwor2.wydawca);
    printf("Rok wydania: %d\n", utwor2.rok_wydania);
    printf("Gatunek: %s\n", utwor2.gatunek);
    printf("Epoka: %s\n", utwor2.epoka);

    return 0;
}