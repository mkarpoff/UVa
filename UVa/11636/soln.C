/* UVa problem: 11636
 *
 * Topic: Arithmetics
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Calculate the minimum number of copy pasts it would take to duplicate
 *	something N times
 *
 * Solution Summary:
 *
 *   Ceiling of log(N)
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
#include <cmath>
using namespace std;

int main() {
	int n, cases = 1;
	while(true) {
		cin >> n;
		if (n < 0) return 0;
		int ret = 0;
		int s = 1;
		while (s < n) { ++ret; s <<=1; }
		cout << "Case " << cases++ << ": " << ret << endl;
	}
	return 1;
}
