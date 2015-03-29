/* UVa problem: 11137
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial 
 * 
 * Brief problem description: 
 *
 *   Coin problem with coins of value of 0.05,0.1,0.2,0.5,1,2,5,10,20,50,100 
 *	 find all combos
 *
 * Solution Summary:
 *
 *   Multiply target and all coin values by 20 so I'm only working with ints.
 *	 then it is the same as all coin problems. 
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

ll lookup[22][6000];
int C_TYPES[11] = {1,2,4,10,20,40,100,200,400,1000,2000};
int NUM_TYPES = 11;


ll rec(int type, ll value) {
	if (value == 0) return 1; // Success case
	if (value < 0 || type == NUM_TYPES) return 0; // failure case
	if (lookup[type][value] != -1) return lookup[type][value];
	lookup[type][value] = rec(type+1, value) + rec(type, value - C_TYPES[type]); 
	return lookup[type][value];
}

int main() {
	memset(lookup, -1, sizeof lookup);
	float target;
	cin >> target >> ws;
	while (0 != ((ll) (target*20))) {
		printf("%6.2f%17ld\n", target, rec(0, 20*target));
		cin >> target;
	}
	return 0;
}
