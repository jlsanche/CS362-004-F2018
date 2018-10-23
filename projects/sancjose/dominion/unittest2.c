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
    int k[10] = {smithy, adventurer, embargo, steward, sea_hag, minion, outpost, salvager, mine, gardens};
    x = initializeGame(numPlayer, k, 1000, &G);

    printf("Unit test 2: Check if game is over\n ");

    y = isGameOver(&G);
    assert(y == 1);

    printf("\nTest Successfuly Completed\n");



    return 0;
}
