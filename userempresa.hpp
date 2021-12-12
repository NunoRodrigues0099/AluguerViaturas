/*
 * userempresa.hpp
 */

// UserEmpresa (Classe derivada)

#ifndef USEREMPRESA
#define USEREMPRESA

#include <iostream>
#include <string>
#include <stdio.h>
#include "utilizador.hpp"

using namespace std;

class UserEmpresa : public Utilizador{
	
	private:
		string funcao;
	
	public:
		// Construtor
		UserEmpresa();
		
		// Destrutor
		~UserEmpresa();
		
		// Manipuladores
		void fixaInfoUser(int,int,int,string,string);
		
		// Seletores
		string devolveFuncao();
};
#endif
