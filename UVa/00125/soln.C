/* UVa problem: 00125
 *
 * Topic: Graph Traversal
 *
 * Level: non-trivial
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

using namespace std;

const int INF = -1;
const int MAX_N = 30;

int adj_mat[MAX_N][MAX_N];
int test = 0, P, l_seen;

void print();

int main() {
	cin >> ws;
	while (!cin.eof()) {
		for (int i = 0; i < MAX_N; ++i) {
			memset(adj_mat[i], 0, MAX_N * sizeof(adj_mat[i][0]));
		}
		l_seen = 0, P = 0;
		cin >> P >> ws;
		for( int i = 0; i < P; ++i) {
			int t1,t2;
			cin >> t1 >> t2 >> ws;
			l_seen = max(l_seen,max(t1,t2));
			adj_mat[t1][t2] = 1;
		}
		l_seen++;
		for (int k = 0; k < l_seen; ++k) {
		for (int i = 0; i < l_seen; ++i) {
		for (int j = 0; j < l_seen; ++j) {
			adj_mat[i][j] = adj_mat[i][j] + adj_mat[i][k] * adj_mat[k][j];
		}}}


		cout << "matrix for city " << test++ << endl;
		print();
	}
		return 0;
}
void print() {
	for (int i = 0; i < l_seen; ++i) {
	for (int j = 0; j < l_seen; ++j) {
		if (adj_mat[i][j] > P) {
			cout << "-1";
		} else {
			cout << adj_mat[i][j];
		}
		if (j != l_seen-1) {
			cout << " ";
		} else {
			cout << endl;
		}
	 }}
}
