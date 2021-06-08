//Nome Completo: Vitor Duda Versiani
//Matrícula: UC21106822
//Curso: Ciência da Computação

#include <stdio.h> //lib: importar funções printf e scanf
#include <locale.h> //lib: formatar textos em utf-8
#include <string.h> //lib: importar funções para trabalhar com strings
#include <stdlib.h> //lib: importar a função de limpar a tela
#include <ctype.h> //lib: importar função toupper


/*
	Definição dos dois Structs principais do código, além de seus atributos.
	Eles serão utilizados para manipular as Reservas de um determinado Voo.
	Struct Reserva => Armazena os dados de cada Cadeira do Avião, como idade, valor e status do Passageiro.
*/
struct Reserva {
	int id = 0;
	int idadePassageiro = 0;
	float valorPassagem = 0.0;
	char status = 'D'; // 'D' => Disponível; 'R' => Reservada; 'C' => Venda confirmada;
};
	
struct Voo {
	char destino[50];
	int totalAssentos = 0;
	float valorPassagem = 0.0;
	struct Reserva reservas[200];
};

struct Voo voo;

/*
	Definição das funções auxiliares
*/
void efetuarReserva();
void cancelarReserva();
void confirmarReserva();
void exibirMapaAviao();
void exibirRelatorio();

//Definição da função principal
int main() {
	setlocale(LC_ALL, "Portuguese");

	
	/*
		Definição das variáveis do software
	*/
	int menuOpcaoPrincipal = 0;
	
	printf("================================================\n\n");
	printf("\tSeja bem-vindo, configure o Voo!");
	printf("\n\n================================================\n\n");
	
	/*
		Aqui é onde ocorrerá as configurações iniciais do Voo, sendo feita pela companhia aérea.
		Essas configurações são: Destino final, quantidade de assentos e valor integral da Passagem.
	*/
	do {
		printf("Qual o destino? ");
		fgets(voo.destino, 50, stdin);
		fflush(stdin);
		voo.destino[strlen(voo.destino) - 1] = '\0'; //remover o \n de uma possível "entrada nula", e assim, respeitando a lógica do while
	} while(strlen(voo.destino) == 0);

	do {
		printf("Qual a quantidade de assentos? (Assentos min.: 90 e máx.: 200): ");
		scanf("%d", &voo.totalAssentos);
		fflush(stdin);
	} while(voo.totalAssentos < 90 || voo.totalAssentos > 200);

	do {
		printf("Qual o valor integral, em reais, da passagem? ");
		scanf("%f", &voo.valorPassagem);
		fflush(stdin);
	} while(voo.valorPassagem < 1);
	
	system("cls"); //Limpar a tela
	
	/*
		Inicío do MENU
	*/
	while(menuOpcaoPrincipal != 9) {
		system("cls");
		printf("\n\n============== SEJA BEM-VINDO ==============\n\n");
		printf("» Voo com destino para %s, com %d assentos e com passagem no valor máximo de R$ %.2f.\n", voo.destino, voo.totalAssentos, voo.valorPassagem);
		printf("» O que você deseja fazer? \n\n");
		printf("[1] » Verifique a ocupação do Destino (Mapa do avião)\n");
		printf("[2] » Efetuar uma reserva\n");
		printf("[3] » Confirmar uma reserva\n");
		printf("[4] » Cancelar uma reserva\n");
		printf("[5] » Relatório do Avião\n");
		printf("[9] » Finalizar o Software");
		printf("\n\n============== SEJA BEM-VINDO ==============\n\n");
		printf("» O que você deseja fazer? ");
		scanf("%d", &menuOpcaoPrincipal);
		switch(menuOpcaoPrincipal) {
			case 1:
				//Mapa do Avião
				exibirMapaAviao();
				break;
			case 2:
				//Efetuar uma Reserva
				efetuarReserva();
				break;
			case 3:
				//Confirmar uma Reserva
				confirmarReserva();
				break;
			case 4:
				//Cancelar uma Reserva
				cancelarReserva();
				break;
			case 5:
				//Relatório
				exibirRelatorio();
				break;
			default:
				printf("\n\n============== VOLTE SEMPRE ==============\n\n");
				printf("\t» Que pena! Você já vai...");
				printf("\n\n============== VOLTE SEMPRE ==============\n\n");
				menuOpcaoPrincipal = 9;
		}
	}
	return 0; // retorno da função
}

