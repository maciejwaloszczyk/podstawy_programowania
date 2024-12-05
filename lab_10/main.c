#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//7.1 Zaprojektowanie nowego typu strukturalnego zawierającej pola, pośród których znajduje się tablica znaków
#define N 5

typedef struct {
    double d;
    char tab_c[N];
    int m;
} NewStruct;

void check_sizeof() {
    for (int i = 1; i <= 5; i++) {
        printf("Rozmiar struktury dla N = %d: %zu bajtów\n", i, sizeof(NewStruct));
    }
}

//Wyrównanie adresów (address alignment) polega na umieszczaniu zmiennych w pamięci na adresach, które są wielokrotnością pewnej liczby (zwykle rozmiaru typu danych). Dla przykładu, zmienna typu 'double' (8 bajtów) będzie wyrównana do adresu będącego wielokrotnością 8. Wyrównanie to jest wymagane przez architekturę procesora, aby zapewnić efektywny dostęp do pamięci.
//W przypadku naszej struktury, wyrównanie powoduje, że pola są umieszczane w pamięci w taki sposób, aby każde pole zaczynało się na odpowiednio wyrównanym adresie. To może prowadzić do dodania tzw. paddingu (wypełnienia) między polami, co zwiększa całkowity rozmiar struktury.

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Wyjaśnienie:
// W strukturze pole nie może być zmienną tego samego typu, ponieważ prowadziłoby to do nieskończonej rekursji w alokacji pamięci.
// Jednak pole może być wskaźnikiem do tego samego typu, co pozwala na tworzenie powiązanych struktur danych, takich jak listy powiązane.

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

