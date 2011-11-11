#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	ofstream outfile("input");
	srand((unsigned) time(NULL));
	
	for(int i = 0; i < 100 ; i++)
	{
		for(int j = 0 ; j < 100 ; j++ )
		{
			outfile << rand()%10 << " ";
		}
		outfile << "\n";
	}
	return 0;
}
