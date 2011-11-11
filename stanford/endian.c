#include <stdio.h>

int main()
{
	int i = 256 + 2 ;
	char *c = (char*)&i;

	printf("%d , %d \n", *c, *(c++));
	if(*c == 1)
		printf("This machine is of type BIG INDIAN ! \n");
}
