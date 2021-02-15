#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	printf("Dinners: %s\n", argv[1]);
	printf("Juice: %s addr=%p\n", getenv("JUICE"),getenv("JUICE"));
	return 0;
}