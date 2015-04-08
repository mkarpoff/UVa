/* UVa problem: <number>
 *
 * Topic: <topic>
 *
 * Level: trivial/non-trivial
 * 
 * Brief problem description: 
 *
 *   Find the number of combinations that can be made from a bunch of articles
 *	 of clothing
 *
 * Solution Summary:
 *
 *   Straight forward
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
	int a,b,c,d,e;
	cin >> a >> b >> c >> d >> e;
	while(a or b or c or d or e) {
		cout << a*b*c*d*d*e*e << endl;
		cin >> a >> b >> c >> d >> e;
	}
	return 0;
}
