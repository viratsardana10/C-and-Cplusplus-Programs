#include <iostream>
using namespace std;

int main()
{
	short input;
	cin >> input;
	while( input != 42 ) {
		cout << input << endl;
		cin >> input;
	}
}
