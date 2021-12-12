/*
 * userparticular.hpp
 */

// UserParticular (Classe derivada)

#ifndef USERPARTICULAR
#define USERPARTICULAR

#include <iostream>
#include <string>
#include <stdio.h>
#include "utilizador.hpp"

using namespace std;

class UserParticular : public Utilizador{
	
	private:
		int idade;
		int cc;
	
	public:
		// Construtor
		UserParticular();
		
		// Destrutor
		~UserParticular();
		
		// Manipuladores
		void fixaInfoUser(int,int,int,string,int,int);
		
		// Seletores
		int devolveIdade();
		int devolveCc();
};
#endif
