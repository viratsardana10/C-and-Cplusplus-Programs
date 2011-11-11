#include <iostream>
#include <cstring>
using namespace std;

void print(char*[] ,int );
int main()
{
    
    //char s[]="04/08/2009";
    char* s=new char;
    cout<<"Enter date in the format dd/mm/yyyy :";
    cin>>s;
    char* token;
    char* a[30];
    token=new char;
    
    token=strtok(s,"/");
    a[0]=token;
    int i=0;
    while(token!=NULL)
    {
        i++;
        //cout<<token<<endl;
        token=strtok(NULL,"/");
        a[i]=new char;
        a[i]=token;
    }
    print(a,i);    
    cout<<endl<<endl;
    
    system("pause");
    return 0;
}

void print(char* a[],int size)
{
   int date_1=(static_cast<int>(*a[0]))-48;
   int date_2=(static_cast<int>(*(a[0]+1)))-48;
   int date=date_1*10+date_2;
   //cout<<date; 
   
   int month_1=(static_cast<int>(*a[1]))-48;
   int month_2=(static_cast<int>(*(a[1]+1)))-48;
   int month=month_1*10+month_2;
   //cout<<endl<<month;
   
   char* month_names[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   cout<<"\n The date is:  "<<month_names[(month-1)]<<" "<<date<<", "<<a[2];   
} 







       
