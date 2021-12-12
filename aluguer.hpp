/*
 * aluguer.hpp
 */

#ifndef ALUGUER
#define ALUGUER

#include <iostream>
#include <string>
#include "utilizador.hpp"
#include "veiculo.hpp"
#include "carrinha.hpp"
#include "ligeiro.hpp"
#include "caravana.hpp"
#include <list>

using namespace std;

class Aluguer{

	private:
		int idAlug = 0;
		int idCarro;
		list<Aluguer> alugueres;
		string tipo;
	
	public:
		// Construtores
		Aluguer();
		~Aluguer();
		
		// Manipuladores
		void fixaInfoAlug(int, int, string);
		void criarFileAluguer();
		void adicionarAluguer(int, list<Carrinha>, list<Ligeiro>, list<Caravana>);
		void lerFicheiroAluguer();
		void mostraInfoAlug();
};
#endif
