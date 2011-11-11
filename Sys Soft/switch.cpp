int _switch(int x)
{
	int t=x;

	switch(x)
	{
		case 100:
			t*=13;
			break;

		case 102:
			t+=10;

		case 103:
			t+=11;
                        break;

		case 104:
		case 106:
                        t*=t;
                        break;

		default:
			t=0;
	}
	return t;
}
