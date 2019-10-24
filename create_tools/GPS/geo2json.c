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
    float longitude;
    char info[80];
    int started = 0;

    puts("{\"data\":[");
    while(scanf("%f, %f, %79[^\n]",&latitude ,&longitude ,info) == 3) {//scanf()返回成功读取数据条数
        if (started)
            printf(",\n");
        else
            started = 1;
        if((latitude < -90.0) || (latitude > 90.0)) { //如果输入的纬度无效，将输出发送到标准错误
            fprintf(stderr, "Invalid latitude %f\n", latitude);
            return 2;
        }
        if((longitude < -180.0) || (longitude > 180.0)) { //如果输入的经度无效，将输出发送到标准错误
            fprintf(stderr, "Invalid longitude %f\n", longitude);
            return 2;
        }
        printf("{\"latitude\": %f, \"longitude\": %f, \"info\": \"%s\"}",latitude ,longitude ,info );
    }
    puts("]\n}");
    return 0;
}
