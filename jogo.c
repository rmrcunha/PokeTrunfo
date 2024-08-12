#include "pokedex.h"
#include "deck.h"

#include <stdio.h> 

void newGame(int numPlayers, int numCards)
{
  Player players[numPlayers];
  for(int i = 0; i <= numPlayers; i++)
  {
    players[i].deck = newDeck();
    for(int j=0;j<=(numCards/numPlayers);j++){
      insertCard(players[i].deck, );
    }

  }
}

void CL_BUFF()
{
  while((getchar())!='\n');
}
    
