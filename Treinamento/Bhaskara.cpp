//Entrada: a, b, c
//Sa�da: x1 e x2
//Processamento: calcular bhaskara

#include <stdio.h> // inclus�o da biblioteca que possu� as fun��es "printf" e "scanf"
#include <math.h> // inclus�o da biblioteca que ir� nos aux�liar nos c�lculos matem�ticos

int main(){ // in�cio do algoritmo: fun��o main

	double a, b, c, delta, x1, x2; // declara��es de vari�veis
	
	printf("Qual o valor de A "); // impress�o do texto na tela do usu�rio
	scanf("%lf", &a); // vincula��o do valor digitado pelo usu�rio � respectiva vari�vel (no caso, valor de A)

	printf("Qual o valor de B "); // impress�o do texto na tela do usu�rio
	scanf("%lf", &b);// vincula��o do valor digitado pelo usu�rio � respectiva vari�vel (no caso, valor de B)

	printf("Qual o valor de C "); // impress�o do texto na tela do usu�rio
	scanf("%lf", &c); // vincula��o do valor digitado pelo usu�rio � respectiva vari�vel (no caso, valor de C)
	
	delta = (pow(b, 2)) - 4 * a * c; // lineariaza��o da f�rmula de delta, com a inclsu�o da fun��o "pow" para calcular pot�ncia

	if((delta < 0) || (a == 0)) { //condicionamento das quebra de padr�es da bhaskara, ou seja: delta MENOR que ZERO ou A IGUAL a ZERO
		printf("Bhaskara fora dos padr�es, n�o foi poss�vel calcular"); // impress�o do texto na tela do usu�rio
	}else if(delta == 0){ // condicionamento de quando delta for IGUAL a ZERO, portanto, apenas um valor de X.
		x1 = (-(b) + sqrt(delta)) / 2 * a; // lineariaza��o da f�rmula de bhaskara (calculando x1 e x2), com a inclus�o da fun��o "sqrt" para calcular raiz quadrade
		printf("Os valores sao: \nX1: %.2lf \nX2: %.2lf", x1, x1); // impress�o do texto na tela do usu�rio, com os respectivos valores de X1 e X2.
	}else{ // um bhaskara normal, com duas raizes e delta positivo
		x1 = (-(b) + sqrt(delta)) / 2 * a; // lineariaza��o da f�rmula de bhaskara (calculando x1), com a inclus�o da fun��o "sqrt" para calcular raiz quadrade
		x2 = (-(b) - sqrt(delta)) / 2 * a; // lineariaza��o da f�rmula de bhaskara (calculando x2), com a inclus�o da fun��o "sqrt" para calcular raiz quadrade
		printf("Os valores sao: \nX1: %.2lf \nX2: %.2lf", x1, x2); // impress�o do texto na tela do usu�rio, com os respectivos valores de X1 e X2.
	}
	
	return 0; // retorno padr�o da fun��o "main"
} // fim do algoritmo 
