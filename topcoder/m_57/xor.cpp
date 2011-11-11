#include <iostream>
#include <cmath>
using namespace std;
void binary(int num,int& i);
int i=0;
int a[40]={0};
int main()
{
	int a=0,b=1,c=2,d=3;
	int x=33;
	//cout<<(a^x);
	int n=5381*33;
//    binary(n,i);    
    cout<<endl;
    for(int i=33;i<=126;i++)
    {
            n=(n^i);
            binary(n,i);
            cout<<" : ";
            long dec=0;
            for(int j=0;j<40;j++)
            {
                   // dec+=(pow(2.0,a[j])*a[j]);
            }
            cout<<dec<<endl;
    }
	system("pause");
	return 0;
}


void binary(int num,int& i)
{
      if(num!=1)
      {
        int rem=num%2;
        a[i]=rem;
        i++;
        binary(num/2,i);
        cout<<rem;
      }
      else
         cout<<num;
      
}
