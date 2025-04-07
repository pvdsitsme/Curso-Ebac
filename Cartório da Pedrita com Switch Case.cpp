#include <stdio.h> //biblioteca de comunia��o com o usu�rio
#include <stdlib.h> //biblioteca responsavel por aloca��o de espa�os de memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o/pais
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por adastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string (conjuntos de variaveis). Ex: uma fileira de alunos, cada aluno � uma variavel e a fileira � uma string
	char arquivo[40];
	char cpf[40];//o colchete significa que � uma string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletanod informa��o do usu�rio
	scanf("%s", cpf);//%s significa que vai salvar/armazenar dentro de uma string. %s refere-se a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // fopen significa abrir um arquivo com o nome que tiver dentro dessa variavel. Cria o arquivo. "W" significa escrever.
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//a � atualizar, j� temos o arquivo criado j�.
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//a � atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");// o system(pause) serve para ficar aparecendo a mensagem at� o usuario n�o querer mais
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//esse R signifca ler o cpf ou o que est� sendo requisitado
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;// o primeiro fala sobre entrar no campo da biblioteca que fala sobre a fun��o file e dentro dela puxar os arquivos
	file = fopen(cpf,"r");// ele le o valor passado na string %s,cpf e abrindo esse arquivo na biblioteca que j� passamos
	
	printf("Usu�rio deletado!.\n");
	system("pause");
	
	if(file == NULL)
	{
		printf("O usur�io n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main() //toda fun��o tem parenteses ()
{
	//esse espa�o � meramente visual, mas ajuda quem trabalha
	
	int	opcao=0; //definindo vari�veis
	//isso � uma variavel local, uma variavel que s� funciona dentro de uma fun��o
	//Temos uma variavel repsonsavel por armazenar o valor que o usuario colocar aqui
	//a partir do momento que criarmos a variavel do tipo int opcao=0, sempre temos que setar a variavel, alocamos um espa�o de memoria
	//um pedacionho do meu computador agora se chama opcao, e ela come�a 0 porque se n�o fica um valor variavel de memoria.
	//Quando deletamos um arquivo da memoria do computador, n�o necessariamente foi deletado, s� avismaos que aquele espa�o est� livre para o computador
	//Precisamos avisar que a nossa variavel opcao n�o est� livre, ela � nossa e ela equivale a 0.
	int laco=1;// laco � o nome da variavel
	
	for(laco=1;laco=1;)//for(x=1;x=10;x++) nesse caso ele vai at� 10 vezes e depois fecha o programa, o primero x seria a entrada e o seguno a saida
	//o tercerio x � para subir 1 na variavel, ou seja, 10 tentativas e vai aumentando a cada tentativa at� chegar em 10
	//for(laco=1;laco=1;) quando for 1 ele continua aqui, aqui n�o tem incremento, ele sempre volta ao menu, s� sai se quiser
	{
		//Quando eu abro e quando eu encerro um laco? vai ser aberto apartir do momento que voc� queira que deva voltar para um ponto
		//Tudo que tiver dentro das chaves, ele sempre vai do inicio ao fim e volta
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio da Pedrita ###\n\nOi tudo bem?\nTudo sim\nLegal!\n");//inicio do menu
		printf("Escolher a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n"); //o \t � o responsav�l por descolar da parede as palavras/dar o espa�o tipo tab
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nome\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
		//tem o objetivo que escanear o que o usuario coloca. Para amarzenarmos uma variavel de tipo inteiro usamos %d
		//Com %d estamos falando para o computador que o que o ususario digitar antes, voce armazena na variavel e referenciamos a variavel opcao com &
	
		system("cls");//cls serve para limpar a tela
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
		}//fim da sele��o
		
		printf("Esse Software � de livre uso da Pedrita");
}
}
