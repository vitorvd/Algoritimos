#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qntNumerosFibonacci = 20, fibonacci1 = 1, fibonacci2 = 1, soma = 0;
	
	printf("Sequência de Fibonacci:\n\n");
	
	printf("%d, %d, ", fibonacci1, fibonacci2);
	
	for (int i = 3; i <= qntNumerosFibonacci; i = i + 1){
		
		soma = fibonacci1 + fibonacci2;  
		fibonacci1 = fibonacci2;                           
		fibonacci2 = soma; 
		
		printf("%d, ", soma);
	}
		
	return 0;
}
