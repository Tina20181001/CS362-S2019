/* CS362 Assignment 4
 * Name: Tianshu Ren
 * Date: May 19, 2019
 * Description: This is the random testing for card Adventurer.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "time.h"

int main (int argc, char** argv) {
    int kingdom[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int testSuccessful = 0, testFailed = 0,i, tests = 1000;//sets number of tests, testSuccessful = successful, testFailed = not successful

    clock_t t;
    t = clock();

    for(i = 0; i < tests; i++) {

        int num_players = 2, player = 0, rand_seed = rand();//set player, number of players, and random seed
        struct gameState *g = malloc(sizeof(struct gameState));//make game state
        initializeGame(num_players, kingdom, rand_seed, g);//Initialize game

        g->deckCount[player] = rand() % MAX_DECK;//randomize deck size
        g->discardCount[player] = rand() % MAX_DECK;//randomize discard size
        int oldHand = g->handCount[player] = rand() % MAX_HAND;//randomize hand size
        int opponentsHand = g->handCount[1] = rand() % MAX_HAND;
        int opponentsDeck = g->deckCount[1] = rand() % MAX_DECK;
        int checkStatus = 0,x;//variable to track if cards added were treasure cards or not

        for(x = 0 ; x < g->handCount[player]; x++) {
            if((g->hand[player][x] == gold) || (g->hand[player][x] == silver) || (g->hand[player][x] == copper)) {
                checkStatus++;
            }
        }

        cardEffectAdventurer(g);//play the card

        for(x = 0 ; x < g->handCount[player]; x++) {
            if((g->hand[player][x] == gold) || (g->hand[player][x] == silver) || (g->hand[player][x] == copper)) {
                checkStatus--;
            }
        }

        if(checkStatus < 0 && oldHand + 1 == g->handCount[player] && opponentsHand == g->handCount[1] && opponentsDeck == g->deckCount[1])
            testSuccessful++;
        else
            testFailed++;

        free(g);
    }

    printf("Random Test Adventurer Card");
    printf("\nRunning time is %f", ((double) t) / CLOCKS_PER_SEC);
    printf("\nThere were %d successful adventurer card plays, and %d failures [out of %d games]\n\n", testSuccessful, testFailed, tests);

    return 0;
}