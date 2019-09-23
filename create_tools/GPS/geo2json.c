//
// Created by Ethan on 2019/9/23.
//
/*
 * 格式化经纬度
 */
#include<stdio.h>

int main()
{
    float latitude;
    float longtitude;
    char info[80];
    int started = 0;

    puts("data=[");
    while(scanf("%f, %f, %79[^\n]",&latitude ,&longtitude ,info) == 3) {
        if (started)
            printf("\n");
        else
            started = 1;
        printf("{latitude: %f, longtitude: %f, info: '%s'}",latitude ,longtitude ,info );
    }
    puts("\n]");
    return 0;
}
