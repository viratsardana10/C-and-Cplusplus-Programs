

/******   Instructions for participation in code optimization contest   =
*/
/* 1. Please make a table of execution time for matrix size =3D 10*10, =
15*15, 20*20, 25*25, 30*30, 35*35... */
      /* The table should be consisting of the following fields:
                   S. No.             Matrix size          Old execution =
time            New Execution Time
       */

/* You should clearly mention the optimization through proper documents =
per line */
/* please specify your machine architecture  as well */
/* Email your code which has the table and explanation at the top of the =
page to me */
/* There should be only single file without zipping it  */

/* Deadline : 24th Sept, 8:00am  */           
           
           
/************************************************************************=
*****************/           
/*This program calculates the determinant of a square matrix using a
recursive function "determinant" based on Kramer's formula. By using =
this program
user can calculate determinant for any size of matrix. Program runs for =
any input
given by user until user wants to do so. Results for various inputs are =
stored in
"resultdeterminant.txt" text file. Elements of the matrix are generated =
randomly.*/



#include <conio.h>
#include <cstdlib>
#include <ctype.h>
#include <dos.h>
#include <iostream>
#include <ctime>
#include <fstream.h>

#define RANLIM 1000

using namespace std;
//This function returns submatrix without 1st line and colth column of A
void submatrix(int n, int col, double **matrix, double **B)
{
  int i,j,flag=0;

  if (n<3) return;
  for (i=0; i<n-1; i++)
  {
	 flag=0;
	 for (j=0; j<n-1; j++)
	 {
		 if (j!=col)
		 {
			 if (flag==1)
			 {	 B[i][j]=matrix[i+1][j+1];  		 }
			 else
			 {  B[i][j]=matrix[i+1][j];         }
		 }
		 else
		 {
			 flag=1;
			 B[i][j]=matrix[i+1][j+1];
		 }
	  }
	}
}

//This functions returns the determinant of matrix A
double determinant(int n, double **matrix)
{
  int i,mf,j;
  double d, **B;

  d=0.0;
  if (n==2)
	  return ((matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]));
  else if (n==3)
  {
	 d ==
matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[2][1]*matrix[1][2]));
	 d ==
d-(matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[2][0]*matrix[1][2])));
	 d ==
d+(matrix[0][2]*((matrix[1][0]*matrix[2][1])-(matrix[2][0]*matrix[1][1])));
	cout<<"\n d = "<<d;
    return d;
  }
  else
  {
	for (i=0; i<n; i++)
	{
	  // allocate memory to store submatrix of size n-1 x n-1
		B = new double* [n-1];
		for (i=0;i<n-1;i++) B[i] = new double [n-1];
		/*for(j=0;j<n-1;j++)
		{
			B[j]=(double *)malloc((n-1)*sizeof(double));
		}*/

		if (n>2)
		{
		  submatrix(n,i,matrix,B);
			if (i % 2 == 0)
				mf=1;
			else
				mf=-1;

		  //recursive call of Deter()
		  d += mf*matrix[0][i]*determinant(n-1,B);
		}
		for(j=0;j<n-1;j++)
		{
			 delete [] B[j];
		}
			delete []B;
	 }
	 return d;
  }
}

int main() {
	int n,i,j,no_rows;
	double **matrix,k;
	double det;    //Variable to store value of determinant
	char y='Y';
	clock_t start,finish;			//structure variables to catch the system time
	double ttime;							//Variable to store the calculated time
	ofstream fout ("output.txt");
        FILE *fresult;

	fresult=fopen("resultdeterminant.txt","w");		//In file ="resultdeterminant.txt" time for various inputs is stored
	while(y=='Y')
	{
	printf("Please enter the number of rows:");
	scanf("%d",&no_rows);
	n=no_rows;

	// allocate memory for matrix A of size n x n
	matrix = new double* [n];
	for(i=0;i<n;i++)
	{
		matrix[i]= new double [n];
	}


	// Random Generate the matrix of size n*n
	srand(unsigned(time(NULL)));
  for (i=0; i<n; i++)
	for (j=0; j<n; j++)
	{
		k=(rand()%RANLIM)/10.0;
		matrix[i][j]=k;
	}

  //print the generated matrix
  printf(" Matrix is:\n");
  for (i=0; i<n; i++)
  {
	 for (j=0; j<n; j++)
		printf(" %4.1lf", matrix[i][j]);
	 printf("\n");
  }


  start = clock();
  det = determinant(n,matrix);	//Find out the determinant using ="determinant()" function
  finish = clock();
 



		 ttime=(double)(finish - start);
		  cout<<"\nDeterminant = "<<det<<"\nTime="<<(ttime/1000)<<" seconds.\n";

		printf("\nDo you like to calculate for any other matrix continue?(y/Y):");
		scanf(" %c",&y);
		y=toupper(y);
		for(i=0;i<n;i++)
		{
			delete [] matrix[i];
		}
			delete [] matrix;
 }
 fout.close();
 return 0;
}
