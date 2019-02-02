#include<stdio.h>
int rowNum(int num, char **board);
void undoRedo(char *x, char **board, int num, int *undoCol,
               int *undoRow, int *k, int *l, int *z,
               int *redoCol, int *redoRow, int *q);
void undoRedoLimit(int num, int *undoCounter, int *redoCounter);
void saveLoad(int *num, char **board);
void XMLformating(FILE* file);