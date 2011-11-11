#include <iostream>
using namespace std;

int main()
{
int num,i=1,j,k;
cout<< ("\nEnter a number:");

cin>>num;

while(i<=num) 
{ k=0; 
  if(num%i==0) 
  { j=1; 
    while(j<=i) 
    { if(i%j==0) k++; j++; } 
      if(k==2) 
         cout << ("\n%d is a prime factor",i); 
    } 
    i++; 
} 
return 0; 
}
