/*
 * caravana.hpp
 */

// Caravana (Classe derivada)

#ifndef CARAVANA
#define CARAVANA

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include "veiculo.hpp"

using namespace std;

class Caravana : public Veiculo{
    
	protected:
		int qtCamas;
		list<Caravana> listaFicheiro;
		list<Caravana> listaVisivel;
		
	public:
		// Construtor
		Caravana();
		
		// Destrutor
		~Caravana();
		
		// Manipulador
		void fixaInfoCaravana(int, float, string, string, int, string, int, int);
		void lerFicheiro();
		void mostraInfoCaravana();
		void filtrarPreco(int);
		void filtrarDisponibilidade();
		void filtrarTempo(int);
		void verificaId(int);
		void registarCarro(int);
		void guardar();
		
		// Seletores
		int devolveQtCamas();
		list<Caravana> devolveLista();
};
#endif
