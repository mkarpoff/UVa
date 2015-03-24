/* UVa problem: 11195
 *
 * Topic: Backtracking
 *
 * Level: trivial/non-trivial
 * 
 * Brief problem description: 
 *
 *  N-Queens problem up to 15x15 with bad tile spots
 *
 * Solution Summary:
 *
 *  most of this code is right out of the book
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
#include <bitset>

using namespace std;

const int OK[] = {0,0,0,0,(1<<4)-1,(1<<5)-1,(1<<6)-1,(1<<7)-1,(1<<8)-1,(1<<9)-1,
	(1<<10)-1,(1<<11)-1,(1<<12)-1,(1<<13)-1,(1<<14)-1};


int board[15];
int N, sol;

void dfs(int row, int rw, int ld, int rd) {
	if (rw == OK[N]) { sol++; return; }
	int pos = OK[N] & (~board[row] & ~(rw|ld|rd));
	while (pos) {
		int p = pos & -pos;
		pos -= p;
		dfs(row+1, rw|p, (ld|p) << 1, (rd|p)>>1);
	}
}

int main() {
	int tests = 0;
	cin >> N;
	while (N) {
		sol = 0;
		for (int i = 0; i < N; ++i) {
		board[i] = OK[N];
		for (int j = 0; j < N; ++j) {
			char c;
			cin >> c;
			board[i] ^= (c == '*'? 0:1)<<j;
		} }
		dfs(0,0,0,0);
		cout << "Case " << ++tests << ": " << sol<< endl;
		cin >> N;
	}
	return 0;
}
