#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Fruta
{
	int id;
	char nome[30];
	float precoCompra;
	float precoVenda;
} Fruta;

typedef struct Compra {
	int id;
	int idFruta;
	int quantidade;
	float desconto;
} Compra;

typedef struct Venda {
	int id;
	int idFruta;
	int quantidade;
	float desconto;
} Venda;

Fruta* frutas = NULL;
Compra* compras = NULL;
Venda* vendas = NULL;

int quantidadeFrutas = 0;
int quantidadeCompras = 0;
int quantidadeVendas = 0;

void adicionarFruta()
{
	Fruta fruta;
	fruta.id = quantidadeFrutas + 1;

	int InputStatus = 0;

	printf("Digite o nome da fruta: ");
	InputStatus = scanf_s("%s", fruta.nome);
	if (InputStatus == EOF) { printf("ERRO - Falha na inser��o de dados\n"); return; }

	printf("Digite o pre�o de compra da fruta: ");
	InputStatus = scanf_s("%f", &fruta.precoCompra);
	if (InputStatus == EOF) { printf("ERRO - Falha na inser��o de dados\n"); return; }

	printf("Digite o pre�o de venda da fruta: ");
	InputStatus = scanf_s("%f", &fruta.precoVenda);
	if (InputStatus == EOF) { printf("ERRO - Falha na inser��o de dados\n"); return; }

	if (quantidadeFrutas > 0)
	{
		//Realocando todas as listas em vari�veis tempor�rias...
		//verificando as listas pra evitar tentar inserir dados em listas inv�lidas.		
		Fruta* bufferFrutas = (Fruta*)realloc(frutas, (quantidadeFrutas + 1) * sizeof(Fruta));
		if (bufferFrutas == NULL) { printf("Deu ruim!"); return; }
		frutas = bufferFrutas;
	}

	frutas[quantidadeFrutas] = fruta;
	quantidadeFrutas++;

	FILE* arquivoFrutas = fopen("frutas.txt", "a+");
	fprintf(arquivoFrutas, "%d %s %f %f\n", fruta.id, fruta.nome, fruta.precoCompra, fruta.precoVenda);
	fclose(arquivoFrutas);
}

bool frutaValida(int idFruta)
{
	for (int i = 0; i < quantidadeFrutas; i++)
	{
		if (idFruta == frutas[i].id) return true;
	}
	return false;
}

int quantidadeComprada(int idFruta)
{
	int quantidadeComprada = 0;
	for (int i = 0; i < quantidadeCompras; i++)
	{
		if (compras[i].idFruta == idFruta) quantidadeComprada += compras[i].quantidade;
	}
	return quantidadeComprada;
}

int quantidadeVendida(int idFruta)
{
	int quantidadeVendida = 0;
	for (int i = 0; i < quantidadeVendas; i++)
	{
		if (vendas[i].idFruta == idFruta) quantidadeVendida += vendas[i].quantidade;
	}
	return quantidadeVendida;
}

float lucro(int idFruta)
{
	float pc = 0;
	float pv = 0;
	for (int i = 0; i < quantidadeFrutas; i++)
	{
		if (idFruta == frutas[i].id)
		{
			pc = frutas[i].precoCompra;
			pv = frutas[i].precoVenda;
		}
	}

	int qc = quantidadeComprada(idFruta);
	int qv = quantidadeVendida(idFruta);

	float lucro = (pv * qv) - (pc * qc);
	return lucro;
}

int estoque(int idFruta)
{
	int qc = quantidadeComprada(idFruta);
	int qv = quantidadeVendida(idFruta);
	int estoque = qc - qv;
	return estoque;
}

void comprar()
{
	Compra compra;
	printf("Digite o id da fruta a ser comprada:\n");
	scanf_s("%d", &compra.idFruta);
	printf("Digite a quantidade a ser comprada:\n");
	scanf_s("%d", &compra.quantidade);
	printf("Digite o valor de desconto (ou 0 se n�o foi condedido desconto):\n");
	scanf_s("%f", &compra.desconto);

	if (!frutaValida(compra.idFruta)) { printf("ERRO: N�o existe fruta cadastrada com o id fornecido!"); return; }
	if (compra.quantidade <= 0) { printf("ERRO: quantidade inv�lida.");		return; }
	if (compra.desconto < 0) { printf("ERRO: desconto inv�lido."); return; }

	if (quantidadeCompras > 0)
	{
		Compra* bufferCompras = (Compra*)realloc(compras, (quantidadeCompras + 1) * sizeof(Compra));
		if (bufferCompras == NULL) { printf("Deu ruim!"); return; }
		compras = bufferCompras;
	}

	compra.id = quantidadeCompras + 1;
	compras[quantidadeCompras] = compra;
	quantidadeCompras++;

	FILE* arquivoCompras = fopen("Compras.txt", "a+");
	fprintf(arquivoCompras, "%d %d %d %f\n",compra.id, compra.idFruta, compra.quantidade, compra.desconto);
	fclose(arquivoCompras);
}

