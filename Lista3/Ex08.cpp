#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	struct Produto{
		int id;
		float preco;
	};
	
	int porcentagemAumento = 10, qntProdutos = 0;

	printf("Quantos produtos você deseja cadastrar? ");
	scanf("%d", &qntProdutos);
	
	//corrigir e funcionar de acordo com o indice
	qntProdutos--;
	
	Produto produtos[qntProdutos];
	
	for(int i = 0; i <= qntProdutos; i++) {
		printf("\nQual o id do produto? ");
		scanf("%d", &produtos[i].id);
		fflush(stdin);
		
		printf("Qual o atual valor do produto? ");
		scanf("%f", &produtos[i].preco);
		fflush(stdin);
		produtos[i].preco += (produtos[i].preco * porcentagemAumento) / 100;
	}
	 
	int len = sizeof(produtos) / sizeof(produtos[0]);
	
	printf("\n=-=-=-=- PRODUTOS -=-=-=-=\n\n");
	for(int i = 0; i <= len; i++){
		printf("Identificador: %d || Preço: R$ %.2f reais.\n", produtos[i].id, produtos[i].preco);
	}
	printf("\n=-=-=-=- PRODUTOS -=-=-=-=");
	
	return 0;
}
