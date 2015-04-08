/* UVa problem: 10219
 *
 * Topic: Combinatorics
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   find the number of digits in the result of nCk
 *
 * Solution Summary:
 *
 *   using the method of calculating nCk without overflow
 *		 for( int i = n-k+1; i <= n; ++i) { num += i;}
 *		 for( int i = 0; i <= k; ++i) {den += i;}
 *		 nCk = num/den;
 *		 I take the intermediary log base 10s to reduce the size of the number
 *		 by using a long double for my acumulator i maintain enough decimal
 *		 accuracy at the sacrifice of time but is still within bounds
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CrPUT 403 
 * collaboration policy.
 *
 * --- rarcus Karpoff
 */
#include <iostream>
#include <cmath>

using namespace std;
typedef long double ll;

int main() {
	int n,k;
	cin >> ws;
	while(!cin.eof()) {
		cin >> n >> k;
		ll ret = 0;
		for (ll i = n-k+1; i <= n; ++i) {ret += log10(i);}
		for (ll i = 1; i <= k; ++i) {ret -= log10(i);}
		cout << (long int)ceil(ret) << endl;
		cin >> ws;
	}
	return 0;
}
