

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
  int i,j,flag=3D0;

  if (n<3) return;
  for (i=3D0; i<n-1; i++)
  {
	 flag=3D0;
	 for (j=3D0; j<n-1; j++)
	 {
		 if (j!=3Dcol)
		 {
			 if (flag=3D=3D1)
			 {	 B[i][j]=3Dmatrix[i+1][j+1];  		 }
			 else
			 {  B[i][j]=3Dmatrix[i+1][j];         }
		 }
		 else
		 {
			 flag=3D1;
			 B[i][j]=3Dmatrix[i+1][j+1];
		 }
	  }
	}
}

//This functions returns the determinant of matrix A
double determinant(int n, double **matrix)
{
  int i,mf,j;
  double d, **B;

  d=3D0.0;
  if (n=3D=3D2)
	  return ((matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]));
  else if (n=3D=3D3)
  {
	 d =3D =
matrix[0][0]*((matrix[1][1]*matrix[2][2])-(matrix[2][1]*matrix[1][2]));
	 d =3D =
d-(matrix[0][1]*((matrix[1][0]*matrix[2][2])-(matrix[2][0]*matrix[1][2]))=
);
	 d =3D =
d+(matrix[0][2]*((matrix[1][0]*matrix[2][1])-(matrix[2][0]*matrix[1][1]))=
);
	cout<<"\n d =3D "<<d;=20
    return d;
  }
  else
  {
	for (i=3D0; i<n; i++)
	{
	  // allocate memory to store submatrix of size n-1 x n-1
		B =3D new double* [n-1];
		for (i=3D0;i<n-1;i++) B[i] =3D new double [n-1];
		/*for(j=3D0;j<n-1;j++)
		{
			B[j]=3D(double *)malloc((n-1)*sizeof(double));
		}*/

		if (n>2)
		{
		  submatrix(n,i,matrix,B);
			if (i % 2 =3D=3D 0)
				mf=3D1;
			else
				mf=3D-1;

		  //recursive call of Deter()
		  d +=3D mf*matrix[0][i]*determinant(n-1,B);
		}
		for(j=3D0;j<n-1;j++)
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
	char y=3D'Y';
	clock_t start,finish;			//structure variables to catch the system time
	double ttime;							//Variable to store the calculated time
	ofstream fout ("output.txt");=09
  //FILE *fresult;

	//fresult=3Dfopen("resultdeterminant.txt","w");		//In file =
"resultdeterminant.txt" time for various inputs is stored
	while(y=3D=3D'Y')
	{
	printf("Please enter the number of rows:");
	scanf("%d",&no_rows);
	n=3Dno_rows;

	// allocate memory for matrix A of size n x n
	matrix =3D new double* [n];
	for(i=3D0;i<n;i++)
	{
		matrix[i]=3D new double [n];
	}


	// Random Generate the matrix of size n*n
	srand(unsigned(time(NULL)));
  for (i=3D0; i<n; i++)
	for (j=3D0; j<n; j++)
	{
		k=3D(rand()%RANLIM)/10.0;
		matrix[i][j]=3Dk;
	}

  //print the generated matrix
  printf(" Matrix is:\n");
  for (i=3D0; i<n; i++)
  {
	 for (j=3D0; j<n; j++)
		printf(" %4.1lf", matrix[i][j]);
	 printf("\n");
  }


  start =3D clock();
  det =3D determinant(n,matrix);	//Find out the determinant using =
"determinant()" function
  finish =3D clock();
 =20



		 ttime=3D(double)(finish - start);
		  cout<<"\nDeterminant =3D "<<det<<"\nTime=3D"<<ttime<<'\n';

		printf("\nDo you like to calculate for any other matrix =
continue?(y/Y):");
		scanf(" %c",&y);
		y=3Dtoupper(y);
		for(i=3D0;i<n;i++)
		{
			delete [] matrix[i];
		}
			delete [] matrix;
 }
 fout.close();
 return 0;
}
