#include "Score.h"
#include "appli.h"

int horizontalScore(char **board, char character){
    int u, v;
    int score1=0;
    for(u=0;u<height;u++)
    {
        for(v=0;v<(width-3);v++)
        {
            if(board[u][v] == character && board[u][v+1] == character && board[u][v+2] == character && board[u][v+3] == character){
                score1++;
            }
        }
    }
    return score1;
}

int verticalScore(char **board, char character){
    int u, v;
    int score1=0;
    for(v=0;v<width;v++)
    {
        for(u=0;u<(height-3);u++)
        {
            if(board[u][v] == character && board[u+1][v] == character && board[u+2][v] == character && board[u+3][v] == character){
                score1++;
            }
        }
    }
    return score1;
}

void highscore(int high)
{
    int i=0, n=0, temp;
    int *highs;
    FILE *highsc;
    highs = malloc(sizeof(int)*highscores);
    highsc = fopen("highscores.text", "w+");
    fscanf(highsc, "%d", &highs[i]);
    do
    {
        i++;
        if(fscanf(highsc, "%d", &n)!=EOF){highs[i]=n;}
        else {break;}
    }while(i<highscores);
    while(highscores>i){highs[i]=0;i++;}
    i--;
    if(high>highs[i])
    {
        highs[i] = high;
    }
    while(highs[i]>highs[i-1] && i>0)
    {
        temp = highs[i-1];
        highs[i-1] = highs[i];
        highs[i] = temp;
        i--;
    }
    highsc = fopen("highscores.text", "w");
    printf("\n\t      High Scores\n\t\t*****");
    for(i=0; i<highscores; i++)
    {
        fprintf(highsc,"%d ", highs[i]);
        printf("\n\t\t* %d *", highs[i]);
    }
    printf("\n\t\t*****");
    fclose(highsc);
}

int diagonal(char **board, char character){
    int u, v;
    int score1=0;
    for(u=(height-1);u>=3;u--)
    {
        for(v=0;v<(width-3);v++)
        {
            if(board[u][v] == character && board[u-1][v+1] == character && board[u-2][v+2] == character && board[u-3][v+3] == character){
                score1++;
            }
        }
    }
    return score1;
}

int diagonal1(char **board, char character){
    int u, v;
    int score1=0;
    for(u=(height-1);u>=3;u--)
    {
        for(v=(width-1);v>=3;v--)
        {
            if(board[u][v] == character && board[u-1][v-1] == character && board[u-2][v-2] == character && board[u-3][v-3] == character){
                score1++;
            }
        }
    }
    return score1;
}

int numX(char **board){
    int i, j, counter=0;
    for(i=height-1;i>=0;i--){
        for(j=width-1;j>=0;j--){
            if(board[i][j] == 'X'){;
            counter+=1;
            }
        }
    }
    return counter;
}

int numO(char **board){
    int i, j, counter=0;
    for(i=height-1;i>=0;i--){
        for(j=width-1;j>=0;j--){
            if(board[i][j] == 'O'){;
            counter+=1;
            }
        }
    }
    return counter;
}