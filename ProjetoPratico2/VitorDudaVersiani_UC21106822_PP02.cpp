//Nome Completo: Vitor Duda Versiani
//Matr�cula: UC21106822
//Curso: Ci�ncia da Computa��o

#include <stdio.h> //lib: importar fun��es printf e scanf
#include <locale.h> //lib: formatar textos em utf-8
#include <string.h> //lib: importar fun��es para trabalhar com strings
#include <stdlib.h> //lib: importar a fun��o de limpar a tela
#include <ctype.h> //lib: importar fun��o toupper


/*
	Defini��o dos dois Structs principais do c�digo, al�m de seus atributos.
	Eles ser�o utilizados para manipular as Reservas de um determinado Voo.
	Struct Reserva => Armazena os dados de cada Cadeira do Avi�o, como idade, valor e status do Passageiro.
*/
struct Reserva {
	int id = 0;
	int idadePassageiro = 0;
	float valorPassagem = 0.0;
	char status = 'D'; // 'D' => Dispon�vel; 'R' => Reservada; 'C' => Venda confirmada;
};
	
struct Voo {
	char destino[50];
	int totalAssentos = 0;
	float valorPassagem = 0.0;
	struct Reserva reservas[200];
};

struct Voo voo;

/*
	Defini��o das fun��es auxiliares
*/
void efetuarReserva();
void cancelarReserva();
void confirmarReserva();
void exibirMapaAviao();
void exibirRelatorio();

