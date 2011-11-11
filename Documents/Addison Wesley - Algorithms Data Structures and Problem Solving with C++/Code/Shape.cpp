// Shape class interface: abstract base class for shapes
//
// CONSTRUCTION: is not allowed; Shape is abstract
//     zero-parameter constructor provided for derived classes
//
// ******************PUBLIC OPERATIONS**********************
// double Area( )         --> Return the area (pure virtual)
// <                      --> Compare to Shape objects by area
// <<                     --> Output of Shape objects

#include <iostream.h>
#include "String.h"

class Shape
{
  public:
    virtual ~Shape( ) { }                     // Destructor
    virtual double Area( ) const = 0;         // Area function

    int operator<( const Shape & Rhs ) const  // < function
            { return Area( ) < Rhs.Area( ); }

    friend ostream & operator<<               // Output
            ( ostream & Output, const Shape & S );
  protected:
    String Name;                              // Shape ID
};

ostream & operator<<( ostream & Output, const Shape & S )
{
    Output << S.Name << " of area " << S.Area( ) << '\n';
    return Output;
}

// Circle, Square, Rectangle class interfaces;
//     all based on Shape
//
// CONSTRUCTION: with (a) no initializer or (b) radius (for
//     circle), side length (for square), length and width
//     (for rectangle)
// ******************PUBLIC OPERATIONS**********************
// double Area( )       --> Implements Shape pure virtual Area

const double Pi = 3.1415927;

class Circle : public Shape
{
  public:
    Circle( double R = 0.0 ) : Radius( R )
            { Name = "circle"; }
    double Area( ) const  { return Pi * Radius * Radius; }
  private:
    double Radius;
};

class Rectangle : public Shape
{
  public:
    Rectangle( double L = 0.0, double W = 0.0 ) :
            Length( L ), Width( W )  { Name = "rectangle"; }
    double Area( ) const  { return Length * Width; }
  private:
    double Length;
    double Width;
};

class Square : public Rectangle
{
  public:
    Square( double S = 0.0 ) : Rectangle( S, S )
            { Name = "square"; }
};

// Read a pointer to a shape
// Bare bones, with no error checking

istream & operator>>( istream & Input, Shape * & S )
{
    char Ch;
    double D1, D2;

    Input >> Ch;      // First character represents shape
    switch( Ch )
    {
      case 'c':
        Input >> D1;
        S = new Circle( D1 );
        break;

      case 'r':
        Input >> D1 >> D2;
        S = new Rectangle( D1, D2 );
        break;

      case 's':
        Input >> D1;
        S = new Square( D1 );
        break;

      default:
        cerr << "Needed one of c, r, or s" << endl;
        S = new Circle;      // Radius is 0
        break;
    }

    return Input;
}

struct PtrToShape
{
    Shape *Ptr;

    int operator < ( const PtrToShape & Rhs ) const
            { return *Ptr < *Rhs.Ptr; }

    const Shape & operator*( ) const { return *Ptr; }
};

template <class Etype>
void
InsertionSort( Etype A[ ], int N )
{
    for( int P = 1; P < N; P++ )
    {
        Etype Tmp = A[ P ];
        int j;

        for( j = P; j > 0 && Tmp < A[ j-1 ]; j-- )
            A[ j ] = A[ j-1 ];
        A[ j ] = Tmp;
    }
}

// main: read shapes and output increasing order of area
// Error checks omitted for brevity

int
main( )
{
    int NumShapes;
    cout << "Enter number of shapes:\n"; // Added this line not in text
    cin >> NumShapes;

        // Rule change requires use of new here.
        // Alternate form is to use Vector instead
    PtrToShape *Array = new PtrToShape[ NumShapes ];

        // Read the shapes
    for( int i = 0; i < NumShapes; i++ )
    {
        cout << "Enter a shape: ";
        cin >> Array[ i ].Ptr;
    }

    InsertionSort( Array, NumShapes );

    cout << "Sorted by increasing size:" << endl;
    for( int j  = 0; j < NumShapes; j++ )
        cout << *Array[ j ];

    return 0;
}
