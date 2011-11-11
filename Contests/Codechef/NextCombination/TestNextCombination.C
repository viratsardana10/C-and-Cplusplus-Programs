#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include "next_combination.h"
using namespace std;

int main(int argc, char *argv[])
{
   // INITIALIZE
   int j,k,n,t=0;
   //int b[] = { 1,1,2,2,3,3};//(4,6)->6
   //int c[] = { 1,2,2,3,5};//(3,5)->7
   //int a[] = { 1,2,2,3,4,4,5};//(4,7)->18


   char a[] = { 'A','B','C','D','E','F' };//(4,6)->15;   
   j=1; k=4; n=6;
   while ( next_combination( a, a+k, a+n ) ) j++;
   assert(j==15); t++;
   
   int b[] = { 1,2,2,2,2,3,4,4,5,6,6,6,7};//(8,13)->136
   j=1; k=8; n=13;
   while ( next_combination( b, b+k, b+n ) ) j++;
   assert(j==136); t++;
   
   int c[] = { 1,2,2,3,5};//(3,5)->7
   j=0; k=3; n=5;
   do {
      for ( int i = 0 ; i < n ; i++ ) {
         if (i == k) cout << "| "; 
         cout << c[ i ] << " ";
      }
      cout << "\n";
      j++;
   } while ( next_combination( c, c+k, c+n ) );
   assert(j==7); t++;

   int d[] = { 1,2,2,4,4,6,8,9 };//(4,8)->36
   j=0; k=4; n=8;
   do {
      for ( int i = 0 ; i < n ; i++ ) {
         if (i == k) cout << "| "; 
         cout << d[ i ] << " ";
      }
      cout << "\n";
      j++;
   } while ( next_combination( d, d+k, d+n ) );
   assert(j==36); t++;
   
   //    // LIFECYCLE
   //    // Identity testing
   //    BitFunction F,G(0x76543210),H(G);
   //    assert(F==G);
   //    assert(F==H);
   //    assert(F*F==F);
   //    assert(F.inverse()==F);
   //    assert(F*F*F==F);
   //
   //    // 2-cycle testing
   //    G=0x01234567;
   //    assert(G*G==F);
   //    assert(G.inverse()==G);
   //    assert(G*G*G==G);
   //    
   //    // Random function testing
   //    H=0x47320156;
   //    assert((H.inverse()*H).IsIdentity());
   //    assert((H*H.inverse()).IsIdentity());
   //    assert(H*H*H.inverse()==H);
   //    
   //    //INQUIRY
   //    assert(F.IsIdentity());
   //    assert(F.IsInvertible());
   //    G=0x12341234;
   //    assert(!G.IsInvertible());
   //    assert(!G.IsIdentity());
   //    
   //    //OPERATORS;
   //    
   //    // ACCESS

   cout << t << " tests passed.\n";
   return 0;
}


