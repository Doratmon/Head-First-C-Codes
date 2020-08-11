//
// Created by Ethan on 2019/9/25.
//
#include<stdio.h>
#include "encrypt.h"

int main()
{
    char msg[80];
    //fgets()输入字符数少于79时，会读入'\n'
    while (fgets(msg, 80, stdin)) {
        encrypt(msg);
        printf("%s\n", msg);
    }

    return 0;
}