# -*- mode: makefile; -*-

NAME=puny-server

CC?=gcc

CFLAGS=-Wall -std=gnu99 -fPIC
LDFLAGS=-pthread

EXE=$(NAME).bin
SO=lib$(NAME).so
SO_EXE=$(NAME).so.bin

src = puny-server.c main.c
objects = $(patsubst %.c,%.o,$(src))

all: $(EXE) $(SO_EXE)

$(EXE): $(objects)
	$(info Linking object $< for $@)
	$(CC) $(objects) -o $@ $(LDFLAGS)

$(SO): $(objects)
	$(info Creating shared objects $< for $@)
	$(CC) -shared $(objects) -o $@ $(LDFLAGS)

$(SO_EXE): $(SO)
	$(info Linking binary to shared object $< for $@)
	$(CC) main.c -o $@ $(LDFLAGS) -L. -lpuny-server

%.o : %.c
	$(info Processing source $<)
	$(CC) $(CFLAGS) -c $< -o $(patsubst %.c,%.o,$<)

clean:
	@-rm -fr *.o
	@-rm -fr *.coff
	@-rm -fr *.bin
	@-rm -fr *.exe
	@-rm -fr *.so
	@-rm -fr *.dll
