/*
 * carrinha.cpp
 */

#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "veiculo.hpp"
#include "carrinha.hpp"

using namespace std;

Carrinha::Carrinha() : Veiculo(){};		//Construtor

Carrinha::~Carrinha(){};				//Destrutor

/* O módulo fixa a informação das carrinhas de transporte ligeiro
 * ---> todos os dados das carrinhas de transporte ligeiro
 * <---
 */
void Carrinha::fixaInfoCarrinha(int _id, float _preco, string _marca, string _modelo, int _ccv, string _estado, int _tempo, int _cargaMax){
	id = _id;
	preco = _preco;
	marca = _marca;
	modelo = _modelo;
	ccv = _ccv;
	estado = _estado;
	tempo = _tempo;
	cargaMax = _cargaMax;
};

/* O módulo lê o ficheiro "carrinhas.txt" e guarda os
 * dados numa lista de carrinhas
 * --->
 * <---
 */
void Carrinha::lerFicheiro(){
	ifstream arquivo("carrinhas.txt");
	Carrinha c;
	if (arquivo.is_open()){
		string line;
		while(getline(arquivo,line)){
			stringstream ss(line);
			string _id, _preco, _marca, _modelo, _ccv, _estado, _tempo, _cargaMax;
			
			getline(ss,_id,',');
				id = stoi(_id);
			getline(ss,_preco,',');
				preco = stof(_preco);
			getline(ss,_marca,',');
				marca = _marca;
			getline(ss,_modelo,',');
				modelo = _modelo;
			getline(ss,_ccv,',');
				ccv = stoi(_ccv);
			getline(ss,_estado,',');
				estado = _estado;
			getline(ss,_tempo,',');
				tempo = stoi(_tempo);
			getline(ss,_cargaMax,',');
				cargaMax = stoi(_cargaMax);
			
			vector <string> enrolled;
			string course;
			while (getline(ss,course,',')){
				enrolled.push_back(course);
				cout << ",\"" << course << "\"";
			}
			c.fixaInfoCarrinha(id,preco,marca,modelo,ccv,estado,tempo,cargaMax);
			listaFicheiro.push_back(c);
			listaVisivel.push_back(c);
			cout << "\n";
		}
		arquivo.close();
	}
	else{
		cout<<"\nErro ao abrir ficheiro!\n";
		exit(0);
	}
};

/* O módulo mostra toda a informação presente
 * na lista Visivel das carrinhas
 * ---> 
 * <--- print de todos as informações
 */
void Carrinha::mostraInfoCarrinha(){
	list<Carrinha>::iterator it;
	cout << "ID\tPreço\tMarca\tModelo\tCv\tEstado\t\tTempo\tCarga Máx\n";
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		cout << it->id << "\t" << it->preco << "\t" << it->marca << "\t" << it->modelo << "\t" << it->ccv << "\t" << it->estado << "\t" << it->tempo << "\t" << it->cargaMax << "\n";
	}
};

/* O módulo filtra as carrinhas consoante o preço inserido
 * ---> preco máximo que o utilizador quer pagar
 * <---
 */
void Carrinha::filtrarPreco(int _preco){
	list<Carrinha>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (_preco < it->preco){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo filtra as carrinhas consoante a disponibiidade
 * ---> 
 * <---
 */
void Carrinha::filtrarDisponibilidade(){
	list<Carrinha>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (it->estado == "Indisponivel"){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo filtra as carrinhas consoante o tempo de aluguer pretendido
 * ---> tempo de aluguer do veículo
 * <---
 */
void Carrinha::filtrarTempo(int _tempo){
	list<Carrinha>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (_tempo > it->tempo){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo verifica se o utilizador inseriu um ID válido para alugar
 * ---> _id
 * <---
 */
void Carrinha::verificaId(int _id){
	list<Carrinha>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		//Verifica se o ID do carro é válido
		if (_id == it->id){
			//Altera o estado do veículo para "Indisponivel" na lista visível
			it->estado = "Indisponivel";
			cout << "Veículo Alugado!\n\n";
			return;
		}
	}
	cout << "Carro indisponivel!\n";
	cout << "\n";
};

/* O módulo altera o estado do veículo a alugar para "Indisponivel" 
 * na lista ficheiro
 * ---> _id
 * <---
 */
void Carrinha::registarCarro(int _id){
	list<Carrinha>::iterator it;
	
	for (it = listaFicheiro.begin(); it != listaFicheiro.end(); it++){
		if (_id == it->id){
			it->estado = "Indisponivel";
			return;
		}
	}
	cout << "\n";
};

/* O módulo guarda a nova informação após o aluguer num novo ficheiro 
 * ---> 
 * <---
 */
void Carrinha::guardar(){
	list<Carrinha>::iterator it;
	remove("carrinhas.txt");
	FILE *arq;
	arq = fopen("carrinhas.txt", "wt");  // Cria um arquivo texto para gravação
	ofstream arquivo("carrinhas.txt",ios::app);
		if (arquivo){
			for (it = listaFicheiro.begin(); it != listaFicheiro.end(); it++){
				arquivo << it->id << "," << it->preco << "," << it->marca << "," << it->modelo << "," << it->ccv << "," << it->estado << "," << it->tempo << "," << it->cargaMax << "\n";
			}
		}
		else{
			cout << "\nErro ao abrir ficheiro!\n";
			exit(0);
		}
		arquivo.close();
};

/* O módulo devolve a carga máxima de uma carrinha
 * --->
 * <--- Carga máxima
 */
int Carrinha::devolveCargaMax(){
	return (cargaMax);
};

/* O módulo devolve a Lista ficheiro
 * ---> 
 * <--- Lista ficheiro
 */
list<Carrinha> Carrinha::devolveLista(){
	return (listaFicheiro);
};
