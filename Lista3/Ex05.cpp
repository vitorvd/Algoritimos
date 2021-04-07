#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numFatorial, contador, resultadoFatorial = 1;
	
	printf("Informe o número que deseja calcular o fatorial: ");
	scanf("%d", &numFatorial);
	
	if(numFatorial > 0){
		contador = numFatorial;
		
		while(contador > 0){
			resultadoFatorial *= contador;
			contador--;
		}
	}
	
	printf("O valor do fatorial %d! é %d", numFatorial, resultadoFatorial);
	
	return 0;
}
