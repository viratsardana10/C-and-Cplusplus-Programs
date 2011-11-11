#include "AQT.h"
int main(){
    ArrayQueue<char> AQ;
    AQ.pop();
    AQ.push('a');
    AQ.push('b');
    AQ.push('c');
    AQ.push('d');
    AQ.pop();
    AQ.pop();
    AQ.pop();
    AQ.push('e');
    AQ.push('f');
    AQ.push('g');
    AQ.pop();
    AQ.pop();
    AQ.pop();
    AQ.pop();
    AQ.pop();
    AQ.pop();
    system("pause");
}    
