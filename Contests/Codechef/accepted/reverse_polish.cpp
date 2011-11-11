#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		string infix;
		cin >> infix;
		int size = infix.size();
		
		stack<char> bracket;
		stack<char> operators;
		string postfix;

		for(int i = 0; i < size; ++i)
		{
			if(infix[i] == '(')
				bracket.push('(');
			else if(infix[i] == ')') {
				bracket.pop();
				postfix.push_back(operators.top());
				operators.pop();
			}
			else if(infix[i] >= 'a' && infix[i] <= 'z')
				postfix.push_back(infix[i]);
			else 
				operators.push(infix[i]);
		}
		cout << postfix << endl;
	}
	return 0;
}
