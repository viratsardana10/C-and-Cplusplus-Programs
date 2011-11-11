class Diagonals{
	public static void main(String args[])
	{
		int x = 0, y = 0;
                long sum = 0;
		for(int i = 1; i <= 10001*10001; i++)
		{
			if(Math.abs(x) == Math.abs(y))
				sum+=i;
			if(y >= Math.abs(x))
				x++;
			else if((y <= -x && x > 0) || (y < x && x <= 0))
				x--;
			else if(x > 0)
				y--;
			else if(x < 0)
				y++;
		}
		System.out.println(sum);
	}
}
