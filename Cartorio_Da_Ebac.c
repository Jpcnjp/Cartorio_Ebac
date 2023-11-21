#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memoria
#include <locale.h> // biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() //função responsavel por cadastraros usuários no sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); // %s referesse a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // abrindo o arquivo e o "w" significa escrever dentro no arquivo.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abrindo o arquivo e o "a" significa atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r"); // Abre o arquivo e "r" significa que ele vai ler o arquivo.
  	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, arquivo não localizado!.\n");
	}
	
while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
system ("pause");

}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("O usuario não existe no sistema.\n");
		system("pause");
	}
}

int main()
{
	
	int opcao=0; //definindo variáveis
	int laco=1;
	char senhadigitada[] = "a";
	int comparacao;
	
	printf("\t Cartorio da EBAC \n\n");
	printf("Login de administrador!\n\n Digite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada,"Eu");
	
	if(comparacao == 0\)
	{
	
	
		for (laco=1;laco=1;)
		{
		
			system("cls");
				
			setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
			
			printf ("\t Cartorio da EBAC \n\n"); //inicio do menu
			printf ("Escolha a opção desejada do menu:\n\n");
			printf ("\t1 - Registrar nomes\n");
			printf ("\t2 - Consultar nomes\n");
			printf ("\t3 - Deletar nomes\n");
			printf ("\t4 - Sair do sistema\n\n");
			printf("Opção : ");  //fim do menu
			
			scanf("%d", &opcao); //armazenando a escolha do usuário
			
			system("cls");
			
			switch(opcao) //inicio da escolha
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break;
				
				default:
				printf ("Essa opção não existe ou não está disponivel!\n");
				system("pause");
				break;
			} //fim da escolha
			
		}
	}
	
	else 
		printf("Senha incorreta !");
}
