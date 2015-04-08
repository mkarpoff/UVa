/* UVa problem: 11955
 *
 * Topic: Arithmetic
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Calculate Binomial sums up to exponent is 50
 *
 * Solution Summary:
 *
 *   This is straigh forward
 *
 * Used Resources:
 *
 *   http://en.wikipedia.org/wiki/Binomial_theorem
 *	 http://en.wikipedia.org/wiki/Binomial_coefficient
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

typedef double ll;

ll coef(int n, int k) {
	ll ret = 1;
	if (k > n - k) {	k = n - k;}
	for (int i = 0; i < k; ++i) {
		ret *= (n - i);
		ret /= (i + 1);
	}
	return ret;
}


void print(char * A, char * B, int k) {
	for (int i = 0; i <= k; ++i) {
		double c = coef(k,i);
		int pow_A = k-i, pow_B = i;
		if (i != 0 and i != k) printf("%.0f*", c);
		if (pow_A == 1) printf("%s", A);
		else if (pow_A > 1) printf("%s^%d", A,pow_A);
		if (pow_A and pow_B ) {
			printf("*");
		}
		if (pow_B == 1) printf("%s", B);
		else if (pow_B > 1) printf("%s^%d", B,pow_B);
		if (k-i) printf("+");
	}
}

int main() {
	int tests, k, cases = 1;
	int a = scanf("%d\n", &tests);
	while (tests--) {
		char _A[110],_B[110];
		memset(_A, 0, sizeof _A);
		memset(_B, 0, sizeof _B);
		a = scanf("(%[a-zA-Z]+%[a-zA-Z])^%d\n", _A, _B, &k);
		cout << "Case " << cases++ << ": ";
		print(_A,_B,k);
		cout << endl;
	}
	return 0;
}
