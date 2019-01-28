#include "GameBoard.h"
#include "appli.h"
#include <stdlib.h>
#include <stdio.h>

int rowNum(int num, char **board){
    int i=0;
    for(i=0;i<height;i++){
        if(num == 0){return 0;}
        if(board[i][num-1]!=blanc){break;}
    }
    return i-1;
}

void undoRedo(char *x, char **board, int num, int *undoCol,int *undoRow, int *k, int *l, int *z,
               int *redoCol, int *redoRow, int *q){

        static int ccounter = 0, dcounter = 0;
        
        if(num != 0 && !checkCol(num, board) && num != -3 && !(num<-3) && !(num>width) && !(num == -2)){
            undoCol[*q] = num-1;
            *k = rowNum(num, board);
            undoRow[*q] = *k;
        }
        if(num != 0 && !checkCol(num, board) && num != -3 && !(num<-3) && !(num>width) && !(num == -2)){
            redoCol[*z] = num-1;
            *l = rowNum(num, board);
            redoRow[*z] = *l;
            *z+=1;
        }
        if(num == 0){
            ccounter +=1;
            board[undoRow[(*q-1)]][undoCol[(*q-1)]] = blanc;
            print(board);
            *q-=1;
            *z-=1;
        }
        else if(num == -3){
            dcounter += 1;
            if((dcounter <= ccounter)){
                board[redoRow[*z]][redoCol[*z]] = *x;
                print(board);
                *q+=1;
                undoCol[*q] = redoCol[*z+1];
                undoRow[*q] = redoRow[*z+1];
                *z+=1;
            }
        }
        else if(num == -1){
            printf("Game Loaded Successfully");
        }
        else if(num == -2){
            printf("Game saved Successfully");
            print(board);
        }
        else{
            *q+=1;
            player(board,num,*x);
            ccounter = 0;
            dcounter = 0;
        }
}

void undoRedoLimit(int num, int *undoCounter, int *redoCounter){
    if(num == 0){
        *undoCounter += 1;
    }
    else if(num == -3){
        *redoCounter += 1;
    }
    else{
        *undoCounter = 0;
        *redoCounter = 0;
    }
}

void saveLoad(int *num, char **board){
    FILE *pfile;
    int r, t;
    if(*num == -2){
        printf("Game Saved Successfully");
        pfile = fopen("save.txt", "w+");
        for(r=height-1;r>=0;r--){
            for(t=width-1;t>=0;t--){
                fprintf(pfile, "%c", board[r][t]);
            }
        }
        fclose(pfile);
    }
    if(*num == -1){
        pfile = fopen("save.txt", "r");
        if(pfile == NULL)
        {
            printf("Aucune partie n'as été sauvegarder !! \n");
        }
        else
        {
            for(r=height-1;r>=0;r--){
                for(t=width-1;t>=0;t--){
                    fscanf(pfile, "%c", &board[r][t]);
                }
            }
            
            fclose(pfile);
            print(board);
        }
        
        
        
    }
}

void XMLformating(FILE* file)
{
    char  c, c1, c2, c3, c4, c5, c6, c7, widthTag, heightTag, highscoresTag;
    int start=0, End=0, flag1=0, flag2=0, widthflag=0, heightflag=0, highscoresflag=0;
    fscanf(file,"< Configurations %c", &c);
    if(c=='>'){
        flag1=1;
        start=ftell(file);
    }
    else{
        while(fscanf(file,"%c", &c1)!=EOF){
            fscanf(file,"< Configurations %c", &c2);
            if(c2=='>'){
                flag1=1;
                start=ftell(file);
                break;
            }
        }
    }
    while(fscanf(file,"%c", &c3)!=EOF){
        fscanf(file,"< / Configurations %c", &c4);
        if(c4=='>'){
            flag2=1;
            End=ftell(file);
            break;
        }
    }
    if(flag1==1 && flag2==1)
    {
        fseek(file,start,SEEK_SET);
        while(fscanf(file,"%c", &c5)!=EOF){
            fscanf(file,"< Width >%d < / Width %c", &width, &widthTag);
            if( (widthTag=='>') && (width>=4) && ftell(file)<End ) {widthflag=1; break;}
        }
        fseek(file,start,SEEK_SET);
        while(fscanf(file,"%c", &c6)!=EOF){
            fscanf(file,"< Height >%d < / Height %c", &height, &heightTag);
            if( (heightTag=='>') && (height>=4) && ftell(file)<End ) {heightflag=1; break;}
        }
        fseek(file,start,SEEK_SET);
        while(fscanf(file,"%c", &c7)!=EOF){
            fscanf(file,"< Highscores >%d < / Highscores %c", &highscores, &highscoresTag);
            if( (highscoresTag=='>') && (highscores>=4) && ftell(file)<End ) {highscoresflag=1; break;}
        }
    }
    if(width==0 || widthflag==0){
        width=7;
        printf("Incorrect file format, default value of width (7) is loaded\n");
    }
    if(height==0 || heightflag==0){
        height=6;
        printf("Incorrect file format, default value of height (6) is loaded\n");
    }
    if(highscores==0 || highscoresflag==0){
        highscores=5;
        printf("Incorrect file format, default value of highscore list (5) is loaded\n");
    }
    fclose(file);
}