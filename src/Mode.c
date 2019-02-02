
//*****************************************************************************
//
//! \file Mode.c(print).
//! \brief This function (print) displays the game board.
//!
//! \param Game board.
//!
//*****************************************************************************

#include "appli.h"
#include "Messages.h"

void print(char **board)
{
    int i, j;
    for(i=0; i<height; i++)
    {
        printf("\n+");
        for(j=0; j<width; j++)
        {
            printf("---+");
        }
        printf("\n|");
        for(j=0; j<width; j++)
        {
            printf(" %c |", board[i][j]);
        }
    }
    printf("\n+");
    for(i=0; i<width; i++)
    {
        printf("---+");
    }
    printf("\n");
    for(i=1;i<=width;i++){
        printf("   %d",i);
    }
    printf("\n\n\n");
}

//*****************************************************************************
//
//! \file Mode.c(ModeOne).
//! \brief This function (ModeOne) hosts all the features for the player versus player mode.
//!
//! \param Game board.
//! \param The row table for undo.
//! \param The row table for redo.
//! \param The column table for undo.
//! \param The column table for redo.
//! \param The first player's score
//! \param The second player's score
//!
//*****************************************************************************

void ModeOne(int *score1,int *score2,int num,int redoCounter,int undoCounter,int *undoCol,
                int *undoRow, int *redoCol,int *redoRow,int z,int q,char **board){

    int k,l; 
    char x='X',o='O';

    if(numX(board) <= numO(board)){

        printf("\nplayer 1 enter number of the column:");
        scanf("%d", &num);
        saveLoad(&num, board);
        num = checknum(num,board);

        if(checkCol(num,board)){

            while(board[0][num-1]!=blanc)
            {
                print(board);
                printf("Invalid input. Do another move : ");
                scanf("%d", &num);
                saveLoad(&num, board);
                if(num == 0 || num == -3){
                    break;
                }
            }
        }

        if(redoCounter >= undoCounter){

            while(num == -3){
                print(board);
                printf("\ncannot redo!! play again");
                scanf("%d", &num);
                saveLoad(&num, board);
                if(num == 0){
                    break;
                }
            }
        }

        while(num == 0 && checkEmpty(board)){
            print(board);
            printf("\ncannot undo! play again");
            scanf("%d", &num);
            saveLoad(&num, board);

            if(num == -3){

                if(redoCounter >= undoCounter){

                    while(num == -3){
                        print(board);
                        printf("\ncannot redo!! play again");
                        scanf("%d", &num);

                        if(num == 0){
                            break;
                        }
                    }
                }
            }
        }

        undoRedoLimit(num,&undoCounter,&redoCounter);
        undoRedo(&x,board,num,undoCol,undoRow,&k,&l,&z,redoCol,redoRow,&q);
        *score1=horizontalScore(board,x)+verticalScore(board,x)+diagonal(board,x)+diagonal1(board,x);
        message(1,*score1, *score2,0);
    }
    if(numO(board) < numX(board)){

        printf("\nplayer 2 enter number of the column:");
        scanf("%d", &num);
        saveLoad(&num, board);
        num = checknum(num,board);
        if(checkCol(num,board)){
            while(board[0][num-1]!=blanc){
                print(board);
                printf("Invalid input. Do another move : ");
                scanf("%d", &num);
                saveLoad(&num, board);

                if(num == 0 || num == -3){
                    break;
                }
            }
        }

        if(redoCounter >= undoCounter){

            while(num == -3){
                print(board);
                printf("\ncannot redo!! play again");
                scanf("%d", &num);
                saveLoad(&num, board);

                if(num == 0){
                    break;
                }
            }
        }

        while(num == 0 && checkEmpty(board)){
            print(board);
            printf("\ncannot undo! play again");
            scanf("%d", &num);
            saveLoad(&num, board);

            if(num == -3){

                if(redoCounter >= undoCounter){

                    while(num == -3){
                        print(board);
                        printf("\ncannot redo!! play again");
                        scanf("%d", &num);
                        saveLoad(&num, board);

                        if(num == 0){
                            break;
                        }
                    }
                }
            }
        }
        undoRedoLimit(num,&undoCounter,&redoCounter);
        undoRedo(&o,board,num,undoCol,undoRow,&k,&l,&z,redoCol,redoRow,&q);
        *score2=horizontalScore(board,o)+verticalScore(board,o)+diagonal(board,o)+diagonal1(board,o);
        message(2,*score1,*score2,0);
    }
} 

//*****************************************************************************
//
//! \file mode.c(ModeTwo).
//! \brief This function (ModeTwo) hosts all the features for solo mode.
//!
//! \param Game board.
//! \param The row table for undo.
//! \param The row table for redo.
//! \param The column table for undo.
//! \param The column table for redo.
//! \param The first player's score.
//! \param The score of the second player.
//!
//*****************************************************************************

