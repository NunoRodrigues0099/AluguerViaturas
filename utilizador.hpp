/*
 * utilizador.hpp
 */

// Utilizador (Classe de Base)

#ifndef UTILIZADOR
#define UTILIZADOR

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Utilizador{

	protected:
		int id;
		int nif;
		int contacto;
		string nome;
	
	public:
		// Construtor
		Utilizador();
		
		// Destrutor
		~Utilizador();
		
		// Seletores
		int devolveId();
		int devolveNif();
		int devolveContacto();
		string devolveNome();
};
#endif
