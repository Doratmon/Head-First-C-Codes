//
// Created by Ethan on 2019/10/27.
//
#include <stdarg.h>//处理可变参数函数的代码都在stdarg.h中，务必包含
#include <stdio.h>

enum drink{
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d)
{
    switch (d)
    {
        case MUDSLIDE:
            return 6.79;
        case  FUZZY_NAVEL:
            return 5.31;
        case MONKEY_GLAND:
            return 4.82;
        case  ZOMBIE:
            return 5.89;
    }
    return 0;
}
/*void print_ints(int args, ...)//...表示后面还有更多参数
{
    va_list ap;//va_list用来保存传递给函数的其他参数
    va_start(ap, args);//说明参数从哪儿开始，传递最后一个普通参数，这个例子中为args
    int i;
    for (i = 0; i < args; i++)
    {
        printf("argument: %i\n", va_arg(ap, int));//va_arg读取保存在va_list中的参数，传入va_list与参数类型
    }
    va_end(ap);//销毁va_list
}*/
double total(int args, ...)
{
    double total = 0.0;
    va_list ap;
    va_start(ap, args);
    int i;
    for (i = 0; i < args; i++){
        enum drink d = va_arg(ap, enum drink);
        total += price(d);
    }
    va_end(ap);
    return total;
}
int main()
{
    printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("Price is %.2f\n", total(1, ZOMBIE));
    return 0;
}
