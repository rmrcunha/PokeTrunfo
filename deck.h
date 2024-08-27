#ifndef DECK_H
#define DECK_H

#include "pokedex.h"

typedef struct card{
  Pokemon *cards;
  struct card* next;
} Card;

typedef struct deck{
  Card* top;
  Card* bot;
} Deck;

//Criar outro arquivo com player.h
//player.h possuirá uma lda.
//cada player será introduzido com uma funcao
//e pode ser removido quando a quantidade 
//de cards em seu deck chegar a zero.

Card *newCard(Pokemon *p);
Deck *newDeck();
void insertCard(Deck *deck, Pokemon *p);
int loseCard(Deck *deck);
bool isEmpty(Deck *deck);

#endif
