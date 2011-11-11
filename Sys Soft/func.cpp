int func(int x,int y,int z)
{
	int p=(y-z);
	int q=x*(y-z);
	p=p<<31;
	p=p>>31;
	p=p^q;

	return p;
}
