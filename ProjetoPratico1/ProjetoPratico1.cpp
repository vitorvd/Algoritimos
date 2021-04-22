//Nome Completo: Vitor Duda Versiani
//Matrícula: UC21106822
//Curso: Ciência da Computação

//Importando as bibliotecas (libs)
#include <stdio.h> //lib: importar funções printf e scanf
#include <locale.h> //lib: formatar textos em utf-8
#include <string.h> //lib: importar funções para trabalhar com strings
#include <stdlib.h> //lib: importar a função de limpar a tela
#include <ctype.h> //lib: importar função toupper

int main() {
	setlocale(LC_ALL, "Portuguese"); //definição da linguagem global do programa
	
	/*
		Aqui é realizado a criação do "struct", semelhante à um Objeto, na POO.
		Onde o struct Pessoa possui três variáveis:
		- nome, do tipo char[], que representa o nome da Pessoa;
		- idade, do tipo int, que representa a idade da Pessoa;
		- sexo, do tipo char, que representa o sexo da Pessoa.
	*/
	struct Pessoa {
		char nome[30]; //nova funcionalidade: nome da Pessoa
		int idade;
		char sexo;
	};
	
	int qntSessoesRealizadas = 0, pessoasAssistiramFilme = 0, pessoasMasculino = 0, pessoasFeminino = 0, maioresIdadeMasculino = 0, maioresIdadeFeminino = 0; //váriaveis auxíliares
	int criancas = 0, adolescentes = 0, adultos = 0, idosos = 0; //variáveis das classificações
	char nomeFilme[40]; //variável representativa do nome do filme
	
	/*
		o "do" e o "while" são estruturas de repetição, onde irá acontecer no minímo uma vez e só será quebrado quando "qntSessoesRealizadas" for 2
		o printf irá mostrar a respectiva mensagem pro usuário;
		o scanf irá armazenar o que o usuário digitou na respectiva variável;
		o fflush(stdin) irá retirar o lixo da memória.
	*/
	do {
		printf("Quantas sessões serão realizadas? ");
		scanf("%d", &qntSessoesRealizadas); //tipo int
		fflush(stdin);
	} while(qntSessoesRealizadas != 2);
	
	/*
		o "do" e o "while" são estruturas de repetição, onde irá acontecer no minímo uma vez e só será quebrado quando a var "nomeFilme" não for nula
		o printf irá mostrar a respectiva mensagem pro usuário;
		o fgets irá armazenar o que o usuário digitou na respectiva variável;
		o fflush(stdin) irá retirar o lixo da memória.
	*/
	do {
		printf("Qual o nome do filme? ");
		fgets(nomeFilme, 30, stdin);
		fflush(stdin);
		nomeFilme[strlen(nomeFilme) - 1] = '\0'; //remover o \n de uma possível "entrada nula", e assim, respeitando a lógica do while
	} while(strlen(nomeFilme) == 0);
	
	/*
		o "do" e o "while" são estruturas de repetição, onde irá acontecer no minímo uma vez e só será quebrado quando a var "pessoasAssistiramFilme" for >= 10;
		o printf irá mostrar a respectiva mensagem pro usuário;
		o scanf irá armazenar o que o usuário digitou na respectiva variável;
		o fflush(stdin) irá retirar o lixo da memória.
	*/
	do {
		printf("Quantas pessoas assistiram ao filme? ");
		scanf("%d", &pessoasAssistiramFilme);
		fflush(stdin);
	} while(pessoasAssistiramFilme < 10);
	
	// criando a var que irá representar cada Pessoa do ecossistema, onde Pessoa é um struct.
	struct Pessoa pessoas[pessoasAssistiramFilme];
	
	// estrutura de repetição que irá realizar a quantidade de vezes que foi informado pelo usuário em "pessoasAssistiramFilme"
	for(int i = 0; i < pessoasAssistiramFilme; i++) {
		system("cls"); //limpa a tela do usuário, para melhor usuabilidade e um design mais clean
		
		/*
			o "do" e o "while" são estruturas de repetição, onde irá acontecer no minímo uma vez e só será quebrado quando a var "pessoas[i].nome" não for nulo
			o printf irá mostrar a respectiva mensagem pro usuário;
			o fgets irá armazenar o que o usuário digitou na respectiva variável;
			o fflush(stdin) irá retirar o lixo da memória.
			**IMPORTANTE:** Essa é a nova funcionalidade pedida pela professora!
		*/
		do {
			printf("Qual o nome da %dº pessoa? ", i + 1); // "i + 1" pq a contagem do "for" começa no zero, portanto, para mostrar visualmente de forma correta, isso é necessário
			fgets(pessoas[i].nome, 30, stdin);
			fflush(stdin);
			pessoas[i].nome[strlen(pessoas[i].nome) - 1] = '\0'; //remover o \n de uma possível "entrada nula", e assim, respeitando a lógica do while
		} while(strlen(pessoas[i].nome) == 0);
		
		/*
			o "do" e o "while" são estruturas de repetição, onde irá acontecer no minímo uma vez e só será quebrado quando a var "pessoas[i].sexo" for "M" ou "F";
			o printf irá mostrar a respectiva mensagem pro usuário;
			o scanf irá armazenar o que o usuário digitou na respectiva variável;
			o fflush(stdin) irá retirar o lixo da memória.
		*/
		do {	
			printf("Qual o sexo de %s? M = Masculino; F = Feminino: ", pessoas[i].nome);
			scanf("%c", &pessoas[i].sexo);
			pessoas[i].sexo = toupper(pessoas[i].sexo); //torno o que o usuário digitou maiúsculo (lib ctype.h)
			fflush(stdin);
		} while((pessoas[i].sexo != 'M') && (pessoas[i].sexo != 'F'));
	
		// lógica que é responsável por incrementar uma Pessoa na respectiva variável, sempre relativa ao seu sexo.
		if(pessoas[i].sexo == 'M')
			pessoasMasculino++;
		else
			pessoasFeminino++;
	
		/*
			o "do" e o "while" são estruturas de repetição, onde irá acontecer no minímo uma vez e só será quebrado quando a var "pessoas[i].idade" >= 3 && <= 100
			o printf irá mostrar a respectiva mensagem pro usuário;
			o scanf irá armazenar o que o usuário digitou na respectiva variável;
			o fflush(stdin) irá retirar o lixo da memória.
		*/
		do {
			printf("Qual a idade de %s? ", pessoas[i].nome);
			scanf("%d", &pessoas[i].idade);
			fflush(stdin);
		} while((pessoas[i].idade < 3) || (pessoas[i].idade > 100));
		
		/*
			lógica que irá dizer onde a Pessoa se encaixa de acordo com a classificação fornecida na atividade.
			as vars são incrementadas de acordo com a classificação
		*/
		if((pessoas[i].idade >= 3) && (pessoas[i].idade <= 13)) // de 3 até 13 anos - Crianças
			criancas++;
		else if((pessoas[i].idade >= 14) && (pessoas[i].idade <= 17)) // de 14 até 17 anos - Adolescentes
			adolescentes++;
		else if((pessoas[i].idade >= 18) && (pessoas[i].idade <= 64)) // de 18 até 64 anos - Adultos
			adultos++;
		else // de 65 até 100 anos - Idosos
			idosos++;
	}
	
	system("cls"); //limpa a tela do usuário, para melhor usuabilidade e um design mais clean
	
	/*
		Aqui será exibido o relatório final pro usuário, após todas as perguntas.
		Onde será infomado:
			- o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo masculino que assistiram ao filme
			- a quantidade de pessoas, seguindo a classificação da tabela
	*/
	printf("========================\n\n");
	printf("O filme assistido foi: %s, com %d espectadores.\n", nomeFilme, pessoasAssistiramFilme);
	printf("%d homens e %d mulheres assistiram ao filme.\n\n", pessoasMasculino, pessoasFeminino);
	printf("%d Crianças (3 à 13 anos)\n", criancas);
	printf("%d Adolescentes (14 à 17 anos)\n", adolescentes);
	printf("%d Adultos (18 à 64 anos)\n", adultos);
	printf("%d Idosos (65 à 100 anos)\n\n", idosos);
	
	// estrutura de repetição para separar os maiores de idade
	for(int i = 0; i < pessoasAssistiramFilme; i++) {
		if(pessoas[i].idade >= 18){ // checando se é maior de idade (adulto)
			switch(pessoas[i].sexo){ //lógica que separa de acordo com o sexo
				case 'M':
					maioresIdadeMasculino++; //incrementa
					break; // quebra o "switch"
				case 'F':
					maioresIdadeFeminino++; //incrementa
					break; // quebra o "switch"
				default: // valor desconhecido
					printf("** SEXO NÃO INFORMADO **");
			}
		}
	}
	
	// restante do relatório
	printf("%d Homens maiores de idade assistiram ao filme %s.\n", maioresIdadeMasculino, nomeFilme);
	printf("%d Mulheres maiores de idade assistiram ao filme %s.", maioresIdadeFeminino, nomeFilme);
	printf("\n\n========================");	
	
	return 0; // retorno da função
}
