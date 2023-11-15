CC = gcc

CCFLAGS = -g -Wall -Wextra -c
COFLAGS = -g -Wall -Wextra -o

PROGRAMS = complex

$(PROGRAMS) : %: bin/%.o
	$(CC) $< $(COFLAGS) $@
# Rule that creates the executables of the programs in the list PROGRAMS

%.o : src/%.c include/%.h
	$(CC) $(CCFLAGS) $< -o bin/$@

%.o : src/%.c
	$(CC) $(CCFLAGS) $< -o bin/$@
# Rule that creates the binary file of yourfile.c into ./bin/yourfile.o
# To use, just type "make yourfile.o" and enter

clean : 
	rm -f bin/*.o
	rm -f $(PROGRAMS)