#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>
#include <utility>

#include <ctime>

using namespace std;

// =========================================
/*
<strong class="highlight">Miller</strong> <strong class="highlight">Rabin</strong> PT
= Further enhancement by testing n using first
  7 primes(2, 3, 5, 7, 11, 13, 17, 19)
= depends on correctness of 
		Extended Riemann Hypothesis
= If N is an odd composite number then 
			the number of witnesses to the 
			compositeness of N is at least
			(N - 1) / 2.

			Example 

			1. n = 15
						(15 - 1) / 2 = 7 composite number
						4, 6, 8, 9, 10, 12, 14
			2. n  = 9
						(9 - 1) / 2 = 4 composite number
						4, 6, 8, 9
= <strong class="highlight">Test</strong> 32 bit n using 2, 7, and 61 only
		Add 3 and 5 for correctness


Algorithm Background
Let p be number to <strong class="highlight">test</strong>
x is a nontrivial square root of 1 mod p. Then:
X ^ 2 congruence 1 (mod p)
(x-1)(x+1) congruence 0 (mod p)

Since x is nontrivial, x is neither 
1 nor −1 mod p, and 
therefore both x−1 and x+1 are coprime to p

If p does not divide (x-1) or (x+1) 
	but product of(x-1)(x+1) then
	IsNotPrime
	X=1;
	X=-1;


Algorithm Steps
Let n be odd prime then n-1 is even rewrite
them as 2 ^ s * d(Odd)

Therefore, 

1)a ^ d = 1 (mod n) or 

2)a ^ 2r * d = -1 (mod n) for some 0 <= r <= s-1

If a is chosen uniformly at random and n is prime, 
these formulas hold with probability 1/4.

Fermat Little Theorem used 
to proove these two formula.

a ^ n-1 = 1 (mod n)

if Sqrt(a ^ n-1) must be either 1 or -1 == -1 
	2) true
else
	a ^ 2^0 * d 
	a^d != -1 mod(n) 
	1) true

If find a ^ d != 1 (mod n) or 
		a ^ 2r * d != -1 (mod n)
		a is a witness for the compositeness of n 



Example
n = 221

n-1 
= 221 - 1   
= 220
= 2 ^ s * d
= 2 ^ 2 * 55

Randomly select a < n

a = 174


<strong class="highlight">Test</strong> the two formula 

a ^ d = 1 (mod 221)
a ^ 2r *d = -1 (mod 221)

174 ^ 55  
= 47 not congruence to 1 (mod 221)

174 ^ 2(1) * 55
= 174 ^ 110 (mod 221)
= 220 (n-1)


Choose a = 137
137 ^ 55 (mod 221)
= 188 not congruence to 1 (mod 221)

137 ^ 2(1) * 55 (mod 221)
= 205 not congruence to -1 (mod 221)

Therefore, 221 is not prime



Solovay–Strassen primality <strong class="highlight">test</strong>




*/
// =========================================

const unsigned short NITE = 50;

//typedef unsigned long long ulong;

void Userinput(ulong&);
bool MillerRabinPrimeTest(const ulong&);
ulong ComputeModularExponentiation(const ulong&, const ulong&, const ulong&);
ulong ComputeExponentiation(const ulong&, const ulong&);

// =========================================
int main()
{
	ulong number(0);

	while (1)
	{
		cout << "\n";
		Userinput(number);
		cout << boolalpha << MillerRabinPrimeTest(number);
	}
	
	return 0;
}
// =========================================
void Userinput(ulong& number)
{
	cout << "Enter Number : ";
	cin >> number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');

		cout << "\nEnter Number : ";
		cin >> number;
	}
}
// =========================================
bool MillerRabinPrimeTest(const ulong& number)
{
	ulong a(0), x(0), y(0), tempNumber(0);
	bool IsPrime(false);
	
	tempNumber = number - 1;
	
	if (number > 2)
	{
			// Write them as 2 ^ s * d
		while (tempNumber % 2 == 0)
		{
			// tempNumber is d
			tempNumber /= 2;
		}

		for (int loop = 0;loop < NITE;++loop)
		{
			srand((unsigned int)time(0));
			// rand() % upperBound + startnumber
			 a = rand() % (number - 2) + 2;
		//	a = primeFactor[loop];
			x = ComputeModularExponentiation(a, tempNumber, number);

			y = (x * x) % number;
			if (x == 1 || y == -1)
			{
				return true;
			}
			
		}
	}

	return IsPrime;
}
// =========================================
ulong ComputeModularExponentiation(
			const ulong& a, const ulong& d, 
			const ulong& n)
{
	enum {NBITS = numeric_limits<ulong>::digits };
	string bitExponent = bitset<NBITS>((unsigned long)d).to_string(); 
	typedef string::size_type strType;
	strType MSSB = bitExponent.find_first_of('1'); 
	ulong result(a % n);

	MSSB += 1;

	while (MSSB < NBITS)
	{
		result *= result;

		if (bitExponent[MSSB] == '1')
		{
			result = result * a % n; 
		}
		++MSSB;
	}

	return result;
}
// =========================================
ulong ComputeExponentiation(const ulong& base, const ulong& exponent)
{
	enum {NBITS = numeric_limits<ulong>::digits };
	string bitExponent = bitset<NBITS>((unsigned long)exponent).to_string(); 
	typedef string::size_type strType;
	strType MSSB = bitExponent.find_first_of('1'); 
	ulong result(base);

	MSSB += 1;

	while (MSSB < NBITS)
	{
		result *= result;

		if (bitExponent[MSSB] == '1')
		{
			result *= base; 
		}
		++MSSB;
	}

	return result;
}
// =========================================



// =========================================


// =========================================



// =========================================




// =========================================


// =========================================
