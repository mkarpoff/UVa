/* UVa problem: 10003
 *
 * Topic: <topic>
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Find the minimum cutting cost where the cost is increased base off where
 *	 you cut the stick
 *
 * Solution Summary:
 *
 *  DP clean and clear
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
#include <climits>

using namespace std;

int memo[52][52];
int cuts[52];

int rec(int l, int r) {
	if (l+1 == r) return 0;
	if (memo[l][r] != -1) return memo[l][r];

	int ans = INT_MAX;
	for (int i = l + 1; i < r; ++i)
		ans = min(ans, rec(l,i) + rec(i,r) + cuts[r] - cuts[l]);
	return memo[l][r] = ans;
}

int main() {
	int l, n;
	cin >> l;
	while (l) {
		cin >> n;
		memset(memo, -1, sizeof memo);
		for(int i = 1; i <= n; ++i) {
			cin >> cuts[i];
		} cuts[n+1] = l;
		int cost = rec(0, n+1);

		cout << "The minimum cutting is " << cost << '.' << endl;

		cin >> l;
	}
	return 0;
}
