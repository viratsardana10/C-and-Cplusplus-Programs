#include<iostream>
using namespace std;
int main()
{
	int k,n,c;
	char ch;
	cin>>n;
	while(n--)
	{
		cin>>k;
		c=k;
		if(k<=25)
		{
			ch=k+'a';
			for(;ch>='a';--ch)
			cout<<ch;
		}
		else if(k<=50)
		{
			ch=k+'a'-25;
			for(;ch>='a';--ch)
			cout<<ch;
			for(ch='z';ch>='a';--ch)
			cout<<ch;
		}
		else if(k<=75)
		{ 
			ch=k+'a'-50;
			for(;ch>='a';--ch)
			cout<<ch;
			for(ch='z';ch>='a';--ch)
			cout<<ch;
			for(ch='z';ch>='a';--ch)
			cout<<ch;
		}
		else if(k<=100)
		{
			ch=k+'a'-75;
			for(;ch>='a';--ch)
			cout<<ch;
			for(ch='z';ch>='a';--ch)
			cout<<ch;
			for(ch='z';ch>='a';--ch)
			cout<<ch;
			for(ch='z';ch>='a';--ch)
			cout<<ch;
		}
		cout << endl;
	}
	return 0;
}
