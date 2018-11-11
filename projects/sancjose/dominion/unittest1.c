#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//test to check buy card

int main(int argc, char const *argv[])
{
	int result = 0;
	int expected = 0;
	struct gameState G;
	int numPlayer = 2;
	int x, y;
	int k[10] = { smithy, adventurer, embargo, steward, sea_hag, minion, outpost, salvager, mine, village };

	x = initializeGame(numPlayer, k, 1000, &G);
    printf("\n");
	printf("Unit test 1: Test buy Cards\n");

	// test if number of buys greater than 1
	printf("\nTest if number of buys greater than 1\n");
	result = buyCard(smithy, &G);
	expected = 0;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// test if number of cards less than 1
	printf("\nTest if number of buys less than 1\n");
	result = buyCard(smithy, &G);
	expected = -1;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// initialize game
	x = initializeGame(numPlayer, k, 1000, &G);

	// test supply count 
	printf("\nTest supply count greater equal\n");
	result = buyCard(smithy,&G);
	expected = 0;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);

	// initialize game
	 x = initializeGame(numPlayer, k, 1000, &G);

	// test supply count less
	printf("\nTest supply count less \n");
	result = buyCard(village, &G);
	expected = -1;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);


	// Test coins >= getCost(supplyPos) 
	x = initializeGame(numPlayer, k, 1000, &G);
	printf("\nTest coins >= getCost(supplyPos)\n");
	result = buyCard(smithy, &G);
	expected = 0;
	assert(result == expected);
	printf("expected %d == result %d\n", expected, result);
	result = G.coins;
	expected = 0;
	assert(result >= expected);
	printf("result %d >= expected %d\n", result, expected);

	printf("\nTest Successfuly Completed\n");
    printf("\n");


	return 0;
}
