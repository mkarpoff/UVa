/* UVa problem: 12646
 *
 * Topic: Other
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Find the odd man out
 *
 * Solution Summary:
 *
 *   Represent the numbers as first is 0|3 0|4 0|5 from the sum we know exactly 
 *	 which is the odd man out
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
	int a,b,c,sum;
	while (!cin.eof()) {
		cin >> a >> ws >> b >> ws >> c >> ws;
		sum = a*3 + b*4 + c*5;
		switch (sum) {
			case 3: cout << 'A' << endl; break;
			case 4: cout << 'B' << endl; break;
			case 5: cout << 'C' << endl; break;
			case 7: cout << 'C' << endl; break;
			case 8: cout << 'B' << endl; break;
			case 9: cout << 'A' << endl; break;
			default: cout << '*' << endl; break;
		}
	}
	return 0;
}
