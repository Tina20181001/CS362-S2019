//
// Created by Tianshu Ren on 5/5/19.
//

/*
 * cardtest4.c
 * This test is to test the card effect of Sea Hag.
 * It asserts the other players trash their top card and get a curse card on top of their deck.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Sea Hag"

int main() {

    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int otherPlayer = 1;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(sea_hag, choice1, choice2, choice3, &testG, handpos, &bonus);

    //top of other player's deck is replaced with curse card.

    printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer]);
    assert(testG.handCount[otherPlayer] == G.handCount[otherPlayer]);

    printf("expected top card of other player is %d\n", testG.handCount[thisPlayer] - 1);
    assert(testG.deckCount[otherPlayer] == curse);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}





