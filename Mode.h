#include "appli.h"

void print(char **board);
void mode_one(int *score1,int *score2,int num,int redoCounter,int undoCounter,
				int *undoCol,int *undoRow,int *redoCol,int *redoRow,int z,int q,char **board);

void mode_two(int *score1,int *score2,int choose,int high,int num,int redoCounter,int undoCounter,
				int *undoCol,int *undoRow,int *redoCol,int *redoRow,int *compUndoCol,
				int *compUndoRow,int compUndoCounter,int z,int q,int c,int d,char **board);
 
void display_mode(int high,int score1,int score2,int *compUndoCol,int undoCounter,int redoCounter,
					int compUndoCounter, int  num, int *undoCol,int *undoRow,int *redoCol,
					int *redoRow,int *compUndoRow, int q,int z,int d,int c, char **board);