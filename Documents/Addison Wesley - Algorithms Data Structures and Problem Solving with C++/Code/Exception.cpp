#include "Exception.h"
#include <stdlib.h>
#include <iostream.h>

void
EXCEPTION( int Condition, const char *ErrMsg )
{
    if( Condition )
    {
        cerr << "Exception: " << ErrMsg << endl;
        abort( );
    }
}
