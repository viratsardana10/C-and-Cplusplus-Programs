#include <iostream>
using namespace std;

class Complex
{
    public:
    Complex(int r=0,int i=0)
    {
        real=r;
        img=i;
    }
    
    
        Complex add(Complex complex1,Complex complex2)
        {
            Complex addition;
            addition.real=complex1.real+complex2.real;
            addition.img=complex1.img+complex2.img;
            return addition;
        }
        
        Complex subtract(Complex complex1,Complex complex2)
        {
            Complex sub;
            sub.real=complex1.real+complex2.real;
            sub.img=complex1.img+complex2.img;
            return sub;
        }
        
        void print(Complex complex)
        {
            cout<<complex.real<<" + i*"<<complex.img<<endl;
        } 
        
     private:
            int real;
            int img;   
};

int main()
{
    Complex a(1,2);
    Complex b(4,5);
    Complex c;
    
    c=c.add(a,b);
    a.print(a);
    b.print(b);
    c.print(c);
    
    system("pause");
    return 0;
}
