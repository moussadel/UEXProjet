CC=gcc
CFLAGS=-Wall -Werror -g -IHeader
ifdef L
CPPFLAGS=-DL=$(L) 
endif
ifdef C
CPPFLAGS=-DC=$(C) 
endif

SRCS=$(wildcard src/*.c)

OBJS=$(SRCS:.c=.o)
EXEC=bin/appli
DOXYGENDIR = Doxygen

all:$(EXEC)

doxygen:
	doxygen ./Doxyfile

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

.PHONY:clean,doxygen
clean:
	-rm -rf $(OBJS) $(EXEC) $(DOXYGENDIR)




	