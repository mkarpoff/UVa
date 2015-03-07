/* UVa problem: 00125
 *
 * Topic: Graph Traversal
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   count number of paths from one point to any other and then print graph 
 *
 * Solution Summary:
 *
 *   Floyd Warshall (Small graph) 
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

const int MAX_N = 30;

int adj_mat[MAX_N][MAX_N];
int test = 0, P, l_seen;

void final_print();

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
			if (adj_mat[i][k] && adj_mat[k][j])
				adj_mat[i][j] += adj_mat[i][k] * adj_mat[k][j];
		}}}

		for (int k = 0; k < l_seen; ++k) {
		if (adj_mat[k][k]) {
		for (int i = 0; i < l_seen; ++i) { 
		for (int j = 0; j < l_seen; ++j) {
		if (adj_mat[i][k] && adj_mat[k][j]) {
			adj_mat[i][j] = -1;
		}}}}}

		cout << "matrix for city " << test++ << endl;
		final_print();
	}
		return 0;
}

void final_print() {
	for (int i = 0; i < l_seen; ++i) {
	for (int j = 0; j < l_seen; ++j) {
			cout << adj_mat[i][j];
		if (j != l_seen-1) {
			cout << " ";
		} else {
			cout << endl;
		}
	 }}
}
