# AUTHORS : TAN Philippe
#           GOGRITCHIANI Lasha
#           CHEN Virginie


# déclaration de variables
# le compilateur
CC = gcc
# les options de compilateur
#-fsanitize=address
CCFLAGS = -g  -Wall -Wextra -c
COFLAGS = -g  -Wall -Wextra -o
# liste des programme à créer 
PROGRAMS = main

# premiere regle : liste des programme à compiler
# règle sans action, seulement avec des dépendances 
all : $(PROGRAMS)
# règle pour compiler le main
# il faut mettre tous les noms des fichiers .o dans les dépendances
main : main.o  complex.o polynom.o
	$(CC) $(COFLAGS) main bin/*.o -lm
main.o :   src/main.c include/*.h
	$(CC) $(CCFLAGS) src/main.c -o bin/main.o
# règle générique de compilation des .o à partir des .c
%.o : src/%.c 
	$(CC) $(CCFLAGS) $< -o bin/$@
# effacer les .o et les executables 
# pour executer cette regle il faut taper dans le termnal "make clean"
clean : 
	rm -f bin/*.o
	rm $(PROGRAMS)