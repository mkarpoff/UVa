/* UVa problem: 00599
 *
 * Topic: Data Structures and Libraries
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Count number of trees of size 2 or more and lone nodes
 *
 * Solution Summary:
 *
 *   Used Adjacency matrix because the size is 26x26 max
 *
 * Used Resources:
 *
 *   None
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
#include <set>

using namespace std;

const int A = (int) 'A';
bool adjmat[26][26];
vector<int> convec;
int trees;
int cones;


int main() {
	int cases = 0;
	cin >> cases >> ws;
	while(cases--) {	
		trees = 0;
		cones = 0;
		memset(adjmat, false, sizeof(bool) * 26 * 26);
		convec.clear();
		while(cin.peek() != '*' && cin.peek() != EOF ) {
			string t;
			cin >> t >> ws;
			int a,b;
			bool f1 = false;
			for ( char c: t) {
				if (!isalpha(c) ) {;
				} else if (f1) {
					a = ((int) c) - A;
				} else {
					b = ((int) c) - A;
					f1 = true;
				}
			}
			if (a != b) {
				adjmat[a][b] = true;
				adjmat[b][a] = true;
			}
		}
		while(cin.peek() == '*') {
			char g;
			cin >> g >> ws;
		}
		string points;
		cin >> points >> ws;
		for (char c: points) {
			if (isalpha(c)) {
				int i = ((int) c) - ((int) 'A');
				convec.push_back(i);
			}
		}

		/* Flood fill */
		for( auto s: convec) {
			if ( ! adjmat[s][s]) {
				set<int> openset;		
				openset.insert(s);
				int found = 0;
				while(!openset.empty()) {
					int cur = *openset.begin();
					openset.erase(cur);
					adjmat[cur][cur] = true;
					for(int i = 0; i < 26; ++i ) {
						if (adjmat[cur][i] && ! adjmat[i][i]) {
							++found;
							openset.insert(i);
						}
					}
				}
				if(!found) {
					++cones;
				} else {
					++trees;
				}
			}
		}
		cout << "There are " << trees << " tree(s) and " << cones << " acorn(s)." << endl;
	}
	return 0;
}
