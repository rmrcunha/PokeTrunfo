#ifndef POKEDEX_H
#define POKEDEX_H

#include <stdbool.h>

#define MAX_NAME 32
#define MAX_CARDS 1024

typedef struct pokemon
{
  char type1[16];
  char type2[16];
  int gen, total;
  unsigned int HP, attack, defense, speed, sp_def, sp_attack;
  bool legendary;
  char name[MAX_NAME];
} Pokemon;

typedef struct stack
{
  int n;
  struct stack *next;
} Stack;

void printPokedex(Pokemon *deck);
void read_pokedex();

#endif
