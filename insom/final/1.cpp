#include <iostream>
#include <fstream>
using namespace std;

int* a;

int main()
{
        ifstream infile("input.txt");
        ofstream outfile("output.txt");
	int N;
	infile>>N;
        a=new int[N];
	for(int i=0;i<N;i++)
	   infile>>a[i];
     
     int count=0;
     int zeros=0;
     while(zeros!=N)
     {  
	int longest=1;
        int index=101;
	for(int i=0;i<N;i++)
	{
                if(a[i]==0)
                     continue;

 		int temp=1;
		int last=a[i];
		for(int j=(i+1);j<N;j++)
		{
			if(a[j]>last)
			{
                                cout<<a[j]<<"  "; 
				last=a[j];
				temp++;
			}
		}
                cout<<endl;
		if(temp>=longest)
                {
		     longest=temp;
                     index=i;
                }
	}
       
        cout<<"index : "<<index<<" , longest: "<<longest<<endl;
     if(longest==1 && index<101)
        {
             a[index]=0;
             count++;
             zeros++;
        }
     else if(longest==1 && index==101)
     {
          cout<<"here";
          outfile<<count<<endl;
          return 0;
     } 
     else {
    //   if(index<101)
    //    {
             int last=a[index];
             a[index]=0;
             zeros++;
             for(int j=(index+1);j<N;j++)
             {
                  if(a[j]>last)
                  {
                     last=a[j];
                     a[j]=0;
                     zeros++;
                  }
             } 
    /*    } 
        else if(index==101)
        {
              outfile<<count<<endl;
              return 0; 
        } */
        count++;
       }  
       
      }
        outfile<<count<<endl;
        return 0;
}

