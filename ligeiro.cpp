/*
 * ligeiro.cpp
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
#include "ligeiro.hpp"

using namespace std;

Ligeiro::Ligeiro() : Veiculo(){};		//Construtor

Ligeiro::~Ligeiro(){};					//Destrutor

/* O módulo fixa a informação dos ligeiros de transporte de passageiros
 * ---> todos os dados do Ligeiro
 * <---
 */
void Ligeiro::fixaInfoLigeiro(int _id, float _preco, string _marca, string _modelo, int _ccv, string _estado, int _tempo, int _numPassageiros){
	id = _id;
	preco = _preco;
	marca = _marca;
	modelo = _modelo;
	ccv = _ccv;
	estado = _estado;
	tempo = _tempo;
	numPassageiros = _numPassageiros;
};

/* O módulo lê o ficheiro "ligeiros.txt" e guarda os
 * dados numa lista de ligeiros
 * --->
 * <---
 */
void Ligeiro::lerFicheiro(){
	ifstream arquivo("ligeiros.txt");
	Ligeiro l;
	if (arquivo.is_open()){
		string line;
		while(getline(arquivo,line)){
			stringstream ss(line);
			string _id, _preco, _marca, _modelo, _ccv, _estado, _tempo, _numPassageiros;
			
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
			getline(ss,_numPassageiros,',');
				numPassageiros = stoi(_numPassageiros);
			
			vector <string> enrolled;
			string course;
			while (getline(ss,course,',')){
				enrolled.push_back(course);
				cout << ",\"" << course << "\"";
			}
			l.fixaInfoLigeiro(id,preco,marca,modelo,ccv,estado,tempo,numPassageiros);
			listaFicheiro.push_back(l);
			listaVisivel.push_back(l);
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
 * na lista Visivel dos ligeiros
 * ---> 
 * <--- print de todos as informações
 */
void Ligeiro::mostraInfoLigeiro(){
	list<Ligeiro>::iterator it;
	cout << "ID\tPreço\tMarca\tModelo\tCv\tEstado\t\tTempo\tNum Passageiros\n";
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		cout << it->id << "\t" << it->preco << "\t" << it->marca << "\t" << it->modelo << "\t" << it->ccv << "\t" << it->estado << "\t" << it->tempo << "\t" << it->numPassageiros << "\n";
	}
};

/* O módulo filtra os ligeiros consoante o preço inserido
 * ---> preco máximo que o utilizador quer pagar
 * <---
 */
void Ligeiro::filtrarPreco(int _preco){
	list<Ligeiro>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (_preco < it->preco){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo filtra os ligeiros consoante a disponibiidade
 * ---> 
 * <---
 */
void Ligeiro::filtrarDisponibilidade(){
	list<Ligeiro>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (it->estado == "Indisponivel"){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo filtra os ligeiros consoante o tempo de aluguer pretendido
 * ---> tempo de aluguer do veículo
 * <---
 */
void Ligeiro::filtrarTempo(int _tempo){
	list<Ligeiro>::iterator it;
	
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
void Ligeiro::verificaId(int _id){
	list<Ligeiro>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (_id == it->id){
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
void Ligeiro::registarCarro(int _id){
	list<Ligeiro>::iterator it;
	
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
void Ligeiro::guardar(){
	list<Ligeiro>::iterator it;
	remove("ligeiros.txt");
	FILE *arq;
	arq = fopen("ligeiros.txt", "wt");  // Cria um arquivo texto para gravação
	ofstream arquivo("ligeiros.txt",ios::app);
		if (arquivo){
			for (it = listaFicheiro.begin(); it != listaFicheiro.end(); it++){
				arquivo << it->id << "," << it->preco << "," << it->marca << "," << it->modelo << "," << it->ccv << "," << it->estado << "," << it->tempo << "," << it->numPassageiros << "\n";
			}
		}
		else{
			cout << "\nErro ao abrir ficheiro!\n";
			exit(0);
		}
		arquivo.close();
};

/* O módulo devolve o número de passageiros de um ligeiro
 * --->
 * <--- Num. Passageiros
 */
int Ligeiro::devolveNumPassageiros(){
	return (numPassageiros);
};

/* O módulo devolve a Lista ficheiro
 * ---> 
 * <--- Lista ficheiro
 */
list<Ligeiro> Ligeiro::devolveLista(){
	return (listaFicheiro);
};
