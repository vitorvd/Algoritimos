#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float numeroA, numeroB, diferenca;
	
	printf("Qual o 1� n�mero? ");
	scanf("%f", &numeroA);
	
	printf("Qual o 2� n�mero? ");
	scanf("%f", &numeroB);
	
	if(numeroA >= numeroB){
		diferenca = numeroA - numeroB;
	}else{
		diferenca = numeroB - numeroA;
	}
	
	printf("A diferen�a entra os n�meros %.1f e %.1f � de %.1f", numeroA, numeroB, diferenca);

}
