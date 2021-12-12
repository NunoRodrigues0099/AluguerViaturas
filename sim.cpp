#include <iostream>
#include "utilizador.hpp"
#include "veiculo.hpp"
#include "aluguer.hpp"
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <stdexcept> 
#include <unistd.h>
#include "func_aux.hpp"

using namespace std;

int main(int argc, char **argv){
	
	Simulacao simul;
	
	simul.simulacao();
	
	cout << "\n";
	
	return 0;
}
