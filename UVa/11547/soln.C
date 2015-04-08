/* UVa problem: 11547
 *
 * Topic: Other
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Calculate a number after certain operations are performed
 *
 * Solution Summary:
 *
 *   I reduced the arithmetic operations to prevent overflow, but to be honest 
 *	 I'm just really frustrated with other problems and needed a gimme.
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

using namespace std;

int main() {
	int tests, n;
	cin >> tests;
	while (tests--) {
		cin >> n;
		cout << abs((((n*63+7492)*5-498)/10)%10) << endl;
	}
	return 0;
}
