#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;
extern string randomString(int ,bool ,bool ,bool );

int main()
{

    long init_clock=clock();
    int count;
    cin>>count;
    srand(time(0));
    
    string name[count];
    for(int i=0;i<count;i++)
    {
          name[i]=randomString((rand()%100+1),true,false,false);
	//  cout<<name[i]<<"  ";
    }
    cout<<endl;

    int length=0;
    for(int i=0;i<count;i++)
    {
            for(int j=(i+1);j<count;j++)
            {
                    int temp=0;
                    int len=name[i].size();
                    for(int k=0;k<len;k++)
                    {
                            if(name[i][k]==name[j][k] || name[i][k]==(name[j][k]-32) || name[i][k]==(name[j][k]+32))
                                    temp++;
                            else
                                 break;    
                    }
                    if(temp>length)
                           length=temp;
            }
    }
    cout<<length;
    long final_clock=clock();
    cout<<endl<<" Time difference : "<<((double)(final_clock-init_clock)/1000);
    
    cout<<endl;
    system("pause");
    return 0;
}
