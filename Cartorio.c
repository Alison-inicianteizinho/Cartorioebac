#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocações de texto por regioes
#include <string.h> //biblioteca responsavel por cuidar das strings


int registrar () //função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação das strings/variaveis
	char arquivo [40];	//variavel/string de caracteres que suporta ate 40 char's
	char cpf [40];
	char nome [40];	
	char sobrenome [40];	
	char cargo [40];	
	//fim da criação das strings/variaveis
	
	printf ("Qual o cpf a ser cadastrado? \n");
	scanf ("%s", cpf); //armazena a string na variavel indicada
	
	strcpy (arquivo, cpf); //responsavel por copiar o valor das strings
	FILE *file; // crie um arquivo
	
	file = fopen (arquivo, "w"); // crie o arquivo
	fprintf (file, "\n Cpf: ");
	fprintf (file,cpf); //salva o valor da variavel
	fclose (file); //fecha o arquivo
	
	file =fopen (arquivo, "a");
	fprintf (file, "\n Nome: ");
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado! \n");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a"); //adicionar a variavel no arquivo (atualizar o file)
	fprintf (file,nome);
	fclose (file); 
	
	file = fopen( arquivo, "a");
	fprintf (file, "\n Sobrenome: ");
	fclose (file);
	
	printf ("digite o sobrenome a ser cadastradro\n");
	scanf ("%s", sobrenome); 
	
	file = fopen (arquivo, "a"); 
	fprintf (file,sobrenome);
	fclose (file);
	
	file = fopen( arquivo, "a");
	fprintf (file, "\n Cargo: ");
	fclose (file);
	
	printf ("Digite o cargo a ser cadastrado! \n ");
	scanf ("%s", cargo); 
	
	file = fopen (arquivo, "a");
	fprintf (file,cargo );
	fprintf (file, "\n\n");
	fclose (file);
	system ("pause"); //deixar a tela pausada ate a proxima ação do usuario
	

	
	
}

int consultar ()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf [40]; 
	char conteudo [200];
	
	printf ("qual o cpf deseja consultar?:\n");
	scanf ("%s", cpf); 
	
	FILE *file;
	file = fopen (cpf, "r"); 
	
	if (file == NULL) // se file for nulo...
	{
		printf ("Esse cpf não esta cadastrado, não localizado \n");
		
	}
	
	
	printf ("\n essas sao as seguintes informações do usuario: \n");
	
	
	while (fgets(conteudo, 200, file) != NULL) //mostra todas informaçoes inseridas ao usuario
	{
		printf ("%s", conteudo);
		
		
	}
	
	system ("pause");
	
}

int excluir ()
{
	char cpf[40];
	
	printf("Qual o cpf do usuario que deseja deletar? \n");
	scanf("%s", cpf);
	
	remove(cpf); //remover(apagar) a string/variavel dos arquivos
		
	FILE*file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("\n O usuario não existe! \n");
	}
	
	else
	{
		printf("\n O usuario desejado foi excluido! \n");
	}
			
	system ("pause");
	
}




int main ()
{
	int escolha = 0; // defenindo o tipo de variavel
	int laco = 1;
	
	for(laco=1;laco=2;) // retornar sempre ao inicio do codigo quando uma ação for realizada!
	{
		
		system ("cls"); //limpa a tela


    	setlocale(LC_ALL, "portuguese"); //definindo a lingua do codigo
    
    
    	printf ("\t---------------\n"); //inicio do menu
    	printf ("\tCARTORIO EBAC\n");
    	printf ("\t---------------\n\n");
    	printf ("Escolha uma das opções a seguir: \n\n");
    	printf ("1 - Registrar nome!\n");
    	printf ("2 - Consultar nomes!\n");
    	printf ("3 - excluir nomes!\n"); 
    	printf ("4 - sair do menu!\n\n");
		printf("escolha: \n"); // final do menu
    
    	scanf("%d", &escolha ); // armazenamento das variaveis
    
    	system("cls"); // deixando a tela limpa
    
    	switch (escolha) // se a variavel for... faça...
    	{
    		case 1: //faça
    			registrar();
    		break; // finalização do caso.
    		case 2:
    			consultar();
			break; // finalização do caso.
			
			case 3:
				excluir();
			break; // finalização do caso.
			
			case 4:
				printf("Obrigado por ultilizar o menu!");
			return 0;
			break;
			
			
			default: // caso nao seja nenhuma das opções registradas...
				printf ("Sinto muito, essa opção nao esta disponivel! \n");
				system ("pause");
			break; //finalização do "caso nao".
			    		
		}	//final da seleção	
	}
} 

