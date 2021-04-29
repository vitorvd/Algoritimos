#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	int qntJuizes = 0, qntConcorrentes = 3, pontosTemp = 0, maiorPontuacao;
	
	struct Concorrente {
		char nome[40];
		int pontos = 0;	
	};
	
	struct Concorrente concorrentes[qntConcorrentes], concorrenteVencedor;
	
	for(int concorrenteTemp = 1; concorrenteTemp <= qntConcorrentes; concorrenteTemp++){
		printf("\nQual o nome do %dº concorrente? ", concorrenteTemp);
		scanf("%s", &concorrentes[concorrenteTemp].nome);
		fflush(stdin);
	}
	
	printf("\nQuantos juizes terão? ");
	scanf("%d", &qntJuizes);
	fflush(stdin);
	
	for(int concorrenteTemp = 1; concorrenteTemp <= qntConcorrentes; concorrenteTemp++){
		for(int x = 1; x <= qntJuizes; x++){
			system("cls");
			printf("\nQual a nota do %dº Juiz para o %s? ", x, concorrentes[concorrenteTemp].nome);
			scanf("%d", &pontosTemp);
			fflush(stdin);
			concorrentes[concorrenteTemp].pontos += pontosTemp;
		}
		if(concorrentes[concorrenteTemp].pontos >= concorrenteVencedor.pontos)
			concorrenteVencedor = concorrentes[concorrenteTemp];
	}
	
	system("cls");
	
	printf("\n\n==========CONCORRENTES==========\n\n");
	for(int concorrenteTemp = 1; concorrenteTemp <= qntConcorrentes; concorrenteTemp++){
		printf("%s com %d pontos.\n", concorrentes[concorrenteTemp].nome, concorrentes[concorrenteTemp].pontos);
	}
	printf("\n==========CONCORRENTES==========\n\n");
	printf("\n\n==========VENCEDOR===============\n\n");
	printf("%s foi o vencedor com %d pontos.", concorrenteVencedor.nome, concorrenteVencedor.pontos);
	printf("\n\n==========VENCEDOR===============\n\n");
	
	return 0;
}
