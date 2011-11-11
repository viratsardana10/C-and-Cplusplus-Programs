#include <iostream>
#include <process.h>
#include "2stacks.h"
using namespace std;

int main ()
{  stack<int> s;
 cout<<"-----------\nmain menu\n-----------\n-->press 1 to push in stack 1\n-->press 2 to push in stack 2\n-->press 3 to pop from stack 1\n-->press 4 to pop from stack 2\n";
int c,val;

start:
cout<<"\nenter choise:\n";
cin>>c;
switch(c)
{case 1:   cout<<"\nenter value\n";
           cin>>val;
           s.push1(val);
           break;
case 2:    cout<<"\nenter value\n";
           cin>>val;
           s.push2(val);
           break;
case 3:    cout<<"\n"<<s.pop1()<<"\n";
           break;
case 4:    cout<<"\n"<<s.pop2()<<"\n";
           break;
default: exit(0);          
           
}

  
goto start;
   
   
   
   system("pause");
   return 0;
}
