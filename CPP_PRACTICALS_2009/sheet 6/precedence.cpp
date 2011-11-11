bool precedence(char a,char b)
{
	if((a=='+' || a=='-') && (b=='+'|| b=='-'))
		return true;
	else if(a=='*' || a=='/')
		return true;
	else
	       return false;

}
