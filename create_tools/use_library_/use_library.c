//
// Created by Ethan on 2019/9/23.
//
#include<stdio.h>
#include<unistd.h>
/*
 *  getopt(int nargc,char* const* nargv,const char* options)
 *  解释：当使用命令行编程时，参数过多就难以辨认出每个选项得意思，getopt可用于指定参数
 *      nargc与nargv分别对应main(int argc,char *argv[])
 *      options对应选项 例如ab:c::
 *                  单个字符a         表示选项a没有参数            格式：-a即可，不加参数
 *                  单字符加冒号b:     表示选项b有且必须加参数       格式：-b 100或-b100,但-b=100错
 *                  单字符加2冒号c::   表示选项c可以有，也可以无     格式：-c200，其它格式错误
 *  几个变量说明：
 *  1.optind-》下一个选项的索引
 *  2.optarg指向下一个选项的第一个参数
 *  3.opterr 如果不希望getopt()印出错信息，则只要将全域变量opterr设为0即可
 *  4.optopt 如果找到不符合规定的参数 optopt设为?
 *
 *
 *  注：
 *      getopt()会将参数重新排序 还是对于ab:c::
 *      例如 ./test -a apple -b banana -cstrawberry
 *              =》./test -a -b banana -cstrawberry apple (因为a不能指定参数 -c参数为strawberry)
 */
int main(int argc, char *argv[])
{
    char *delivery = "";
    int thick = 0;
    int count = 0;
    char ch;
    while((ch = getopt(argc, argv, "d:t")) != EOF){
//        printf("opt = %c\t\t", ch);
//        printf("optarg = %s\t\t",optarg);
//        printf("optind = %d\t\t",optind);
//        printf("argv[optind] = %s\n",argv[optind]);
        switch (ch) {
            case 'd':
                delivery = optarg;
                break;
            case 't':
                thick = 1;
                break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
        }
    }

    /*
     * 下面两行为跳过有效选项与参数
     */
    //printf("optind=%d\n",optind);
    argc -= optind;
    //printf("before:%s\n",*argv);
    argv += optind;
    //printf("after:%s\n",*argv);
    //printf("argv->'%s'\n",argv)

    if(thick)
        puts("Thick crust.");

    if(delivery[0])
        printf("To be delivered %s.\n", delivery);

    puts("Ingredients:");

    for(count = 0; count < argc; count ++)
        puts(argv[count]);
    return 0;
}

