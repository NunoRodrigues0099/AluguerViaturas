/*
 * func_aux.cpp
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <stdexcept> 
#include <unistd.h>
#include <string>
#include <vector>
#include "utilizador.hpp"
#include "userparticular.hpp"
#include "userempresa.hpp"
#include "veiculo.hpp"
#include "carrinha.hpp"
#include "ligeiro.hpp"
#include "caravana.hpp"
#include "aluguer.hpp"
#include "func_aux.hpp"

using namespace std;

Simulacao::Simulacao() {};  //Construtor

Simulacao::~Simulacao(){};  //Destrutor

void apresentacao();
void menu1();
void menu2();

/* O módulo apresenta as informações principais do trabalho
 * ---> 
 * <---
*/
void apresentacao() {
    cout << "\n";
    cout << "***********************************************\n";
    cout << "***********************************************\n";
    cout << "*                    FCTUC                    *\n";
    cout << "*          DEPARTAMENTO DE MATEMÁTICA         *\n";
    cout << "***********************************************\n";
    cout << "*    Programaçao Orientada para os Objetos    *\n";
    cout << "*           Professor Pedro Quaresma          *\n";
    cout << "*             Ano Letivo 2020/2021            *\n";
    cout << "*                  Projeto 2                  *\n";
    cout << "***********************************************\n";
    cout << "*    Trabalho realizado por:                  *\n";
    cout << "*    - Alice Conceiçao (2018295146)           *\n";
    cout << "*    - Nuno Rodrigues  (2018282528)           *\n";
    cout << "*      Grupo 4                                *\n";
    cout << "***********************************************\n";
    cout << "***********************************************\n";
};


/* O módulo apresenta o MENU utilizador
 * ---> 
 * <---
*/
void menu1(){
	cout << "***********************************************\n";
    cout << "******** BEM-VINDO AO ALUGUER DE CARROS *******\n";
    cout << "***********************************************\n";
    cout << "* Escolha o tipo de utilizador:               *\n";
    cout << "* 1 - Particular                              *\n";
    cout << "* 2 - Empresa                                 *\n";
    cout << "* 0 - Sair                                    *\n";
    cout << "***********************************************\n";
};

/* O módulo apresenta o MENU tipo de veículo
 * ---> 
 * <---
*/
void menu2(){
	cout << "***********************************************\n";
	cout << "************ Aluguer de Veículos **************\n";
	cout << "* Escolha o tipo de veículo a alugar:         *\n";
	cout << "* 1 - Carrinha de transporte ligeiro          *\n";
	cout << "* 2 - Ligeiro de passageiros                  *\n";
	cout << "* 3 - Auto-caravana                           *\n";
	cout << "* 0 - Terminar Aluguer                        *\n";
	cout << "***********************************************\n";
};

