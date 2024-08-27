#include "player.h"
#include <stdlib.h>

Player *newPlayer(Deck *deck){
  Player *createdPLayer = malloc(sizeof(Player));
  createdPLayer->deck = deck; 
  
  return createdPLayer;
}

PlayerStack* createPlayerStack() {
    return NULL;
}

void pushPlayer(PlayerStack **stack, Player *player) {
    PlayerStack *newNode = (PlayerStack*) malloc(sizeof(PlayerStack));
    newNode->player = player;
    newNode->next = *stack;
    *stack = newNode;
}

Player* popPlayer(PlayerStack **stack) {
    if (*stack == NULL) return NULL;
    PlayerStack *temp = *stack;
    Player *player = temp->player;
    *stack = (*stack)->next;
    free(temp);
    return player;
}

bool isStackEmpty(PlayerStack *stack) {
    return stack == NULL;
}
