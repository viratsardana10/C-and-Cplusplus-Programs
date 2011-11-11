#include <iostream>
using namespace std;
//void merge_sort(string* ,int );
extern string randomString(int ,bool ,bool ,bool );
string* s;
string* substring;

int main()
{
    int cases;
    cin>>cases;
    int result[cases];
    int n;
    cin>>n;
    string random_str=randomString(n,true,false,false);
  
    cout<<random_str<<endl;
  for(int p=0;p<cases;p++)
  {
    int count;
    cin>>count;
    s=new string[count];
    s[0]=random_str;
  //  cin>>s[0];
    int smallest_size=s[0].size();
    string smallest_str=s[0];

    for(int i=1;i<count;i++)
    {	    
         s[i]=randomString(((rand()%9998)+2),true,false,false);
	 int temp=s[i].size();
	 if(temp<smallest_size)
	 {
		 smallest_size=temp;
		 smallest_str=s[i];
	 }
    }
         
    cout<<"before substring.\n"; 
    int len=smallest_size/2;
    int size=(len+1)*(len+2)/2;
    cout<<size<<endl;   
    substring=new string[size];
    string str;
 //   int max_length=len+1; 
    int length_str=0;    
    int k=0;
    for(register int i=0;i<=len;i++)
    {
          for(register int j=0;j<=(len-i);j++)
          {
            substring[k]=smallest_str.substr(i,(len-i-j+1));
  //          cout<<substring[k]<<"  ";
             int counter=0;
            for(int t=0;t<count;t++)
            {
                    register int pos1=s[t].find(substring[k]);
                    register int pos2=s[t].rfind(substring[k]);
                    if(pos1==pos2)
                          break;
                    
                    counter++;      
            }
            if(counter==count)
            {
                   str=substring[k];
                   int temp=str.size();
                   if(temp>length_str)
                   {
                         length_str=temp;
                   }   
                  
            } 
            k++;
          }
    }
    cout<<"after substring.\n";


    /*
    for(int i=(size-1);i>=0;i--)
    {
            int counter=0;
            for(int j=0;j<count;j++)
            {
                    int pos1=s[j].find(substring[i]);
                    int pos2=s[j].rfind(substring[i]);
                    if(pos1==pos2)
                          break;
                    
                    counter++;      
            }
            if(counter==count)
            {
                   str=substring[i];
                   int temp=str.size();
                   if(temp==max_length)
                         length_str=max_length;
                   else if(temp>length_str)
                   {
                         length_str=temp;
                   }   
                  
            }
    }*/
    result[p]=length_str;
  }
  for(int p=0;p<cases;p++)
      cout<<result[p]<<endl;
  //  system("pause");  
    return 0;
}


