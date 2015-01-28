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
#include <utility>

using namespace std;

void solve(int size, int start);
void print(int casenum, int size, int start);
void print_graph(int size);
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
		solve( size, start );
		print( cnum, size, start);
		cnum++;
		cin >> size >> ws;
	} 
	return 0;
}

void solve(int size, int start) {
	print_graph(size);
	for (int k = 0; k < size; ++k) {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
	//			if ( adj[i][k] < size && size >  adj[k][j])
					adj[i][j] = max(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	print_graph(size);
}

void print(int casenum, int size, int start) {
	print_graph(size);
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
			adj[i][j] = size;
		}
		adj[i][i] = 0;
	}
}

void print_graph(int maxsize) {
	return;
	cout << "   ";
	for (int i = 0; i < maxsize; ++i) {
		cout << i << ' ';
	}
	cout << endl;
	for (int j = 0; j < maxsize; ++j ){
		cout << j << ": ";
		for (int i = 0; i < maxsize; ++i ){
			cout << adj[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
