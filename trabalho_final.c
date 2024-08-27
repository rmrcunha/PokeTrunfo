#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "jogo.h"
#include "pokedex.h"
#include "deck.h"
#include "player.h"

int main(){

  List *mainDeck = newPokemonList();
  mainDeck = fillPokeList(mainDeck, 0);

  char pokemon_name[32];
  int option = 0, qnt_cards = 0, qnt_players = 0;
  do
    {
        printf("\n\t\tBem vindo ao Menu de Poketrunfo! \n");
        printf("\n\t\t_________________________\n");
        printf("\t\t1 - Comecar novo jogo \n"
        "\t\t-------------------------\n"
        "\t\t2 - Buscar Pokemon \n"
        "\t\t-------------------------\n"
        "\t\t3 - Exibir a pokedex \n"
        "\t\t-------------------------\n"
        "\t\t4 - Creditos \n"
        "\t\t-------------------------\n"
        "\t\t5 - Regras do jogo \n"
        "\t\t-------------------------\n"
        "\t\t6 - Sair do jogo\n"
        "\t\t_________________________\n");
        scanf("%d", &option);
        getchar();

    } while (option < 1 || option > 6);

    switch (option){
        case 1:
            printf("How many players will play the game?\n");
            scanf("%d", &qnt_players);
            if(qnt_players > 8){
              printf("Numero de jogadores redefinido para 8 (limite)\n\n");
              qnt_players = 8;
            }
            printf("Com quantos cards deseja jogar?\n");
            scanf("%d", &qnt_cards);
            if(qnt_cards < 2*qnt_players){
              qnt_cards = qnt_players*2;
              printf("Quantidade de cards informada foi insuficiente, então foi redefinida para %d\n\n", qnt_cards);
            }
            if(qnt_cards > MAX_CARDS){
              qnt_cards = MAX_CARDS;
              printf("Quantidade de cards redefinida para %d", MAX_CARDS);
            }
            newGame(qnt_players, qnt_cards);
            break;
        case 2:
        printf("Digite o nome do pokemon a ser buscado: \n");
            fgets(pokemon_name, sizeof(pokemon_name), stdin); //os caracteres do nome digitado vao ser convertido para maiusculos, bem como os caracteres do nome do arquivo .txt
                pokemon_name[strcspn(pokemon_name, "\n")] = '\0'; // remove newline character
                search_pokemon(pokemon_name, mainDeck);
            break;
        case 3:
            printPokedex(mainDeck);
            break;
        case 4:
            printf("Trabalho Final - AED I\n\nIntegrates: Andre Schwantes e Renan Cunha\n\n");
            break;
        case 5:
            print_rules();
            break;
        case 6:
            exit(0);
            break;
        }
    
   
}    //o numero de jogadores sera o numero de pilhas
    // o numero de cartas para alguem ganhar sera n_pilhas * n;