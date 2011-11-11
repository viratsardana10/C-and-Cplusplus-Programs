#include <iostream>
#include <cstdlib>

int main() {
unsigned long N,K,P; scanf("%lu %lu %lu",&N, &K, &P);
unsigned long sums[N+1], sum, num, prev=0;

if(K>=P || N==0) exit(1);

sums[0] = 0;
for(unsigned long i=1; i<=N; i++) {
scanf("%lu", &num);
num = num %P;
if(num > (P-prev)) {
// overflow
sum = prev -(P -num);
} else
sum = prev + num;
prev = sum;
sums[i] = sum;
}
unsigned long tmp;
unsigned long resultSum=P, resultI=0, resultJ=0;

for(unsigned long j=1; j<=N; j++) {
for(unsigned long i=1; i<=j; i++) {
unsigned long add = P -sums[i-1];

if(add > (P-sums[j])) {
// overflow
tmp = sums[j] -(P -add);
} else
tmp = add +sums[j];

if(tmp>=K && (tmp < resultSum)) {
resultSum = tmp;
resultI = i;
resultJ = j;
}
#if 0
printf("%lu: (%ld, %ld) => ", tmp, i, j);
printf("%lu: (%ld, %ld)n", resultSum, resultI, resultJ);
#endif
if(resultSum == K) break;
}
if(resultSum == K) break;
}
if(resultSum != P) printf("%lu: (%ld, %ld)n", resultSum, resultI, resultJ);

system("pause");
return 0;
}
