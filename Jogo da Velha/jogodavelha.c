#include <stdio.h>

void inicializaTabuleiro(char tabuleiro[3][3]){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			tabuleiro[i][j] = ' ';
		}	
	}
}

void mostraTabuleiro(char tabuleiro[3][3]){
	printf("%c|%c|%c\n", 	tabuleiro[0][0],
							tabuleiro[0][1],
							tabuleiro[0][2]);
	printf("-+-+-\n");
	printf("%c|%c|%c\n", 	tabuleiro[1][0],
							tabuleiro[1][1],
							tabuleiro[1][2]);
	printf("-+-+-\n");
	printf("%c|%c|%c\n", 	tabuleiro[2][0],
							tabuleiro[2][1],
							tabuleiro[2][2]);	
}

int preencheCasaDoTabuleiro(char tabuleiro[3][3], int casa, int jogador){
	int statusDoPreenchimento = 1;
	
	switch(casa){
		case 1:
			if(tabuleiro[0][0] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[0][0] = 'O';
			else if(jogador == 2)
				tabuleiro[0][0] = 'X';
			break;
		case 2:
			if(tabuleiro[0][1] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[0][1] = 'O';
			else if(jogador == 2)
				tabuleiro[0][1] = 'X';
			break;
		case 3:
			if(tabuleiro[0][2] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[0][2] = 'O';
			else if(jogador == 2)
				tabuleiro[0][2] = 'X';
			break;
		case 4:
			if(tabuleiro[1][0] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[1][0] = 'O';
			else if(jogador == 2)
				tabuleiro[1][0] = 'X';
			break;
		case 5:
			if(tabuleiro[1][1] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[1][1] = 'O';
			else if(jogador == 2)
				tabuleiro[1][1] = 'X';
			break;
		case 6:
			if(tabuleiro[1][2] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[1][2] = 'O';
			else if(jogador == 2)
				tabuleiro[1][2] = 'X';
			break;
		case 7:
			if(tabuleiro[2][0] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[2][0] = 'O';
			else if(jogador == 2)
				tabuleiro[2][0] = 'X';
			break;
		case 8:
			if(tabuleiro[2][1] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[2][1] = 'O';
			else if(jogador == 2)
				tabuleiro[2][1] = 'X';
			break;
		case 9:
			if(tabuleiro[2][2] != ' ')
				statusDoPreenchimento = 0;
			else if(jogador == 1)
				tabuleiro[2][2] = 'O';
			else if(jogador == 2)
				tabuleiro[2][2] = 'X';
			break;
	}	
	return statusDoPreenchimento;
}

void jogar(char tabuleiro[3][3], int jogador){
	int casa, statusDoPreenchimento;
	do{
		do{
			printf("Jogador %i entre com a casa a ser jogada: ", jogador);
			scanf("%i", &casa);
		}while(casa < 1 || casa > 9);
		statusDoPreenchimento = preencheCasaDoTabuleiro(tabuleiro, casa, jogador);
	}while(statusDoPreenchimento == 0);
}

int statusDoJogo(char tabuleiro[3][3]){
	int i, j, soma1, soma2;
	
	//linha 0
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[0][i] == 'O')
			soma1++;
		else if(tabuleiro[0][i] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[0][0] == 'O')
			return -1;
		else return -2;
	}
	
	//linha 1 
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[1][i] == 'O')
			soma1++;
		else if(tabuleiro[1][i] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[1][0] == 'O')
			return -1;
		else return -2;
	}
	
	//linha 2 
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[2][i] == 'O')
			soma1++;
		else if(tabuleiro[2][i] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[2][0] == 'O')
			return -1;
		else return -2;
	}
	
	//coluna 0
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[i][0] == 'O')
			soma1++;
		else if(tabuleiro[i][0] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[0][0] == 'O')
			return -1;
		else return -2;
	}
	
	//coluna 1 
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[i][1] == 'O')
			soma1++;
		else if(tabuleiro[i][1] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[0][1] == 'O')
			return -1;
		else return -2;
	}
	
	//coluna 2 
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[i][2] == 'O')
			soma1++;
		else if(tabuleiro[i][2] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[0][2] == 'O')
			return -1;
		else return -2;
	}
	
	//diagonal principal 
	soma1 = 0;
	soma2 = 0;
	for(i = 0; i < 3; i++){
		if(tabuleiro[i][i] == 'O')
			soma1++;
		else if(tabuleiro[i][i] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[0][0] == 'O')
			return -1;
		else return -2;
	}
	
	//diagonal secundaria 
	soma1 = 0;
	soma2 = 0;
	for(i = 0, j = 2; i < 3; i++, j--){
		if(tabuleiro[i][j] == 'O')
			soma1++;
		else if(tabuleiro[i][j] == 'X')
			soma2++;	
	}
	
	if(soma1 == 3 || soma2 == 3){
		if(tabuleiro[0][2] == 'O')
			return -1;
		else return -2;
	}
	
	//proximo jogador
	soma1 = 0;	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(tabuleiro[i][j] == 'O' || tabuleiro[i][j] == 'X')
				soma1++;
		}	
	}
	
	if(soma1 == 9)
		return 0;
	else if(soma1%2 == 0)
		return 1;
	else
		return 2;		
}

void resultadoFinal(int situacao){
	switch(situacao) {
    	case 0:
      		printf("Partida empatada!\n");
    		break;
    	case -1:
      		printf("Jogador 1 venceu!\n");
    		break;
    	case -2:
      		printf("Jogador 2 venceu!\n");
    		break;
    	default:
      		printf("Isto nao deveria acontecer!\n");
  	}
}


int main(){
	char tabuleiro[3][3];
	int situacao = 1;
	
	inicializaTabuleiro(tabuleiro);
	
	do{
		mostraTabuleiro(tabuleiro);
		jogar(tabuleiro, situacao);
		situacao = statusDoJogo(tabuleiro);
	}while(situacao > 0);
	
	mostraTabuleiro(tabuleiro);
	resultadoFinal(situacao);
	return 0;
}
