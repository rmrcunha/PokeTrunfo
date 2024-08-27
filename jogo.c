#include "pokedex.h"
#include "deck.h"
#include "player.h"

#include <stdio.h>
#include <stdlib.h>

void newGame(int numPlayers, int numCards)
{ 
//começo do jogo deve ser + ou - isso aqui: crio um novo player e crio um deck para ele.
  List *gameCardList = newPokemonList();
  gameCardList = fillPokeList(gameCardList, 1);
  int numPlayersJogaveis = numPlayers;
  if(numPlayers == 1) numPlayersJogaveis = numPlayersJogaveis+1;
 
  PlayerStack *playersStack = createPlayerStack();

  int winner;

  Deck *decks[numPlayersJogaveis];
  Player *players[numPlayersJogaveis];
  

  for(int i = 0; i< numPlayersJogaveis; i++){
    decks[i] = newDeck();
    players[i] = newPlayer(decks[i]);
    players[i]->id = i+1;
  }

//Daí eu posso distribuir o numero de cartas para cada player:
  for(int i = 0; i <numCards/numPlayersJogaveis;i++){
    for(int j = 0; j<numPlayersJogaveis; j++){
      if(gameCardList !=NULL &&gameCardList->poke !=NULL){
        insertCard(players[j]->deck, gameCardList->poke);
        gameCardList = gameCardList->next;
      }
    }
  }

  
  for(int round = 0;  round< numCards/numPlayersJogaveis; round++){
    for(int currentPlayer = 0; currentPlayer < numPlayersJogaveis; currentPlayer ++){
      printf("player #%d time!\n\n",currentPlayer+1);
      printf("The card that you draw is:\n");
      printf("%s - HP: %d - Attack: %d - Defense: %d - Sp_Attack: %d - Sp_Def: %d - Speed %d - Total: %d\n\n",
          players[currentPlayer]->deck->top->cards->name, players[currentPlayer]->deck->top->cards->HP,
            players[currentPlayer]->deck->top->cards->attack, players[currentPlayer]->deck->top->cards->defense,
              players[currentPlayer]->deck->top->cards->sp_attack, players[currentPlayer]->deck->top->cards->sp_def,
                players[currentPlayer]->deck->top->cards->speed, players[currentPlayer]->deck->top->cards->total);


      int choose, maxStat; 
      winner = currentPlayer;
      printf("Choose an atribute:\n(1 - HP / 2 - Attack / 3 - Defense / 4 - Sp_Attack / 5 - Sp_Def / 6 - Speed / 7 - Total)\n\n");
      if(numPlayers == 1 && currentPlayer == 1){ 
        choose = (rand() % 7) + 1;
        printf("\nChoosed %d\n\n", choose);
      }
      else scanf("%d", &choose);
      
      int currentPlayerStats;
      switch (choose) {
        case 1:
          currentPlayerStats = players[currentPlayer]->deck->top->cards->HP;
          break;
        case 2:
          currentPlayerStats = players[currentPlayer]->deck->top->cards->attack;
          break;
        case 3:
          currentPlayerStats= players[currentPlayer]->deck->top->cards->defense;
          break;
        case 4:
          currentPlayerStats = players[currentPlayer]->deck->top->cards->sp_attack;
          break;
        case 5:
          currentPlayerStats = players[currentPlayer]->deck->top->cards->sp_def;
          break;
        case 6:
          currentPlayerStats = players[currentPlayer]->deck->top->cards->speed;
          break;
        case 7:
          currentPlayerStats = players[currentPlayer]->deck->top->cards->total;
          break;
        default:
          printf("invalid choice\n\n");
          continue;
      }
      maxStat = currentPlayerStats;
      int values[numPlayersJogaveis];
      for(int i = 0;i<numPlayersJogaveis;i++){
        if(i !=currentPlayer){
          printf("Card drawed by player #%d:\n\n**%s**\n\n", i+1,players[i]->deck->top->cards->name);
          int opponentStats;

          switch (choose) {
            case 1:
              opponentStats = players[i]->deck->top->cards->HP;
              break;
            case 2:
              opponentStats = players[i]->deck->top->cards->attack;
              break;
            case 3:
              opponentStats = players[i]->deck->top->cards->defense;
              break;
            case 4:
              opponentStats = players[i]->deck->top->cards->sp_attack;
              break;
            case 5:
              opponentStats = players[i]->deck->top->cards->sp_def;
              break;
            case 6:
              opponentStats = players[i]->deck->top->cards->total;
              break;
          }
          values[i] = opponentStats;
        }
      }
      for(int i = 0; i<numPlayers; i++)
      {
        if(values[i] >maxStat)
        {
          maxStat = values[i];
          winner = i;
        }
      }

      printf("Player #%d is the winner!!\n\n", winner+1);

      for (int i = 0; i < numPlayers; i++) {
            if (i != winner) {
                insertCard(players[winner]->deck, players[i]->deck->bot->cards);
                loseCard(players[i]->deck);

                if (isEmpty(players[i]->deck)) {
                printf("Player #%d is out of the game!\n", i + 1);
                pushPlayer(&playersStack, players[i]);
                }
            }
      }
    }
  }

  printf("Final Ranking\n");
  int rank = numPlayersJogaveis;
  while(!isStackEmpty(playersStack)){
    Player *play = popPlayer(&playersStack);
    printf("#%d - Player #%d\n", rank, play->id);
    rank--;
  }
  printf("#%d - Player #%d (Winner)\n", rank, winner +1);
}
//A comparação de cards deve ser algo do tipo:
//  switch (escolha) {
//    1:players->deck->top->cards->HP;
//    2:players->deck->top->cards->attack;
//  }
//daí armazena o valor escolhido em uma variavel e compara com o dos demais players;

