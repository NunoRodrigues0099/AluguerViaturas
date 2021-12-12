/*
 * caravana.cpp
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
#include "caravana.hpp"

using namespace std;

Caravana::Caravana() : Veiculo(){};		//Construtor

Caravana::~Caravana(){};				//Destrutor

/* O módulo fixa a informação das caravanas
 * ---> todos os dados das Caravanas
 * <---
 */
void Caravana::fixaInfoCaravana(int _id, float _preco, string _marca, string _modelo, int _ccv, string _estado, int _tempo, int _qtCamas){
	id = _id;
	preco = _preco;
	marca = _marca;
	modelo = _modelo;
	ccv = _ccv;
	estado = _estado;
	tempo = _tempo;
	qtCamas = _qtCamas;
};

/* O módulo lê o ficheiro "caravanas.txt" e guarda os
 * dados numa lista de caravanas
 * --->
 * <---
 */
void Caravana::lerFicheiro(){
	ifstream arquivo("caravanas.txt");
	Caravana c;
	if (arquivo.is_open()){
		string line;
		while(getline(arquivo,line)){
			stringstream ss(line);
			string _id, _preco, _marca, _modelo, _ccv, _estado, _tempo, _qtCamas;
			
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
			getline(ss,_qtCamas,',');
				qtCamas = stoi(_qtCamas);
			
			vector <string> enrolled;
			string course;
			while (getline(ss,course,',')){
				enrolled.push_back(course);
				cout << ",\"" << course << "\"";
			}
			c.fixaInfoCaravana(id,preco,marca,modelo,ccv,estado,tempo,qtCamas);
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
 * na lista Visivel das caravanas
 * ---> 
 * <--- print de todos as informações
 */
void Caravana::mostraInfoCaravana(){
	list<Caravana>::iterator it;
	cout << "ID\tPreço\tMarca\t\tModelo\t\tCv\tEstado\t\tTempo\tQt Camas\n";
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		cout << it->id << "\t" << it->preco << "\t" << it->marca << "\t" << it->modelo << "\t\t" << it->ccv << "\t" << it->estado << "\t" << it->tempo << "\t" << it->qtCamas << "\n";
	}
};

/* O módulo filtra as caravanas consoante o preço inserido
 * ---> preco máximo que o utilizador quer pagar
 * <---
 */
void Caravana::filtrarPreco(int _preco){
	list<Caravana>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (_preco < it->preco){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo filtra as caravanas consoante a disponibiidade
 * ---> 
 * <---
 */
void Caravana::filtrarDisponibilidade(){
	list<Caravana>::iterator it;
	
	for (it = listaVisivel.begin(); it != listaVisivel.end(); it++){
		if (it->estado == "Indisponivel"){
			it = listaVisivel.erase(it);
		}
	}
	cout << "\n";
};

/* O módulo filtra as caravanas consoante o tempo de aluguer pretendido
 * ---> tempo de aluguer do veículo
 * <---
 */
void Caravana::filtrarTempo(int _tempo){
	list<Caravana>::iterator it;
	
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
void Caravana::verificaId(int _id){
	list<Caravana>::iterator it;
	
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
void Caravana::registarCarro(int _id){
	list<Caravana>::iterator it;
	
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
void Caravana::guardar(){
	list<Caravana>::iterator it;
	remove("caravanas.txt");
	FILE *arq;
	arq = fopen("caravanas.txt", "wt");  // Cria um arquivo texto para gravação
	ofstream arquivo("caravanas.txt",ios::app);
		if (arquivo){
			for (it = listaFicheiro.begin(); it != listaFicheiro.end(); it++){
				arquivo << it->id << "," << it->preco << "," << it->marca << "," << it->modelo << "," << it->ccv << "," << it->estado << "," << it->tempo << "," << it->qtCamas << "\n";
			}
		}
		else{
			cout << "\nErro ao abrir ficheiro!\n";
			exit(0);
		}
		arquivo.close();
};

/* O módulo devolve a quantidade de camas numa caravana
 * --->
 * <--- Quantidade de Camas
 */
int Caravana::devolveQtCamas(){
	return (qtCamas);
};

/* O módulo devolve a Lista ficheiro
 * ---> 
 * <--- Lista ficheiro
 */
list<Caravana> Caravana::devolveLista(){
	return (listaFicheiro);
};
