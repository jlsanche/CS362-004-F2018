#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// test to check if player is finished with their turn

int main(int argc, char const *argv[])
{

    struct gameState G;
    int numPlayer = 2;
    int x, y;
    int k[10] = {smithy, adventurer, embargo, steward, sea_hag, minion, outpost, salvager, mine, gardens};
    x = initializeGame(numPlayer, k, 1000, &G);

    printf("Unit test 1: Check if player is finished with their turn \n ");

    y = isGameOver(&G);
    assert(y == 0);

    printf("\nTest Successfuly Completed\n");

    assert(y == 0);

    return 0;
}