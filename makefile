CC = gcc

CCFLAGS = -g -Wall -Wextra -c
COFLAGS = -g -Wall -Wextra -o

PROGRAMS = complex

$(PROGRAMS) : %: bin/%.o
	$(CC) $< $(COFLAGS) $@

bin/%.o : src/%.c include/%.h
	$(CC) $(CCFLAGS) $< -o $@

bin/%.o : src/%.c
	$(CC) $(CCFLAGS) $< -o $@

clean : 
	rm -f bin/*.o
	rm -f $(PROGRAMS)