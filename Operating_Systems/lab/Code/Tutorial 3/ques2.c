#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 4

int q1[MAX*2];
int q2[MAX];
int x;
int y;

int len_q2 = MAX;
int len_q1 = MAX;
main()
{
	int i,j,flag,rem = 1;	
	printf("Enter the priorities of the %d running processes : ",MAX);
	for(i=0;i<MAX;i++)
		scanf("%d",&q1[i]);
	printf("Enter the priorities of the %d dormant processes : ",MAX);
	for(i=0;i<MAX;i++)
		scanf("%d",&q2[i]);
	printf("Enter the priority increase rate(x y) : ");
	scanf("%d%d",&x,&y);
	while(len_q2>0)
	{	
		sleep(1);
		for(i=0;i<len_q2;i++)
			q2[i] = q2[i] + x;
		for(i=0;i<len_q1;i++)
			q1[i] = q1[i] + y;
		
		for(i=0;i<len_q2;i++)
		{
			flag = 0;			
			for(j=0;j<len_q1;j++)
			{	
				if(q2[i]>=q1[j])
				{ flag = 1;break;}
			}
			if(flag)
			{
				q1[len_q1] = q2[i];
				len_q1++;
				len_q2--;
				for(j=i;j<len_q2;j++)
					q2[j] = q2[j+1];
				i = i -1;
			}
		}
		
		printf("\nStatus after the %d Quantum Cycle(s) :\n",rem);
		printf("Ready Queue : \t");		
		for(i=0;i<len_q1;i++)
			printf("%d\t",q1[i]);
		printf("\nWaiting Queue : ");
		for(i=0;i<len_q2;i++)
			printf("%d\t",q2[i]);
		printf("\n");		
		rem++;
		
	}
		
	
}

