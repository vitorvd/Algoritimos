//Nome Completo: Vitor Duda Versiani
//Matr�cula: UC21106822
//Curso: Ci�ncia da Computa��o

//Importando as bibliotecas (libs)
#include <stdio.h> //lib: importar fun��es printf e scanf
#include <locale.h> //lib: formatar textos em utf-8
#include <string.h> //lib: importar fun��es para trabalhar com strings
#include <stdlib.h> //lib: importar a fun��o de limpar a tela
#include <ctype.h> //lib: importar fun��o toupper

int main() {
	setlocale(LC_ALL, "Portuguese"); //defini��o da linguagem global do programa
	
	/*
		Aqui � realizado a cria��o do "struct", semelhante � um Objeto, na POO.
		Onde o struct Pessoa possui tr�s vari�veis:
		- nome, do tipo char[], que representa o nome da Pessoa;
		- idade, do tipo int, que representa a idade da Pessoa;
		- sexo, do tipo char, que representa o sexo da Pessoa.
	*/
	struct Pessoa {
		char nome[30]; //nova funcionalidade: nome da Pessoa
		int idade;
		char sexo;
	};
	
	int qntSessoesRealizadas = 0, pessoasAssistiramFilme = 0, pessoasMasculino = 0, pessoasFeminino = 0, maioresIdadeMasculino = 0, maioresIdadeFeminino = 0; //v�riaveis aux�liares
	int criancas = 0, adolescentes = 0, adultos = 0, idosos = 0; //vari�veis das classifica��es
	char nomeFilme[40]; //vari�vel representativa do nome do filme
	
	/*
		o "do" e o "while" s�o estruturas de repeti��o, onde ir� acontecer no min�mo uma vez e s� ser� quebrado quando "qntSessoesRealizadas" for 2
		o printf ir� mostrar a respectiva mensagem pro usu�rio;
		o scanf ir� armazenar o que o usu�rio digitou na respectiva vari�vel;
		o fflush(stdin) ir� retirar o lixo da mem�ria.
	*/
	do {
		printf("Quantas sess�es ser�o realizadas? ");
		scanf("%d", &qntSessoesRealizadas); //tipo int
		fflush(stdin);
	} while(qntSessoesRealizadas != 2);
	
	/*
		o "do" e o "while" s�o estruturas de repeti��o, onde ir� acontecer no min�mo uma vez e s� ser� quebrado quando a var "nomeFilme" n�o for nula
		o printf ir� mostrar a respectiva mensagem pro usu�rio;
		o fgets ir� armazenar o que o usu�rio digitou na respectiva vari�vel;
		o fflush(stdin) ir� retirar o lixo da mem�ria.
	*/
	do {
		printf("Qual o nome do filme? ");
		fgets(nomeFilme, 30, stdin);
		fflush(stdin);
		nomeFilme[strlen(nomeFilme) - 1] = '\0'; //remover o \n de uma poss�vel "entrada nula", e assim, respeitando a l�gica do while
	} while(strlen(nomeFilme) == 0);
	
	/*
		o "do" e o "while" s�o estruturas de repeti��o, onde ir� acontecer no min�mo uma vez e s� ser� quebrado quando a var "pessoasAssistiramFilme" for >= 10;
		o printf ir� mostrar a respectiva mensagem pro usu�rio;
		o scanf ir� armazenar o que o usu�rio digitou na respectiva vari�vel;
		o fflush(stdin) ir� retirar o lixo da mem�ria.
	*/
	do {
		printf("Quantas pessoas assistiram ao filme? ");
		scanf("%d", &pessoasAssistiramFilme);
		fflush(stdin);
	} while(pessoasAssistiramFilme < 1);
	
	// criando a var que ir� representar cada Pessoa do ecossistema, onde Pessoa � um struct.
	struct Pessoa pessoas[pessoasAssistiramFilme];
	
	// estrutura de repeti��o que ir� realizar a quantidade de vezes que foi informado pelo usu�rio em "pessoasAssistiramFilme"
	for(int i = 0; i < pessoasAssistiramFilme; i++) {
		system("cls"); //limpa a tela do usu�rio, para melhor usuabilidade e um design mais clean
		
		/*
			o "do" e o "while" s�o estruturas de repeti��o, onde ir� acontecer no min�mo uma vez e s� ser� quebrado quando a var "pessoas[i].nome" n�o for nulo
			o printf ir� mostrar a respectiva mensagem pro usu�rio;
			o fgets ir� armazenar o que o usu�rio digitou na respectiva vari�vel;
			o fflush(stdin) ir� retirar o lixo da mem�ria.
			**IMPORTANTE:** Essa � a nova funcionalidade pedida pela professora!
		*/
		do {
			printf("Qual o nome da %d� pessoa? ", i + 1); // "i + 1" pq a contagem do "for" come�a no zero, portanto, para mostrar visualmente de forma correta, isso � necess�rio
			fgets(pessoas[i].nome, 30, stdin);
			fflush(stdin);
			pessoas[i].nome[strlen(pessoas[i].nome) - 1] = '\0'; //remover o \n de uma poss�vel "entrada nula", e assim, respeitando a l�gica do while
		} while(strlen(pessoas[i].nome) == 0);
		
		/*
			o "do" e o "while" s�o estruturas de repeti��o, onde ir� acontecer no min�mo uma vez e s� ser� quebrado quando a var "pessoas[i].sexo" for "M" ou "F";
			o printf ir� mostrar a respectiva mensagem pro usu�rio;
			o scanf ir� armazenar o que o usu�rio digitou na respectiva vari�vel;
			o fflush(stdin) ir� retirar o lixo da mem�ria.
		*/
		do {	
			printf("Qual o sexo de %s? M = Masculino; F = Feminino: ", pessoas[i].nome);
			scanf("%c", &pessoas[i].sexo);
			pessoas[i].sexo = toupper(pessoas[i].sexo); //torno o que o usu�rio digitou mai�sculo (lib ctype.h)
			fflush(stdin);
		} while((pessoas[i].sexo != 'M') && (pessoas[i].sexo != 'F'));
	
		// l�gica que � respons�vel por incrementar uma Pessoa na respectiva vari�vel, sempre relativa ao seu sexo.
		if(pessoas[i].sexo == 'M')
			pessoasMasculino++;
		else
			pessoasFeminino++;
	
		/*
			o "do" e o "while" s�o estruturas de repeti��o, onde ir� acontecer no min�mo uma vez e s� ser� quebrado quando a var "pessoas[i].idade" >= 3 && <= 100
			o printf ir� mostrar a respectiva mensagem pro usu�rio;
			o scanf ir� armazenar o que o usu�rio digitou na respectiva vari�vel;
			o fflush(stdin) ir� retirar o lixo da mem�ria.
		*/
		do {
			printf("Qual a idade de %s? ", pessoas[i].nome);
			scanf("%d", &pessoas[i].idade);
			fflush(stdin);
		} while((pessoas[i].idade < 3) || (pessoas[i].idade > 100));
		
		/*
			l�gica que ir� dizer onde a Pessoa se encaixa de acordo com a classifica��o fornecida na atividade.
			as vars s�o incrementadas de acordo com a classifica��o
		*/
		if((pessoas[i].idade >= 3) && (pessoas[i].idade <= 13)) // de 3 at� 13 anos - Crian�as
			criancas++;
		else if((pessoas[i].idade >= 14) && (pessoas[i].idade <= 17)) // de 14 at� 17 anos - Adolescentes
			adolescentes++;
		else if((pessoas[i].idade >= 18) && (pessoas[i].idade <= 64)) // de 18 at� 64 anos - Adultos
			adultos++;
		else // de 65 at� 100 anos - Idosos
			idosos++;
	}
	
	system("cls"); //limpa a tela do usu�rio, para melhor usuabilidade e um design mais clean
	
	/*
		Aqui ser� exibido o relat�rio final pro usu�rio, ap�s todas as perguntas.
		Onde ser� infomado:
			- o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo masculino que assistiram ao filme
			- a quantidade de pessoas, seguindo a classifica��o da tabela
	*/
	printf("========================\n\n");
	printf("O filme assistido foi: %s, com %d espectadores.\n", nomeFilme, pessoasAssistiramFilme);
	printf("%d homens e %d mulheres assistiram ao filme.\n\n", pessoasMasculino, pessoasFeminino);
	printf("%d Crian�as (3 � 13 anos)\n", criancas);
	printf("%d Adolescentes (14 � 17 anos)\n", adolescentes);
	printf("%d Adultos (18 � 64 anos)\n", adultos);
	printf("%d Idosos (65 � 100 anos)\n\n", idosos);
	
	// estrutura de repeti��o para separar os maiores de idade
	for(int i = 0; i < pessoasAssistiramFilme; i++) {
		if(pessoas[i].idade >= 18){ // checando se � maior de idade (adulto)
			switch(pessoas[i].sexo){ //l�gica que separa de acordo com o sexo
				case 'M':
					maioresIdadeMasculino++; //incrementa
					break; // quebra o "switch"
				case 'F':
					maioresIdadeFeminino++; //incrementa
					break; // quebra o "switch"
				default: // valor desconhecido
					printf("** SEXO N�O INFORMADO **");
			}
		}
	}
	
	// restante do relat�rio
	printf("%d Homens maiores de idade assistiram ao filme %s.\n", maioresIdadeMasculino, nomeFilme);
	printf("%d Mulheres maiores de idade assistiram ao filme %s.", maioresIdadeFeminino, nomeFilme);
	printf("\n\n========================");	
	
	return 0; // retorno da fun��o
}
