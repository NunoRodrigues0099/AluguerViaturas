/*
 * veiculo.hpp
 */

// Veiculo (Classe de Base)

#ifndef VEICULO
#define VEICULO

#include <iostream>
#include <string>
#include <stdio.h>
#include <list>

using namespace std;

class Veiculo{

	protected:
		int id;
		float preco;
		string marca;
		string modelo;
		int ccv;
		string estado;
		int tempo;
    
	public:
		// Construtor
		Veiculo();
		
		// Destrutor
		~Veiculo();
		
		// Manipuladores
		void fixaInfoVeiculo(int, float, string, string, int, string, int);
		
		// Seletores
		int devolveId();
		float devolvePreco();
		string devolveMarca();
		string devolveModelo();
		int devolveCcv();
		string devolveEstado();
		int devolveTempo();
};
#endif
