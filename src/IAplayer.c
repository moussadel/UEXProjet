//*****************************************************************************
//
//! \file IAplayer.c(player).
//! \brief This function (player) Write the character character in the case num. 
//!
//! \param Game board.
//! \param Number of the case.
//! \param The character to place in the game table.
//!
//*****************************************************************************

#include "appli.h"

void player(char **board, int num, char character)
{
    int i;
    for(i=(height-1); i>=0;i--)
    {
        if(board[i][num-1]==blanc)
        {
            board[i][num-1] = character;
            break;
        }
    }
    print(board);
}

//*****************************************************************************
//
//! \file IAplayer.c(Easy)
//! \brief This function (Easy) contains The level of easy play.
//!
//! \param Game board.
//! \param Number  wich indecate the level of the IA.
//!
//*****************************************************************************

void Easy(char **board, int *num)
{
    int i, j, flag, l;
    l = rand() % width;
    for(i=(height-1); i>=0; i--)
    {
        if(board[i][l]==blanc)
        {
            board[i][l] = 'O';
            break;
        }
        flag = 0;
        while(i==0 && board[i][l]!=blanc)
        {
            l = rand() % width;
            flag = 1;
        }
        for(j=(height-1); flag==1; j--)
        {
            if(board[j][l]==blanc)
            {
                board[j][l] = 'O';
                break;
            }
        }
    }
    *num = l+1;
}

//*****************************************************************************
//
//! \file IAplayer.c (Medium).
//! \brief This function (Medium) contains The level of Medium play.
//!
//! \param Board  game board.
//! \param Number wich indecate the level of the IA.
//!
//*****************************************************************************

int Medium(char **board, char character, int *num)
{
    int i, j;
    for(i=height-1; i>=3; i--)
    {
        for(j=0; j<width; j++)
        {
            if(board[i][j] == character && board[i-1][j] == character && board[i-2][j] == character && board[i-3][j]==blanc)
            {
                board[i-3][j] = 'O';
                *num = j+1;
                return 1;
            }
        }
    }
    for(i=0;i<height;i++)
    {
        for(j=0;j<(width-3);j++)
        {
            if(board[i][j] == character && board[i][j+1] == character && board[i][j+2] == character && checkEmpty1(board,j+3,i)){
                board[i][j+3] = 'O';
                *num = j+3+1;
                return 1;
            }
            if(board[i][j+1] == character && board[i][j+2] == character && board[i][j+3] == character && checkEmpty1(board,j,i)){
                board[i][j] = 'O';
                *num = j+1;
                return 1;
            }
            if(board[i][j] == character && board[i][j+2] == character && board[i][j+3] == character && checkEmpty1(board,j+1,i)){
                board[i][j+1] = 'O';
                *num = j+1+1;
                return 1;
            }
            if(board[i][j] == character && board[i][j+1] == character && board[i][j+3] == character && checkEmpty1(board,j+2,i)){
                board[i][j+2] = 'O';
                *num = j+2+1;
                return 1;
            }
        }
    }
    for(i=height-1; i>=3; i--)
    {
        for(j=0;j<(width-3);j++)
        {
            if(board[i][j] == character && board[i-1][j+1] == character && board[i-2][j+2] == character && checkEmpty1(board,j+3,i-3)){
                board[i-3][j+3] = 'O';
                *num = j+3+1;
                return 1;
            }
            if(board[i-1][j+1] == character && board[i-2][j+2] == character && board[i-3][j+3] == character && checkEmpty1(board,j,i)){
                board[i][j] = 'O';
                *num = j+1;
                return 1;
            }
            if(board[i][j] == character && board[i-2][j+2] == character && board[i-3][j+3] == character && checkEmpty1(board,j+1,i-1)){
                board[i-1][j+1] = 'O';
                *num = j+1+1;
                return 1;
            }
            if(board[i][j] == character && board[i-1][j+1] == character && board[i-3][j+3] == character && checkEmpty1(board,j+2,i-2)){
                board[i-2][j+2] = 'O';
                *num = j+2+1;
                return 1;
            }
        }
    }
    for(i=height-1; i>=3; i--)
    {
        for(j=width-1; j>=3; j--)
        {
            if(board[i][j] == character && board[i-1][j-1] == character && board[i-2][j-2] == character && checkEmpty1(board,j-3,i-3)){
                board[i-3][j-3] = 'O';
                *num = j-3+1;
                return 1;
            }
            if(board[i-1][j-1] == character && board[i-2][j-2] == character && board[i-3][j-3] == character && checkEmpty1(board,j,i)){
                board[i][j] = 'O';
                *num = j+1;
                return 1;
            }
            if(board[i][j] == character && board[i-2][j-2] == character && board[i-3][j-3] == character && checkEmpty1(board,j-1,i-1)){
                board[i-1][j-1] = 'O';
                *num = j-1+1;
                return 1;
            }
            if(board[i][j] == character && board[i-1][j-1] == character && board[i-3][j-3] == character && checkEmpty1(board,j-2,i-2)){
                board[i-2][j-2] = 'O';
                *num = j-2+1;
                return 1;
            }
        }
    }
    return 0;
}

//*****************************************************************************
//
//! \file IAplayer.c (Hard).
//! \brief This function (Hard)contains The level of Hard play. 
//!
//! \param Game board.
//! \param Number wich indecate the level of the IA.
//!
//*****************************************************************************

void Hard(char **board, int *num)
{
    int i, j;
    char x='X',o='O';
    if(Medium(board,x,num)==1)return;
    if(Medium(board,o,num)==1)return;
    for(i=height-1; i>=2; i--)
    {
        for(j=0; j<width; j++)
        {
            if(board[i][j] == 'O' && board[i-1][j] == 'O' && board[i-2][j]==blanc)
            {
                board[i-2][j] = 'O';
                *num = j+1;
                return;
            }
        }
    }
    for(i=0;i<height;i++)
    {
        for(j=0;j<(width-2);j++)
        {
            if(board[i][j] == 'O' && board[i][j+1] == 'O' && checkEmpty1(board,j+2,i)){
                board[i][j+2] = 'O';
                *num = j+2+1;
                return;
            }
            if(board[i][j+1] == 'O' && board[i][j+2] == 'O' && checkEmpty1(board,j,i)){
                board[i][j] = 'O';
                *num = j+1;
                return;
            }
        }
    }
    for(i=height-1; i>=2; i--)
    {
        for(j=0;j<(width-2);j++)
        {
            if(board[i][j] == 'O' && board[i-1][j+1] == 'O' && checkEmpty1(board,j+2,i-2)){
                board[i-2][j+2] = 'O';
                *num = j+2+1;
                return;
            }
            if(board[i-1][j+1] == 'O' && board[i-2][j+2] == 'O' && checkEmpty1(board,j,i)){
                board[i][j] = 'O';
                *num = j+1;
                return;
            }
        }
    }
    for(i=height-1; i>=2; i--)
    {
        for(j=width-1; j>=2; j--)
        {
            if(board[i][j] == 'O' && board[i-1][j-1] == 'O' && checkEmpty1(board,j-2,i-2)){
                board[i-2][j-2] = 'O';
                *num = j-2+1;
                return;
            }
            if(board[i-1][j-1] == 'O' && board[i-2][j-2] == 'O' && checkEmpty1(board,j,i)){
                board[i][j] = 'O';
                *num = j+1;
                return;
            }
        }
    }
    Easy(board,num);
}