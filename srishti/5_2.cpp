#include <iostream>
#include <math.h>
using namespace std;
 
long cal_num_divisor(int number);
 
int main()
{
	int num_divisor=2;  // 1 and itself
	int i = 1, number = 1;
	while (num_divisor<=300)
	{
		i++;
		number += i;
		num_divisor = cal_num_divisor(number);
	}
	cout<<number<<endl;
	return 0;
}
 
long cal_num_divisor(int number)
{
	int num_divisor=2;  // 1 and itself
	for (int ix=2; ix<=sqrt(number); ix++)
	{
		if (number%ix==0)
		{
			num_divisor++;
		}
	}
	return num_divisor*2;
 
}
