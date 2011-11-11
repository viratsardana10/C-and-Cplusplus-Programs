#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	ifstream infile("input");
	ofstream outfile("output_column_major");

	int a[100][100];

	for(int i = 0; i < 100 ; i++)
	{
		for(int j = 0 ; j < 100 ; j++ )
		{
			infile >> a[i][j];
		}
	}

	long c[100][100];
	long init = clock();
	for(int j = 0; j < 100 ; j++)
	{
		for(int i = 0 ; i < 100 ; i++)
		{
			c[i][j] = 0;
			for(int k = 0 ; k < 100 ; k++)
				c[i][j] += a[i][k]*a[k][j];

			outfile << c[i][j]%10;
		}
		outfile << "\n";
	}
	long final = clock();
	cout << (double)(final-init)/1000;
	cout << endl;
	return 0;
}

