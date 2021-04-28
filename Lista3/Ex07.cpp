#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	int opcao, qntAbacaxi = 0, qntMaca = 0, qntPera = 0, qntScanf = 0;
	
	printf("\nOlá, seja bem-vindo à Feira do Guará!\n");
	while(opcao != 4){
		printf("\n[1] Abacaxi \n[2] Maçã \n[3] Pera \n[4] Finalizar pedido");
		printf("\n\nSelecione qual fruta você deseja colocar no carrinho: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\nQuantos abacaxis você deseja comprar? ");
				scanf("%d", &qntScanf);
				qntAbacaxi += qntScanf;	
			break;
			case 2:
				printf("\nQuantos maçãs você deseja comprar? ");
				scanf("%d", &qntScanf);
				qntMaca += qntScanf;
			break;
			case 3:
				printf("\nQuantos peras você deseja comprar? ");
				scanf("%d", &qntScanf);
				qntPera += qntScanf;	
			break;
			case 4:
				printf("\nVocê finalizou o pedido! \n");
				printf("Você comprou %d abacaxis, %d maçãs e %d peras", qntAbacaxi, qntMaca, qntPera);
			break;
			default:
				printf("\nOpção não cadastrada, selecione uma disponível!\n");
		}
	}
	return 0;
}
