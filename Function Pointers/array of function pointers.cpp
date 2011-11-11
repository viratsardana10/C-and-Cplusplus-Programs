#include <iostream>
using namespace std;

void function0(int);
void function1(int);
void function2(int);

int main()
{
    void(*g[])(int)={function0,function1,function2};
    
    int choice;
    cin>>choice;
    
    if(choice>=0 && choice<3)
    {
        (*g[choice])(choice);
    }
    cout<<"Program execution completed."<<endl;
    
    system("pause");
    return 0;          
}    

void function0(int a)
{
    cout<<"You entered "<<a<<" so function0 was called."<<endl;
}

void function1(int a)
{
    cout<<"You entered "<<a<<" so function1 was called."<<endl;
}

void function2(int a)
{
    cout<<"You entered "<<a<<" so function2 was called."<<endl;
}

    
