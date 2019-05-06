//
// Created by Tianshu Ren on 5/5/19.
//

/*
 * cardtest1.c
 * This test is to test the card effect of Adventurer. It asserts the current player receive exactly 2 Treasure cards;
 * These cards are from his own pile; There is no state change to other players; No state change to victory card piles and kingdom card piles.
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "Adventurer"

int main() {

    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int cardDrawn1;
    int cardDrawn2;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 0;
    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    // the top 2 cards are treasure cards

    cardDrawn1 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 1];
    cardDrawn2 = testG.hand[thisPlayer][testG.handCount[thisPlayer] - 2];

    assert(cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold);
    assert(cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold);

    newCards = 2;
    xtraCoins = 0;

    //the cards are from his own pile.

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
    assert(testG.coins == G.coins + xtraCoins);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}





