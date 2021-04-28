#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int qntHomens, qntMulheres = 0;
	float nota, mediaHomens, mediaMulheres;
	char sexo;
	
	while(nota >= 0){
		while((sexo != 'M') && (sexo != 'm') && (sexo != 'F') && (sexo != 'f')){
			printf("Digite o sexo (M - Masculino e F - Feminino): ");
			scanf("%c", &sexo);
		}
		printf("\nQual a nota? ");
		scanf("%f", &nota);
		
		if(nota >= 0){
			if((sexo == 'M') || (sexo == 'm')) {
				qntHomens++;
				mediaHomens += nota;
			}else{
				qntMulheres++;
				mediaMulheres += nota;
			}
		}

		sexo = 'V';
	}
	
	mediaHomens = mediaHomens / qntHomens;
	mediaMulheres = mediaMulheres / qntMulheres;
	
	printf("\nA média de nota dos %d homens: %.2f", qntHomens, mediaHomens);
	printf("\nA média de nota das %d mulheres: %.2f\n", qntMulheres, mediaMulheres);	
	
	return 0;
}
