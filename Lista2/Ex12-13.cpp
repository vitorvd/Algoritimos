#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int ddd;
	char cidade[30];
	
	printf("Qual o DDD? ");
	scanf("%d", &ddd); // 61
	
	switch(ddd){
		case 61:
			strcpy(cidade, "Bras�lia"); //definindo cidade = Bras�lia
		break;
		case 71:
			strcpy(cidade, "Salvador");
		case 11:
			strcpy(cidade, "S�o Paulo");
		break;
		case 21:
			strcpy(cidade, "Rio de Janeiro");
		break;
		case 32:
			strcpy(cidade, "Juiz de Fora");
		break;
		case 19:
			strcpy(cidade, "Campinas");
		break;
		case 27:
			strcpy(cidade, "Vit�ria");
		break;
		case 31:
			strcpy(cidade, "Belo Horizonte");
		break;
		default:
			strcpy(cidade, "Sem idenfica��o");
	}

	printf("A cidade com DDD %d �: %s", ddd, cidade); // Sa�da: A cidade com DDD 61 �: Bras�lia

}
