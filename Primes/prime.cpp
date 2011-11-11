#include<iostream>
using namespace std;

int main(){
  long long num;
  bool prime;

  cout << "Please enter a positive integer" << endl;
  cin >> num;

  for(int i = 3; i <= num; i++){
    prime = true;
    for(int n = 2; n <= i - 1; n++){
      if(i % n == 0){
        prime = false;
      }
    }
    if(prime){
     if(num%i==0)
     {    
          cout << i << "   "<< (num/i) << "   "<<i+(num/i)<< endl;
          return 0;
     }
    }
  }

  return 0;
}
