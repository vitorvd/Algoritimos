#include<stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int numero;
	
	printf("Qual o valor do n�mero que voc� deseja descobrir o seu m�dulo? ");
	scanf("%d", &numero);
	
	printf("O m�dulo �: %d", abs(numero));
	
	return 0;
}
