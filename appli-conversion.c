#include <string.h>
#include <stdio.h>
#include "utilitaires.h"
#include "calculs.h"

#ifndef N
#define N 8
#endif

int main(int argc, char** argv) {
  int r;
  char v[N+1];

  if (argc == 2 && valide(argv[1], N)) {
    strcpy(v, argv[1]);
    printf("  Vous avez passe en parametre la chaine de caracteres :  ");
    affichage_tab(v, N);
    r = convert_vers_dec(v, N);
    printf("  Valeur convertie en decimal = %d\n", r);
    return 0;
  }
  else {
    fprintf(stderr, "Mauvais nb de parametres ou parametre non valide\n");
    return 1;
  }
}
