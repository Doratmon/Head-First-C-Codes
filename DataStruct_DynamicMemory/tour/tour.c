//
// Created by ethan on 2019/10/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

void display(island *start)
{
    island *i = start;
    for( ; i != NULL; i = i->next)
    {
        printf("Name: %s \nopen: %s-%s\n\n",i->name, i->opens, i->closes);
    }

}

island* create(char *name)
{
    island *i = malloc(sizeof(island));
    i->name = strdup(name);//strdup()在堆空间分配内存
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void release(island *start)//释放分配在堆空间的内存
{
    island *i = start;
    island *next = NULL;
    for(; i != NULL; i = next)
    {
        next = i->next;
        free(i->name);//岛屿的名字分配在堆空间 所以需要释放
        free(i);
    }

}
int main()
{
    char name[80];
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    for(; fgets(name, sizeof(name),stdin)!= NULL; i=next)
    {
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }
    display(start);
    release(start);

    return 0;
}
