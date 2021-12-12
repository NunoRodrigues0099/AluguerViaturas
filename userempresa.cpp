/*
 * userempresa.cpp
 */
 
#include <iostream>
#include <stdexcept> 
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include "utilizador.hpp"
#include "userempresa.hpp"

using namespace std;

UserEmpresa::UserEmpresa() : Utilizador(){};	//Construtor

UserEmpresa::~UserEmpresa(){};					//Destrutor

/* O módulo fixa a informação do Utilizador Empresas
 * ---> todos os dados do UsrEmpresa
 * <---
 */
void UserEmpresa::fixaInfoUser(int _id, int _nif, int _contacto, string _nome, string _funcao){
	id = _id;
	nif = _nif;
	contacto = _contacto;
	nome = _nome;
	funcao = _funcao;
};

/* O módulo devolve a função do trabalhador 
 * ---> 
 * <--- funcao
 */
string UserEmpresa::devolveFuncao(){
	return (funcao);
};
