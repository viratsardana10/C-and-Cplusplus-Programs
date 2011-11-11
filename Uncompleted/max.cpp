#include<iostream>
using namespace std;
float max(float *p[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        if (*p[i]<*p[i+1])
        p[i]=p[i+1];
    }
    return *p[n];
}        
int main()
{
    int a[10]={11,22,33,44,33,55,77,1,22,33};
    int*p[10];
    int input;
    for (int i=0;i<10;i++)
    {
        p[i]=&a[i];
    }
    cout <<"enter no, "<<endl;
    cin>>input;
    for (int j=0;j<10;j++)
    {
        if (input==*p[j])
        cout<<p[j]<<endl;
}

    system("pause");
    return 0;
}
        
