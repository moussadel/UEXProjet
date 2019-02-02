//*****************************************************************************
//
//! \file GameBoaerd.c (rowNum).
//! \brief This function (rowNum) calculates the point obtained after the shot.
//!
//! \param  Game board.
//! \param  The variable that indicates the location.
//!
//! \return The point obtained after the shot. 
//!
//*****************************************************************************

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

//*****************************************************************************
//
//! \file GameBoaerd.c (undoRedo).
//! \brief This function (undoRedo) undo redo the player input. 
//!
//! \param The number that indicates whether to back up or restore.
//! \param Game board.
//! \param The number of the case that wants to cancel.
//! \param The rew to be undo.
//! \param The rew to be redo.
//! \param The column to be undo. 
//! \param The column to be redo.
//!
//*****************************************************************************

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

//*****************************************************************************
//
//! \file GameBoaerd.c (undoRedoLimit).
//! \brief This function (undoRedoLimit) calculates  limite undo redo the player input. 
//!
//! \param The variable which indicates if one must undo redo.
//! \param The variable that indicates the number of redo made.
//! \param The variable that indicates the number of undo made.
//!
//*****************************************************************************

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

//*****************************************************************************
//
//! \file GameBoaerd.c (saveLoad).
//! \brief This function (saveLoad)save or restore the game.
//!
//! \param The variable that indicates whether to back up or restore.
//! \param Game board.
//!
//*****************************************************************************

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

//*****************************************************************************
//
//! \file GameBoaerd.c (XMLformating).
//! \briefh This function (XMLformating) read the size from XML file.
//!
//! \param The file that contains the size of the game table.
//!
//*****************************************************************************

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