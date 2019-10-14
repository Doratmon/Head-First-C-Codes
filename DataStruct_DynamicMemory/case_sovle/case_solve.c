//
// Created by Ethan on 2019/10/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node { //定义一个二叉树
    char *question;
    struct node *no;
    struct node *yes;
} node;

int yes_no(char *question)//判断回答是否为yes
{
    char answer[3];
    printf("%s? (y/n):", question);
    fgets(answer, sizeof(answer), stdin);
    /*
    if(answer[0] == 'y')
        return 1;
    else
        return 0;
    */
    return answer[0] == 'y';//这个写法可以借鉴,比上面写法好
}

node* create(char *question)//创建一棵二叉树
{
    node *n = malloc(sizeof(node));
    n->question = strdup(question);//注意此处是分配到堆中
    n->no = NULL;
    n->yes = NULL;
    return n;
}

void release(node *n)//释放内存空间
{
    if (n) {
        if (n->no)
            release(n->no);
        if (n->yes)
            release(n->yes);
        if (n->question);
            free(n->question);
            free(n);//三个指针变量占了24个字节存储空间（64位系统）
    }
}

int main()
{
    char question[80];
    char suspect[20];
    node *start_node = create("Does suspect have a mustache");
    start_node->yes = create("Vinny the Spoon");
    start_node->no = create("Loretta Barnsworth");
    /*
     *          Does suspect have a mustache
     *                        |
     *              |———————————————————|
     * Vinny the Spoon              Loretta Barnsworth
     */

    node *current;
    do {
        current = start_node;
        while (1) {
            if (yes_no(current->question)) {
                if (current->yes) {
                    current = current->yes;
                } else {
                    printf("SUSPECT IDENTIFIED\n");
                    break;
                }
            } else if (current->no) {
                current = current->no;
            } else {
                /*Make the yes-node the new suspect name*/
                printf("Who's the suspect? ");
                fgets(suspect, 20, stdin);
                node *yes_node = create(suspect);//创建新的嫌疑人 假设为Tom
                current->yes = yes_node;

                /*Make the no-node a copy of this question*/
                node *no_node = create(current->question);//当前犯罪嫌疑人 Vinny the Spoon
                current->no = no_node;

                /*假设判定到Vinny the Spoon后，这个人不是嫌疑人
                 *                         Does suspect have a mustache
                 *                                      |
                 *                             |———————————————————|
                 *                   Vinny the Spoon              Loretta Barnsworth
                 *                        |
                 *               |———————————————————|
                 *              Tom             Vinny the Spoon
                 *
                 */

                /*Then replace this question with the new question*/
                printf("Give me a question that is TRUE for %s but not for %s? ",
                       suspect, current->question);
                fgets(question, 80, stdin);
                free(current->question);
                current->question = strdup(question);//新的犯罪嫌疑人特征(假设为long hair) ！！！此时并未free()之前的question
                /*
                 *                  Vinny the Spoon------> long hair
                 *                        |
                 *               |———————————————————|
                 *              Tom             Vinny the Spoon
                 */
                break;
            }
        }
    } while(yes_no("Run again"));
    release(start_node);
    return 0;
}