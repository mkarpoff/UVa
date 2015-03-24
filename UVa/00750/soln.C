/* UVa problem: 00750
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   N-Queens with a set spot that on queen must be on
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
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <vector>
#include <bitset>

using namespace std;

struct S {
	int v[8];
};

bitset<20> rw, ld, rd;
bool board[8][8];
S cursol;
vector<S> sols;

bool cmp(const S a, const S b) {
	for (int i = 0; i < 8; ++i) {
		if ( a.v[i] == b.v[i]) continue;
		return a.v[i] < b.v[i];
	}
}

void dfs(int c) {
	if (c == 8) {sols.push_back(cursol);/* add to list */ return; }
	for (int r = 0; r < 8; ++r) {
		if (board[r][c] && !rw[r] && !ld[r-c+7] && !rd[r+c]) {
			rw[r] = ld[r-c+7] = rd[r+c] = true;
			cursol.v[r] = c;
			dfs(c+1);
			rw[r] = ld[r-c+7] = rd[r+c] = false;
}	} }

int main() {
	int tests;
	cin >> tests;
	while(tests) {
		rw.reset(); ld.reset(); rd.reset();
		memset(board, true, sizeof(board[0][0]) * 8 * 8);
		sols.clear();
		int x, y;
		cin >> x >> y;
		--x;--y;
		for (int i = 0; i < 8; ++i) {
			board[i][x] = false;
			board[y][i] = false;
		}
		board[y][x] = true;
		dfs(0);
		cout << "SOLN       COLUMN" << endl << " #      1 2 3 4 5 6 7 8" << endl;
		cout << endl;
		sort(sols.begin(), sols.end(), cmp);
		int s = sols.size();
		for (int i = 0; i < s; ++i) {
			cout << setw(2) << i+1 << "     ";
			for (int j = 0; j < 8; ++j) cout << " " << sols[i].v[j]+1;
			cout << endl;
		}
		if (--tests) cout << endl;
	}
	return 0;
}
