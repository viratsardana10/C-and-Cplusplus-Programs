#include "Queue.cpp"
#include <iostream.h>

int
main( )
{
    Queue<int> Q1, Q2;
    int i;

    for( i = 0; i < 5; i++ )
        Q1.Enqueue( i );
    while( !Q1.IsEmpty( ) )
        Q1.Dequeue( );

    for( i = 0; i < 5; i++ )
    {
        Q1.Enqueue( i );
        Q2.Enqueue( i * 2 );
    }

    Q2 = Q1;

    cout << "Print Q1: (should be 0 1 2 3 4)\n";
    while( !Q1.IsEmpty( ) ) 
    {
        cout << Q1.GetFront( ) << "\n";
        Q1.Dequeue( );
    }

    cout << "Print Q2: (should be 0 1 2 3 4)\n";
    while( !Q2.IsEmpty( ) ) 
    {
        cout << Q2.GetFront( ) << "\n";
        Q2.Dequeue( );
    }

    Q2.Enqueue( 10 );
    Q2 = Q1;

    cout << "Print Q2: (should be empty)\n";
    while( !Q2.IsEmpty( ) ) 
    {
        cout << Q2.GetFront( ) << "\n";
        Q2.Dequeue( );
    }

    return 0;
}
