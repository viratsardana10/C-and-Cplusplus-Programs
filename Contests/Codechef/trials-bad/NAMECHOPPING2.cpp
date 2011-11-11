#include <iostream>
#include <cstring>
using namespace std;

int main()
{


    int count;
    cin>>count;
      
    char* name[count];
    for(int i=0;i<count;i++)
    {
	    name[i]=new char;
	cin>>name[i];
    }
  
    int length=0;
    for(int i=0;i<count;i++)
    {

            for(int j=(i+1);j<count;j+=3)
            {
                    int temp=0,len;
                    int len1=strlen(name[i]);
                    int len2=strlen(name[j]);
                    if(len1<len2)
                          len=len1;
                    else
                          len=len2;
                    for(int k=0;k<len;k++)
                    {
                            if(*(name[i]+k)==*(name[j]+k) || *(name[i]+k)==*(name[j]+k)-32 || *(name[i]+k)==*(name[j]+k)+32)
                                    temp++;
                            else
                                 break;    
                    }
                    if(temp>length)
                           length=temp;
                 

		  if((j+1)>=count)
			  break;

		    temp=0;
                    for(int k=0;k<len;k++)
                    {
                            if(*(name[i]+k)==*(name[j+1]+k) || *(name[i]+k)==*(name[j+1]+k)-32 || *(name[i]+k)==*(name[j+1]+k)+32)
                                    temp++;
                            else
                                 break;    
                    }
                    if(temp>length)
                           length=temp;


		    if((j+2)>=count)
			    break;

		    temp=0;
                    for(int k=0;k<len;k++)
                    {
                            if(*(name[i]+k)==*(name[j+2]+k) || *(name[i]+k)==*(name[j+2]+k)-32 || *(name[i]+k)==*(name[j+2]+k)+32)         
			          temp++;
                            else
                                 break;    
                    }
                    if(temp>length)
                           length=temp;
              }
    }
    cout<<length;
    
//    system("pause");
    return 0;
}
