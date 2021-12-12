/*
 * carrinha.hpp
 */

// Carrinha (Classe derivada)

#ifndef CARRINHA
#define CARRINHA

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include "veiculo.hpp"

using namespace std;

class Carrinha : public Veiculo{
	
	private:
		int cargaMax;
		list<Carrinha> listaFicheiro;
		list<Carrinha> listaVisivel;
		
	public:
		// Construtor
		Carrinha();
		
		// Destrutor
		~Carrinha();
		
		// Manipuladores
		void fixaInfoCarrinha(int, float, string, string, int, string, int, int);
		void lerFicheiro();
		void mostraInfoCarrinha();
		void filtrarPreco(int);
		void filtrarDisponibilidade();
		void filtrarTempo(int);
		void verificaId(int);
		void registarCarro(int);
		void guardar();
		
		// Seletores
		int devolveCargaMax();
		list<Carrinha> devolveLista();
};
#endif
