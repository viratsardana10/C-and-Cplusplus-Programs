
#include <stdio.h>
int main() {
    unsigned int dig[10000], first=0, last=0, carry, n, x, sum=0;
    dig[0] = 1;    
    for(n=2; n <= 3249; n++) {
        carry = 0;
        for(x=first; x <= last; x++) {
            carry = dig[x]*n + carry;
            dig[x] = carry%100000;
            if(x == first && !(carry%100000)) first++;
            carry /= 100000; }
        if(carry) dig[++last] = carry; }
    for(x=first; x <= last; x++)
        sum += dig[x]%10 + (dig[x]/10)%10 + (dig[x]/100)%10 + (dig[x]/1000)%10
            + (dig[x]/10000)%10;
    printf("Sum: %d\n",sum); }

