#ifndef MENGER
#define MENGER
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menger(int level);
char *level_up(char *sponge, int l);
char *build_sponge(char *sponge, int size);
int build_border_center(char *b, char *ce, int c, char *l, int t);
char *concatenate(char *border, char *center, int size);
#endif
