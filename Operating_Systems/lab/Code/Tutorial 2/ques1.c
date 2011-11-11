#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<math.h>
int main()
{
	pid_t pid,pid2;
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);
	//double test = 1.39;
	//double sqr_test = sqrt(test);
	FILE *fopen(), *fp,*fp2; 
	int n1 = (int) (n/2);
	int n2 = (int) (n);
	pid = fork();
	if(pid==0) /*child process */
	{
		int nWritten,i;		
		fp = fopen("factors.dat","w");
		for(i = n1+1;i<n;i++)
		{
			if(n%i==0)
			{
				nWritten = fwrite(&i, sizeof(int), 1, fp);
			}
		}
		fclose(fp);
		printf("Child 1 exited.\n");	
		
	}
	else if(pid>0) /*parent process */
	{
		pid2 = fork();
		if(pid2==0)	/*child process*/
		{
			int nWritten,i;		
			fp2 = fopen("factors2.dat","w");
			for(i = 2;i<=n1;i++)
			{
				if(n%i==0)
				{
					nWritten = fwrite(&i, sizeof(int), 1, fp2);
					
				}	
			}
			printf("Child 2 exited.\n");
		}
		else if(pid2>0) /*parent process*/
		{	
				
			
			int nRead,factor;		
			fp2 = fopen("factors2.dat","r");
			while(nRead = fread(&factor, sizeof(int), 1, fp2))
			{
				printf("%d\n",factor);
			}
			fclose(fp2);	
			fp = fopen("factors.dat","r");
			while(nRead = fread(&factor, sizeof(int), 1, fp))
			{
				printf("%d\n",factor);
			}
			fclose(fp);
			wait(NULL);
			printf("parent exited.\n");		
		}
	}
	

}
	
