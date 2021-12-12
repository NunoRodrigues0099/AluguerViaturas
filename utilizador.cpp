/* 
 * utilizador.cpp 
 */

#include <iostream>
#include <stdexcept> 
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include "utilizador.hpp"

using namespace std;

Utilizador::Utilizador(){};		//Construtor

Utilizador::~Utilizador(){};	//Destrutor

// Manipuladores

/* O módulo devolve o ID 
 * ---> 
 * <--- id
 */
int Utilizador::devolveId(){
	return (id);
};

/* O módulo devolve o NIF 
 * ---> 
 * <--- nif
 */
int Utilizador::devolveNif(){
	return (nif);
};

/* O módulo devolve o Contacto 
 * ---> 
 * <--- contacto
 */
int Utilizador::devolveContacto(){
	return (contacto);
};

/* O módulo devolve o Nome 
 * ---> 
 * <--- nome
 */
string Utilizador::devolveNome(){
	return (nome);
};
