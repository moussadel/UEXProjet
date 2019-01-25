#include "calculs.h"

int convert_vers_dec(char v[], int l){    // Conversion bin -> dec
  int valeur, i;
  valeur = 0;
  for(i=l-1; i>=0; i--)
    valeur = valeur*2 + (v[i] - '0');
  return valeur;
}
