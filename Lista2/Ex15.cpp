#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float horasUtilizadas, preco;
	int valorBasico = 30; // R$ 30 por at� 20 horas
	
	printf("Quantas horas de internet foram utilizadas? ");
	scanf("%f", &horasUtilizadas);
	
	if(horasUtilizadas > 20){
		preco = valorBasico + ((horasUtilizadas - 20) * 3); // 10% de R$ 30,00, onde ser� aplicadas nas horas extras
	}else{
		preco = valorBasico;
	}
	
	printf("Qual foi manito?! Voc� est� devendo R$ %.2f reais para NET CLARO.", preco);	
	
}
