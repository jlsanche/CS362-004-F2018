


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//source cited: using template from cardtest4.c on canvas

#define TESTCARD "gardens"

int main() {
    int newCards = 0;
    int discarded = 1;
    int shuffledCards = 0;

    int handpos = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);


	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(gardens, 0, 0, 0, &testG, handpos, &bonus);

	printf("supply count =%d, expected =%d\n", testG.supplyCount[thisPlayer], G.supplyCount[thisPlayer] < 0 );
	assert(testG.supplyCount[thisPlayer] == G.supplyCount[thisPlayer]);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}

