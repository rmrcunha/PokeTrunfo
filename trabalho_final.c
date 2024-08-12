#include "pokedex.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_NAME 32
#define MAX_CARDS 1024
// 166 cartas disponiveis
// 2-8 jogadores
// n maximo = 20 p 8 jogadores
//  para 2 jogadores, n maximo = 83
// tad player
// tad carta - contendo Hp, attack, defense, speed, sp. def, legendary

// tad p implementação da pilha
int main()
{
    Stack *rear = NULL;
    bool option;
    int temp = 0, qnt_players = 0, max_cards = 0;

    do
    {
        printf("\n0 - START NEW GAME \nPRESS ANY BUTTON TO EXIT GAME\n");
        scanf("%d", &temp);
        CL_BUFF();
        option = temp;

    } while (option != 0 && option != 1);
    if (option != 0)
        exit(1);
    else
    {
        do
        {
            printf("HOW MANY PLAYERS WILL PLAY?\n");
            scanf("%d", &qnt_players);
            CL_BUFF();
        } while (qnt_players < 2 || qnt_players > 8);
        switch (qnt_players)
        {
                case 2: 
                    max_cards = 83;
                    break;
                case 3: 
                    max_cards = 55;
                    break;
                case 4: 
                    max_cards = 41;
                    break;
                case 5: 
                    max_cards = 33;
                    break;
                case 6: 
                    max_cards = 27;
                    break;
                case 7: 
                    max_cards = 23;
                    break;
                case 8: 
                    max_cards = 20;
                    break;                 
          }
        }
        read_pokedex();
    //o numero de jogadores sera o numero de pilhas
    // o numero de cartas para alguem ganhar sera n_pilhas * n;
//menu para iniciar novo jogo/ parar de jogar a qualquer momento
//    
//quantos jogadores vao jogar?
//iniciar jogo ao embaralhar as cartas e distribuir n cartas para os m jogadores
}
