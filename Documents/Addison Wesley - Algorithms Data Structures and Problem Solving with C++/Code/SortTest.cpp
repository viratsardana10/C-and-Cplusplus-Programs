#include <iostream.h>
#include "Indirect.cpp"
#include "Mergesrt.cpp"
#include "Quicksrt.cpp"
#include "Shellsrt.cpp"
#include "Select.cpp"

int main( void )
{
    const int Size = 1000;

    int A[ Size ];
    int B[ Size ];
    int C[ Size ];
    int D[ Size ];
    int i;

    for( i = 0; i < Size; i++ )
        A[ i ] = B[ i ] = C[ i ] = D[ i ] = rand( );

    QuickSelect( A, Size, Size / 2 );
    cout << "Median is " << A[ Size / 2 - 1 ] << "\n";

    ShellSort( A, Size );
    MergeSort( B, Size );
    QuickSort( C, Size );
    Shellsort( D, Size );

    for( i = 0; i < Size; i++ )
        if( A[ i ] != B[ i ] )
            cout << "Error in sorts A != B" << endl;

    for( i = 0; i < Size; i++ )
        if( A[ i ] != C[ i ] )
            cout << "Error in sorts A != C" << endl;

    for( i = 0; i < Size; i++ )
        if( B[ i ] != C[ i ] )
            cout << "Error in sorts B != C" << endl;

    for( i = 0; i < Size; i++ )
        if( B[ i ] != D[ i ] )
            cout << "Error in sorts B != D" << endl;

    cout << "Median is " << B[ Size / 2 - 1 ] << "\n";

    return 1;
}
