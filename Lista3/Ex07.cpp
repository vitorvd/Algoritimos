#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	int opcao, qntAbacaxi = 0, qntMaca = 0, qntPera = 0, qntScanf = 0;
	
	printf("\nOl�, seja bem-vindo � Feira do Guar�!\n");
	while(opcao != 4){
		printf("\n[1] Abacaxi \n[2] Ma�� \n[3] Pera \n[4] Finalizar pedido");
		printf("\n\nSelecione qual fruta voc� deseja colocar no carrinho: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				printf("\nQuantos abacaxis voc� deseja comprar? ");
				scanf("%d", &qntScanf);
				qntAbacaxi += qntScanf;	
			break;
			case 2:
				printf("\nQuantos ma��s voc� deseja comprar? ");
				scanf("%d", &qntScanf);
				qntMaca += qntScanf;
			break;
			case 3:
				printf("\nQuantos peras voc� deseja comprar? ");
				scanf("%d", &qntScanf);
				qntPera += qntScanf;	
			break;
			case 4:
				printf("\nVoc� finalizou o pedido! \n");
				printf("Voc� comprou %d abacaxis, %d ma��s e %d peras", qntAbacaxi, qntMaca, qntPera);
			break;
			default:
				printf("\nOp��o n�o cadastrada, selecione uma dispon�vel!\n");
		}
	}
	return 0;
}
