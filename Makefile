# Makefile para os programas dos apontamentos
CC		= g++
FLAGS	= -lm

.PHONY: clean all

all: sim

clean: 
	-rm *.o sim
	
sim: sim.cpp utilizador.o userparticular.o userempresa.o veiculo.o carrinha.o ligeiro.o caravana.o aluguer.o func_aux.o
	$(CC) -o $@ $@.cpp utilizador.o userparticular.o userempresa.o veiculo.o carrinha.o ligeiro.o caravana.o aluguer.o func_aux.o