/*
	Função responsável por realizar uma Reserva (Neste momento, a Reserva ainda não está Confirmada).
*/
void efetuarReserva() {
	system("cls");
	bool reservou = false;
	for(int i = 0; i < voo.totalAssentos; i++) {
		if(voo.reservas[i].idadePassageiro == 0) {
			voo.reservas[i].id = i + 1;
			voo.reservas[i].status = 'R';
			
			do {
				printf("Qual a idade do passageiro? ");
				scanf("%d", &voo.reservas[i].idadePassageiro);
				fflush(stdin);
			} while(voo.reservas[i].idadePassageiro < 1);
			
			if(voo.reservas[i].idadePassageiro <= 5) {
				voo.reservas[i].valorPassagem = 0.5 * voo.valorPassagem;
			}else{
				voo.reservas[i].valorPassagem = voo.valorPassagem;
			}
			
			system("cls");
			
			printf("\n\n============== RESERVADO ==============\n\n");
			printf("» Token de identificação da reserva: %d\n", voo.reservas[i].id);
			printf("» Idade do Passageiro: %d anos\n", voo.reservas[i].idadePassageiro);
			if(voo.reservas[i].idadePassageiro <= 5) {
				printf("» Valor da Passagem: %.2f (50%% OFF)", voo.reservas[i].valorPassagem);
			}else{
				printf("» Valor da Passagem: %.2f", voo.reservas[i].valorPassagem);
			}
			printf("\n\n============== RESERVADO ==============\n\n");
			reservou = true;
			system("pause");
			break;
		}
	}
	
	if(!reservou) {
		printf("\n\n============== SUPERLOTAÇÃO ==============\n\n");
		printf("» Desculpe, mas o avião já está lotado!");
		printf("\n\n============== SUPERLOTAÇÃO ==============\n\n");
	}
}

/*
	Função responsável por Cancelar uma Reserva de acordo com o Token (id).
*/
void cancelarReserva() {
	int id = 0;
	do {
		printf("\nQual o Token (id) da Reserva para cancelamento? ");
		scanf("%d", &id);
		fflush(stdin);
	} while(id <= 0);
	
	id -= 1;  //Faço isso para respeitar o INDICE do Array 
	
	system("cls");
	if(voo.reservas[id].idadePassageiro > 0){
		voo.reservas[id].id = 0;
		voo.reservas[id].idadePassageiro = 0;
		voo.reservas[id].valorPassagem = 0.0;
		voo.reservas[id].status = 'D';
		printf("\n\n============== CANCELADA ==============\n\n");
		printf("» Reserva, do Token %d, cancelada!", id + 1);
		printf("\n\n============== CANCELADA ==============\n\n");
	}else{
		printf("» ERRO: Reserva, do Token %d, não encontrada!\n\n", id + 1);
	}
	system("pause");
}

/*
	Função responsável por Confirmar uma Reserva de acordo com o Token (id).
*/
void confirmarReserva() {
	
	int id = 0;
	do {
		printf("\nQual o Token (id) da Reserva para confirmação? ");
		scanf("%d", &id);
		fflush(stdin);
	} while(id <= 0);
	
	id -= 1; //Faço isso para respeitar o INDICE do Array 
	
	system("cls");
	if(voo.reservas[id].idadePassageiro > 0){
		voo.reservas[id].status = 'C';
		printf("\n\n============== CONFIRMADA ==============\n\n");
		printf("» Reserva, do Token %d, confirmada!", id + 1);
		printf("\n\n============== CONFIRMADA ==============\n\n");
	}else{
		printf("\n\n» ERRO: Reserva, do Token %d, não encontrada!\n\n", id + 1);
	}
	system("pause");
}

/*
	Função responsável por exibir, na tela do Usuário, o Mapa do Avião.
	Com o respectivo status da cadeira ([D]isponível, [R]eservado, [C]onfirmado);
*/
void exibirMapaAviao() {
	system("cls");
	printf("\n» Voo com destino para %s, com %d assentos e com passagem no valor máximo de R$ %.2f.\n", voo.destino, voo.totalAssentos, voo.valorPassagem);
	printf("\n============== MAPA DO AVIÃO ==============\n\n");
	
	for(int i = 0; i < voo.totalAssentos - 5; i += 5) { 
		printf("%c	%c	%c	%c	%c \n", 
		voo.reservas[i].status, 
		voo.reservas[i + 1].status, 
		voo.reservas[i + 2].status, 
		voo.reservas[i + 3].status, 
		voo.reservas[i + 4].status);
	}
	printf("\n\n============== MAPA DO AVIÃO ==============\n\n");
	system("pause");
}

/*
	Função responsável por exibir o relatório do avião, das cadeiras disponíveis, reservadas ou compradas.
*/
void exibirRelatorio() {
	int lugaresDisponiveis = 0, lugaresReservados = 0, lugaresConfirmados = 0;
	float capitalTotal = 0.0;
	for(int i = 0; i < voo.totalAssentos; i++) {
		if(voo.reservas[i].status == 'R') {
			lugaresReservados++;
		}else if(voo.reservas[i].status == 'C') {
			lugaresConfirmados++;
			capitalTotal += voo.reservas[i].valorPassagem;
		}else{
			lugaresDisponiveis++;
		}
	}
	
	system("cls");
	
	printf("\n\n============== RELATÓRIO ==============\n\n");
	printf("» Voo com destino para %s, com %d assentos e com passagem no valor máximo de R$ %.2f.\n", voo.destino, voo.totalAssentos, voo.valorPassagem);
	printf("» Disponíveis: %d/%d\n", lugaresDisponiveis, voo.totalAssentos);
	printf("» Reservados: %d/%d\n", lugaresReservados, voo.totalAssentos);
	printf("» Confirmados: %d/%d\n", lugaresConfirmados, voo.totalAssentos);
	printf("» Capital Total: R$ %.2f reais", capitalTotal);
	printf("\n\n============== RELATÓRIO ==============\n\n");
	system("pause");
}
