
CC=gcc
CFLAGS=-Wall -Werror -g
ifdef N
CPPFLAGS=-DN=$(N)
endif
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
EXEC=appli

all:$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

.PHONY:clean exec
clean:
	-rm $(OBJS)	
exec: clean
	-rm	$(EXEC)



	