#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca para aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o (pt-BR, en-us, etc...)
#include <string.h> //biblioteca respons�vel por cuidar das strings

	  	/*"%" = prefixo para declarar tipo de dado esperado.
		 tipos esperados:
	 	char ou %c = caracter
	 	int ou %d = inteiro
	 	float ou %f = real
		char[] ou %s = cadeia (string)*/


int registro() //Fun��o respons�vel por cadastrar no sistema
{
	//cria��o das vari�veis do tipo string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	char telefone [40];
	
	printf("Digite o CPF a ser cadastrado (apenas n�meros): ");//coleta de info do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings strcpy(PARA, DE);
	
	FILE *file; // FILE em caps � a fun��o de arquivar
	file = fopen(arquivo, "w"); // file = fopen cria o arquivo (nome da variavel, "o que faz")
	fprintf (file, "CPF: ");
	fprintf (file, cpf); // escreve o valor da variavel "cpf" no arquivo
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,";\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf (file, "Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,";\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf (file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,";\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf (file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"; \n");
	fclose(file);
	
	printf("Digite o telefone a ser cadastrado (apenas n�meros): ");
	scanf("%s", telefone);
	
	file = fopen(arquivo, "a");
	fprintf (file, "Telefone: ");
	fprintf(file,telefone);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"; \n\n");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o arquivo!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
		printf("\nEssas s�o as informa��es do usu�rio: ");
	system("pause");
}

int deleta()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado (apenas n�meros): ");
	scanf("%s", cpf);	
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		fclose(file);
		printf("O arquivo a ser deletado n�o existe. \n");
		system("pause");
	}
	
	else if (file != NULL)
	{
		fclose(file);
		printf("O arquivo foi deletado. Espero que voc� tenha digitado certo! :) \n");
		system("pause");
		remove (cpf);
	}
	
}




int main()
{	
	int menu_choice; //declara variavel sem valor, pode atribuir valor pr�vio com " = "
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //puxa da biblioteca para settar o esquema de texto com acentos em pt_br
	
		printf("\t\t    ##################################################\n");
		printf("\t\t    #### @@@@@@ ## @@@@@ ####### @@@@@ #### @@@@@ ####\n");
		printf("\t\t    #### @@ ###### @@  @@@ #### @@  @@ ## @@ #########\n");
		printf("\t\t    #### @@@@ #### @@@@@ ##### @@@@@@@ ## @@ #########\n");
		printf("\t\t    #### @@ ###### @@  @@@ ## @@  # @@ ## @@ #########\n");
		printf("\t\t    #### @@@@@@ ## @@@@@ ### @@  ## @@ ###  @@@@@ ####\n");
		printf("\t\t    ##################################################\n");
		printf("\t\t     Escola Brit�nica de Artes Criativas e Tecnologia \n\n");
	
		printf("\t\t\t\t--- Cart�rio da EBAC ---\n\n"); // sempre finalizar a��o com ;
	
		printf("\t\t\t   Escolha uma op��o para prosseguir: \n\n");
		printf("\t1 - Registrar Novos Alunos");
		printf("\t2 - Consultar Nomes");
		printf("\t3 - Deletar Cadastros");
		printf("\t4 - Sair do Sistema");
		printf("\n\n");
	
		printf("Op��o: ");
		scanf("%d", &menu_choice); //scanf = coleta dados pelo teclado do usu�rio
							  
		system("cls"); //funcao para limpar os textos do terminal
		
		
		switch(menu_choice)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deleta();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
		}

		//printf("\n\n\nSoftware de uso livre para fins de estudo. Nenhum direito reservado. 2023");
	}
}
