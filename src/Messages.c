//*****************************************************************************
//
//! \file Messages.c(message).
//! \brief This function (message) hosts the different displays.
//!
//! \param That she display.
//! \param High score.
//! \param The first player's score
//! \param The second player's score
//!
//*****************************************************************************	

#include <stdio.h>
#include <klee/klee.h>

void ReadChar(char *x,const char *p){
    klee_make_symbolic(x,sizeof(char),p);
}
void ReadInt(int *x,const char *p){
    klee_make_symbolic(x,sizeof(int),p);
}

void message(int P,int score1,int score2,int *high){

	switch(P){
		case 0:
			printf("\n\n                     **** WELCOME TO THE GAME ****\n\n");
            printf("Player1 vs Player2: press 1 \n\nPlayer vs Computer: press 2 \n\n");
		break;

		case 1:
			printf("\n***************************************************");
    		printf("\n***************************************************");
    		printf("\n**                      **                       **");
    		printf("\n**   User  score : %d    **  Computer score  : %d  **", score1, score2);
    		printf("\n**                      **                       **");
    		printf("\n***************************************************");
    		printf("\n***************************************************");
		break;

		case 2:
			printf("\n***************************************************");
    		printf("\n***************************************************");
    		printf("\n**                      **                       **");
    		printf("\n**   User  score : %d    **  Computer score  : %d  **", score1, score2);
    		printf("\n**                      **                       **");
    		printf("\n***************************************************");
    		printf("\n***************************************************");
		break;

		case 3:
			printf("\n***************************************************");
    		printf("\n***************************************************");
    		printf("\n**                      **                       **");
    		printf("\n** player1 score : %d    **   player2 score  : %d  **", score1, score2);
    		printf("\n**                      **                       **");
    		printf("\n***************************************************");
    		printf("\n***************************************************");
		break;

		case 4:
			printf("\n***************************************************");
    		printf("\n***************************************************");
    		printf("\n**                      **                       **");
    		printf("\n** player1 score : %d    **   player2 score  : %d  **", score1, score2);
    		printf("\n**                      **                       **");
    		printf("\n***************************************************");
    		printf("\n***************************************************");
		break;

		case 5:
			if(score2>score1){
                *high=score2;
                printf("score1 :%i\n",score1 );
                printf("score2 :%i\n",score2 );
                printf("\nComputer WINS\n");
            }
            else if(score1==score2){
                *high=score1;
                printf("\nDRAW\n");
            }
            else{
                *high=score1;
                printf("\nUser WINS\n");
            }
		break;

		case 6:
			if(score2>score1){
                *high=score2;
                printf("\nPLAYER 2 WINS");
            }
            else if(score1==score2){
                *high=score1;
                printf("\nDRAW");
            }
            else{
                *high=score1;
                printf("\nPLAYER 1 WINS");
            }        
		break;

		case 7:
			printf("\nif you want to undo, press 0\n");
			printf("if you want to redo, press -3, to load, press -1, to save, press -2\n");
		break;

		default:
		break;
	}    
}
	
    