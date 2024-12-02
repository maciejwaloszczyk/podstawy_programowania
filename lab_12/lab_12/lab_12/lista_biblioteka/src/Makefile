# SHELL = /bin/sh

# kompilator C
CC = gcc
# konsolidator (linker, loader) C
LD = gcc
# archiwizator (program do tworzenia bibliotek)
AR = ar -ru

# opcje kompilacji
# wersja do debugowania
CFL = -g -DMY_DEBUG
# wersja zoptymalizowana 
OPT = -O3
#opcje linkowania
LDFL = 
# katalogi z bibliotekami i dolaczane biblioteki
# biblioteki
LIB = -L../lib -llista_powiazana -lm
# katalogi z plikami naglowkowymi i  pliki naglowkowe 
INC = -I../include

OBJDIR = ../obj
BINDIR = ../bin

zabawa: $(OBJDIR)main.o
	$(LD) $(LDFL) -o $(BINDIR)zabawa $(OBJDIR)main.o $(LIB)
	make clean

$(OBJDIR)main.o: main.c include/lista_powiazana.h
	$(CC) $(CFL) $(INC) -c main.c -o $(OBJDIR)main.o $(INC)

clean:
	rm -f *.o zabawa
