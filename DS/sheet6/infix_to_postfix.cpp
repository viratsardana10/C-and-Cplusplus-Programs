#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

#define OPER1 +
#define OPER2 -
#define OPER3 *
#define OPER4 /

bool precedence(char ,char );
int main()
{
  char choice;  
  do{
	Stack<char> operators;
    Stack<char> postexpr;

    string expr;
	cout<<"Enter the infix expression: ";
	cin>>expr;
	int size=expr.length();
//	cout<<size<<endl;

	int postexpr_count=0;

	for(int i=0;i<size;i++)
	{
		if(expr[i]>=48 && expr[i]<=57)
		{
			postexpr.push(expr[i]);
			postexpr_count++;
		}
		else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/')
		{
			while(!(operators.isEmpty()) && precedence(operators.top(),expr[i]))
			{
				char op1;
				if(operators.pop(op1))
				{
				    postexpr.push(op1);
				    postexpr_count++;
				}
			}
			operators.push(expr[i]);
		
		}
	}
    char postfix[size+1];
	postfix[size]='\0';

    for(int i=(postexpr_count-1);i>=0;i--)
	{
		char pexpr;
		if(postexpr.pop(pexpr))
		{
			postfix[i]=pexpr;
		}
	}

    while(!operators.isEmpty())
	{
		char op;
		if(operators.pop(op))
		{
           postfix[postexpr_count]=op;
		   postexpr_count++;

		}
	}

    cout<<"\nThe postfix expr is : "<<postfix<<endl;
    
    Stack<int> post;
    
    for(int i=0;i<size;i++)
    {
            if(postfix[i]>=48 && postfix[i]<=57)
                     post.push(int(postfix[i])-48);
            else
            {
                   int op2;
                   post.pop(op2);
                   int op1;
                   post.pop(op1);
                   
                   int result;
                   if(postfix[i]=='+')
                          result=op1 OPER1 op2;
                   else if(postfix[i]=='-')
                          result=op1 OPER2 op2;
                   else if(postfix[i]=='*')
                          result=op1 OPER3 op2;
                   else if(postfix[i]=='/')
                          result=op1 OPER3 op2;
                          
                   post.push(result);                                            
            }
           
                
    }
    int value;
    if(post.pop(value))
         cout<<"The result is : "<<value<<endl<<endl;
       
    //char choice;
    cout<<"Do You Want To Continue (y/n) :";
    cin>>choice;     
   }while(choice=='y' || choice=='Y');      
	cout<<endl;
	system("pause");
	return 0;
            	
}


bool precedence(char op1,char op2)
{
	if((op1=='+' || op1=='-') && (op2=='+'|| op2=='-'))
		return true;
	else if(op1=='*' || op1=='/')
		return true;
	else
	       return false;
}

