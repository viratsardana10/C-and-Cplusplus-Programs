/*
 * Precedence.c
 *
 *  Created on: 11-Sep-2010
 *      Author: vivek
 */

#include <stdio.h>

int main()
{
/*	struct {
		int len;
		char* str;
	} *p;

	p->len = 5 ;
	p->str = "ABCD";

	printf("%d, %d, %d, %d\n", ++p->len, ++p->len, ++(p->len), (++p)->len);
	printf("Hello.\n");
*/
	int a[10];
	int i = 0;
	for(; i < 10 ; ++i)
		a[i]=2*i;
	
	int *ptr = a;
	++*ptr;
	*ptr++;
	printf("%d \n", *ptr++);
	
	return 0;
}
