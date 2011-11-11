#include <stdio.h>

int checkprime (int num)


{
  int counter = 2;
  while (1)
   {
    if (!(num %  counter)) return 0; //Divisor found hence number is not prime.
    if ((num/counter) < counter) return counter; //No Divisor Found
    counter ++;
   }
}

int main ()

{
 long int num;
 
 printf ("\n\nEnter Number To Be Checked : ");
 scanf ("%d", &num);
 
 if (checkprime (num))
  {
    printf ("\n\n %d Is A Prime Number. ",num);
  }
 else
  {
    printf ("\n\n %d Is Not A Prime Number.", num);
  }
 return 0;

}
