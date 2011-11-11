#include <iostream.h>
#include "Rational.h"

// Rational number test program

main( )
{
    Rational X;
    Rational Sum = 0;
    Rational Max = 0;
    int N = 0;

    cout << "Type as many rational numbers as you want\n";

    while( cin >> X )
    {
        cout << "Read " << X << '\n';
        Sum += X;
        if( X > Max )
            Max = X;
        N++;
    }
    cout << "Read " << N << " rationals\n";
    if( Max > Rational( IntType( 0 ) ) )  // Extra cast for Visual 5.0
        cout << "Largest positive number is " << Max << '\n';
    if( N > 0 )
        cout << "Average is " << Sum / Rational( IntType( N ) ) << '\n';

    return 0;
}
