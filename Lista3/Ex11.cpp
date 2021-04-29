#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	int qntJuizes = 0, qntConcorrentes = 1, pontosTemp = 0, maiorPontuacao;
	
	struct Concorrente {
		char nome[40];
		int pontos = 0;	
	};
	
	Concorrente concorrentes[qntConcorrentes], concorrenteVencedor;
	
	for(int concorrenteTemp = 0; concorrenteTemp <= qntConcorrentes; concorrenteTemp++){
		printf("\nQual o nome do %dº concorrente? ", concorrenteTemp + 1);
		scanf("%s", &concorrentes[concorrenteTemp].nome);
		fflush(stdin);
	}
	
	printf("\nQuantos juizes terão? ");
	scanf("%d", &qntJuizes);
	fflush(stdin);
	
	for(int concorrenteTemp = 0; concorrenteTemp <= qntConcorrentes; concorrenteTemp++){
		concorrentes[concorrenteTemp].pontos = 0;
		printf("\nNovo concorrente: %s - %d pts.\n", concorrentes[concorrenteTemp].nome, concorrentes[concorrenteTemp].pontos);
		for(int x = 1; x <= qntJuizes; x++){
			//system("cls");
			printf("\nQual a nota do %dº Juiz para o %s? ", x, concorrentes[concorrenteTemp].nome);
			scanf("%d", &pontosTemp);
			fflush(stdin);
			concorrentes[concorrenteTemp].pontos = 0;
			printf("pontosConcorrente: %d\n", concorrentes[concorrenteTemp].pontos);
			concorrentes[concorrenteTemp].pontos = pontosTemp;
			printf("pontosTemp: %d || pontosConcorrente: %d\n", pontosTemp, concorrentes[concorrenteTemp].pontos);
		}
		if(concorrenteVencedor.pontos >= maiorPontuacao)
			concorrenteVencedor = concorrentes[concorrenteTemp];
	}
	
	//system("cls");
	
	printf("\n\n===============================\n\n");
	for(int concorrenteTemp = 0; concorrenteTemp <= qntConcorrentes; concorrenteTemp++){
		printf("%s com %d pontos.\n", concorrentes[concorrenteTemp].nome, concorrentes[concorrenteTemp].pontos);
	}
	printf("\n===============================\n\n");
	printf("\n\n===============================\n\n");
	printf("%s foi o vencedor com %d pontos.", concorrenteVencedor.nome, concorrenteVencedor.pontos);
	printf("\n\n===============================\n\n");
	
	return 0;
}
