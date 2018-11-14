#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define TESTCARD "gardens"

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int j, m;
    int handpos = 0, bonus = 0;
    int seed = (rand() % 1000) + 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int n, i, p;

    struct gameState G, testG;

    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, outpost, smithy, gardens};

    SelectStream(2);
    PutSeed(3);

    printf("random test for card 1: %s\n", TESTCARD);

    for (n = 0; n < 2000; n++)
    {
        for (i = 0; i < sizeof(struct gameState); i++)
        {
            ((char *)&G)[i] = floor(Random() * 256);
        }

        initializeGame(numPlayers, k, seed, &G);

        thisPlayer = floor(Random() * 2);
        G.deckCount[thisPlayer] = floor(Random() * MAX_DECK);
        G.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
        G.handCount[thisPlayer] = floor(Random() * MAX_HAND);
        G.coins = floor(Random() * 7);

        testG.deckCount[thisPlayer] = floor(Random() * MAX_DECK);
        testG.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
        testG.handCount[thisPlayer] = floor(Random() * MAX_HAND);
        testG.coins = floor(Random() * 7);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        cardEffect(gardens, 0, 0, 0, &testG, handpos, &bonus);

        printf("supply count =%d, expected =%d\n", testG.supplyCount[thisPlayer], G.supplyCount[thisPlayer] < 0);
        assert(testG.supplyCount[thisPlayer] == G.supplyCount[thisPlayer]);

        printf("\n >>>>> SUCCESS: Testing complete for %s card <<<<<\n\n", TESTCARD);
    }

    exit(0);

    return 0;
}
