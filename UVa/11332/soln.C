/* UVa problem: 11332
 *
 * Topic: Dynamic Programming
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   calculate the sum of the digits in a number until the number is a single
 *	 digit
 *
 * Solution Summary:
 *
 *   Recursion. Won't go very deap beacuse at most the number of digits will
 *	 stay the same
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>

using namespace std;

typedef long long ll;

ll rec(ll n) {
	ll s = 0;
	while (n) {
		s += n%10;
		n /= 10;
	}
	if (s >= 10) return rec(s);
	return s;
}

int main() {
	ll orig;
	cin >> orig;
	while(orig) {
		cout << rec(orig) << endl;
		cin >> orig;
	}
	return 0;
}
