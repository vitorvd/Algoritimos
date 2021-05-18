#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	struct Pais {
		char nomePais[35];
		int medalhasOuro = 0, medalhasPrata = 0, medalhasBronze = 0, pontuacaoTotal = 0;
	};	
	
	int pesoOuro = 3, pesoPrata = 2, pesoBronze = 1;
	
	struct Pais paises[2], primeiroPais, segundoPais, terceiroPais;
	
	for (int i = 0; i < 3; i++) {
		printf("Qual o nome do %dº país? ", i + 1);
		scanf("%s", &paises[i].nomePais);
		
		printf("Quantas medalhas de Ouro o país %s ganhou? ", paises[i].nomePais);
		scanf("%d", &paises[i].medalhasOuro);
		
		printf("Quantas medalhas de Prata o país %s ganhou? ", paises[i].nomePais);
		scanf("%d", &paises[i].medalhasPrata);
		
		printf("Quantas medalhas de Bronze o país %s ganhou? ", paises[i].nomePais);
		scanf("%d", &paises[i].medalhasBronze);
		
		paises[i].pontuacaoTotal = (paises[i].medalhasOuro * pesoOuro) + (paises[i].medalhasPrata * pesoPrata) + (paises[i].medalhasBronze * pesoBronze);
		
		if(paises[i].pontuacaoTotal >= primeiroPais.pontuacaoTotal){
			terceiroPais = segundoPais;
			segundoPais = primeiroPais;
			primeiroPais = paises[i];
		}else if(paises[i].pontuacaoTotal >= segundoPais.pontuacaoTotal){
			terceiroPais = segundoPais;
			segundoPais = paises[i];
		}else{
			terceiroPais = paises[i];
		}
		
		system("cls");
	}
		
	printf("1º País: %s com %d pts. \n", primeiroPais.nomePais, primeiroPais.pontuacaoTotal);
	printf("2º País: %s com %d pts. \n", segundoPais.nomePais, segundoPais.pontuacaoTotal);
	printf("3º País: %s com %d pts. \n", terceiroPais.nomePais, terceiroPais.pontuacaoTotal);
		
	return 0;
}
