/*
 * veiculo.cpp
 */

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "veiculo.hpp"

using namespace std;

Veiculo::Veiculo(){};		//Construtor

Veiculo::~Veiculo(){};		//Destrutor

/* O módulo fixa a informação de um veiculo introduzido
 * ---> todos os dados do veiculo
 * <---
 */
void Veiculo::fixaInfoVeiculo(int _id, float _preco, string _marca, string _modelo, int _ccv, string _estado, int _tempo){
	id = _id;
	preco = _preco;
	marca = _marca;
	modelo = _modelo;
	ccv = _ccv;
	estado = _estado;
	tempo = _tempo;
};

/* O módulo devolve o ID do carro 
 * ---> 
 * <--- id
 */
int Veiculo::devolveId(){
	return (id);
};

/* O módulo devolve o Preço 
 * ---> 
 * <--- preco
 */
float Veiculo::devolvePreco(){
	return (preco);
};

/* O módulo devolve a marca 
 * ---> 
 * <--- marca
 */
string Veiculo::devolveMarca(){
	return (marca);
};

/* O módulo devolve o modelo 
 * ---> 
 * <--- modelo
 */
string Veiculo::devolveModelo(){
	return (modelo);
};

/* O módulo devolve o nº de cavalos 
 * ---> 
 * <--- ccv
 */
int Veiculo::devolveCcv(){
	return (ccv);
};

/* O módulo devolve o estado do veículo 
 * ---> 
 * <--- estado
 */
string Veiculo::devolveEstado(){
	return (estado);
};

/* O módulo devolve o tempo em que o veículo está disponível
 * ---> 
 * <--- tempo
 */
int Veiculo::devolveTempo(){
	return (tempo);
};