/* O módulo recebe as informações sobre o tipo de utilizador, o tipo 
 * de veículo que pretende alugar e quais os filtros que devem ser 
 * aplicados e imprime na tela os veículos que correspondem aos
 * requisitos
 * ---> 
 * <--- print dos veículos que correspondem aos filtros aplicados
*/
void Simulacao::simulacao(){
	int op1,op2,_nif,_contacto,_cc,_idade,_tempo,_id;
	string _nome, _funcao;
	float _preco;
	UserParticular p;
	UserEmpresa e;
	Carrinha c;
	Ligeiro l;
	Caravana ca;
	Aluguer alug;
	
	apresentacao();
	c.Carrinha::lerFicheiro();
	l.Ligeiro::lerFicheiro();
	ca.Caravana::lerFicheiro();
	
	do{
		menu1();
		cin >> op1;
	
		switch (op1){
			//Utilizador Particular
			case 1:
				cout << "\n***********************************************\n";
				cout << "************* Introdução de Dados *************\n";
				cout << "***********************************************\n";
				cout << "Nome: "; cin >> _nome; cout << "\n";
				cout << "NIF: "; cin >> _nif; cout << "\n";
				cout << "Contacto: "; cin >> _contacto; cout << "\n";
				cout << "CC (8 dígitos): "; cin >> _cc; cout << "\n";
				cout << "Idade: "; cin >> _idade; cout << "\n";
				p.UserParticular::fixaInfoUser(1,_nif,_contacto,_nome,_idade,_cc);
				do{
					menu2();
					cin >> op2;
					switch (op2){
						//Carrinhas
						case 1:
							cout << "\n***********************************************\n";
							cout << "* A alugar: Carrinha de transporte ligeiro    *\n";
							cout << "***********************************************\n\n";
							c.Carrinha::mostraInfoCarrinha();
							c.Carrinha::filtrarDisponibilidade();
							cout << "\n\nPreço Máx. a pagar(em €): ";
							cin >> _preco;
							c.Carrinha::filtrarPreco(_preco);
							cout << "\n\nTempo de aluguer(em semanas): ";
							cin >> _tempo;
							c.Carrinha::filtrarTempo(_tempo);
							c.Carrinha::mostraInfoCarrinha();
							cout << "\nID do veículo a alugar: ";
							cin >> _id;
							c.Carrinha::verificaId(_id);
							c.Carrinha::registarCarro(_id);
							alug.Aluguer::adicionarAluguer(_id,c.devolveLista(),l.devolveLista(),ca.devolveLista());
							break;
						//Ligeiros
						case 2:
							cout << "\n***********************************************\n";
							cout << "* A alugar: Ligeiro de passageiros            *\n";
							cout << "***********************************************\n\n";
							l.Ligeiro::mostraInfoLigeiro();
							l.Ligeiro::filtrarDisponibilidade();
							cout << "\n\nPreço Máx. a pagar(em €): ";
							cin >> _preco;
							l.Ligeiro::filtrarPreco(_preco);
							cout << "\n\nTempo de aluguer(em semanas): ";
							cin >> _tempo;
							l.Ligeiro::filtrarTempo(_tempo);
							l.Ligeiro::mostraInfoLigeiro();
							cout << "\nID do veículo a alugar: ";
							cin >> _id;
							l.Ligeiro::verificaId(_id);
							l.Ligeiro::registarCarro(_id);
							alug.Aluguer::adicionarAluguer(_id,c.devolveLista(),l.devolveLista(),ca.devolveLista());
							break;
						//Caravanas
						case 3:
							cout << "\n***********************************************\n";
							cout << "* A alugar: Auto-caravana                     *\n";
							cout << "***********************************************\n\n";
							ca.Caravana::mostraInfoCaravana();
							ca.Caravana::filtrarDisponibilidade();
							cout << "\n\nPreço Máx. a pagar(em €): ";
							cin >> _preco;
							ca.Caravana::filtrarPreco(_preco);
							cout << "\n\nTempo de aluguer(em semanas): ";
							cin >> _tempo;
							ca.Caravana::filtrarTempo(_tempo);
							ca.Caravana::mostraInfoCaravana();
							cout << "\nID do veículo a alugar: ";
							cin >> _id;
							ca.Caravana::verificaId(_id);
							ca.Caravana::registarCarro(_id);
							alug.Aluguer::adicionarAluguer(_id,c.devolveLista(),l.devolveLista(),ca.devolveLista());
							break;
						case 0:
							cout <<"\n***********************************************\n";
							cout << "* 0. Sistema de aluguer encerado.             *\n";
							cout << "***********************************************\n\n\n";
							break;
						default:
							cout <<"\n***********************************************\n";
							cout << "* Opção inválida!                             *\n";
							cout << "***********************************************\n\n\n";
					}
				}while (op2 != 0);
				break;
			//Utilizador Empresarial
			case 2:
				cout << "\n***********************************************\n";
				cout << "************* Introdução de Dados *************\n";
				cout << "***********************************************\n";
				cout << "Nome: "; cin >> _nome; cout << "\n";
				cout << "NIF: "; cin >> _nif; cout << "\n";
				cout << "Contacto: "; cin >> _contacto; cout << "\n";
				cout << "Função: "; cin >> _funcao; cout << "\n";
				e.UserEmpresa::fixaInfoUser(1,_nif,_contacto,_nome,_funcao);
				do{
					menu2();
					cin >> op2;
					switch (op2){
						//Carrinhas
						case 1:
							cout << "\n***********************************************\n";
							cout << "* A alugar: Carrinha de transporte ligeiro    *\n";
							cout << "***********************************************\n\n";
							c.Carrinha::mostraInfoCarrinha();
							c.Carrinha::filtrarDisponibilidade();
							cout << "\n\nPreço Máx. a pagar(em €): ";
							cin >> _preco;
							c.Carrinha::filtrarPreco(_preco);
							cout << "\n\nTempo de aluguer(em semanas): ";
							cin >> _tempo;
							c.Carrinha::filtrarTempo(_tempo);
							c.Carrinha::mostraInfoCarrinha();
							cout << "\nID do veículo a alugar: ";
							cin >> _id;
							c.Carrinha::verificaId(_id);
							c.Carrinha::registarCarro(_id);
							alug.Aluguer::adicionarAluguer(_id,c.devolveLista(),l.devolveLista(),ca.devolveLista());
							break;
						//Ligeiros
						case 2:
							cout << "\n***********************************************\n";
							cout << "* A alugar: Ligeiro de passageiros            *\n";
							cout << "***********************************************\n\n";
							l.Ligeiro::mostraInfoLigeiro();
							l.Ligeiro::filtrarDisponibilidade();
							cout << "\n\nPreço Máx. a pagar(em €): ";
							cin >> _preco;
							l.Ligeiro::filtrarPreco(_preco);
							cout << "\n\nTempo de aluguer(em semanas): ";
							cin >> _tempo;
							l.Ligeiro::filtrarTempo(_tempo);
							l.Ligeiro::mostraInfoLigeiro();
							cout << "\nID do veículo a alugar: ";
							cin >> _id;
							l.Ligeiro::verificaId(_id);
							l.Ligeiro::registarCarro(_id);
							alug.Aluguer::adicionarAluguer(_id,c.devolveLista(),l.devolveLista(),ca.devolveLista());
							break;
						//Caravanas
						case 3:
							cout << "\n***********************************************\n";
							cout << "* A alugar: Auto-caravana                     *\n";
							cout << "***********************************************\n\n";
							ca.Caravana::mostraInfoCaravana();
							ca.Caravana::filtrarDisponibilidade();
							cout << "\n\nPreço Máx. a pagar(em €): ";
							cin >> _preco;
							ca.Caravana::filtrarPreco(_preco);
							cout << "\n\nTempo de aluguer(em semanas): ";
							cin >> _tempo;
							ca.Caravana::filtrarTempo(_tempo);
							ca.Caravana::mostraInfoCaravana();
							cout << "\nID do veículo a alugar: ";
							cin >> _id;
							ca.Caravana::verificaId(_id);
							ca.Caravana::registarCarro(_id);
							alug.Aluguer::adicionarAluguer(_id,c.devolveLista(),l.devolveLista(),ca.devolveLista());
							break;
						case 0:
							cout <<"\n***********************************************\n";
							cout << "* 0. Sistema de aluguer encerado.             *\n";
							cout << "***********************************************\n\n\n";
							break;
						default:
							cout <<"\n***********************************************\n";
							cout << "* Opção inválida!                             *\n";
							cout << "***********************************************\n\n\n";
					}
				}while (op2 != 0);
				break;
				case 0:
					cout <<"\n***********************************************\n";
					cout << "* 0. Sistema de aluguer encerado.             *\n";
					cout << "***********************************************\n\n\n";
					break;
				default:
					cout <<"\n***********************************************\n";
					cout << "* Opção inválida!                             *\n";
					cout << "***********************************************\n\n\n";
		}
	}while (op1 != 0 && op1 != 1 && op1 != 2);
	
	c.Carrinha::guardar();
	l.Ligeiro::guardar();
	ca.Caravana::guardar();
	
	alug.Aluguer::criarFileAluguer();
	cout << "************************************************\n";
	cout << "* FROTA DOS SEUS ALUGUERES                     *\n";
	cout << "************************************************\n";
	alug.Aluguer::mostraInfoAlug();
};
