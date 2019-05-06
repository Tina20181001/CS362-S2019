//
// Created by Tianshu Ren on 5/5/19.
//

/*
 * unittest4.c
 * This test is to test the card effect of Feast. It asserts the current player receive 1 card worth not more than 5;
 * These cards are from his own pile; There is no state change to other players; No state change to victory card piles and kingdom card piles.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Feast"

int main() {

    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("TEST feast card effect\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(feast, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 0;
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

    printf("Top card is %d", testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1]);
    assert(getCost(testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1]) <= 5);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}





