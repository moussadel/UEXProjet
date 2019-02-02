//*****************************************************************************
//
//! \file appli.c(main)
//! \brief The main program.
//!  This function is the main program that allows you to allocate memory, 
//!     initialize variables and start the game.
//!
//! \param argc the number of arguments to pass in parameter.
//! \param argv * [] the name of the file containing the dimensions of the game table.
//!
//! \return the function termination code.      
//!
//*****************************************************************************

#include "appli.h"

int main(int argc,char* argv[])
{
    int high=0;
    
    FILE *file;
    if(argc==1){
        printf("Donner un argument\n");
        exit(0);
    }
    file= fopen(argv[1], "r");
    if(file==NULL) {
        perror("fopen ");
        exit(0);
    }
    XMLformating(file);
    char playAgain;
    do{
        int score1=0, score2=0,*compUndoCol=NULL, undoCounter=0,redoCounter=0, compUndoCounter =0;
        int num=0, *undoCol=NULL,*undoRow=NULL,*redoCol=NULL, *redoRow=NULL,*compUndoRow=NULL;
        static int q=0, z=0, d=0, c=0;
        char **board=NULL;

        AllocationMemoire(&undoCol, &redoCol, &undoRow,
                         &redoRow, &compUndoCol, &compUndoRow, &board);
        initialisation(&undoCol, &redoCol, &undoRow,
                         &redoRow, &compUndoCol , &compUndoRow, &board);
        DisplayMode(high,score1,score2,compUndoCol,undoCounter,redoCounter,compUndoCounter,
                    num, undoCol,undoRow,redoCol,redoRow,compUndoRow,q,z,d,c,board);
        scanf("\n%c",&playAgain);
    }while(playAgain == 'y');
    return 0;
}