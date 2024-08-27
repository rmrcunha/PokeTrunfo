#ifndef PLAYER_H
#define PLAYER_H

#include "deck.h"

#define MAX_NAME 32

typedef struct player
{
  int id;
  Deck *deck;
}Player;

typedef struct PlayerStack {
    Player *player;
    struct PlayerStack *next;
} PlayerStack;

Player *newPlayer(Deck *deck);
PlayerStack* createPlayerStack();
void pushPlayer(PlayerStack **stack, Player *player);
Player* popPlayer(PlayerStack **stack);
bool isStackEmpty(PlayerStack *stack);


#endif
