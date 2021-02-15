#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char* now()//获取当前时间
{
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}
int main()
{
	char comment[80];
	char cmd[120];
	fgets(comment,80,stdin);//输入comment
	sprintf(cmd,
		"echo '%s %s' >> reports.log",
		comment,
		now());//构建好命令存到字符串cmd中
	system(cmd);
	return 0;
}