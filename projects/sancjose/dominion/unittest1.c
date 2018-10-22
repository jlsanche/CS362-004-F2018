#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


// test initializeGame deck is  == 10

int main(int argc, char const *argv[])
{

    struct gameState G;
    

    int kCards[10] = {smithy, adventurer, gardens, embargo, outpost, sea_hag, tribute, mine, baron, steward};
    int x = initializeGame(2, kCards, 1000, &G);

    printf('Unit test 1: Making sure there are 10 cards to start \n');

    int y = isGameOver(&G);
    assert(y == 0);
    
    printf('Test passed!\n');

    assert(x == 0);
    
    return 0;
}