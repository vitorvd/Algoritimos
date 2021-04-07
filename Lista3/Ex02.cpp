#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numA, numB, contador, resultado = 0;
	bool temSinal;
	
	printf("Informe os n�meros que deseja multiplicar: \n");
	scanf("%d%d", &numA, &numB);
	
	//transformando poss�veis n�meros negativos em positivos (p/ facilitar a vida)
	if(numA < 0) {
		numA *= -1;
		//para tornar o resultado negativo
		temSinal = true;
	}
	
	if(numB < 0) {
		numB *= -1;
		//caso os dois sejam negativos, o resultado deve ser positivo
		if(temSinal) temSinal = false;	
	}

	if(numA >= numB){
		for(contador = 0; contador < numB; contador++){
			resultado += numA;
		}		
	}else{
		for(contador = 0; contador < numA; contador++){
			resultado += numB;
		}
	}
	
	if(temSinal){
		resultado *= -1;
	}
	
	printf("O resultado da multiplica��o entre %d e %d � %d", numA, numB, resultado);

	return 0;
}
