#include<stdio.h>

#define N 6

int teams[2][N/2];

void displaySchedule();
void rotate();

int main()
{
	int i,a = 1,j,skip,count,day=1;

	//initialize the teams randomly	
	srand(time(0));
	int start = (rand()%N) + 1;	
	for(i=0;i<N;i++)
		*(teams[0] + i) = ((start+i) % N) + 1;
	
	for(count=1;count<N;count++,day = day+3)
	{
		printf("\nSchedule for the day %d \n",day);
		displaySchedule();
		rotate();
	}		
}

void displaySchedule()
{
	int i;
	for(i=0;i<N/2;i++)
		printf("Team %d vs. Team %d \n",teams[0][i],teams[1][i]);
}

void rotate()
{
	int i,tmp = *(teams[0]+1) ;
	for(i=1;i<N-1;i++)
		*(teams[0]+i) = *(teams[0]+i+1);
	*(teams[0] + (N-1)) = tmp;
}