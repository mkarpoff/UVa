/* UVa problem: 00103
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   box nesting in up to 10 dimensions
 *
 * Solution Summary:
 *
 *   Recursive DP soln
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
#include <algorithm>
#include <list>

using namespace std;

typedef list<int> CONT;

int box[35][10];

bool doesFit(int out, int in, int D) {
	if (out == in) return false;
	for (int i = 0; i < D; ++i) {
		if (box[out][i] <= box[in][i]) return false;
	} return true;
}

CONT rec(int cur, int N, int D) {
	CONT r;
	for (int i = 0; i < N; ++i) {
		if (doesFit(cur, i, D)) {
			CONT t = rec(i, N, D);
			if (t.size() > r.size()) r = t;
		}
	}
	r.push_back(cur);
	return r;
}

int main() {
	int N, D;
	cin >> ws;
	while( !cin.eof() ) {
		cin >> N >> D >> ws;
		for (int i = 0; i < N; ++i) {
		for (int j = 0; j < D; ++j) {
			cin >> box[i][j];
		}
		sort(box[i], box[i] + D);
		}
		CONT b_list;
		for (int i = 0; i < N; ++i) {
			CONT t_list = rec(i, N, D);
			if (t_list.size() > b_list.size()) b_list = t_list;
		}
		cout << b_list.size() << endl;
		bool f = false;
		for (auto i: b_list) {
			if (f) cout << " ";
			cout << i+1;
			f = true;
		}
		cout << endl;
		cin >> ws;
	}
	return 0;
}
