#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> /* getch */

#define CARACTERES_EM_MATRICULA 10
#define CARACTERES_EM_NOME 100
#define CARACTERES_EM_STATUS 12

void inicializarAlunos(char nomes[100][100], char matriculas[100][11], char statusRefeicao[100][13]){
	int i;
	for(i = 0; i < 100; i++){
		nomes[i][0] = ' ';
		matriculas[i][0] = ' ';
		statusRefeicao[i][0] = ' ';
	}
}

void tornarRefeicaoDisponivel(char statusRefeicao[100][13], int posicao){
	strcpy(statusRefeicao[posicao], "disponivel");
}

void tornarTodosDisponivel(char statusRefeicao[100][13]){
	int i;
	for(i = 0; statusRefeicao[i][0] != ' '; i++){
		tornarRefeicaoDisponivel(statusRefeicao, i);
	}
}

void tornarRefeicaoIndisponivel(char statusRefeicao[100][13], int posicao){
	strcpy(statusRefeicao[posicao], "indisponivel");
}

int nomeEhValido(char nome[100]){
	int i, statusValidacao = 1;
	for(i = 0; nome[i] != '\0'; i++){
		if(!(nome[i]>='a' && nome[i]<='z') && !(nome[i]>='A' && nome[i]<='Z') && !(nome[i] == ' ')){
			statusValidacao = 0;
			break;
		}
	}
	return statusValidacao;
}
 
int matriculaEhValida(char matricula[11]){
	int i, cont = 0;
	for(i = 0; matricula[i] != '\0'; i++){
		if(matricula[i] >= '0' && matricula[i] <= '9'){
			cont++;
		}
	}
	return cont;
}

int matriculaExiste(char matriculas[100][11], char matricula[11]){
	int i, statusMatricula = 0;
	if(matriculas[0][0] != ' '){
		for(i = 0; matriculas[i][0] != ' '; i++){
			if(strcmp(matriculas[i], matricula) == 0){
				statusMatricula = 1;
				break;
			}
		}	
	}
	return statusMatricula;
}

int cadastrarAluno(char nomes[100][100], char matriculas[100][11], char statusRefeicao[100][13])
{
	int statusCadastro = 0;
	int posVazia = 0;
	char matricula[11];
	
	printf("Informe a matricula do aluno: \n");
	gets(matricula);
	while(matriculaEhValida(matricula) != CARACTERES_EM_MATRICULA){
		printf("Matricula incorreta (informe 10 digitos para a matricula)\n");
		printf("Informe a matricula correta do aluno: \n");
		gets(matricula);
	}
	
	if(!matriculaExiste(matriculas, matricula)){
		while(nomes[posVazia][0] != ' '){
			posVazia++;
		}
		
		strcpy(matriculas[posVazia], matricula);
		
		printf("Informe o nome do aluno: \n");
		gets(nomes[posVazia]);
		while(!nomeEhValido(nomes[posVazia])){
			printf("O nome deve conter apenas letras ou espaco\n");
			printf("Informe o nome correto do aluno: \n");
			gets(nomes[posVazia]);
		}		
		tornarRefeicaoDisponivel(statusRefeicao, posVazia);
		statusCadastro = 1;
	}
	
	return statusCadastro;
}

void listarAlunos(char nomes[100][100], char matriculas[100][11], char statusRefeicao[100][13]){
	printf("----------------------------------------------\n");
	printf("TODOS OS ALUNOS CADASTRADOS:\n");
	printf("----------------------------------------------\n");
	int i;
	for(i = 0; nomes[i][0] != ' '; i++){
		printf("NOME: %s\n", nomes[i]);
		printf("MATRICULA: %s\n", matriculas[i]);
		printf("STATUS REFEICAO DIARIA: %s\n", statusRefeicao[i]);
		printf("----------------------------------------------\n");
	}
}

void cardapioAlmoco(){
	printf("------------------------------------------------------------------------------\n");
	printf("CARDAPIO DO ALMOCO - RESTAURANTE UNIVERSITARIO DA UFERSA CAMPUS PAU DOS FERROS\n");
	printf("------------------------------------------------------------------------------\n");
	printf("PRINCIPAL:\n");
	printf("Feijoada e Franfo Assado\n");
	printf("SALADA:\n");
	printf("Vinagrete\n");
	printf("ACOMPANHAMENTO:\n");
	printf("Arroz e Feijao Carioca\n");
	printf("SUCO:\n");
	printf("Abacaxi\n");
	printf("SOBREMESA:\n");
	printf("Melancia\n");
}

void cardapioJanta(){
	printf("------------------------------------------------------------------------------\n");
	printf("CARDAPIO Da JANTA - RESTAURANTE UNIVERSITARIO DA UFERSA CAMPUS PAU DOS FERROS\n");
	printf("------------------------------------------------------------------------------\n");
	printf("PRATO QUENTE:\n");
	printf("Franfo ao Molho e Carne com Legumes\n");
	printf("ACOMPANHAMENTO:\n");
	printf("Arroz e Macarrao\n");
	printf("SUCO:\n");
	printf("Goiaba\n");
	printf("CAFE:\n");
	printf("Cafe Puro\n");
}

void menuPrincipal(){
	printf("MENU PRINCIPAL\n");
	printf("1 - Cadastrar aluno\n");
	printf("2 - Listar alunos\n");
	printf("3 - Mostrar cardapio\n");
	printf("4 - Iniciar almoco\n");
	printf("5 - Iniciar janta\n");
	printf("6 - Efetuar venda de refeicao\n");
	printf("7 - Encerrar almoco\n");
	printf("8 - Encerrar janta\n");
	printf("9 - Encerrar sistema\n");
}

