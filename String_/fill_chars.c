//
// Created by Ethan on 2019/9/23.
//
/*
 * 填字游戏
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
    puts("");

}

int main()
{
    char *juices[] = {
            "dragonfruit", "waterberry", "sharonfruit", "uglifruit",
            "rumberry", "kiwifruit", "mulberry", "strawberry",
            "blueberry", "blackberry", "starfruit"
    };
    char *a;
    puts(juices[6]);//1
    print_reverse(juices[7]);//2
    a = juices[2];
    /*
     * 为什么能修改数组的元素值？
     * 先有一个数组 所以字符串会在栈中拷贝副本 因此指针指向的是栈中字符串
     */
    juices[2] = juices[8];
    juices[8] = a;
    puts(juices[8]);//3
    print_reverse(juices[(18+7) / 5]);
    puts(juices[2]);
    print_reverse(juices[9]);
    juices[1] = juices[3];
    puts(juices[10]);
    print_reverse(juices[1]);
    return 0;
}