#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <sys/wait.h>
using namespace std;

void computeLowerFactor(int );
void computeHigherFactor(int );
vector<int> factors1;
vector<int> factors2;
int main()
{
	
	int n;
	cout << "\nEnter a positive no. :";
	cin >> n;
	
	int pid1;
	pid1 = fork();
	if(pid1==0)
	{
	//	cout << "Child 1" << endl;
		computeLowerFactor(n);
	}
	else
	{
		int pid2;
		pid2 = fork();

		if(pid2 == 0)
		{
		//	cout << "pid2: " << pid2 << endl;
		//	cout << "Child 2" << endl;
			computeHigherFactor(n);
		}
		else 
		{
			wait(NULL);
			wait(NULL);
			cout << n;
		/*	ostream_iterator<int> output(cout," ");
			copy(factors1.begin(), factors1.end(), output);
			cout << factors1.size();*/
			cout << "Parent Process" << endl;
		}
	}
	return 0;
}

void computeLowerFactor(int n)
{
	int limit = sqrt(n/2);
	for(int i = 2 ; i <= limit ; i++)
	{
		if((n%i) == 0)
		{
			factors1.push_back(i);
			cout << i << " ";
			if((n/i) != i)
			{
				factors1.push_back(n/i);
			    cout << (n/i) << " ";	
			}
		}
	}
	return;
}

void computeHigherFactor(int n)
{
	int limit = sqrt(n);
	for(int i = (sqrt(n/2)+1) ; i <= limit ; i ++)
	{
		if((n%i) == 0)
		{
			factors2.push_back(i);
			cout << i << " ";
			if((n/i) != i)
			{
				factors2.push_back(n/i);
				cout << (n/i) << " ";	
			}
		}
	}
	return;
}
