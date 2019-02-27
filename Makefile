CC=wllvm
CFLAGS=-Wall -g -IHeader -ILibMessages/Header -I $(KLEE)/include 
LDFLAGS=-L LibMessages/lib
LDLIBS=-lMessages

#ifdef L
#CPPFLAGS=-DL=$(L)
#endif
#ifdef C
#CPPFLAGS=-DC=$(C)
#endif

SRCS=$(wildcard src/*.c)

OBJS=$(SRCS:.c=.o)
EXEC=bin/appli
DOXYGENDIR = Doxygen

all:$(EXEC) $(EXEC).bc

$(EXEC) : LibMessages.a

$(EXEC).bc : $(EXEC)
	extract-bc $<

LibMessages.so: src/Messages.c
	$(CC) -fPIC -c src/Messages.c
	$(CC) -shared -o LibMessages/lib/LibMessages.so src/Messages.o

LibMessages.a: src/Messages.o
	$(AR) cr $@ $+

doxygen:
	doxygen ./Doxyfile

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

.PHONY:clean,doxygen
clean:
	-rm -rf $(OBJS) $(EXEC) $(DOXYGENDIR) 

