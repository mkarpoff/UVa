/* UVa problem: 10038
 *
 * Topic: Data Structures and Libraries
 *
 * Level: trivial
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
#include <sstream>
#include <string>

using namespace std;

bool isFound[3000] = { false };

int main() {
	int cur, last, size;
	
	while(true) {
		string line;
		getline(cin, line);
		if (line.length() == 0) {
			return 0;
		}
		cin >> ws;
#ifdef DEBUG
		cout << line << endl;
#endif
		istringstream iss(line);
		iss >> ws >> size >> ws;
		if (size <= 1) {
		 cout << "Jolly" << endl;
		} else {
			for( int i =0; i < size-1; ++i) {
				isFound[i] = false;
			}
			iss >> last >> ws;
			for (int i = 0; i < size-1; ++i) {
				iss >> cur >> ws;
				int j = abs(cur - last);
#ifdef DEBUG
				cout << " last: " << last << "cur: " << cur << " diff: " << j << endl;
#endif
				if (j < size) {
					isFound[j-1] = true;
				} 
				last = cur;
			}
			bool allTrue = true;
			for (int i = 0; i < size-1; ++i ) {
				if (!	isFound[i]) {
					allTrue = allTrue && isFound[i];
				}
			}
			if (allTrue) {
				cout << "Jolly" << endl;
			} else {
				cout << "Not jolly" << endl;
			}
		}
	}
	return 0;
}
