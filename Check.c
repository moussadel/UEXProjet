#include "Check.h"
#include "appli.h"


int checknum(int num, char **board)
{
    while((num<-3) || (num>width))
    {
        print(board);
        printf("\nPlease enter a number between 1 and %d :", width);
        scanf("%d", &num);
    }
    return num;
}

int checkfull(char **board)
{
    int i, j;
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(board[i][j] == blanc)
            {
                return 1;
            }
        }

    }
    return 0;
}

int checkEmpty(char **board){
    int n, m;
    for(n=0;n<height;n++){
        for(m=0;m<width;m++){
            if(board[n][m] != blanc){return 0;}
        }
    }
    return 1;
}

int checkCol(int num, char **board){
    int i, counter=0;
    for(i=height-1;i>=0;i--){
        if(board[i][num-1] == blanc){
            counter = 0;
            break;
        }
        else{
            counter = 1;
        }
    }
    return counter;
}

int checkEmpty1(char **board,int num,int numOfrow)
{
    if(numOfrow==(height-1) && board[numOfrow][num]==blanc){return 1;}
    else if(board[numOfrow+1][num]!=blanc && board[numOfrow][num]==blanc){return 1;}
    return 0;
}