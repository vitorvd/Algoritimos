#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");

	char sexo, corOlho[9], corCabelo[9];
	int idade = 0, totalHabitantes = 0, maiorIdade = 0, habFeminina = 0;
	float porcentagemFeminina = 0;

	do {

        do {	
			printf("Informe o sexo, onde M = Masculino; F = Feminino: ");
			scanf("%c", &sexo);
			fflush(stdin);
		} while((sexo != 'M') && (sexo != 'F'));
        
        printf("Informe a cor dos olhos: ");
        scanf("%s", &corOlho);
        fflush(stdin);
        
        printf("Informe a cor dos cabelos: ");
        scanf("%s", &corCabelo);
        fflush(stdin);
        
        printf("Informe a idade: ");
        scanf("%d", &idade);
        fflush(stdin);
        
        if(idade == -1){
        	printf("\nCadastro de habitantes finalizado.\n");
        	break;
		}
		
		//validação de a idade informada é a maior, if ternário
		maiorIdade = idade >= maiorIdade ? idade : maiorIdade;
		
		if((sexo == 'F') && (idade >= 18) && (idade <= 35) && (strcmp(corOlho,"verdes") == 0) && (strcmp(corCabelo,"loiros") == 0))
			habFeminina++;
		
		totalHabitantes++;
	} while (idade != -1);
	
	
	system("cls");
	
	porcentagemFeminina = ((float) habFeminina/(float) totalHabitantes) * 100;
	
	printf("\n\nA maior idade é: %d\n", maiorIdade);
	printf("Porcentagem de mulheres com olhos verdes, cabelos loiros que estão entre 18 e 35 anos: %.2f\n\n", porcentagemFeminina);
	
	return 0;
}