void print_rules(){
    printf("Ol�! Aqui voce pode conferir as regras do jogo! "
    
    "PokeTrunfo � uma varia��o tem�tica do jogo de cartas SuperTrunfo.\n"
    "No PokeTrunfo os jogadores competem utilizando cartas de Pokemons,\n"
    "onde cada carta possui diferentes atributos, como for�a, velocidade,\n"
    "intelig�ncia, ataque, entre outros.\n\n\n"

    "FASE DE PREPARA��O\n"
    "A cada rodada, O baralho de cartas Pok�Trunfo � embaralhado e\n"
    "distribu�do igualmente entre os jogadores. Cada jogador\n"
    "mant�m suas cartas empilhadas e viradas para baixo, sem olhar para elas\n\n\n"
    
    
    "OBJETIVO\n"
    "O objetivo do jogo � ganhar todas as cartas dos outros jogadores.\n\n"

    "JOGANDO A RODADA\n"
    "Define-se quem come�ar� a partida. Ent�o, o jogador\n"
    "da vez olha para a carta no topo de sua pilha e escolhe\n"
    "um atributo (for�a, velocidade, intelig�ncia, ataque, etc.) que\n"
    "acredita ser superior �s cartas dos advers�rios.\n"
    "Os outros jogadores revelam a carta no topo de suas\n"
    "pilhas e comparam o mesmo atributo.\n\n\n"

    "DETERMINANDO O VENCEDOR DA RODADA\n"
    "O jogador com o maior valor no atributo escolhido ganha a rodada.\n"
    "O vencedor coleta todas as cartas jogadas e as coloca no fundo de\n"
    "sua pr�pria pilha.\n\n\n"


    "EMPATE\n"
    "Em caso de empate (quando dois ou mais jogadores t�m o mesmo valor \n"
    "no atributo escolhido), os jogadores empatados desviram mais uma carta.\n"
    "A compara��o � feita novamente com o atributo da nova carta virada para cima\n"
    "O vencedor ent�o coleta todas as cartas da rodada. \n\n\n"
    
    "FIM DO JOGO\n"
    "O jogo continua at� que apenas um jogador tenha todas as cartas, \n"
    "declarando-o como vencedor.\n\n\n"
    
    "ATRIBUTOS QUE PODEM SER COMPARADOS:\n"
    "HP (Health ou Hit Points): HP mede quanto dano um pok�mon pode sofrer antes de morrer.\n"
    "Ataque (Attack): A for�a de ataque do Pok�mon.\n"
    "Defesa (Defense): A capacidade do Pok�mon de se defender.\n"
    "Velocidade (Speed): A rapidez do Pok�mon.\n"
    "Ataque especial (Sp. Atk): Determina qu�o poderosos ser�o os movimentos especiais de um Pok�mon.\n"
    "Defesa especial (Sp. Def): Determina quanto dano � causado quando um Pok�mon � atingido por um\n"
                               "movimento especial.\n\n\n"
    "Lend�rio (Legendary): determina se este � um pok�mon lend�rio ou n�o (atributo bin�rio). Pok�mons\n"
                          "lend�rios, s�o uma esp�cie rara e poderosa dePok�mon. Eles geralmente \n"
                          "possuem estat�sticas mais altas, habilidades �nicas e s�o mais dif�ceis de\n"
                          "capturar. No pok�trunfo, um pok�mon lend�rio ganhade qualquer pok�mon \n"
                          "n�o lend�rio.\n"
                          "Em compara��o com outros pok�mons lend�rios, um crit�rio deve ser\n"
                          "escolhido para compara��o das esp�cies.\n\n\n"
    );
}

void CL_BUFF()
{
  while((getchar())!='\n');
}
