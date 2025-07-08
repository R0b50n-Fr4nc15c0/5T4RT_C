#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>

class PowerSource {
public:
	int PM;		/*Produção Media em MW/Ano*/
	int CM;		/*Custo Medio da instalação*/
	int CM_M;	/*Custo Medio de Manutenção*/
};

class painel_S : public PowerSource {	
public:
	int PM;
	int CM = 3000;
	int CM_M = 20;

	//void L_Painel()
	//{
	//	srand(time(0));
	//	PM = rand() % 1701;
	//}
};
void Tabela(const PowerSource) {

	painel_S P;
	std::cout << "+-------------------------------------------------------------------------------------------------------------------+";
	std::cout << "|      PowerSource     |   Produção Media em MW/Ano   |   Custo Medio da instalação   |  Custo Medio de Manutenção  |";
	std::cout << "|-------------------------------------------------------------------------------------------------------------------|";
	std::cout << "|     Painel Solar     |        " + P.PM, + "         |                               |                             |";
	std::cout << "|                      |                              |                               |                             |";
}

int main(){
	std::cout << "---Gerador---\n" << Tabela;
	return 0;
}
//IMCOMPLETO!!!
