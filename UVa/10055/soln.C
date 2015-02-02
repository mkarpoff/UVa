/* UVa problem: 10055
 *
 * Topic: Arithmetics
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   diff two numbers
 *
 * Solution Summary:
 *
 *   diff two numbers
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

int main() {
	while (!cin.eof()) {
		long long a, b;
		cin >> a >> ws >> b >>ws;	
		cout << max(a,b) - min(a,b) << endl;
	}
	return 0;
}
