/* UVa problem: 11362
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   Algorithmic idea, data structures ...
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
#include <cstring>

using namespace std;

typedef unsigned long long int ll;

int memo[10000];

ll recsum(ll n) {
	if (n >= 10000) {
		return recsum(n % 10000) + recsum( n/ 10000);
	} else {
		if (memo[n] != -1) return memo[n];
	}
	int ret = 0;
	int t = n;
	while (t > 0) {
		ret += t %10;
		t /= 10;
	}
	memo[n] = ret;
	return memo[n];
}

bool is_sum_div(ll n, ll k) {
	return recsum(n) % k == 0;
}

int main() {
	memset(memo, -1, sizeof(memo[0]) * 10000);
	
	int tests;
	cin >> tests;
	while(tests--) {
		ll A, B, k;
		cin >> A >> B >> k;
		ll base = A/k;
		if (k * base < A) ++base;
		ll found = 0;
		if (k == 1) {
			cout << B-A+ 1<< endl;
			continue;
		} else if (k > 83) {
			cout << 0 << endl;
			continue;
		}
		for (int i = base*k; i <= B; i+=k) {
			if (is_sum_div(i, k)) ++found;
		}
		cout << found << endl;
	}
}
