/* UVa problem: 11137
 *
 * Topic: Dynamic Programming
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Coin problem with coins of value of n =1->21 n^3, find all combos
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

typedef long long ll;

ll lookup[22][10000];
int NUM_TYPES = 22;


ll rec(int type, ll value) {
	if (value == 0) return 1; // Success case
	if (value < 0 || type == NUM_TYPES) return 0; // failure case
	if (lookup[type][value] != -1) return lookup[type][value];
	lookup[type][value] = rec(type+1, value) + rec(type, value - type*type*type); 
	return lookup[type][value];
}

int main() {
	memset(lookup, -1, sizeof lookup);
	ll target;
	while (!cin.eof()) {
		cin >> target >> ws;
		cout << rec(1, target) << endl;
	}
	return 0;
}
