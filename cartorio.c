#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca para alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região (pt-BR, en-us, etc...)
#include <string.h> //biblioteca responsável por cuidar das strings

	  	/*"%" = prefixo para declarar tipo de dado esperado.
		 tipos esperados:
	 	char ou %c = caracter
	 	int ou %d = inteiro
	 	float ou %f = real
		char[] ou %s = cadeia (string)*/


int registro() //Função responsável por cadastrar no sistema
{
	//criação das variáveis do tipo string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	char telefone [40];
	
	printf("Digite o CPF a ser cadastrado (apenas números): ");//coleta de info do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings strcpy(PARA, DE);
	
	FILE *file; // FILE em caps é a função de arquivar
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
	
	printf("Digite o telefone a ser cadastrado (apenas números): ");
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
		printf("Não foi possível localizar o arquivo!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
		printf("\nEssas são as informações do usuário: ");
	system("pause");
}

int deleta()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado (apenas números): ");
	scanf("%s", cpf);	
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		fclose(file);
		printf("O arquivo a ser deletado não existe. \n");
		system("pause");
	}
	
	else if (file != NULL)
	{
		fclose(file);
		printf("O arquivo foi deletado. Espero que você tenha digitado certo! :) \n");
		system("pause");
		remove (cpf);
	}
	
}




int main()
{	
	int menu_choice; //declara variavel sem valor, pode atribuir valor prévio com " = "
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
		printf("\t\t     Escola Britânica de Artes Criativas e Tecnologia \n\n");
	
		printf("\t\t\t\t--- Cartório da EBAC ---\n\n"); // sempre finalizar ação com ;
	
		printf("\t\t\t   Escolha uma opção para prosseguir: \n\n");
		printf("\t1 - Registrar Novos Alunos");
		printf("\t2 - Consultar Nomes");
		printf("\t3 - Deletar Cadastros");
		printf("\t4 - Sair do Sistema");
		printf("\n\n");
	
		printf("Opção: ");
		scanf("%d", &menu_choice); //scanf = coleta dados pelo teclado do usuário
							  
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
			printf("Esta opção não está disponível!\n\n");
			system("pause");
			break;
		}

		//printf("\n\n\nSoftware de uso livre para fins de estudo. Nenhum direito reservado. 2023");
	}
}
