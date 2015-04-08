/* UVa problem: 10452
 *
 * Topic: Backtracking
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *  There is a specific path that must be followed yo must translate this path
 *	into a series of directions.
 *
 * Solution Summary:
 *
 *  originally I did DP but realized that recursion was very unnecisary because
 *	IEHOVA# is the path
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
#include <string>
#include <list>

using namespace std;

short map[10][10];

short spot_type(char c) {
	switch (c) {
	case 'I': return 2;
	case 'E': return 3;
	case 'H': return 4;
	case 'O': return 5;
	case 'V': return 6;
	case 'A': return 7;
	case '#': return 8;
	case '@': return 1; // Indy's start
	default: return 0;
} }

int main() {
	int tests, N, M, s_i, s_j;
	cin >> tests;
	while (tests--) {
		list<string> path;
		memset(map, 0, sizeof(map[0][0]) * 10 *10);
		cin >> M >> N >> ws;
		for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			char s;
			cin >> s;
			map[i][j] = spot_type(s);
			if (map[i][j] == 1) { s_i = i; s_j = j; }
		}	}
		for (int i = 2; i <= 8; ++i) {
			if (map[s_i-1][s_j] == i) {	--s_i; path.push_back("forth");	}
			else if (map[s_i][s_j+1] == i) {	++s_j; path.push_back("right");	}
			else if (map[s_i][s_j-1] == i) { --s_j; path.push_back("left");  }
			path.push_back(" ");
		}
		path.pop_back();
		for(auto s: path) {
			cout << s;
		} cout << endl;
	}
	return 0;
}

