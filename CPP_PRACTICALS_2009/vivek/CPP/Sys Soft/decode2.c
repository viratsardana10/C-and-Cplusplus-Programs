int decode2(int x,int y,int z)
{
	int p=y-z;
	int q=x*(y-z);
	p<<=31;
	p>>=31;
	p=p^q;

	return p;
}