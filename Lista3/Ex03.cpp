#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float alturaAnalise, menorAltura;
	int pessoasMesmaAltura, contador = 1;

	while(contador <= 10){
		printf("Informa a altura da %dº pessoa: ", contador);
		scanf("%f", &alturaAnalise);
		
		if(alturaAnalise == menorAltura) {
			pessoasMesmaAltura++;
		}else if((alturaAnalise < menorAltura) || (menorAltura == 0)){
			menorAltura = alturaAnalise;
		}
		
		contador++;
	}
	
	printf("%d pessoas possuem a MENOR altura de %.2fm", pessoasMesmaAltura, menorAltura);
	
	return 0;
}
