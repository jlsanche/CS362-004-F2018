#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	struct gameState G;
	int numPlayer = 2;
	int x, y;
	int k[10] = { smithy, adventurer, embargo, steward, sea_hag, minion, outpost, salvager, mine, gardens };
	x = initializeGame(numPlayer, k, 1000, &G);
	int result = 0;
	int expected = 0;

    printf("\n");
	printf("Unit test 3: test scoreFor\n ");

	// test scoreFor
	printf("\nTest number of cards in hand\n");
	result = scoreFor(G.whoseTurn,&G);
	expected = 1;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// set cards
	G.hand[G.whoseTurn][0] = steward;
	G.hand[G.whoseTurn][1] = copper;
	G.hand[G.whoseTurn][2] = duchy;
	G.hand[G.whoseTurn][3] = estate;
	G.hand[G.whoseTurn][4] = feast;

	printf("\nTest number of cards in hand\n");
	result = scoreFor(G.whoseTurn, &G);
	expected = 4;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);


	printf("\nTest Successfuly Completed\n");
    printf("\n");


	return 0;
}
