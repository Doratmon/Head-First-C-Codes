//
// Created by ethan on 2019/10/5.
//
#include <stdio.h>

typedef union {
    float lemon;
    int limit_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

int main()
{
    margarita m = {2.0, 1.0, {.limit_pieces=1}};
    printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n",
            m.tequila, m.cointreau, m.citrus.limit_pieces);

    return 0;
}