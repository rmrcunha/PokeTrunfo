#include "pokedex.h" 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void printPokedex(Pokemon *deck)
{
  for(int i = 0;  i<40; i++)
  {
    printf("Name: %s\n\n", deck[i].name);
    printf("Type 1: %s ||", deck[i].type1);
    printf("Total: %d\n", deck[i].total);
    printf("HP: %d\n", deck[i].HP);
    printf("Attack: %d\n", deck[i].attack);
    printf("Defense: %d\n", deck[i].defense);
    printf("Speed: %d\n", deck[i].speed);
    printf("Special Defense: %d\n", deck[i].sp_def);
    printf("Special Attack: %d\n", deck[i].sp_attack);
    printf("\n\n\n");
  }
}

void show_pokedex()
{
  unsigned int i = 0;
  char linha[100];
  FILE *file = fopen("./arquivos/pokemon.txt", "r");
  if(file == NULL)
  {
    perror("ERROR READING THE FILE");
    exit(EXIT_FAILURE);
  }
  Pokemon deck[MAX_CARDS];
  while(fgets(linha, sizeof(linha), file) !=NULL)
  {
    char *token = strtok(linha,",");
    int structCounter = 0;
    while(token !=NULL)
    {
      if(structCounter == 1) strcpy(deck[i].name, token);
      if(structCounter == 2) strcpy(deck[i].type1, token);
      if(structCounter == 3) strcpy(deck[i].type2, token);
      if(structCounter == 4) deck[i].total = atoi(token);
      if(structCounter == 5) deck[i].HP = atoi(token);
      if(structCounter == 6) deck[i].attack= atoi(token);
      if(structCounter == 7) deck[i].defense = atoi(token);
      if(structCounter == 8) deck[i].sp_attack= atoi(token);
      if(structCounter == 9) deck[i].sp_def = atoi(token);
      if(structCounter == 10) deck[i].gen = atoi(token);
      
      structCounter++;
      token = strtok(NULL,",");
    }
      i++;
    
  }
  fclose(file);
  printPokedex(deck);
}

Card search_pokedex(){
  
}

void CL_BUFF()
{
  while((getchar())!='\n');
}
