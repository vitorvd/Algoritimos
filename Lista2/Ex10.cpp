#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numeroA, numeroB, numeroC, menorNumero;
	
	printf("Qual o 1� n�mero? ");
	scanf("%d", &numeroA); //10
	
	printf("Qual o 2� n�mero? ");
	scanf("%d", &numeroB); //15
	
	printf("Qual o 3� n�mero? ");
	scanf("%d", &numeroC); //8

	if((numeroA <= numeroB) && (numeroA <= numeroC)){
		menorNumero = numeroA;
	}else if((numeroB <= numeroA) && (numeroB <= numeroC)){
		menorNumero = numeroB;
	}else if((numeroC <= numeroA) && (numeroC <= numeroB)){
		menorNumero = numeroC; //8 (numeroC � menor de todos)
	}

	printf("O menor n�mero � o: %d", menorNumero); // Sa�da: 8

}
