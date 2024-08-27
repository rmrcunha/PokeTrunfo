#include "deck.h"

#include <stdlib.h>
#include <stdio.h>

//nova fila
//fila possui um ponteiro para o topo e outro para o fundo
Deck *newDeck()
{
  Deck* cardDeck = (Deck*)malloc(sizeof(Deck));
  cardDeck->top = cardDeck->bot = NULL;
  return cardDeck;
}

//nova lista
//lista recebe pokemon
//crio um novo card "d". o conteudo de é o pokemon.
//o proximo card é null.
Card *newCard(Pokemon *p)
{
  Card *d = (Card*)malloc(sizeof(Card));
  d->cards = p;
  //d->next = NULL;
  return d;
}

void insertCard(Deck *deck, Pokemon *p)
{
  if (deck == NULL) {
    fprintf(stderr, "Error: Deck is NULL.\n");
    return;
}
  Card* temp = newCard(p);
  if(deck->bot==NULL)
  {
    deck->top = temp;
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
    deck->bot=NULL; 
    return -1;
    
  }

  Card* temp = deck->top;
  deck->top=deck->top->next;
  
  Pokemon *c = temp->cards;
  free(temp);

  return 0;
}

bool isEmpty(Deck *deck)
{
  if(deck->top==NULL) return true;
  return false;
}