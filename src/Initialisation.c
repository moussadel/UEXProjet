//*****************************************************************************
//
//! \file Initialisation.c(AllocationMemoire).
//! \brief This function (AllocationMemoire) allocate memory for the game.
//!
//! \param Game board.
//! \param The row table for undo.
//! \param The row table for redo.
//! \param The column table for undo.
//! \param The column table for redo.
//! \param
//! \param        
//!
//*****************************************************************************

#include "appli.h"

void AllocationMemoire(int **undoCol,int **redoCol,int **undoRow,
                        int **redoRow,int **compUndoCol,int **compUndoRow,char ***board){

    *undoCol = (int *)malloc(height*width*sizeof(int));
    if(undoCol==NULL) {
        printf("ERROR UndoCol!!!\n");
        exit(0);
    }
    *redoCol = (int *)malloc(height*width*sizeof(int));
    if(redoCol==NULL) {
        printf("ERROR RedoCol!!!\n");
        exit(0);
    }
    *undoRow = (int *)malloc(height*width*sizeof(int));
    if(undoRow==NULL) {
        printf("ERROR UndoRow!!!\n");
        exit(0);
    }
    *redoRow = (int *)malloc(height*width*sizeof(int));
    if(redoRow==NULL) {
        printf("ERROR RedoRow!!!\n");
        exit(0);
    }
    *compUndoCol = (int *)malloc(height*width*sizeof(int));
    if(compUndoCol==NULL) {
        printf("ERROR CompUndoCol!!!\n");
        exit(0);
    }
    *compUndoRow = (int *)malloc(height*width*sizeof(int));
    if(compUndoRow==NULL) {
        printf("ERROR CompUndoRow!!!\n");
        exit(0);
    }
    *board = (char **)malloc(height*sizeof(char **));
    if(board==NULL) {
        printf("ERROR Board!!!\n");
        exit(0);
    }
    for(int i=0; i<height; i++){
        (*board)[i] = malloc(width*sizeof(char *));
        if((*board)[i]==NULL) {
            printf("ERROR Board!!!\n");
            exit(0);
        }
    }   
}

//*****************************************************************************
//
//! \file Initialisation.c(initialisation).
//! \brief This function (initialisation) initializes the different boards for the game.
//!
//! \param Game board.
//! \param The row table for undo.
//! \param The row table for redo.
//! \param The column table for undo.
//! \param The column table for redo.
//! \param
//! \param        
//!
//*****************************************************************************

void initialisation(int **undoCol,int **redoCol,int **undoRow,
                        int **redoRow,int **compUndoCol,int **compUndoRow,char ***board){
    int i,j;

    for(i=0;i<height*width;i++){
            (*undoCol)[i] = 0;
    }
    for(i=0;i<height*width;i++){
        (*redoCol)[i] = 0;
    }
    
    for(i=0;i<height*width;i++){
        (*undoRow)[i] = 0;
    }

    for(i=0;i<height*width;i++){
        (*redoRow)[i] = 0;
    }
    
    for(i=0;i<height*width;i++){
        (*compUndoCol)[i] = 0;
    }
    
    for(i=0;i<height*width;i++){
        (*compUndoRow)[i] = 0;
    }

    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            (*board)[i][j]= blanc;
        }
    }
}    


       