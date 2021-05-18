#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int numeroInformado = 0, quantidadeNumerosInformados = 0;
	float mediaNumerosInformados = 0.0;
	
	do {
		printf("Informe um número: ");
		scanf("%d", &numeroInformado);
		
		if(numeroInformado >= 2 && numeroInformado % 2 == 0) {
			mediaNumerosInformados += numeroInformado;
			quantidadeNumerosInformados++;
		}
		
	} while(numeroInformado != 0);
	
	mediaNumerosInformados /= quantidadeNumerosInformados;
	
	system("cls");
	printf("\nA média, dos números pares, é: %.2f\n", mediaNumerosInformados);
	
	return 0;
}