void ModeTwo(int *score1,int *score2,int choose,int high,int num,int redoCounter,int undoCounter,
                int *undoCol,int *undoRow,int *redoCol,int *redoRow,int *compUndoCol,int *compUndoRow,
                int compUndoCounter,int z,int q,int c,int d,char **board){

    int k,l,flag; 
    char x='X',o='O';

    while(num == -3){
        print(board);
        printf("\ncannot redo!! play again");
        scanf("%d", &num);
        saveLoad(&num, board);
        if(num == 0){
            break;
        }
    }                
    while(num == 0 && checkEmpty(board)){
        print(board);
        printf("\ncannot undo! play again");
        scanf("%d", &num);
        saveLoad(&num, board);
        if(num == -3){
            if(redoCounter >= compUndoCounter){
                while(num == -3){
                    print(board);
                    printf("\ncannot redo!! play again");
                    scanf("%d", &num);
                    saveLoad(&num, board);
                    if(num == 0){
                        break;
                    }
                }
            }
        }
    }
    undoRedoLimit(num,&undoCounter,&redoCounter);
    undoRedo(&x,board,num,undoCol,undoRow,&k,&l,&z,redoCol,redoRow,&q);
    *score1=horizontalScore(board,x)+verticalScore(board,x)+diagonal(board,x)+diagonal1(board,x);
    message(3,*score1, *score2,0);
    switch(choose){

        case 1:{

            if(num != 0 && num != -1 && num != -2){
                Easy(board, &num);
                compUndoCol[d++] = num-1 ;
                compUndoRow[c++] = rowNum(num,board)+1;
                compUndoCounter = 0;
            }

            if(num == 0){
                compUndoCounter += 1;
                c--;
                d--;
                board[compUndoRow[c]][compUndoCol[d]] = blanc;
            }
            break;
        }

        case 2: {

            if(num != 0 && num != -1 && num != -2){
                 flag=0;

                if(Medium(board,x,&num)==1){
                    flag=1;
                }

                if(flag!=1){
                    Easy(board, &num);
                }
                compUndoCol[d++] = num-1 ;
                compUndoRow[c++] = rowNum(num,board)+1;
                compUndoCounter = 0;
            }

            if(num == 0){
                            compUndoCounter += 1;
                 c--;
                d--;
                board[compUndoRow[c]][compUndoCol[d]] = blanc;
            }
            break;
        }

        case 3:{

            if(num != 0 && num != -1 && num != -2){
                Hard(board,&num);
                compUndoCol[d++] = num-1 ;
                compUndoRow[c++] = rowNum(num,board)+1;
                compUndoCounter = 0;
            }

            if(num == 0){
                compUndoCounter += 1;
                c--;
                d--;
                board[compUndoRow[c]][compUndoCol[d]] = blanc;
            }
            break;
        }
    } 
    print(board);
    *score2=horizontalScore(board,o)+verticalScore(board,o)+diagonal(board,o)+diagonal1(board,o);
    message(4,*score1, *score2,0);
}

//*****************************************************************************
//
//! \file mode.c(DisplayMode).
//! \brief The defferent mode game 
//!
//! \param Game board.
//! \param The row table for undo.
//! \param The row table for redo.
//! \param The column table for undo.
//! \param The column table for redo.
//! \param The first player's score.
//! \param The score of the second player.
//! \param
//! \param
//!
//*****************************************************************************

void DisplayMode(int high,int score1,int score2,int *compUndoCol,int undoCounter,int redoCounter,
                    int compUndoCounter,int num, int *undoCol,int *undoRow,int *redoCol,
                    int *redoRow,int *compUndoRow, int q,int z,int d,int c, char **board){
    int choose;
    message(0,0,0,0);
    scanf("%d", &choose);
    while((choose!=1 && choose!=2) || isalpha(choose))
    {
        printf("Enter 1 or 2\n");
        printf("Player1 vs Player2: press 1 \n\nPlayer vs Computer: press 2 \n\n");
        scanf("%d", &choose);
    }

    if(choose == 1){
        print(board);
        do {
            message(7,0,0,0);
            if(numX(board) <= numO(board)){
                ModeOne(&score1,&score2,num,redoCounter,undoCounter,undoCol,undoRow,redoCol,
                            redoRow,z,q,board);
            }

            if(numO(board) < numX(board)){
                ModeOne(&score1,&score2,num,redoCounter,undoCounter,undoCol,undoRow,redoCol,
                          redoRow,z,q,board);
            }           
        }while(checkfull(board));
        message(6,score1,score2,&high);
    }
    else{
        printf("\nEasy (press 1), Medium (press 2), Hard (press 3)\n");
        scanf("%d", &choose);

        while(choose!=1 && choose!=2 && choose!=3){
            printf("Enter 1 , 2 or 3\n");
            printf("\nEasy (press 1), Medium (press 2), Hard (press 3)\n");
            scanf("%d", &choose);
        }
        print(board);

        do{
            message(7,0,0,0);
            printf("\nenter number of the column:");
            scanf("%d", &num);
            saveLoad(&num, board);
            num = checknum(num,board);

            if(checkCol(num,board)){
                while(board[0][num-1]!=blanc){
                    print(board);
                    printf("Invalid input. Do another move : ");
                    scanf("%d", &num);
                    saveLoad(&num, board);
                    if(num == 0 || num == -3){
                        break;
                    }
                }
            }

            if(redoCounter >= compUndoCounter){
                ModeTwo(&score1,&score2,choose,high,num,redoCounter,undoCounter,undoCol,undoRow,redoCol,
                            redoRow,compUndoCol,compUndoRow,compUndoCounter,z,q,c,d,board);
            }
        }while(checkfull(board));    
        message(5,score1,score2,&high);
    }
    highscore(high);
    printf("\nif you  want to play again press y, else press any key\n");         
}