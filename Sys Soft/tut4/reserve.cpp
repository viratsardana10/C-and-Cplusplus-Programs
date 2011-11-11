#include <cstring>

char residents[][5][12];

void reserve(int f,int r,char* name)
{
	strcpy(residents[f][r],name);
}
