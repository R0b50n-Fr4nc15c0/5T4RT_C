#include <stdio.h>
#include <stdlib.h>

int main()
{
	// -------------------------------------------------------------
	// vetor est�tico
	// -------------------------------------------------------------
	// o tamanho � fixo e a mem�ria � pr�-alocada
	// a quantidade de numeros vai ser sempre 3
	// nunca maior nem menor.
	int vetorNumeros[3];
	// preenchendo valores dentro do vetor est�tico
	vetorNumeros[0] = 1;
	vetorNumeros[1] = 2;
	vetorNumeros[2] = 3;
	// imprimindo os valores no vetor... 
	printf("vetorNumeros %d %d %d\n", vetorNumeros[0], vetorNumeros[1], vetorNumeros[2]);

	// -------------------------------------------------------------
	// lista com ponteiro
	// -------------------------------------------------------------
	// o tamanho � definido em tempo de exexu��o
	// e a lista pode ser realocada, com tamanhos diferentes
	// conforme a quantidade de dados crescer
	int quantidadeNumeros = 3;
	int* listaNumeros = (int*)malloc(quantidadeNumeros * sizeof(int));
	listaNumeros[0] = 1;
	listaNumeros[1] = 2;
	listaNumeros[2] = 3;
	printf("listaNumeros %d %d %d\n", listaNumeros[0], listaNumeros[1], listaNumeros[2]);
	
	// aumentando a quantidade de elementos na lista
	quantidadeNumeros = 4;
	// alocando mais mem�ria dinamicamente (a lista cresce durante a execu��o do programa)
	listaNumeros == realloc(listaNumeros, quantidadeNumeros * sizeof(int));
	// atribuindo um novo valor...
	listaNumeros[3] = 68;
	// imprimindo a lista...
	printf("listaNumeros %d %d %d %d\n", listaNumeros[0], listaNumeros[1], listaNumeros[2]);
}