int refeicaoDisponivel(	char matricula[11], char matriculas[100][11], char statusRefeicao[100][13]){
		int posMat = 0;
		while(strcmp(matriculas[posMat], matricula) != 0){
			posMat++;
		}
		
		if(strcmp(statusRefeicao[posMat], "disponivel") == 0){
			return posMat;
		}
		else{
			return -1;
		}
}

void efetuarVenda(char matriculas[100][11], char statusRefeicao[100][13]){
	char matricula[11];
	int posicao;
	fflush(stdin);
	printf("Informe a matricula do aluno: \n");
	gets(matricula);
	while(matriculaEhValida(matricula) != CARACTERES_EM_MATRICULA){
		printf("Matricula incorreta (informe 11 digitos para a matricula)\n");
		printf("Informe a matricula correta do aluno: \n");
		gets(matricula);
	}	
							
	if(matriculaExiste(matriculas, matricula)){
		posicao = refeicaoDisponivel(matricula, matriculas, statusRefeicao);			
		if(posicao != -1){
			tornarRefeicaoIndisponivel(statusRefeicao, posicao);
			printf("Venda de refeicao feita com sucesso ao aluno portador da matricula %s\n", matricula);
		}else{
			printf("Nao eh possivel realizar outra venda para este aluno,\n");
			printf("pois ele ja exerceu hoje o direito para esta refeicao.\n");
		}
	}
	else{
		printf("Nao eh possivel efetuar venda para este aluno,\n");
		printf("pois a matricula informada nao esta cadastrada.\n");
	}
}

int le_opcao(){
    int op;
        while(1){
        	fflush(stdin);
            printf("\nDigite sua opcao: ");
            scanf("%d", &op);
            if(op>=1 && op<=9){
                break;
            }else{
                printf("\nOpcao Invalida. Tente Novamente");
                printf("\nA opcao deve estar entre 1 e 9.\n");
            }
        }
	return op;
}

void limpa_tela(void){
    system("cls");
}

int main(){
	int opcao1, almoco, janta, r;
	almoco = 0; // 0 representa almoco nao liberado, 1 representa almoco liberado
	janta = 0;	// 0 representa janta nao liberada, 2 representa janta liberada
	char nomes[100][100], matriculas[100][11], statusRefeicao[100][13];
	char matricula[11];
	inicializarAlunos(nomes, matriculas, statusRefeicao);
	do{
		printf("Sistema de Controle de Refeicoes do RU UFERSA Campus Pau dos Ferros.\n");
    	printf("Desenvolvido por: Tassio F.C. Todos os direitos reservados.\n\n");
		menuPrincipal();
		opcao1 = le_opcao();
		limpa_tela();
		switch(opcao1){
			case 1:
				fflush(stdin);			
				r = cadastrarAluno(nomes, matriculas, statusRefeicao);
				if(r == 1){
					printf("Aluno cadastrado com sucesso!\n");
				}
				else{
					printf("Ja existe um aluno com esta matricula cadastrado!\n");
				}
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 2:
				if(nomes[0][0] != ' '){
					listarAlunos(nomes, matriculas, statusRefeicao);
				}
				else{
					printf("Nenhum aluno cadastrado.\n");
				}
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 3:
				cardapioAlmoco();
				cardapioJanta();
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 4:
				if(almoco == 0 && janta == 0){
					almoco = 1;
					printf("Almoco liberado!\n");
				}
				else if(almoco == 1){
					printf("A venda de almoco ja encontra-se liberada!\n");
				}
				else{
					printf("Agora estamos vendendo a janta. Nao eh possivel vender almoco!\n");
				}
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 5:
				if(janta == 0 && almoco == 0){
					janta = 2;
					printf("Janta liberada!\n");
				}
				else if(janta == 2){
					printf("A venda de janta ja encontra-se liberada!\n");
				}
				else{
					printf("Agora estamos vendendo o almoco. Nao eh possivel vender janta!\n");
				}
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 6:
				if(almoco == 0 && janta == 0){
					printf("Almoco ou janta nao estao liberados\n");
				}
				else{	
					efetuarVenda(matriculas, statusRefeicao);
				} 
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 7:
				if(almoco == 1){
					almoco = 0;
					tornarTodosDisponivel(statusRefeicao);
					printf("Almoco encerrado!\n");
				}
				else if(janta == 2){
					printf("O almoco nao estava liberado. Estamos servindo a janta!\n");
				}
				else{
					printf("O almoco nao estava liberado!\n");
				}
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 8:
				if(janta == 2){
					janta = 0;
					tornarTodosDisponivel(statusRefeicao);
					printf("Janta encerrada!\n");
				}
				else if(almoco == 1){
					printf("A janta nao estava liberada. Estamos servindo o almoco!\n");
				}
				else{
					printf("A janta nao estava liberada!\n");
				}
				printf("\nVOLTAR AO MENU - DIGITE QUALQUER TECLA\n");
                getch();
				limpa_tela();
				break;
			case 9:
				opcao1 = 9;
				printf("Encerrando o sistema. Ate breve...\n");
				break;
			default:
				printf("Este programa possui um bug\n");
				return 1;
		}
	}while(opcao1 != 9);
	
	return 0;
}
