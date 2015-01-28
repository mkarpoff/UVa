/* UVa problem: 10000
 *
 * Topic: Graph theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   Find longest path in a DAG
 *
 * Solution Summary:
 *
 *   Originally tried DFS using through all podential paths. -- VERY BAD
 *	 Then Used Floyd-Warshall. -- Much better
 *
 * Used Resources:
 *
 *   Text book a lot
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cstring>
#include <utility>
static const int INF = -1;

using namespace std;

void floyd_warshall(int size, int start);
void print(int casenum, int size, int start);
void reset_adj(int size);

int adj[100][100];

int main() {
	int size = 0, cnum = 1, start, p, q;
	cin >> size >> ws;
	while(size) {
		cin >> start >> ws;
		reset_adj(size);
		cin >> p >> ws >> q >> ws;
		while (p || q) {
			adj[p-1][q-1] = 1;
			cin >> p >> ws >> q >> ws;
		}
		floyd_warshall( size, start );
		print( cnum, size, start);
		cnum++;
		cin >> size >> ws;
	} 
	return 0;
}

void floyd_warshall(int size, int start) {
	for (int k = 0; k < size; ++k) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (adj[i][k] != INF && adj[k][j] != INF )
					adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

void print(int casenum, int size, int start) {
	int mx = 0, end = 0;
	for( int i = 0; i < size; ++i) {
		int t = adj[start-1][i];
		if (t != size && i+1 != start) {
			if ( t > mx) {
				end = i+1;
				mx = t;
			}
		}
	}
	cout << "Case " << casenum;
	cout << ": The longest path from " << start << " has length " << mx;
	cout << ", finishing at " << end << ".\n\n";
}

void reset_adj(int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			adj[i][j] = INF;
		}
		adj[i][i] = 0;
	}
}