// 6.1 fun_strukt_wsk_out, która przyjmuje jako argument strukturę zaprojektowanego typu i zwraca wskaźnik do struktury tego typu
Instrument* fun_strukt_wsk_out(Instrument *instr) {
    Instrument *new_instr = (Instrument *)malloc(sizeof(Instrument));
    if (new_instr == NULL) {
        printf("Błąd alokacji pamięci!\n");
        exit(1);
    }

    strcpy(new_instr->nazwa, instr->nazwa);
    strcpy(new_instr->marka, instr->marka);
    strcpy(new_instr->model, instr->model);
    strcpy(new_instr->rodzina, instr->rodzina);
    strcpy(new_instr->najnizszy_dzwiek, instr->najnizszy_dzwiek);
    strcpy(new_instr->najwyzszy_dzwiek, instr->najwyzszy_dzwiek);
    new_instr->rok_produkcji = instr->rok_produkcji;
    new_instr->liczba_strun = instr->liczba_strun;
    new_instr->ma_smyczek = instr->ma_smyczek;
    new_instr->liczba_tlokow = instr->liczba_tlokow;
    new_instr->ma_suwak = instr->ma_suwak;

    printf("Rozmiar struktury Instrument: %zu bajtów\n", sizeof(Instrument));

    return new_instr;
}
// 6.2 fun_strukt_wsk_out, która przyjmuje jako argument strukturę zaprojektowanego typu i zwraca wskaźnik do struktury tego typu
void fun_strukt_wsk_inout(Instrument *instr) {
    Instrument local_instr = *instr;

    strcpy(local_instr.nazwa, "Gitara");
    strcpy(local_instr.marka, "Fender");
    strcpy(local_instr.model, "Stratocaster");
    strcpy(local_instr.rodzina, "Strunowe szarpane");
    strcpy(local_instr.najnizszy_dzwiek, "E2");
    strcpy(local_instr.najwyzszy_dzwiek, "E6");
    local_instr.rok_produkcji = 2021;
    local_instr.liczba_strun = 6;
    local_instr.ma_smyczek = 0;
    local_instr.liczba_tlokow = 0;
    local_instr.ma_suwak = 0;

    printf("\nZmodyfikowane wartości pól lokalnej kopii instrumentu w fun_strukt_wsk_inout:\n");
    printf("Nazwa: %s\n", local_instr.nazwa);
    printf("Marka: %s\n", local_instr.marka);
    printf("Model: %s\n", local_instr.model);
    printf("Rodzina: %s\n", local_instr.rodzina);
    printf("Najniższy dźwięk: %s\n", local_instr.najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", local_instr.najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", local_instr.rok_produkcji);
    printf("Liczba strun: %d\n", local_instr.liczba_strun);
    printf("Ma smyczek: %d\n", local_instr.ma_smyczek);
    printf("Liczba tłoków: %d\n", local_instr.liczba_tlokow);
    printf("Ma suwak: %d\n", local_instr.ma_suwak);

    *instr = local_instr;
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

    // 6.4 wywołanie funkcji
    Instrument instrument2 = instrument1;

    printf("\nPoczątkowe wartości pól instrument2:\n");
    printf("Nazwa: %s\n", instrument2.nazwa);
    printf("Marka: %s\n", instrument2.marka);
    printf("Model: %s\n", instrument2.model);
    printf("Rodzina: %s\n", instrument2.rodzina);
    printf("Najniższy dźwięk: %s\n", instrument2.najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instrument2.najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instrument2.rok_produkcji);
    printf("Liczba strun: %d\n", instrument2.liczba_strun);
    printf("Ma smyczek: %d\n", instrument2.ma_smyczek);
    printf("Liczba tłoków: %d\n", instrument2.liczba_tlokow);
    printf("Ma suwak: %d\n", instrument2.ma_suwak);

    fun_strukt_wsk_inout(&instrument2);

    printf("\nWartości pól instrument2 po powrocie z fun_strukt_wsk_inout:\n");
    printf("Nazwa: %s\n", instrument2.nazwa);
    printf("Marka: %s\n", instrument2.marka);
    printf("Model: %s\n", instrument2.model);
    printf("Rodzina: %s\n", instrument2.rodzina);
    printf("Najniższy dźwięk: %s\n", instrument2.najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instrument2.najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instrument2.rok_produkcji);
    printf("Liczba strun: %d\n", instrument2.liczba_strun);
    printf("Ma smyczek: %d\n", instrument2.ma_smyczek);
    printf("Liczba tłoków: %d\n", instrument2.liczba_tlokow);
    printf("Ma suwak: %d\n", instrument2.ma_suwak);

    // 8. wywołanie funkcji fun_strukt_wsk_kopia (po odpowiedniej deklaracji i definicji)
    Instrument *instrument3 = fun_strukt_wsk_out(&instrument1);

    printf("\nWartości pól instrument3 po powrocie z fun_strukt_wsk_out:\n");
    printf("Nazwa: %s\n", instrument3->nazwa);
    printf("Marka: %s\n", instrument3->marka);
    printf("Model: %s\n", instrument3->model);
    printf("Rodzina: %s\n", instrument3->rodzina);
    printf("Najniższy dźwięk: %s\n", instrument3->najnizszy_dzwiek);
    printf("Najwyższy dźwięk: %s\n", instrument3->najwyzszy_dzwiek);
    printf("Rok produkcji: %d\n", instrument3->rok_produkcji);
    printf("Liczba strun: %d\n", instrument3->liczba_strun);
    printf("Ma smyczek: %d\n", instrument3->ma_smyczek);
    printf("Liczba tłoków: %d\n", instrument3->liczba_tlokow);
    printf("Ma suwak: %d\n", instrument3->ma_suwak);

    free(instrument3);

    typedef struct {
        double d;
        char tab_c[N];
        int m;
    } NewStruct;

    NewStruct newStructInstance;
    newStructInstance.d = 3.14;
    strcpy(newStructInstance.tab_c, "test");
    newStructInstance.m = 42;

    printf("\nWartości pól newStructInstance:\n");
    printf("Double: %f\n", newStructInstance.d);
    printf("Tablica znaków: %s\n", newStructInstance.tab_c);
    printf("Integer: %d\n", newStructInstance.m);

    return 0;
}
