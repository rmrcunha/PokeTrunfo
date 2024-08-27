#include "pokedex.h" 

#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//Func mais feia do que bater na vó
void printPokedex(List *pList)
{
  while(pList != NULL)
  {
    printf("Name: %s\n\n", pList->poke->name);
    printf("Type 1: %s ||", pList->poke->type1);
    printf("Total: %d\n", pList->poke->total);
    printf("HP: %d\n", pList->poke->HP);
    printf("Attack: %d\n", pList->poke->attack);
    printf("Defense: %d\n", pList->poke->defense);
    printf("Speed: %d\n", pList->poke->speed);
    printf("Special Defense: %d\n", pList->poke->sp_def);
    printf("Special Attack: %d\n", pList->poke->sp_attack);
    printf("\n\n\n");

    pList = pList->next;
  }
}

//Retornar um pokemon aleatorio da stack

//Pokemon pickPoke(Pokemon *list){
 
//}

//Mode vai definir se eu vou encher a lista de forma ordenada ou aleatória: 0 - ordenada/ 1 - aleatória
List *fillPokeList(List *pokeList,int mode)
{
  char linha[100];
  FILE *file = fopen("./arquivos/pokemon.txt", "r");
  if(file == NULL)
  {
    perror("ERROR READING THE FILE");
    exit(EXIT_FAILURE);
  }
  List *newPoke;
  srand(time(NULL));
  while(fgets(linha, sizeof(linha), file) !=NULL)
  {
    newPoke = malloc(sizeof(List));
    if(newPoke == NULL){
      perror("ERROR ALLOCATING MEMORY");
      exit(EXIT_FAILURE);
    }

    newPoke->poke = malloc(sizeof(Pokemon));
    if(newPoke->poke == NULL){
      perror("ERROR ALLOCATING MEMORY");
      exit(EXIT_FAILURE);
    }
    char *token = strtok(linha,",");
    int structCounter = 0;
    while(token !=NULL)
    {
      if(structCounter == 1) strcpy(newPoke->poke->name, token);
      if(structCounter == 2) strcpy(newPoke->poke->type1, token);
      if(structCounter == 3) strcpy(newPoke->poke->type2, token);
      if(structCounter == 4) newPoke->poke->total = atoi(token);
      if(structCounter == 5) newPoke->poke->HP = atoi(token);
      if(structCounter == 6) newPoke->poke->attack= atoi(token);
      if(structCounter == 7) newPoke->poke->defense = atoi(token);
      if(structCounter == 8) newPoke->poke->sp_attack= atoi(token);
      if(structCounter == 9) newPoke->poke->sp_def = atoi(token);
      if(structCounter == 10) newPoke->poke->gen = atoi(token);
      
      structCounter++;
      token = strtok(NULL,",");
    }
    if(mode == 0){ 
      newPoke->next = pokeList;
      newPoke->prev = NULL;
      if(pokeList !=NULL){
        pokeList->prev = newPoke;
      }
      pokeList = newPoke;
    }
    if(mode == 1){
      if(pokeList == NULL){
        newPoke->next = NULL;
        newPoke->prev = NULL;
        pokeList = newPoke;
      }
      else{
          List *current = pokeList;
        int nRand = rand()%2;
        if(!nRand){
          newPoke->next = pokeList;
          newPoke->prev = NULL;
          pokeList->prev = newPoke;
          pokeList = newPoke;
        } else {
            while(current->next !=NULL && rand()%2 !=0) current = current->next;
            newPoke->next = current->next;
            newPoke->prev = current;
            if(current->next !=NULL){
              current->next->prev= newPoke;
            }
            current->next = newPoke;
        }
      }
      } 
    }
  fclose(file);
  
  return pokeList;
}
//código ruim/ 0 escalabilidade/ feito de maneira burra
//vai funcionar por um motivo que eu desconheço qual seja
//suco do brainrot

List *removeTop(List* pokeList){
  if(pokeList == NULL){
    printf("The list is empty\n");
    return NULL;
  }
  List *temp = pokeList;
  pokeList = pokeList->next;
  
  if(pokeList !=NULL){
    pokeList->prev = NULL;
  } 
  if(temp->poke != NULL) free(temp->poke);
  free(temp);
  return pokeList;
}

void convert_to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void search_pokemon(const char *pokemon_name, List *deck) {
    char upper_name[1024];
    strcpy(upper_name, pokemon_name);
    
    upper_name[strcspn(upper_name, "\n")] = '\0';
    convert_to_uppercase(upper_name);

    while (deck != NULL) {
        if (deck->poke != NULL) {
            char poke_name_upper[1024];
            strcpy(poke_name_upper, deck->poke->name);
            convert_to_uppercase(poke_name_upper);

            // Comparar os nomes
            if (strcmp(poke_name_upper, upper_name) == 0) {
                printf("Pokemon encontrado:\n");
                printf("Name: %s\n", deck->poke->name);
                printf("Type 1: %s\n", deck->poke->type1);
                printf("HP: %d\n", deck->poke->HP);
                printf("Attack: %d\n", deck->poke->attack);
                printf("Defense: %d\n", deck->poke->defense);
                printf("Speed: %d\n", deck->poke->speed);
                printf("Sp. Attack: %d\n", deck->poke->sp_attack);
                printf("Sp. Defense: %d\n", deck->poke->sp_def);
                printf("\n");
                return;
            }
        }
        deck = deck->next;
    }

    printf("Pokemon não encontrado!\n");
}


List *newPokemonList(){
  return NULL;
}