#include <iostream>
#include <cstring>
using namespace std;
long hash(string s);

int main()
{
	string str;
	cout<<"Enter String: ";
	cin>>str;

	//for()

	long hashValue=hash(str);
	cout<<str<<" : "<<hashValue<<endl;

	return 0;
}

long hash(string s)
{
	long hash_value= 5381;
	int length=s.size();

	for(int i=0;i<length;i++)
	{
		hash_value=(hash_value*33)^s[i];
		cout<<s[i]<<"  ";
		//cout<<hash_value<<"   ";
	}
        cout<<endl;
	return hash_value;
}

string invertHash(long n)
{
	long hash_value=5381;
        
	int a=33;
	int arr[94];
	for(int i=0;i<94;i++)
	{
		arr[i]=a;
		a++;
	}

	int size=pow(94,4);
	int perm[size][4];	
	for(int i=0;i<94;i++)
	{
		for(int j=0;j<4;j++)
		{
			perm[i][j]=
		}
	}


//	for(int i=4;i<=20;i++)
//	{
		for(int j=0;j<i;j++)
//	}
}



#define N    12   // number of elements to permute.  Let N > 2

void QuickPerm(void)
{
   unsigned int a[N], p[N+1];
   register unsigned int i, j, tmp; // Upper Index i; Lower Index j

   for(i = 0; i < N; i++)   // initialize arrays; a[N] can be any type
   {
      a[i] = i + 1;   // a[i] value is not revealed and can be arbitrary
      p[i] = i;
   }
   p[N] = N; // p[N] > 0 controls iteration and the index boundary for i
   //display(a, 0, 0);   // remove comment to display array a[]
   i = 1;   // setup first swap points to be 1 and 0 respectively (i & j)
   while(i < N)
   {
      p[i]--;             // decrease index "weight" for i by one
      j = i % 2 * p[i];   // IF i is odd then j = p[i] otherwise j = 0
      tmp = a[j];         // swap(a[j], a[i])
      a[j] = a[i];
      a[i] = tmp;
      //display(a, j, i); // remove comment to display target array a[]
      i = 1;              // reset index i to 1 (assumed)
      while (!p[i])       // while (p[i] == 0)
      {
         p[i] = i;        // reset p[i] zero value
         i++;             // set new index value for i (increase by one)
      } // while(!p[i])
   } // while(i < N)
} // QuickPerm()

