/* CS362 Assignment4
 * Name: Tianshu Ren
 * Date: May 19, 2019
 * Description: This is the random testing for card Smithy.
 */
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

//testing smithy
int main() {

    int kingdom[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i, testSuccessful, testFailed = 0;
    int tests = 1000;

//    srand(time(NULL));
    //randomize hand size

    clock_t t;
    t = clock();

    for(i = 0; i < tests; i++){

        int num_players = rand() % 4, player = 0, rand_seed = rand();//set player, number of players, and random seed
        struct gameState *g = malloc(sizeof(struct gameState));//make game state
        initializeGame(num_players, kingdom, rand_seed, g);//Initialize game

        int deckSize = rand() % (MAX_DECK + 1);//randomize deck size
        int handSize = rand() % (deckSize + 1);//randomize hand size

        g->deckCount[0] = deckSize - handSize;
        g->handCount[0] = handSize;

        int handPos = g->hand[player][g->handCount[player] - 1];
        //personal checks
        int deckBefore = g->deckCount[player];
        int handBefore = g->handCount[player];
        int discardBefore = g->playedCardCount;

        cardEffectSmithy(handPos, g);//play the card

        int deckAfter = g->deckCount[player];
        int handAfter = g->handCount[player];
        int discardAfter = g->playedCardCount;


        if ((handAfter == (handBefore + 2)) && (deckAfter == (deckBefore - 3)) && (discardAfter == (discardBefore + 1))) {
            testSuccessful++;
        } else {
            testFailed++;
        }
    }
    t = clock() - t;

    printf("Random test 1 Smithy Card");
    printf("\nRunning time is %f", ((double) t) / CLOCKS_PER_SEC);
    printf("\nThere were %d successful Smithy card plays, and %d failures [out of %d games]\n\n", testSuccessful, testFailed, tests);

    return 0;
}

