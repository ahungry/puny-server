# -*- mode: makefile; -*-

NAME=puny-server

CC?=gcc

CFLAGS=-Wall -std=gnu99
LDFLAGS=-pthread

EXE=$(NAME).bin

src = *.c
objects = $(patsubst %.c,%.o,$(src))

all: $(EXE)

$(EXE): $(objects)
	$(info Linking object $< for $@)
	$(CC) $(LDFLAGS) $< -o $@

%.o : %.c
	$(info Processing source $<)
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c,%.o,$<)

clean:
	-rm *.o
	-rm $(EXE)
