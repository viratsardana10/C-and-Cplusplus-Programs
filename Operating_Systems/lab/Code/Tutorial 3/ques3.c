#include<stdio.h>

#define N 5
#define M 5

int process[N][M];
int num = N;
main()
{
	int i,j,k;
	printf("Indicate(0/1) the resources held by %d processes with priority in the that order.\n",N);
	for(i = 0;i<num;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d",&process[i][j]);
	}
	printf("\nInitializing resource allocation and process execution.\n");
	i = 0;	
	while(num>0)
	{
		sleep(3);		
		printf("Executing process with priority : %d\n",i+1);
		for(j=0;j<M;j++)
		{
			if(process[i][j]==1)			
			{
				for(k=i+1;k<N;k++)
				{
					if(process[k][j]==1)
					{
						printf("Execution of the process with priority %d halted.\n",i+1);
						printf("Promoting the process with priority %d to priority to release the resource %d.\n",k+1,j+1);
						printf("Executing process with priority : %d\n",k+1);
						process[k][j]=0;
						printf("Restoring the process with priority %d to its original priority.\n",k+1,j+1);
						printf("Resuming execution of the process with priority : %d\n",i+1);
					}
				}
			}
		}
		printf("Execution Complete for the process with priority : %d\n\n\n",i+1);
		num--;
		i++;
	
	}
}
		
						
		
				
		
