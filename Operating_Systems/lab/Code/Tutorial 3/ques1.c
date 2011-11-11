#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t opr_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;

int avail[1000];
int draw[1000];
int avail_len = 1000;
int draw_len = 0;
int lucky_num = 0;
void *initProcess();
void *scheduler();
void removeElement(int *,int);
void addElement(int *,int);


main()
{
	pthread_t thread_id;
	int i,j;
	for(i=0;i<avail_len;i++)
	{
		avail[i] = i;
		draw[i] = 0;
	}	
	pthread_create(&thread_id,NULL,scheduler,NULL);
	for(;;)
	{
		//srand(time(0));		
		sleep((rand()%2)+3); 
		pthread_create(&thread_id,NULL,initProcess,NULL);
	}
}

void *scheduler()
{
	for(;;)
	{
		sleep(10);		
		pthread_mutex_lock(&condition_mutex);
		printf("\n\n \t\t\t Scheduler Interrupts : ");
		if(draw_len==0)
			printf("No process running.\n");
		else
		{
			srand(time(0));	
			pthread_mutex_lock(&opr_mutex);		
			int lucky_idx = (rand()%draw_len) ;
			lucky_num = draw[lucky_idx];
			pthread_mutex_unlock(&opr_mutex);
			printf("Lucky Draw Number : %d\n",lucky_num);
			pthread_mutex_unlock(&condition_mutex);			
			pthread_cond_broadcast(&condition_cond);
		}
		pthread_mutex_unlock(&condition_mutex);
	}
}			




void *initProcess()
{
	int idx,i,j;	
	srand(time(0));
	int pid = rand()%2000;
	int num = rand()%5 + 1;
	int *tickets = malloc(num * sizeof(int));
	if(tickets==NULL)
	{	
		printf("Allocation Error\n");
		exit(1);
	}
	pthread_mutex_lock(&opr_mutex);		
	for(i=0;i<num;i++)
	{
		srand(time(0));		
		idx = rand()%avail_len;
		tickets[i] = idx;
		removeElement(avail,idx);
		addElement(draw,idx);
	}
	pthread_mutex_unlock(&opr_mutex);				
	printf("\n\nNew process has been created. PID : %d  \t No. of lottery tickets allotted : %d\n",pid,num);
	printf("Lottery Tickets' Nos. : ");	
	for(i=0;i<num;i++) 
		printf("%d   ",tickets[i]); 
	
	//wait process	
	for(;;)
	{	
			
		if(lucky_num==0)
		{
			//printf("\n\n\t\t\tProcess PID : %d is waiting.",pid);
			pthread_cond_wait(&condition_cond,&condition_mutex);
		}
		else
		{
			for(i=0;i<num;i++)
				if(tickets[i]==lucky_num)
				{
					//terminate process
					pthread_mutex_unlock(&condition_mutex);					
											
					printf("\n\n\t\t\tProcess PID : %d wins the lucky coupon %d . Completed . \n",pid,lucky_num);					
					pthread_mutex_lock(&opr_mutex);			
					for(j = 0;j<num;j++)
					{
						removeElement(draw,tickets[j]);
						addElement(avail,tickets[j]);
					}	
					pthread_mutex_unlock(&opr_mutex);	
					
					return;			
				}
				
					pthread_mutex_unlock(&condition_mutex);
					pthread_cond_wait(&condition_cond,&condition_mutex);
				
		}
	}

}

		


void removeElement(int *arr,int idx)
{
	
	int i,arr_len,j;	
	if(arr==avail){
		avail_len = avail_len - 1;
		arr_len = avail_len;
	}
	else if(arr == draw){
		draw_len = draw_len - 1;
		arr_len = draw_len;
	}
	else{
		printf("Wrong Argument\n"); return;
	}
	
	for(i=0;i<=arr_len;i++)
		if(arr[i]==idx)
			break;
	for(j=i;j<arr_len;j++)
	{
		arr[j] = arr[j+1];		
	}

}


void addElement(int *arr,int idx)
{
	int i,j,tmp,arr_len;
		
	if(arr==avail){
		avail_len = avail_len + 1;
		arr_len = avail_len;
	}
	else if(arr == draw){
		draw_len = draw_len + 1;
		arr_len = draw_len;
	}
	else{
		printf("Wrong Argument\n"); return;
	}
	
	for(i=0;i<arr_len-1;i++)
		if(arr[i]>idx)
			break;
	for(j=i;j<arr_len-1;j++)
	{
		tmp = arr[j+1];		
		arr[j+1] = arr[j];
	}
	arr[i] = idx;
}
