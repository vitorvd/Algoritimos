#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int vinhosTinto = 0, vinhosBranco = 0, vinhosRose = 0, totalVinhos = 0;
	float porcentagemTinto = 0.0, porcentagemBranco = 0.0, porcentagemRose = 0.0;
	
	printf("Quantos Vinhos Tinto existem no estoque? ");
	scanf("%d", &vinhosTinto);

	printf("Quantos Vinhos Branco existem no estoque? ");
	scanf("%d", &vinhosBranco);
	
	printf("Quantos Vinhos Rosê existem no estoque? ");
	scanf("%d", &vinhosRose);
	
	totalVinhos = vinhosTinto + vinhosBranco + vinhosRose;
	
	porcentagemTinto = (float) (vinhosTinto/totalVinhos) * 100;
	porcentagemBranco = (float) (vinhosBranco/totalVinhos) * 100;
	porcentagemRose = (float) (vinhosRose/totalVinhos) * 100;
	
	system("cls");
	printf("Vinhos Tinto: %d (%.2f porcento)\n", vinhosTinto, porcentagemTinto);
	printf("Vinhos Branco: %d (%.2f porcento)\n", vinhosBranco, porcentagemBranco);
	printf("Vinhos Rosê: %d (%.2f porcento)\n", vinhosRose, porcentagemRose);
	
	return 0;
}
