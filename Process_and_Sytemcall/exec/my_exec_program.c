#include<unistd.h>
int main()
{
	char* my_env[] = {"JUICE=peach and apple", NULL};
	execle("dinner_info", "dinner_info", "4", NULL, my_env);
	return 0;
}
