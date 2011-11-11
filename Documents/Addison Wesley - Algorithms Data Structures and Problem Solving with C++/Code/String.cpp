#ifndef __String_CPP_
#define __String_CPP_

#include "String.h"
#include "Exception.h"

char *String::NullString = (char *) "";

String::String( const char *Value )
{
    if( Value == NULL )      // Use "" if Value is NULL
    {
        GetBuffer( 0 );
        Buffer[ 0 ] = '\0';
    }
    else
    {
        GetBuffer( (int) strlen( Value ) );
        strcpy( Buffer, Value );
    }
}

String::String( const String & Value )
{
    GetBuffer( (int) strlen( Value.Buffer ) );
    strcpy( Buffer, Value.Buffer );
}

const String &
String::operator=( const String & Rhs )
{
    const int Len = (int) strlen( Rhs.Buffer );

    if( this != &Rhs )       // Don't copy to yourself
    {
        if( Len >= BufferLen )
        {
            if( BufferLen != -1 )
                delete [ ] Buffer;
            GetBuffer( Len );
        }
        strcpy( Buffer, Rhs.Buffer );
    }

    return *this;
}

const String &
String::operator=( const char * Rhs )
{
    if( Rhs == NULL )
        Rhs = "";

    const int Len = (int) strlen( Rhs );

    if( Len >= BufferLen )
    {
        if( BufferLen != -1 )
            delete [ ] Buffer;
        GetBuffer( Len );
    }
    strcpy( Buffer, Rhs );

    return *this;
}

istream &
operator >> ( istream & In, String & Value )
{
    static char Str[ 1024 ];

    In >> Str;
    Value = Str;
    return In;
}

ostream &
operator << ( ostream & Out, const String & Value )
{
    return Out << Value.Buffer;
}

// Modified to not allow reference to null terminator
char &
String::operator[ ]( int Index )
{
    EXCEPTION( Index < 0 || Index >= (int) strlen( Buffer ),
                "Index out of range" );
    return Buffer[ Index ];
}

char
String::operator[ ]( int Index ) const
{
    EXCEPTION( Index < 0 || Index > (int) strlen( Buffer ),
                "Index out of range" );
    return Buffer[ Index ];
}

#endif
