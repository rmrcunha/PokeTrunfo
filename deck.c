#include "deck.h"

#include <stdlib.h>
#include <stdio.h>

Deck *newDeck()
{
  Deck* cardDeck = (Deck*)malloc(sizeof(Deck));
  cardDeck->top = cardDeck->bot = NULL;
  return cardDeck;
}

Card *newCard(Pokemon c)
{
  Card *d = (Card*)malloc(sizeof(Card));
  d->cards = c;
  d->next = NULL;
  return d;
}
//Implementar card distribution no atual insertCard e fazer um insertCard onde eu não
//preciso verificar se o deck está cheio.
void insertCard(Deck *deck, Pokemon c)
{
  Card* temp = newCard(c);
  if(deck->bot==NULL)
  {
    deck->top =deck->bot;
    deck->bot = temp;
    return;
  }
  deck->bot->next=temp;
  deck->bot = temp;
}

int loseCard(Deck *deck)
{
  if(isEmpty(deck)) 
  {
    return -1;
    deck->bot=NULL; 
  }

  Card* temp = deck->top;
  deck->top=deck->top->next;
  
  Pokemon c = temp->cards;
  free(temp);

  return 0;
}

bool isEmpty(Deck *deck)
{
  if(deck->top==NULL) return true;
  return false;
}
