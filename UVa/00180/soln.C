/* UVa problem: 00180
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Josephesus inverse problem with a range
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
#include <vector>
#include <list>

using namespace std;

const int CMAX = 1000000;
int lookup[CMAX];
const int K = 15;

int main() {
	memset(lookup, -1, sizeof(lookup[0]) * CMAX);
	lookup[0] = 1;
	for (int i = 1; i < CMAX;++i) lookup[i] = (lookup[i-1]+K) %i;
	int MIN, MAX;
	cin >> MIN >> MAX;
	while (MIN && MAX) {
		list<int> ns;
		for (int j = MIN; j <= MAX; ++j) {
			int x = lookup[j];
			cout << x << " " << j-x << endl;
			ns.push_back(x+1);
			ns.push_back(j-1-x);
		}
		ns.sort();
		ns.unique();
		bool found = false;
		int i = 0;
		auto j = ns.begin();
		while (j != ns.end() && i < MAX) {
			bool f = false;
			cout << i << " ";
			if (j != ns.end()) {
				
			//	cout << *j << " ";
				if (i == *j) { 
					cout << *j << " ";
					f = true;
					++j;
				} else { cout << "* "; }
			}
			cout << endl;
			++i;
		}
		cout << MAX-1 << endl;
		if (! found ) cout << "Better estimate needed" << endl;
		cin >> MIN >> MAX;
	}
	return 0;
}
