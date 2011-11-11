#include <iostream>

using namespace std;

template <class t>
class stack
{  public:
       t arr[5];
   int top1;
   int top2;
   stack()
   {top1=-1;
   top2=5;
   
       }

void push1(t k)
{if(top2==top1+1)
{cout<<"\noverflow\n";
return;
}
    top1++;
arr[top1]=k;
     }


void push2(t k)
{if(top2==top1+1)
{cout<<"\noverflow\n";
return;
}
    top2--;
arr[top2]=k;
     }
     
     
  t pop1()
{  if(isempty1()==false)
  {top1=top1-1;
  return arr[top1+1];
  }

  else
  {cout<<"underflow";
  return 0;
     }
}

 t pop2()
{  if(isempty2()==false)
  {top2=top2+1;
  return arr[top2-1];
  }

  else
  {cout<<"underflow";
  return 0;
     }
}


bool isempty1()
{if(top1==-1)
return true;
return false;

}

bool isempty2()
{if(top2==5)
return true;
return false;

}
      }; 
