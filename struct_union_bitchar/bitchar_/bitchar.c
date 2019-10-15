//
// Created by ethan on 2019/10/5.
//
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 水族馆问卷调查
 */
typedef struct {
    unsigned int first_visit:1;//是否第一次参观
    unsigned int come_again:1;//还会再来吗
    unsigned int fingers_lost:4;//被食人鱼咬掉了几根手指
    unsigned int shark_attack:1;//鲨鱼是否攻击人
    unsigned int days_a_week:3;//一周来几次
} survey;

int main()
{
    survey s;
    printf("%d", sizeof(survey));
    //printf("hello world");

    return 0;
}
