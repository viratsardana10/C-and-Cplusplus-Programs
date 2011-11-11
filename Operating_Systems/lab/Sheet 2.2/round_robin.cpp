
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string>
#include <math.h>
#include <cmath>
#include <sys/wait.h>

using namespace std;
#define noOfTeams 8

void rotate(int []);

int teams[] = {1, 2, 3, 4, 5, 6, 7, 8};
int noOfMatches = (noOfTeams*(noOfTeams-1))/2;

int main(){
	int j = 1;
	while(noOfMatches > 0){
		cout<<"Day: "<<j<<endl;
		for(int i = 0; i <= noOfTeams/2 - 1; i++){
			cout<<"Match between: "<<teams[i]<<", "<<teams[noOfTeams - 1 - i]<<endl;
		}
		rotate(teams);
		noOfMatches -= noOfTeams/2;
		j+=2;
	}
}

void rotate(int t[]){
	int x = t[noOfTeams - 1];
	for(int i = noOfTeams - 1; i >= 2; i--){
		t[i] = t[i - 1];
	}
	t[1] = x;
}
