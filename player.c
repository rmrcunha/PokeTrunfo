#include "player.h"
#include <stdlib.h>

Player *newPlayer(Deck *deck){
  Player *createdPLayer = malloc(sizeof(Player));
  
  createdPLayer->prevPlayer = NULL;
  createdPLayer->nextPlayer = NULL;
  createdPLayer->deck = deck; 
  
  return createdPLayer;
}

Player *findPlayer(Player *player, int playerPos){
  Player *currentPlayer = player;
  for(int i=1;i<=playerPos;i++) currentPlayer= currentPlayer->nextPlayer;

  return currentPlayer;
}

int removePLayer(Player *player, int pos){
  if(player == NULL) return 1;

  Player *currentPlayer = player;

  for(int i = 1; i<= pos; i++){
    currentPlayer = currentPlayer->nextPlayer;
  }
  if(currentPlayer == NULL) return 1;

  if(currentPlayer->prevPlayer){
    currentPlayer->prevPlayer->nextPlayer =   currentPlayer->nextPlayer;
  }
  if(currentPlayer->nextPlayer){
    currentPlayer->nextPlayer->prevPlayer = currentPlayer->prevPlayer;
  }

  if(player == currentPlayer){
    player= currentPlayer->nextPlayer;
  }
  
  free(currentPlayer);

  return 0;
}
