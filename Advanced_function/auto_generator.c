//
// Created by Ethan on 2019/10/27.
//
#include <stdio.h>
typedef enum response_type {DUMP, SECOND_CHANCE, MARRIAGE}response_type;
typedef struct {
    char* name;
    response_type type;
}response;

void dump(response r)
{
    printf("Dear %s,\n",r.name);
    puts("Unfortunately,your last date contacted us to");
    puts("say that they will not be seeing you again");
}

void second_chance(response r)
{
    printf("Dear %s,\n",r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}

void marriage(response r)
{
    printf("Dear %s,\n",r.name);
    puts("Congratulations! your last date has contacted");
    puts("us with a proposal of marriage");
}
/*
 * 函数指针数组
 */
void (*replies[])(response) = {dump, second_chance, marriage};

int main() {
    response r[] = {
            {"Mike",    DUMP},
            {"Luis",    SECOND_CHANCE},
            {"Matt",    SECOND_CHANCE},
            {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; i++) {
//        switch (r[i].type) {
//            case DUMP:
//                dump(r[i]);
//                break;
//            case SECOND_CHANCE:
//                second_chance(r[i]);
//                break;
//            default:
//                marriage(r[i]);
//                break;
//    }
        (replies[r[i].type])(r[i]);//r[i].type对应DUMP, SECOND_CHANCE, MARRIAGE，分别对应0，1，2ha
    }
    return 0;
}

