CC=gcc
CFLAGS=-Wall
ifdef N
CPPFLAGS=-DN=$(N)
endif
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
EXEC=main

all:$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

clean:
	-rm $(OBJS)
