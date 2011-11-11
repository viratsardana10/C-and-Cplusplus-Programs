#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits>
#include<vector>
#include<bitset>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

#define S scanf
#define P printf
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,FROM,n) for(int i=FROM;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define ll long long int
#define llu long long unsigned int


int t,n;

int ni()
{
    int temp;
    scanf("%d",&temp);
    return temp;
}

ll nl()
{
    ll temp;
    scanf("%lld",&temp);
    return temp;
}

float nf()
{
    float temp;
    scanf("%f",&temp);
    return temp;
}

long long unsigned int gcd(long long unsigned int r0,long long unsigned int r1)
{
    long long unsigned int temp;

    if(r0<r1)
              {
                   temp = r0;
                   r0 = r1;
                   r1=temp;
              }

    //r0 is the larger number and r1 is the smaller number
    long long unsigned int remainder;

    do{
        remainder = r0%r1;

        r0=r1;
        r1=remainder;
        }while(remainder!=0);

    return r0;
}

llu combi(llu x,llu y)
{
    llu a[100];
    if(x-y>y)
    y=x-y;
    int cnt=0;
    REP(i,x-y)
    a[cnt++]=(x-i);
    FOR(i,2,x-y+1)
    {
        llu k=i;
        REP(j,cnt)
        {
            llu g=gcd(a[j],k);
            if(g>1)
            {
                k/=g;
                a[j]/=g;
            }
            if(k==1)
            break;
        }
    }
    llu ans=1;
    REP(i,cnt)
    ans=(ans*a[i]);
    return ans;
}

llu take()
{
    char a[100];
    scanf("%s",a);
    llu x=0;
    for(int i=0;a[i]!='\0';i++)
    {
        x=x*10+(a[i]-'0');
    }
    return x;
}

void print(llu x)
{
    char a[100];
    int cnt=0;
    llu y=x;
    while(y)
    {
        cnt++;
        y/=10;
    }
    a[cnt]='\0';
    while(x)
    {
        char c=(x%10)+'0';
        a[cnt-1]=c;
        cnt--;
        x/=10;
    }
    printf("%s\n",a);
}

int main()
{

   scanf("%d",&t);
   for(int prob=0;prob<t;prob++)
   {
       llu x=take();
       llu y=take();
       if(y==0)
       printf("1\n");
       else if(y>x)
       printf("0\n");
       else
       print(combi(x,y));
   }

   return 0;

}
