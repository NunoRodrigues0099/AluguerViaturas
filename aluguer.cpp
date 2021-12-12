/*
 * aluguer.cpp
 */

#include <iostream>
#include <string>
#include <stdexcept> 
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <list>
#include <vector>
#include "utilizador.hpp"
#include "veiculo.hpp"
#include "carrinha.hpp"
#include "ligeiro.hpp"
#include "caravana.hpp"
#include "aluguer.hpp"

using namespace std;

Aluguer::Aluguer() {};		//Construtor

Aluguer::~Aluguer(){};		//Destrutor

// Manipuladores

/* O módulo fixa a informação de um novo aluguer
 * ---> todos os dados do aluguer
 * <--- 
 */
void Aluguer::fixaInfoAlug(int _idAlug, int _idCarro, string _tipo){
	idAlug = _idAlug;
	idCarro = _idCarro;
	tipo = _tipo;
};

/* O módulo cria um ficheiro com os dados do aluguer
 * --->
 * <--- 
 */
void Aluguer::criarFileAluguer(){
	list<Aluguer>::iterator it;
	
	remove("alugueres.txt");
	FILE *arq;
	arq = fopen("alugueres.txt", "wt");  // Cria um arquivo texto para gravação
	ofstream arquivo("alugueres.txt",ios::app);
	if (arquivo){
		for (it = alugueres.begin(); it != alugueres.end(); it++){
			arquivo << idAlug << "," << it->tipo << "," << it->idCarro << "\n";
		}
	}
	else{
		cout << "\nErro ao abrir ficheiro!\n";
		exit(0);
	}
	arquivo.close();
};

/* O módulo adiciona a informação de um novo aluguer 
 * à lista de alugueres
 * ---> id, lista de Carrinhas, lista de Ligeiros e lista de Caravanas
 * <--- 
 */
void Aluguer::adicionarAluguer(int _id, list<Carrinha> carrinha, list<Ligeiro> ligeiro, list<Caravana> caravana){
	Aluguer a;
	list<Carrinha>::iterator it1;
	list<Ligeiro>::iterator it2;
	list<Caravana>::iterator it3;
		
	for (it1 = carrinha.begin(); it1 != carrinha.end(); it1++){
		if (it1->devolveId() == _id){
			a.idCarro = it1->devolveId();
			a.tipo = "Carrinha";
		}
	}
	for (it2 = ligeiro.begin(); it2 != ligeiro.end(); it2++){
		if (it2->devolveId() == _id){
			a.idCarro = it2->devolveId();
			a.tipo = "Ligeiro";
		}
	}
	for (it3 = caravana.begin(); it3 != caravana.end(); it3++){
		if (it3->devolveId() == _id){
			a.idCarro = it3->devolveId();
			a.tipo = "Caravana";
		}
	}
	a.idAlug = idAlug;
	idAlug++;
	alugueres.push_back(a);
};

/* O módulo lê a insformações presentes no ficheiro "aluguer.txt"
 * ---> 
 * <--- 
*/
void Aluguer::lerFicheiroAluguer(){
	ifstream arquivo("alugueres.txt");
	Aluguer a;
	if (arquivo.is_open()){
		string line;
		while(getline(arquivo,line)){
			stringstream ss(line);
			string _idAlug, _tipo, _idCarro;
			
			getline(ss,_idAlug,',');
				idAlug = stoi(_idAlug);
			getline(ss,_tipo,',');
				tipo = _tipo;
			getline(ss,_idCarro,',');
				idCarro = stoi(_idCarro);
			
			vector <string> enrolled;
			string course;
			while (getline(ss,course,',')){
				enrolled.push_back(course);
				cout << ",\"" << course << "\"";
			}
			a.fixaInfoAlug(idAlug,idCarro,tipo);
			alugueres.push_back(a);
			cout << "\n";
		}
		arquivo.close();
	}
	else{
		cout<<"\nErro ao abrir ficheiro!\n";
		exit(0);
	}
};



/* O módulo mostra toda a informação da lista de alugueres
 * ---> 
 * <--- print de todos as informações
*/
void Aluguer::mostraInfoAlug(){
	list<Aluguer>::iterator it;
	cout << "Tipo\tID\n";
	for (it = alugueres.begin(); it != alugueres.end(); it++){
		cout << it->tipo << "\t" << it->idCarro << "\n";
	}
};
