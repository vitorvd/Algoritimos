#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	struct Pessoa {
		float altura = 0.0;
		char sexo;
	};

	struct Pessoa pessoas[3];
	float maiorAltura = 0.0, menorAltura = 10.0, mediaAlturaMulheres = 0.0, qntMulheres = 0.0;

	for(int i = 0; i < 3; i++) {
		system("cls");
		do {
			printf("Informe o sexo (M = Masculino; F = Feminino): ");
			scanf("%c", &pessoas[i].sexo);
			fflush(stdin);
		} while((pessoas[i].sexo != 'M') && (pessoas[i].sexo != 'F'));

		printf("Informe a altura: ");
		scanf("%f", &pessoas[i].altura);

		if(pessoas[i].altura >= maiorAltura) {
			maiorAltura = pessoas[i].altura;
		}

		if(pessoas[i].altura <= menorAltura) {
			menorAltura = pessoas[i].altura;
		}

		if(pessoas[i].sexo == 'F') {
			mediaAlturaMulheres += pessoas[i].altura;
			qntMulheres++;
		}
	}

	mediaAlturaMulheres /= qntMulheres;

	system("cls");
	printf("\n\nA maior altura é: %.2fm\n", maiorAltura);
	printf("A menor altura é: %.2fm\n", menorAltura);
	printf("A média de altura das mulheres é: %.2fm\n\n", mediaAlturaMulheres);

	return 0;
}
