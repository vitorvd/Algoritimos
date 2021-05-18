#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int codigo = 0;
	int totalVotos = 0;
	float votosCandidato1 = 0, votosCandidato2 = 0, votosCandidato3 = 0, votosCandidato4 = 0, votosNulo = 0, votosBranco = 0;
	 
	do {
		do{
			system("cls");
			printf("\n\nInforme o código, sabendo que: \n\n");
			printf("[1] » Primeiro Candidato\n");
			printf("[2] » Segundo Candidato\n");
			printf("[3] » Terceiro Candidato\n");
			printf("[4] » Quarto Candidato\n");
			printf("[5] » Voto Nulo\n");
			printf("[6] » Voto em Branco\n");
			printf("[7] » Encerrar Votação\n\n");
			
			printf("Qual o código? ");
			scanf("%d", &codigo);
		}while(codigo < 1 || codigo > 7);
		
		totalVotos++;
		
		switch(codigo){
			case 1:
				votosCandidato1++;
				break;
			case 2:
				votosCandidato2++;
				break;
			case 3:
				votosCandidato3++;
				break;
			case 4:
				votosCandidato4++;
				break;
			case 5:
				votosNulo++;
				break;
			case 6:
				votosBranco++;
				break;
			default:
				totalVotos--;
				break;
		}
	} while(codigo != 7);
	
	system("cls");
	
	printf("\n\n========= RELATÓRIO VOTAÇÃO =========\n\n");
	printf("Primeiro Candidato: %.0f (%.2f) \n", votosCandidato1, (float) (votosCandidato1/totalVotos) * 100);
	printf("Segundo Candidato: %.0f (%.2f) \n", votosCandidato2, (float) (votosCandidato2/totalVotos) * 100);
	printf("Terceiro Candidato: %.0f (%.2f) \n", votosCandidato3, (float) (votosCandidato3/totalVotos) * 100);
	printf("Quarto Candidato: %.0f (%.2f) \n", votosCandidato4, (float) (votosCandidato4/totalVotos) * 100);
	printf("Votos Nulos: %.0f (%.2f) \n", votosNulo, (float) (votosNulo/totalVotos) * 100);
	printf("Votos em Branco: %.0f (%.2f)", votosBranco, (float) (votosBranco/totalVotos) * 100);
	printf("\n\n========= RELATÓRIO VOTAÇÃO =========\n");
	return 0;
}
