#include <iostream>
//#include <csring>
#include <ctime>
#include <cstdlib>
using namespace std;
char* randomChar(int ,bool ,bool ,bool );

int main()
{

    long init_clock=clock();
    int count;
    cin>>count;
    srand(time(0));
    
    char* name[count];
    for(int i=0;i<count;i++)
    {
	  name[i]=new char;
          name[i]=randomChar((rand()%100+1),true,false,false);
	//  cout<<name[i]<<"  ";
    }

    int length=0;
    for(int i=0;i<count;i++)
    {
            for(int j=(i+1);j<count;j++)
            {
                    int temp=0;
                    int len=strlen(name[i]);
                    for(int k=0;k<len;k++)
                    {
                            if(*(name[i]+k)==*(name[j]+k))
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

char* randomString(int length, bool letters, bool numbers, bool symbols) 
{
    // the shortest way to do this is to create a string, containing
    // all possible values. Then, simply add a random value from that string
    // to our return value
    char allPossible[26]=""; // this will contain all necessary characters
    char str[length+1]=""; // the random string
 //   if (letters == true) { // if you passed true for letters, we'll add letters to the possibilities
        for (int i = 65; i <= 90; i++) {
	    const char* s=new char;
	    s=(char)i;
            strcat(allPossible,static_cast<char>(i));
        //    allPossible += static_cast<char>(i+32); // add a lower case letter, too!
        } /*
    } if (numbers == true) { // if you wanted numbers, we'll add numbers
        for (int i = 48; i <= 57; i++) {
            allPossible += static_cast<char>(i);
        }
    } if (symbols == true) { // if you want symbols, we'll add symbols (note, their ASCII values are scattered)
        for (int i = 33; i <= 47; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 58; i <= 64; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 91; i <= 96; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 123; i <= 126; i++) {
            allPossible += static_cast<char>(i);
        }
    }*/
    // get the number of characters to use (used for rand())
    int numberOfPossibilities = strlen(allPossible);
    for (int i = 0; i < length; i++) {
          strcat(str,allPossible[rand() % numberOfPossibilities]);
    }
    str[length]='\0';

    return str;

}

