//
// Created by ethan on 2019/10/24.
//
//以函数作为参数进行传递
#include <stdio.h>
#include <string.h> //strstr()函数
int NUM_ADS = 7;
char *ADS[] = {
        "William: SBM GSON likes sports, TV, dining",
        "Matt: SWM NS likes art, movies, theater",
        "Luis: SLM ND likes books, theater, art",
        "Mike: DWM DS likes trucks, sports and bieber",
        "Peter: SAM likes chess, working out and art",
        "Josh: SJM likes sports, movies and theater",
        "Jed: DBM likes theater, books and dining"
};

int sports_no_bieber(char *s)
{
    return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s)
{
    return strstr(s,"sports") || strstr(s, "workout");
}

int ns_theater(char *s)
{
    return strstr(s, "NS") && strstr(s, "theater");
}

int arts_theater_or_dining(char *s)
{
    return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
}

void find(int (*match)(char*))
{
    int i;
    puts("Search results:");
    puts("---------------------");

    for(i = 0; i < NUM_ADS; i++ ) {
        if (match(ADS[i]))
            printf("%s\n", ADS[i]);
    }
    puts("---------------------");
}

int main()
{
    find(sports_no_bieber);
    find(sports_or_workout);
    find(ns_theater);
    find(arts_theater_or_dining);
    return 0;
}
/*
 * 1. 创建函数的同时也创建了一个同名函数指针，指针中保存了函数的地址
 * 2. 当调用函数时，其实也是在使用函数指针，但是函数指针是一个指针常量，不能自增自减
 * 3. char **s 与 char *s[] https://www.cnblogs.com/zhangyachen/p/8035577.html
 * 4.             int(*match)(char*)------>函数指针
 *                 |     |     |
 *     返回类型—————— （*指针变量) ————————————(参数类型)
 */