/* UVa problem: 100
 *
 * Topic: <topic>
 *
 * Level: trivial/non-trivial
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
#include <string>
#include <sstream>

using namespace std;

int alg(int n);

int main() {
	string line;
	getline(cin, line);
	while (! line.empty()) {
		int l, j, max = 0;
		istringstream iss(line);
		iss >> l;
		iss >> j;
		
		for(int i = l; i <= j; ++i) {
				int t =	alg(i);
				max =  t> max? t: max;
		}
		cout << l << ' ' << j << ' ' << max << endl;
		getline(cin, line);
	}	
	return 0;
}

int alg(int n) {
	int c = 1;
	while  (n != 1) {
		if (n % 2) { n = 3*n + 1; }
		else {n /= 2;}
		++c;
	}
	return c;
}
