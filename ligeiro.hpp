/*
 * ligeiro.hpp
 */

// Ligeiro (Classe derivada)

#ifndef LIGEIRO
#define LIGEIRO

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include "veiculo.hpp"

using namespace std;

class Ligeiro : public Veiculo{
    
	protected:
		int numPassageiros;
		list<Ligeiro> listaFicheiro;
		list<Ligeiro> listaVisivel;

	public:
		// Construtor
		Ligeiro();
		
		// Destrutor
		~Ligeiro();
		
		// Manipuladores
		void fixaInfoLigeiro(int, float, string, string, int, string, int, int);
		void lerFicheiro();
		void mostraInfoLigeiro();
		void filtrarPreco(int);
		void filtrarDisponibilidade();
		void filtrarTempo(int);
		void verificaId(int);
		void registarCarro(int);
		void guardar();
		
		// Seletores
		int devolveNumPassageiros();
		list<Ligeiro> devolveLista();
};
#endif
