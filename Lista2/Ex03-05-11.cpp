#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	float a, b, c, soma1, soma2, soma3;
	char tipo[40];
	
	printf("Para formar um tri�ngulo, um lado X tem que ser menor que a soma de Y e Z.\n");
	printf("Digite o valor do lado A: ");
	scanf("%f", &a);
	
	printf("Digite o valor do lado B: ");
	scanf("%f", &b);
	
	printf("Digite o valor do lado C: ");
	scanf("%f",&c);
	
	soma1 = a + b;
	soma2 = a + c;
	soma3 = b + c;
	
	if( (a < soma3) && (b < soma2) && (c < soma1) ){
		//exerc�cio 11
		if((a == b) && (a == c) && (b == c)){
			strcpy(tipo, "Equil�tero");
		}else if((a != b) && (a != c) && (b != c)){
			strcpy(tipo, "Escaleno");
		}else{
			strcpy(tipo, "Is�sceles");
		}
		printf("Com esses valores, � poss�vel criar um tri�ngulo do tipo %s.", tipo);
	}else{
		printf("Com esses valores, n�o � poss�vel criar um tri�ngulo."); //exerc�cio 5
	}
	
}