void vender()
{
	Venda venda;
	printf("Digite o id da fruta a ser vendida:\n");
	scanf_s("%d", &venda.idFruta);
	printf("Digite a quantidade a ser vendida:\n");
	scanf_s("%d", &venda.quantidade);
	printf("Digite o valor de desconto (ou 0 se n�o foi condedido desconto):\n");
	scanf_s("%f", &venda.desconto);

	if (!frutaValida(venda.idFruta)) { printf("ERRO: N�o existe fruta cadastrada com o id fornecido!"); return; }
	if (venda.quantidade <= 0) { printf("ERRO: quantidade inv�lida.");		return; }
	if (venda.desconto < 0) { printf("ERRO: desconto inv�lido."); return; }

	if (quantidadeVendas > 0)
	{
		Venda* bufferVendas = (Venda*)realloc(vendas, (quantidadeVendas + 1) * sizeof(Venda));
		if (bufferVendas == NULL) { printf("Deu ruim!"); return; }
		vendas = bufferVendas;
	}

	venda.id = quantidadeVendas + 1;
	vendas[quantidadeVendas] = venda;
	quantidadeVendas++;

	FILE* arquivoVendas = fopen("vendas.txt", "a+");
	fprintf(arquivoVendas, "%d %d %d %f\n", venda.id, venda.idFruta, venda.quantidade, venda.desconto);
	fclose(arquivoVendas);
}

void listarFrutas()
{
	printf("----------------------------------------------------------------------------------------\n");
	printf("Listando Frutas\n");
	printf("----------------------------------------------------------------------------------------\n");
	printf("               Fruta |  pCompra |  pVenda |  qtdCompra |  qtdVenda |  Estoque |  Lucro |\n");
	for (int i = 0; i < quantidadeFrutas; i++)
	{
		Fruta fruta = frutas[i];
		printf("%20s | ", fruta.nome);
		printf("%5.2f  | ", fruta.precoCompra);
		printf("%5.2f  | ", fruta.precoVenda);
		printf("     %05d  | ", quantidadeComprada(fruta.id));
		printf("    %05d  | ", quantidadeVendida(fruta.id));
		printf("   %05d  | ", estoque(fruta.id));
		printf(" %5.2f |\n", lucro(fruta.id));
	}
}

void carregarFrutasDoArquivo()
{
	FILE* arquivoFrutas = fopen("frutas.txt", "r+");
	while (true) {
		Fruta fruta;
		int retorno = fscanf(arquivoFrutas, "%d %s %f %f\n", &fruta.id, fruta.nome, &fruta.precoCompra, &fruta.precoVenda);
		if (retorno == EOF) break;

		if (quantidadeFrutas > 0)
		{
			Fruta* bufferFrutas = (Fruta*)realloc(frutas, (quantidadeFrutas + 1) * sizeof(Fruta));
			if (bufferFrutas == NULL) { printf("Deu ruim!"); return; }
			frutas = bufferFrutas;
		}
		frutas[quantidadeFrutas] = fruta;
		quantidadeFrutas++;
	}
	fclose(arquivoFrutas);
}

void carregarComprasDoArquivo()
{
	FILE* arquivoCompras = fopen("compras.txt", "r+");
	while (true) {
		Compra compra;
		int retorno = fscanf(arquivoCompras, "%d %d %d %f\n", &compra.id, &compra.idFruta, &compra.quantidade, &compra.desconto);
		if (retorno == EOF) break;

		if (quantidadeCompras > 0)
		{
			Compra* bufferCompras = (Compra*)realloc(compras, (quantidadeCompras + 1) * sizeof(Compra));
			if (bufferCompras == NULL) { printf("Deu ruim!"); return; }
			compras = bufferCompras;
		}
		compras[quantidadeCompras] = compra;
		quantidadeCompras++;
	}
	fclose(arquivoCompras);
}

void carregarVendasDoArquivo()
{
	FILE* arquivoVendas = fopen("vendas.txt", "r+");
	while (true) {
		Venda venda;
		int retorno = fscanf(arquivoVendas, "%d %d %d %f\n", &venda.id, &venda.idFruta, &venda.quantidade, &venda.desconto);
		if (retorno == EOF) break;

		if (quantidadeCompras > 0)
		{
			Venda* bufferVendas = (Venda*)realloc(vendas, (quantidadeVendas + 1) * sizeof(Venda));
			if (bufferVendas == NULL) { printf("Deu ruim!"); return; }
			vendas = bufferVendas;
		}
		vendas[quantidadeVendas] = venda;
		quantidadeVendas++;
	}
	fclose(arquivoVendas);
}
int main()
{
	frutas = (Fruta*)malloc(sizeof(Fruta));
	compras = (Compra*)malloc(sizeof(Compra));
	vendas = (Venda*)malloc(sizeof(Venda));

	int rodando = 1;
	int option = 0;
	while (rodando)
	{
		printf("------------------------------------------------------------------------------------\n");
		printf("Listagem de Frutas\n");
		printf("------------------------------------------------------------------------------------\n");
		printf("1 - Adicionar Fruta\n");
		printf("2 - Comprar\n");
		printf("3 - Vender\n");
		printf("4 - Listar Frutas\n");
		printf("5 - Sair\n");

		int inputStatus = scanf_s("%d", &option);
		if (inputStatus == EOF) { printf("ERRO - Falha ao tentar selecionar op��o..."); return 1; }

		if (option == 1) adicionarFruta();
		if (option == 2) comprar();
		if (option == 3) vender();
		if (option == 4) listarFrutas();
		if (option == 5) rodando = 0;

		carregarFrutasDoArquivo();
		carregarComprasDoArquivo();
		carregarVendasDoArquivo();
	}
	return 0;
}