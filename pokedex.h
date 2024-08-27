#ifndef POKEDEX_H
#define POKEDEX_H

#include <stdbool.h>

#define MAX_CARDS 821

typedef struct pokemon
{
  char type1[16];
  char type2[16];
  int gen, total;
  unsigned int HP, attack, defense, speed, sp_def, sp_attack;
  bool legendary;
  char name[32];
} Pokemon;

typedef struct list
{
  int n;
  Pokemon *poke;
  struct list *prev;
  struct list *next;
} List;


Pokemon *createPokeList();
void printPokedex(List *pList);
void convert_to_uppercase(char *toupper_pokemon_name);
void search_pokemon(const char *pokemon_name, List *deck);
List *fillPokeList(List *pokeList, int mode);
List *newPokemonList();
List *removeTop(List *pokeList);

#endif
