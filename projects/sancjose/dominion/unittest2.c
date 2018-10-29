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
    int k[10] = {smithy, adventurer, embargo, steward, sea_hag, minion, outpost, salvager, mine, gardens};
	int result = 0;
	int expected = 0;

	// initialize game
    x = initializeGame(numPlayer, k, 1000, &G);

    printf("\n");
    printf("Unit test 2: Test numHandCard\n ");

	// test if number of buys greater than 1
	printf("\nTest number of cards in hand\n");
	result = numHandCards(&G);
	expected = 5;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// test add card
	drawCard(G.whoseTurn, &G);

	printf("\nTest add card\n");
	result = numHandCards(&G);
	expected = 6;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// test discard card

	discardCard(0,G.whoseTurn, &G,0);

	printf("\nTest discard card\n");
	result = numHandCards(&G);
	expected = 5;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

    printf("\nTest Successfuly Completed\n");
    printf("\n");


    return 0;
}
