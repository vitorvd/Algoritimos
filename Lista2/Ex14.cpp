#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numeroA, numeroB, numeroC, maiorNumero;
	
	printf("Qual o 1� n�mero? ");
	scanf("%d", &numeroA);
	
	printf("Qual o 2� n�mero? ");
	scanf("%d", &numeroB);
	
	printf("Qual o 3� n�mero? ");
	scanf("%d", &numeroC);

	if((numeroA >= numeroB) && (numeroA >= numeroC)){
		maiorNumero = numeroA;
	}else if((numeroB >= numeroA) && (numeroB >= numeroC)){
		maiorNumero = numeroB;
	}else if((numeroC >= numeroA) && (numeroC >= numeroB)){
		maiorNumero = numeroC;
	}

	printf("O maior n�mero � o: %d", maiorNumero);

}
