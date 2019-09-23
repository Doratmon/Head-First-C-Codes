//
// Created by Ethan on 2019/9/20.
//
#include<stdio.h>
#include<string.h>

char tracks[][80] = {
        "I left my heart in Harvard Med School",
        "Newark, Newark - a wonderful town",
        "Dancing with a Dork",
        "From here to maternity",
        "The girl from two Jima"
};

/*
 * strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串。
 * 如果是，则该函数返回 str1字符串从 str2第一次出现的位置开始到 str1结尾的字符串；否则，返回NULL(0)。
 */
void find_track(char search_for[])
{
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(tracks[i],search_for))
            printf("Track %i: '%s'\n", i, tracks[i]);
    }
}

int main()
{
    char search_for[80];
    printf("Search for: ");
    fgets(search_for, sizeof(search_for),stdin);
    search_for[strlen(search_for)-1] = '\0';
    find_track(search_for);
    return 0;
}