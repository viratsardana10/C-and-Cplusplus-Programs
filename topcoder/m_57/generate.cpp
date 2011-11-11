#include <fstream>
using namespace std;

int main()
{
   ifstream infile("perm");
   ofstream outfile("input");
   while(true)
   {
       long a;
       infile>>a;outfile<<a;
       outfile << 10 << endl;
   }

   return 0;
}
