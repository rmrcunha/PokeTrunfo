#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"

#define MAX_NAME 32

typedef struct player
{
  char username[MAX_NAME];
  Deck *deck;
  struct player *prevPlayer;
  struct player *nextPlayer;
}Player;

Player *newPlayer(Deck *deck);
Player *findPlayer(Player *player, int playerPos);
int removePLayer(Player *player, int pos);


#endif
