//*****************************************************************************
//
//! \file Check.c(checknum).
//!
//! \brief This function (checknum) check if a number is valid. 
//!
//! \param Game board.
//! \param The entry number.
//!
//! \return The valide number.      
//!
//*****************************************************************************

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

//*****************************************************************************
//
//! \file Check.c(checkfull).
//!
//! \brief This function (checkfull) check if there is  empty case.
//!
//! \param Game board.
//! 
//! \return True if ther is  empty cass.  
//!  
//*****************************************************************************

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

//*****************************************************************************
//
//! \file Check.c(checkEmpty).
//!
//! \brief This function (checkEmpty) check if the board game is empty. 
//!
//! \param Game board.
//! 
//! \return True if the column is empty.  
//!
//*****************************************************************************

int checkEmpty(char **board){
    int n, m;
    for(n=0;n<height;n++){
        for(m=0;m<width;m++){
            if(board[n][m] != blanc){return 0;}
        }
    }
    return 1;
}

//*****************************************************************************
//
//! \file Check.c(checkCol).
//!
//! \brief this function (checkCol) check if the column is empty. 
//!
//! \param Game board.
//! \param Number of column.
//! 
//! \return True if the column is empty. 
//!
//*****************************************************************************

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