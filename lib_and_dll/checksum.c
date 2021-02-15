#include "checksum.h"
int checksum(char *message)
{
    int c = 0;
    while (*message) {
        c += c ^ (int)(*message); //根据字符串的内容求一个校验和
        message++;
     }
    return c;
}