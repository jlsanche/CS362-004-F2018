#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define TESTCARD "village"

//source cited: using template from cardtest4.c on canvas

int main(int argc, char const *argv[])
{

    int newCards = 1;
    int discarded = 1;
    int xtraCoins = 2;
    int numActions = 2;
    int shuffledCards = 0;
    int choice1;


    int handpos = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, outpost, smithy, gardens};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

    printf("card test 3: %s\n", TESTCARD);

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(village, choice1, 0, 0, &testG, handpos, &bonus);

    
	newCards = 0;
	xtraCoins = 2;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	printf("actions = %d, expected = %d\n", testG.numActions, G.numActions);
    printf("supply count =%d, expected =%d\n", testG.supplyCount[thisPlayer], G.supplyCount[thisPlayer] );
    printf("embargo tokens =%d, expected =%d\n", testG.embargoTokens[thisPlayer], G.embargoTokens[thisPlayer] );
    
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	assert(testG.numActions == G.numActions + numActions);
    assert(testG.supplyCount[thisPlayer] == G.supplyCount[thisPlayer]);
    assert(testG.embargoTokens[thisPlayer] == G.embargoTokens[thisPlayer]);
   
    printf("\n >>>>> SUCCESS: Testing complete for %s card <<<<<\n\n", TESTCARD);


    return 0;
}
