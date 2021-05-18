#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int primeiroNumero = 0, segundoNumero = 0;
	
	do {
		printf("Informe o 1º Número: ");
		scanf("%d", &primeiroNumero);
	} while(primeiroNumero < 0);
		
	do {
		printf("Informe o 2º Número: ");
		scanf("%d", &segundoNumero);
	} while(segundoNumero < 0);

	for(int i = primeiroNumero; i < segundoNumero; i++) {
		for(int test = 2; test < i; test++){
			if(i % test != 0){
				printf("%d, ", i);
			}
		}
	}
	
	
	return 0;
}
