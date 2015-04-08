/* UVa problem: <number>
 *
 * Topic: <topic>
 *
 * Level: trivial/non-trivial
 * 
 * Brief problem description: 
 *
 *   invert char order in words but not word order in a string
 *
 * Solution Summary:
 *
 *   Straightforward loop
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
#include <stack>
using namespace std;

int main() {
	stack<char> w;
	char c;
	while(cin.get(c)) {
		if (c == ' ' || c == '\n') {
			while(!w.empty()) {cout << w.top();w.pop();}
			cout << c;
		} else w.push(c);
	}
	return 0;
}
