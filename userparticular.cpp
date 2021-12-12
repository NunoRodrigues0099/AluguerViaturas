/* 
 * userparticular.cpp
 */

#include <iostream>
#include <stdexcept> 
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include "utilizador.hpp"
#include "userparticular.hpp"

using namespace std;


UserParticular::UserParticular() : Utilizador(){};	//Construtor

UserParticular::~UserParticular(){};				//Destrutor

/* O módulo fixa a informação do utilizador particular
 * ---> todos os dados do UserParticular
 * <---
 */
void UserParticular::fixaInfoUser(int _id, int _nif, int _contacto, string _nome, int _idade, int _cc){
	id = _id;
	nif = _nif;
	contacto = _contacto;
	nome = _nome;
	idade = _idade;
	cc = _cc;
};

/* O módulo devolve a idade 
 * ---> 
 * <--- idade
 */
int UserParticular::devolveIdade(){
	return (idade);
};

/* O módulo devolve o CC 
 * ---> 
 * <--- cc
 */
int UserParticular::devolveCc(){
	return (cc);
};
