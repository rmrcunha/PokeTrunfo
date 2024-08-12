#ifndef DECK_H
#define DECK_H

#include "pokedex.h"

typedef struct card{
  Pokemon cards;
  struct card* next;
} Card;

typedef struct deck{
  Card* top;
  Card* bot;
} Deck;

typedef struct player
{
  char username[MAX_NAME];
  Deck *deck;
} Player;

Card *newCard(Pokemon c);
Deck *newDeck();
void insertCard(Deck *deck, Pokemon c);
int loseCard(Deck *deck);
bool isEmpty(Deck *deck);

#endif
