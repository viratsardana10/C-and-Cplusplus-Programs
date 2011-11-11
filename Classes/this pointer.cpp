#include <iostream>
using namespace std;

class Test
{
public:    
    Test(int a=0)
    {
        set(a);
    }
    
    Test &set(int a)
    {
        m=a;
        return *this;
    }
    
    void print()
    {
        cout<<m<<endl;
        cout<<this->m;
        cout<<endl<<(*this).m;
    }    
private:
    int m;                
};    
int main()
{
    Test t;
    t.print();
    cout<<endl<<"__________________"<<endl;
    
    Test p(1);
    p.print();
    cout<<endl<<"____________________"<<endl;
    
    t.set(10).print();
    cout<<endl<<"_____________________"<<endl;
    
    p.print();
    cout<<endl;
    
    system("pause");
    return 0;
}    
