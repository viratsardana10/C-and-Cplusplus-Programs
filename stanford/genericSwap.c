#include <stdio.h>
void swap(void *, void * ,int );

int main()
{
	int x = 7;
	int y= 117;
	swap(&x, &y, sizeof(int));
	printf("x: %d , y:%d \n",x,y);

	char *husband = strdup("Fred");
	char *wife = strdup("Wilma");
	swap(&husband, &wife, sizeof(char*));
	printf("husband: %s , wife: %s \n",husband,wife);

	char *c1 = "abc";
	char *c2 = "dsd";
	printf("%0x , %0x\n",c1,c2);
	printf("%0x , %0x\n",*c1,*c2);

	swap(&c1,&c2,sizeof(char*));
	printf("c1: %s , c2: %s \n",c1, c2);

	printf("%0x , %0x\n",c1,c2);
	printf("%0x , %0x\n",*c1,*c2);


}

void swap(void* vp1, void* vp2, int size)
{
	char buffer[size];
	memcpy(buffer,vp1,size);
	memcpy(vp1,vp2,size);
	memcpy(vp2,buffer,size);
}
