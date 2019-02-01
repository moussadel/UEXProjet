
CC=gcc
CFLAGS=-Wall -Werror -g -Iinclude -Ilib_messages/include
LDFLAGS=-L lib_messages/lib -lmessages
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)
EXEC=bin/monpg

all:$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

.PHONY:clean exec
clean:
	-rm $(OBJS)
exec: clean
	-rm	$(EXEC)
