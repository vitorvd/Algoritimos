#include<stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int velocidadeCarro;
	char placaCarro[8];
	
	printf("Qual a velocidade do carro, em km/h? ");
	scanf("%d", &velocidadeCarro);	
	
	printf("Qual a placa do carro, no padrão XXX-0000? ");
	scanf("%s", &placaCarro);
	
	if(velocidadeCarro > 80){
		double percentual = ((velocidadeCarro - 80) / 80) * 100;
		printf("O carro, de placa %s, estava à %dkm/h, excedendo em %.0lf%% o limite e foi multado.", placaCarro, velocidadeCarro, percentual);
	}else{
		printf("O carro, de placa %s, estava a %dkm/h no Eixo Rodoviário, portanto não foi multado.",  placaCarro, velocidadeCarro); //exercício 5
	}
		
	return 0;
}
