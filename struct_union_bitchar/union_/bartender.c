//
// Created by ethan on 2019/10/5.
//
#include <stdio.h>

typedef union {//定义一个联合 lemon变量与limit_pieces变量共用4个字节存储空间
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
//    margarita m = {2.0, 1.0, .citrus.limit_pieces=1}; //指定初始化器
    printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n",
            m.tequila, m.cointreau, m.citrus.limit_pieces);

    return 0;
}