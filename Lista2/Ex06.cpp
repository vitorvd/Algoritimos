#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numero;
	double resto;
	
	printf("Qual o n�mero? ");
	scanf("%d", &numero);
	
	resto = numero % 2;
	
	if(resto == 0){
		printf("O n�mero %d � PAR!", numero);
	}else{
		printf("O n�mero %d � IMPAR!", numero);
	}
}
