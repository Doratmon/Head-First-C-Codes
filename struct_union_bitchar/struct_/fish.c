//
// Created by Ethan on 2019/9/28.
//
#include<stdio.h>
struct exercise {
    const char *description;
    float duration;
};

struct meal {
    const char * ingredients;
    float weight;
};

struct preferences {
    struct meal food;
    struct exercise exercises;
};

struct fish {
    const char *name;
    const char *species;
    int teeth;
    int age;
    struct preferences care;
};

void label(struct fish snappy);
int main()
{
    struct fish snappy = {"snappy", "Pizaha",69,4,{{"meat",0.2},{"swim in the jacuzzi",7.5}}};
    label(snappy);
    return 0;
}
void label(struct fish snappy)
{
    printf("Name:%s Species:%s Teeth:%d Age:%d\n",
            snappy.name, snappy.species, snappy.teeth, snappy.age);
    printf("Feed with %2.2f 1bs of %s and allow to %s for %2.2f hours\n",
            snappy.care.food.weight, snappy.care.food.ingredients, snappy.care.exercises.description, snappy.care.exercises.duration);
}