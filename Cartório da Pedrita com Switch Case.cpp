#include <stdio.h> //biblioteca de comuniação com o usuário
#include <stdlib.h> //biblioteca responsavel por alocação de espaços de memoria
#include <locale.h> //biblioteca de alocações de texto por região/pais
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Função responsavel por adastrar os usuários no sistema
{
	//inicio criação de variáveis/string (conjuntos de variaveis). Ex: uma fileira de alunos, cada aluno é uma variavel e a fileira é uma string
	char arquivo[40];
	char cpf[40];//o colchete significa que é uma string
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletanod informação do usuário
	scanf("%s", cpf);//%s significa que vai salvar/armazenar dentro de uma string. %s refere-se a string
	
	strcpy(arquivo, cpf);// responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // fopen significa abrir um arquivo com o nome que tiver dentro dessa variavel. Cria o arquivo. "W" significa escrever.
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a");//a é atualizar, já temos o arquivo criado já.
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
	
	file = fopen(arquivo, "a");//a é atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");// o system(pause) serve para ficar aparecendo a mensagem até o usuario não querer mais
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//esse R signifca ler o cpf ou o que está sendo requisitado
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];

	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;// o primeiro fala sobre entrar no campo da biblioteca que fala sobre a função file e dentro dela puxar os arquivos
	file = fopen(cpf,"r");// ele le o valor passado na string %s,cpf e abrindo esse arquivo na biblioteca que já passamos
	
	printf("Usuário deletado!.\n");
	system("pause");
	
	if(file == NULL)
	{
		printf("O usuráio não se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main() //toda função tem parenteses ()
{
	//esse espaço é meramente visual, mas ajuda quem trabalha
	
	int	opcao=0; //definindo variáveis
	//isso é uma variavel local, uma variavel que só funciona dentro de uma função
	//Temos uma variavel repsonsavel por armazenar o valor que o usuario colocar aqui
	//a partir do momento que criarmos a variavel do tipo int opcao=0, sempre temos que setar a variavel, alocamos um espaço de memoria
	//um pedacionho do meu computador agora se chama opcao, e ela começa 0 porque se não fica um valor variavel de memoria.
	//Quando deletamos um arquivo da memoria do computador, não necessariamente foi deletado, só avismaos que aquele espaço está livre para o computador
	//Precisamos avisar que a nossa variavel opcao não está livre, ela é nossa e ela equivale a 0.
	int laco=1;// laco é o nome da variavel
	
	for(laco=1;laco=1;)//for(x=1;x=10;x++) nesse caso ele vai até 10 vezes e depois fecha o programa, o primero x seria a entrada e o seguno a saida
	//o tercerio x é para subir 1 na variavel, ou seja, 10 tentativas e vai aumentando a cada tentativa até chegar em 10
	//for(laco=1;laco=1;) quando for 1 ele continua aqui, aqui não tem incremento, ele sempre volta ao menu, só sai se quiser
	{
		//Quando eu abro e quando eu encerro um laco? vai ser aberto apartir do momento que você queira que deva voltar para um ponto
		//Tudo que tiver dentro das chaves, ele sempre vai do inicio ao fim e volta
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da Pedrita ###\n\nOi tudo bem?\nTudo sim\nLegal!\n");//inicio do menu
		printf("Escolher a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n"); //o \t é o responsavél por descolar da parede as palavras/dar o espaço tipo tab
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nome\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
		//tem o objetivo que escanear o que o usuario coloca. Para amarzenarmos uma variavel de tipo inteiro usamos %d
		//Com %d estamos falando para o computador que o que o ususario digitar antes, voce armazena na variavel e referenciamos a variavel opcao com &
	
		system("cls");//cls serve para limpar a tela
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n");
			system("pause");
			break;
		}//fim da seleção
		
		printf("Esse Software é de livre uso da Pedrita");
}
}
