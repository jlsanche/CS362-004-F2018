#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TESTCARD "council_room"

//source cited: using template from cardtest4.c on canvas

int main(int argc, char const *argv[])
{

    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;
    int numBuys = 1;

    int i, j, m;
    int handpos = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, outpost, smithy, council_room};

           

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

    printf("card test 1: %s\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

    printf("here\n");

	cardEffect(council_room, 0, 0, 0, &testG, handpos, &bonus);


    newCards = 4;

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("buys = %d, expected = %d\n", testG.numBuys, G.numBuys + numBuys);

	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(testG.numBuys == G.numBuys + numBuys);
    

    printf("\n >>>>> SUCCESS: Testing complete for %s card <<<<<\n\n", TESTCARD);

    return 0;
}

