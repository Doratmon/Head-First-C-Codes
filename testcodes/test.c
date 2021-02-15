#include <stdio.h>
#include <fcntl.h>
#include <time.h>
void func()
{
    static int x = 20;
    x++;
    printf("[func]:&x=%#0x\n",&x);
    printf("[func]:%d\n",x);
}
int main()
{
    static int x = 40;
    func();
    printf("[main]:%d\n",x);
    printf("[main]:&x=%#0x\n",&x);
    return 0;
}