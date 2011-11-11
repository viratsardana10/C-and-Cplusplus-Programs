#include <iostream>
using namespace std;
int FactCount(int );

 int main()

{
	int input;
	cout << "Enter Number to be factored:\n";
        cin  >> input;
		FactCount(input);
return 0;
}            			

	

	                     
	int FactCount(int nLoopCount){
	int nFirst;					
	if(nLoopCount > 1000000){	//prevent long loop count
	   nLoopCount = 0;
	cout << "Number to be factored must be less than 1000000:\n";
	}
		
     for (int j=2; j <= nLoopCount; j++){   //loops through int and stops a point set by nLoopCount
		for (int i=2; i <=nLoopCount; i++){  //loops through the other number in the factors
	     nFirst = j*i;                       //multiplies the 2 numbers together nLoopCount times

		if(nFirst > 1000000)
			break;
		
		if(nFirst == nLoopCount){ //sort out the numbers we want
		
		
		cout << j <<" * "<< i <<"  =  "<< nFirst << "  sum of factors =   "<< j+i <<
		"  difference of factors =  " << j-i << " , " << i-j << "\n"; //display result
	
	if(j < i)
	break;
	return 0;
			
	}
	}
    }
	}

