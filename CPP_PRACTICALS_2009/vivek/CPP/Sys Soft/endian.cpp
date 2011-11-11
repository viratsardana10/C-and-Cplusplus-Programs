#include <iostream>
using namespace std;

int main()
{
unsigned short n = 0x1234;
unsigned char *p = (unsigned char *) &n;
//printf ("%d\n", *p);
cout<<*p<<"   "<<*(p+1)<<"  "<<*(p+2);

cout<<endl;
system("pause");
return 0;
}
