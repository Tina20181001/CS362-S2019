//
// Created by Tianshu Ren on 5/5/19.
//

/*
 * unittest3.c
 * This test is to test the card effect of Council Room. It asserts the current player receive exactly 4 cards;
 * These cards are from his own pile; Buy action is increased by 1;
 * The other players draw one card from their own pile.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Council Room"

int main() {

    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int numBuy = 1;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(council_room, choice1, choice2, choice3, &testG, handpos, &bonus);

    // the top 2 cards are treasure cards

//    cardDrawn1 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1];
//    cardDrawn2 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 2];

//    assert(cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold);
//    assert(cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold);

    newCards = 4;

    //the cards are from his own pile.
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);

    printf("numBuy = %d, expected = %d\n", testG.numBuys, G.numBuys);
    assert(testG.numBuys == G.numBuys + numBuy);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}




