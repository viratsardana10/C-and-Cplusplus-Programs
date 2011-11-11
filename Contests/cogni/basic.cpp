#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--) {
		string s1, s2;
		cin >> s1 >> s2;
		
		int a[100], b[100];
		for(int i = 0 ; i < 100; ++i)
			a[i] = b[i] = 0;

		int len1 = s1.size();
		int len2 = s2.size();

		for(int i = 0 ; i < len1 ; ++i)
			a[i] = int(s1[i] - '0');

		for(int i = 0 ; i < len2 ; ++i)
			b[i] = int(s2[i] - '0');
	
		int c[len2][110];
		for(int i = 0 ; i < len2; ++i)
			for(int j = 0 ; j < 110; ++j)
				c[i][j] = 0;
	
		int counter = 0;
		for(int i = 0 ; i < len2 ; ++i)
		{	
			int j;	
			for(j = 0 ; j < counter ; ++j)
				c[i][j] = 0;
			
			int d = b[len2-i-1];
			int carry = 0;
			for(int k = len1-1 ; k >=0 ; --k)
			{
				int d1 = a[k];
				int d2 = d*d1 + carry;
			//	cout << d2 << endl;
				c[i][j] = d2%10;
				j++;
				carry = d2/10;				
			}
			while(carry>0)
			{
				c[i][j] = carry%10;
				j++;
				carry = carry/10;
			}
			++counter;				
		}		
		
	/*	for(int i = 0 ; i < len2; ++i)
		{ 
			for(int j = 0 ; j < 100; ++j) 
			{
				cout << c[i][j];
			}
			cout << endl;
		}
	*/
		int count = 0;
		int carry = 0;
		for(int j = 0 ; j < 110; ++j)
		{ 
			int sum = 0;
			for(int i = 0 ; i < len2; ++i) 
			{
				sum += c[i][j];			
			}
			sum += carry;
			if(sum >= 10) { 
		//		 cout << sum << endl;
				 count++;
				 carry = sum/10;
			}
		}
		cout << count << endl;
	}
}
