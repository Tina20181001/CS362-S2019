/* CS362 Assignment4
 * Name: Tianshu Ren
 * Date: May 19, 2019
 * Description: This is the random testing for card Council Room.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "time.h"

//testing council room
int main(int argc, char **argv) {
    int kingdom[10] = {adventurer, gardens, embargo, village, council_room, mine, cutpurse, sea_hag, tribute, smithy};
    int testSuccessful = 0, testFailed = 0, i, tests = 1000;//sets number of tests, testSuccessful = successful, testFailed = not successful

    clock_t t;
    t = clock();

    for (i = 0; i < tests; i++) {

        int num_players = rand() % 4, player = 0, rand_seed = rand();//set player, #players, and random seed
        struct gameState *g = malloc(sizeof(struct gameState));
        //struct gameState g;

        initializeGame(num_players, kingdom, rand_seed, g);//Initialize game

        g->deckCount[player] = rand() % MAX_DECK;//randomize deck size
        g->discardCount[player] = rand() % MAX_DECK;//randomize discard size
        int pastHandCount = g->handCount[player] = rand() % MAX_HAND;//randomize hand size
        int opponentHandCount = g->handCount[1] = rand() % MAX_HAND;//randomize opponents hand size
        int pastNumBuys = g->numBuys;
        //cardEffectCouncilRoom(pastHandCount, g);
        if (pastHandCount + 3 == g->handCount[player] && pastNumBuys + 1 == g->numBuys && opponentHandCount + 1 == g->handCount[1]) {
            testSuccessful++;
        } else
            testFailed++;

        free(g);
    }
    t = clock() - t;

    printf("Random Test 2: Council Room Card");
    printf("\nRunning time is %f", ((double) t) / CLOCKS_PER_SEC);
    printf("\nThere were %d successful council room card plays, and %d failures [out of %d games]\n\n", testSuccessful, testFailed, tests);

    return 0;
}