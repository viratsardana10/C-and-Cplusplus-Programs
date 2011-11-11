#include <iostream.h>
#include "List.cpp"

// g++ hack needed to see template instantiation.
// Go figure...
// This hack might not work for all g++ versions.
// If so, you'll need your own hack. Sorry...
ostream & operator<<( ostream &, const List<int> & );


main( void )
{
    List<int> L;
    ListItr<int> Ptr( L );
    int i;

    cout << L;
    for( i = 0; i < 10; i++ )
        Ptr.Insert( i );
    cout << L;
    Ptr.Find( 5 );
    Ptr.Insert( 12 );
    Ptr.Remove( 99 );
    cout << L;
    for( Ptr.First( ); +Ptr; ++Ptr )
        cout << Ptr( ) << endl;
    /* The next two lines generate an exception deliberately */
/*  Ptr++;
    Ptr( );
*/

    List<int> L2;
    SortListItr<int> Ptr2( L );
    cout << L2;
    L2 = L;
    L.MakeEmpty( );
   // cout << L << L2;

    for( i = 10; i != 0; i = (i+3)% 10 )
        Ptr2.Insert( i );
    cout << L << L2;

    return 0;
}
