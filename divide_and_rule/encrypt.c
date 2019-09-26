//
// Created by Ethan on 2019/9/25.
//
#include "encrypt.h"

void encrypt(char *message)
{
    char c;
    while (*message) {
        *message = *message ^ 31;
        message++;
    }
}