//Defini��o da fun��o principal
int main() {
	setlocale(LC_ALL, "Portuguese");

	
	/*
		Defini��o das vari�veis do software
	*/
	int menuOpcaoPrincipal = 0;
	
	printf("================================================\n\n");
	printf("\tSeja bem-vindo, configure o Voo!");
	printf("\n\n================================================\n\n");
	
	/*
		Aqui � onde ocorrer� as configura��es iniciais do Voo, sendo feita pela companhia a�rea.
		Essas configura��es s�o: Destino final, quantidade de assentos e valor integral da Passagem.
	*/
	do {
		printf("Qual o destino? ");
		fgets(voo.destino, 50, stdin);
		fflush(stdin);
		voo.destino[strlen(voo.destino) - 1] = '\0'; //remover o \n de uma poss�vel "entrada nula", e assim, respeitando a l�gica do while
	} while(strlen(voo.destino) == 0);

	do {
		printf("Qual a quantidade de assentos? (Assentos min.: 90 e m�x.: 200): ");
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
		Inic�o do MENU
	*/
	while(menuOpcaoPrincipal != 9) {
		system("cls");
		printf("\n\n============== SEJA BEM-VINDO ==============\n\n");
		printf("� Voo com destino para %s, com %d assentos e com passagem no valor m�ximo de R$ %.2f.\n", voo.destino, voo.totalAssentos, voo.valorPassagem);
		printf("� O que voc� deseja fazer? \n\n");
		printf("[1] � Verifique a ocupa��o do Destino (Mapa do avi�o)\n");
		printf("[2] � Efetuar uma reserva\n");
		printf("[3] � Confirmar uma reserva\n");
		printf("[4] � Cancelar uma reserva\n");
		printf("[5] � Relat�rio do Avi�o\n");
		printf("[9] � Finalizar o Software");
		printf("\n\n============== SEJA BEM-VINDO ==============\n\n");
		printf("� O que voc� deseja fazer? ");
		scanf("%d", &menuOpcaoPrincipal);
		switch(menuOpcaoPrincipal) {
			case 1:
				//Mapa do Avi�o
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
				//Relat�rio
				exibirRelatorio();
				break;
			default:
				printf("\n\n============== VOLTE SEMPRE ==============\n\n");
				printf("\t� Que pena! Voc� j� vai...");
				printf("\n\n============== VOLTE SEMPRE ==============\n\n");
				menuOpcaoPrincipal = 9;
		}
	}
	return 0; // retorno da fun��o
}

/*
	Fun��o respons�vel por realizar uma Reserva (Neste momento, a Reserva ainda n�o est� Confirmada).
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
			printf("� Token de identifica��o da reserva: %d\n", voo.reservas[i].id);
			printf("� Idade do Passageiro: %d anos\n", voo.reservas[i].idadePassageiro);
			if(voo.reservas[i].idadePassageiro <= 5) {
				printf("� Valor da Passagem: %.2f (50%% OFF)", voo.reservas[i].valorPassagem);
			}else{
				printf("� Valor da Passagem: %.2f", voo.reservas[i].valorPassagem);
			}
			printf("\n\n============== RESERVADO ==============\n\n");
			reservou = true;
			system("pause");
			break;
		}
	}
	
	if(!reservou) {
		printf("\n\n============== SUPERLOTA��O ==============\n\n");
		printf("� Desculpe, mas o avi�o j� est� lotado!");
		printf("\n\n============== SUPERLOTA��O ==============\n\n");
	}
}

/*
	Fun��o respons�vel por Cancelar uma Reserva de acordo com o Token (id).
*/
void cancelarReserva() {
	int id = 0;
	do {
		printf("\nQual o Token (id) da Reserva para cancelamento? ");
		scanf("%d", &id);
		fflush(stdin);
	} while(id <= 0);
	
	id -= 1;  //Fa�o isso para respeitar o INDICE do Array 
	
	system("cls");
	if(voo.reservas[id].idadePassageiro > 0){
		voo.reservas[id].id = 0;
		voo.reservas[id].idadePassageiro = 0;
		voo.reservas[id].valorPassagem = 0.0;
		voo.reservas[id].status = 'D';
		printf("\n\n============== CANCELADA ==============\n\n");
		printf("� Reserva, do Token %d, cancelada!", id + 1);
		printf("\n\n============== CANCELADA ==============\n\n");
	}else{
		printf("� ERRO: Reserva, do Token %d, n�o encontrada!\n\n", id + 1);
	}
	system("pause");
}

/*
	Fun��o respons�vel por Confirmar uma Reserva de acordo com o Token (id).
*/
void confirmarReserva() {
	
	int id = 0;
	do {
		printf("\nQual o Token (id) da Reserva para confirma��o? ");
		scanf("%d", &id);
		fflush(stdin);
	} while(id <= 0);
	
	id -= 1; //Fa�o isso para respeitar o INDICE do Array 
	
	system("cls");
	if(voo.reservas[id].idadePassageiro > 0){
		voo.reservas[id].status = 'C';
		printf("\n\n============== CONFIRMADA ==============\n\n");
		printf("� Reserva, do Token %d, confirmada!", id + 1);
		printf("\n\n============== CONFIRMADA ==============\n\n");
	}else{
		printf("\n\n� ERRO: Reserva, do Token %d, n�o encontrada!\n\n", id + 1);
	}
	system("pause");
}

/*
	Fun��o respons�vel por exibir, na tela do Usu�rio, o Mapa do Avi�o.
	Com o respectivo status da cadeira ([D]ispon�vel, [R]eservado, [C]onfirmado);
*/
void exibirMapaAviao() {
	system("cls");
	printf("\n� Voo com destino para %s, com %d assentos e com passagem no valor m�ximo de R$ %.2f.\n", voo.destino, voo.totalAssentos, voo.valorPassagem);
	printf("\n============== MAPA DO AVI�O ==============\n\n");
	
	for(int i = 0; i < voo.totalAssentos - 5; i += 5) { 
		printf("%c	%c	%c	%c	%c \n", 
		voo.reservas[i].status, 
		voo.reservas[i + 1].status, 
		voo.reservas[i + 2].status, 
		voo.reservas[i + 3].status, 
		voo.reservas[i + 4].status);
	}
	printf("\n\n============== MAPA DO AVI�O ==============\n\n");
	system("pause");
}

/*
	Fun��o respons�vel por exibir o relat�rio do avi�o, das cadeiras dispon�veis, reservadas ou compradas.
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
	
	printf("\n\n============== RELAT�RIO ==============\n\n");
	printf("� Voo com destino para %s, com %d assentos e com passagem no valor m�ximo de R$ %.2f.\n", voo.destino, voo.totalAssentos, voo.valorPassagem);
	printf("� Dispon�veis: %d/%d\n", lugaresDisponiveis, voo.totalAssentos);
	printf("� Reservados: %d/%d\n", lugaresReservados, voo.totalAssentos);
	printf("� Confirmados: %d/%d\n", lugaresConfirmados, voo.totalAssentos);
	printf("� Capital Total: R$ %.2f reais", capitalTotal);
	printf("\n\n============== RELAT�RIO ==============\n\n");
	system("pause");
}
