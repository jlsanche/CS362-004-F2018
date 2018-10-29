#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//test to check if game is over

int main(int argc, char const *argv[])
{
	struct gameState G;
	int numPlayer = 2;
	int x, y;
	int k[10] = { smithy, adventurer, embargo, steward, sea_hag, minion, outpost, salvager, mine, gardens };
	
	int result = 0;
	int expected = 0;


   x = initializeGame(numPlayer, k, 1000, &G);

    printf("\n");
	printf("Unit test 4: Test isGameOver\n ");

	// test game that is not over
	printf("Test if game not over\n ");
	result = isGameOver(&G);
	expected = 0;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// test game that is over
	printf("\nTest if game is over: case 1\n ");

	// initialize game
	x = initializeGame(numPlayer, k, 1000, &G);

	//if stack of Province cards is empty, the game ends
	G.supplyCount[province] = 0;

	result = isGameOver(&G);
	expected = 1;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);


	// test game over
	printf("\nTest if game over: case 2\n ");

	// initialize game
	x = initializeGame(numPlayer, k, 1000, &G);

	//if the three supply piles are at 0, the game ends
	G.supplyCount[0] = 0;
	G.supplyCount[5] = 0;
	G.supplyCount[15] = 0;

	result = isGameOver(&G);
	expected = 1;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	printf("\nTest Successfuly Completed\n");
    printf("\n");


	return 0;
}