public class stringHash {
	public static void main(String args[])
	{
		String str=new String("TYE=]'");
	//	String s=new StringBufferInputStream(s);
	//	str=(String)System.in.read();

		System.out.println(str+" : "+hash(str));
	}

	public static long hash(String s)
	{
		long hashValue=5381;
		int size=s.length();

		for(int i=0;i<size;i++)
		{
			hashValue=(hashValue*33)^((int)s.charAt(i));
		}
		return hashValue;
	}
}
