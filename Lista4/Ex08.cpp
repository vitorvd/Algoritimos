#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float anacletoAltura = 1.50, felisbertoAltura = 1.10, cmPorAnoAnacleto = 0.2, cmPorAnoFelisberto = 0.3;
	int anos = 0;
	
	while(anacletoAltura >= felisbertoAltura) {
		anacletoAltura += cmPorAnoAnacleto;
		felisbertoAltura += cmPorAnoFelisberto;
		anos++;
	}
	
	printf("\n\nFelisberto (%.2fm) será maior que Anacleto (%.2fm) em %d anos de crescimento.", felisbertoAltura, anacletoAltura, anos);
	
	return 0;
}
