#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int dia = 0, mes = 0, ano = 0;
	
	do {
		printf("Informe o dia: ");
		scanf("%d", &dia);
	} while(dia < 1 || dia > 31);

	do {
		printf("Informe o mês: ");
		scanf("%d", &mes);
	} while(mes < 1 || mes > 12);
	
	do {
		printf("Informe o ano: ");
		scanf("%d", &ano);
	} while(dia < 1 || dia > 31);
	
	if((mes == 2) && (dia > 29) ){
		printf("O dia %d é inválido para o mês %d", dia, mes);
	}else if((mes != 2) && !((dia == 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))){
		printf("O dia %d é inválido para o mês %d", dia, mes);
	}else if(!((mes == 2) && (dia == 29) && (ano % 4 == 0))){
		printf("%d não é um ano bissexto, portanto, não há o 29º dia.", ano);
	}else{
		printf("A data %d/%d/%d é válida", dia, mes, ano);
	}
	
	
	return 0;
}
