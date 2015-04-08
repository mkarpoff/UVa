/* UVa problem: 00374
 *
 * Topic: Number Theory
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Large pow mod
 *
 * Solution Summary:
 *
 *	Mod the intermediary parts 
 *
 * Used Resources:
 *
 *   
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

long long int B, P, M, T, out;

int main() {
	cin >> ws;
	while (!cin.eof()) {
		long long int l;
		cin >> B >> P >> M >> ws;
		T = B % M;
		out = 1;
		while (P > 0) {
			if ( P % 2) {
				out = (out * T) % M;
			}
			T = (T * T) % M;
			P = P >> 1;
		}		
		cout << (out % M) << endl;
	}
	return 0;
}
