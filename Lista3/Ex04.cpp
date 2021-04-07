#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	int n, contador;
	float resultado;

	printf("\nFórmula: H = 1/1+1/2+1/3+ ... +1/N.\n");
	printf("Informe o valor de N: ");
	scanf("%d", &n);
	
	for(contador = 1; contador <= n; contador++){
		resultado += 1.0/contador;
	}
	
	printf("\nO valor de H é: %.2f \n", resultado);
	
	return 0;
}
