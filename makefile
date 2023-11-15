CC = gcc

CCFLAGS = -g -Wall -Wextra -c
COFLAGS = -g -Wall -Wextra -o

PROGRAMS = fft

fft : fft.c
	$(CC) $< $(COFLAGS) fft

%.o : src/%.c 
	$(CC) $(CCFLAGS) $< -o /bin/$@

clean : 
	rm -f *.o
	rm -f $(PROGRAMS)