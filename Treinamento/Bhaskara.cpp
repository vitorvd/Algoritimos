//Entrada: a, b, c
//Saída: x1 e x2
//Processamento: calcular bhaskara

#include <stdio.h> // inclusão da biblioteca que possuí as funções "printf" e "scanf"
#include <math.h> // inclusão da biblioteca que irá nos auxíliar nos cálculos matemáticos

int main(){ // início do algoritmo: função main

	double a, b, c, delta, x1, x2; // declarações de variáveis
	
	printf("Qual o valor de A "); // impressão do texto na tela do usuário
	scanf("%lf", &a); // vinculação do valor digitado pelo usuário à respectiva variável (no caso, valor de A)

	printf("Qual o valor de B "); // impressão do texto na tela do usuário
	scanf("%lf", &b);// vinculação do valor digitado pelo usuário à respectiva variável (no caso, valor de B)

	printf("Qual o valor de C "); // impressão do texto na tela do usuário
	scanf("%lf", &c); // vinculação do valor digitado pelo usuário à respectiva variável (no caso, valor de C)
	
	delta = (pow(b, 2)) - 4 * a * c; // lineariazação da fórmula de delta, com a inclsuão da função "pow" para calcular potência

	if((delta < 0) || (a == 0)) { //condicionamento das quebra de padrões da bhaskara, ou seja: delta MENOR que ZERO ou A IGUAL a ZERO
		printf("Bhaskara fora dos padrões, não foi possível calcular"); // impressão do texto na tela do usuário
	}else if(delta == 0){ // condicionamento de quando delta for IGUAL a ZERO, portanto, apenas um valor de X.
		x1 = (-(b) + sqrt(delta)) / 2 * a; // lineariazação da fórmula de bhaskara (calculando x1 e x2), com a inclusão da função "sqrt" para calcular raiz quadrade
		printf("Os valores sao: \nX1: %.2lf \nX2: %.2lf", x1, x1); // impressão do texto na tela do usuário, com os respectivos valores de X1 e X2.
	}else{ // um bhaskara normal, com duas raizes e delta positivo
		x1 = (-(b) + sqrt(delta)) / 2 * a; // lineariazação da fórmula de bhaskara (calculando x1), com a inclusão da função "sqrt" para calcular raiz quadrade
		x2 = (-(b) - sqrt(delta)) / 2 * a; // lineariazação da fórmula de bhaskara (calculando x2), com a inclusão da função "sqrt" para calcular raiz quadrade
		printf("Os valores sao: \nX1: %.2lf \nX2: %.2lf", x1, x2); // impressão do texto na tela do usuário, com os respectivos valores de X1 e X2.
	}
	
	return 0; // retorno padrão da função "main"
} // fim do algoritmo 
