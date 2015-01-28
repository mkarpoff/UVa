/* UVa problem: <number>
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
#include <cstring>
#include <numeric>
#include <utility>

using namespace std;

typedef pair<int,int> ret;

ret solve(int start);
ret dfs(int cur);

bool adj[100][100];
int size;

int main() {
	int start, cnum = 1;
	cin >> size >> ws;
	while(size) {
		cin >> start >> ws;
		ret out = solve( start );
		cout << "Case " << cnum++;
		cout << ": The longest path from " << start << " has length " << out.first;
		cout << ", finishing at " << out.second << ".\n\n";
		cin >> size >> ws;
	} 
	return 0;
}
ret solve(int start) {
	int p, q;
	cin >> p >> ws >> q >> ws;
	memset(adj, false, sizeof(false) * 100 * 100);
	while (p || q) {
		--p, --q;
		adj[p][q] = true;
		cin >> p >> ws >> q >> ws;
	}
	return dfs( start-1);
} 

ret dfs(int cur) {
	ret lgst(-1,cur + 1);
	int l = -1;
	for (int i =0; i < size; ++i) {
		if ( adj[cur][i]) {
			ret r = dfs(i);
			if (l < r.first)	{ lgst = r; l = r.first;}
		}
	}	
	++lgst.first;
	return lgst;
}
