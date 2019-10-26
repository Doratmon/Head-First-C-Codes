//
// Created by Ethan on 2019/10/26.
//
/*
 * void __cdecl qsort(void *_Base,------>一个数组指针
 *                    size_t _NumOfElements,------>数组长度
 *                    size_t _SizeOfElements,------->数组中每个元素的长度
 *                    int (__cdecl *_PtFuncCompare)(const void *,const void *));-->用来比较两数组大小的函数指针
 * qsort是C标准库的排序函数，在头文件stdlib.h中
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare_scores(const void* score_a, const void* score_b)
{
    int a = *(int*)score_a;//首先进行void*指针的转换 然后取得整数值
    int b = *(int*)score_b;
    return a-b;
}
int compare_scores_desc(const void* score_a, const void* score_b)
{
    return -compare_scores(score_a,score_b);
}
/*
 * 难点!!!
 */
int compare_names(const void* a, const void* b)
{
    char **sa = (char**)a;//字符指针数组类型是char**，所以*s才是每一个字符串的首地址
    char **sb = (char**)b;
    return strcmp(*sa,*sb);
}
int main()
{
    int scores[] = {543, 323, 32, 554, 11, 3, 112};
    int i;
    qsort(scores, 7, sizeof(int), compare_scores);
    puts("These are the scores in order:");
    for(i = 0; i < 4; i ++) {
        printf("Score = %i\n", scores[i]);
    }
    char *names[] = {"Karenhellowrooadsnaodonas", "Mark", "Brett", "Molly"};
    qsort(names, 4, sizeof(char*), compare_names);//字符指针数组每一项的大小是sizeof(char*)
    for(i = 0; i < 4; i ++) {
        printf("%s\n", names[i]);
    }
    return 0;
}
