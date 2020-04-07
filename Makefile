CC = gcc
CFLAGS = -g -Wall
TARGETS = main
DTARGETS = main_debug

OBJECTS = main.c hospital.o
.SUFFIXES = .c .o
n_debug : $(TARGETS)
n_debug : DEBUGOPTION = -DNDEBUG 
debug : $(DTARGETS)
debug : DEBUGOPTION = -DDEBUG

$(TARGETS) : $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUGOPTION) -o $@ $^
.c.o :
	$(CC) $(CFLAGS) $(DEBUGOPTION) -c $<

$(DTARGETS) : $(OBJECTS)
	$(CC) $(CFLAGS) $(DEBUGOPTION) -o $@ $^

clean :
	rm *.o $(TARGETS)


dclean :
	rm *.o $(DTARGETS)
touch :
	touch hospital.c
