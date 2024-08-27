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


Card *newCard(Pokemon *p);
Deck *newDeck();
void insertCard(Deck *deck, Pokemon *p);
int loseCard(Deck *deck);
bool isEmpty(Deck *deck);

#endif
