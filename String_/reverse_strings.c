//
// Created by Ethan on 2019/9/23.
//
/*
 * 逆转字符串
 */
#include<stdio.h>
#include<string.h>
void print_reverse(char s[])
{
    size_t len = strlen(s);//计算字符串长度
    char *t = s + len -1; //指针t指向字符串s最后一个字符
    while (t >= s) {
        printf("%c",*t);
        t = t - 1;
    }

}
int main()
{
    char s0[] = "Hello World";
    print_reverse(s0);
    return 0;
}
