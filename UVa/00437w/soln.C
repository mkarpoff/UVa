/* UVa problem: 00437
 *
 * Topic: Graph Traversal
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   http://uva.onlinejudge.org/external/4/437.pdf
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
using namespace std;

const static int V = 60;
int zero_up = 0;
int two_up = 30;

int case_num = 1;
int block[3][30];
int adj_mat[V][V];

int main() {
	int lines = 0 , i =0;
	cin >> ws >> lines >> ws;

	
	while (lines != 0) {
	for (int i = 0; i < V; ++i) {
		for (int k = 0; k < V; ++k) {
			adj_mat[i][k] = -1;
		}
	}
		for (int i = 0; i < lines; ++i) {
			int f,s,t;
			cin >> f >> s >> t;
			if ( f > s ) {
				if ( f > t ) {
					block[0][i] = f;
					block[1][i] = max(s, t);
					block[2][i] = min(s, t);
				} else {
					block[0][i] = t;
					block[1][i] = f;
					block[2][i] = s;
				}
			} else {
				if ( s > t ) {
					block[0][i] = s;
					block[1][i] = max(f, t);
					block[2][i] = min(f, t);
				} else {
					block[0][i] = t;
					block[1][i] = s;
					block[2][i] = f;
				}
			}
		}
		for (int i = 0; i < lines; ++i) {
			for (int k = 0; k < lines; ++k) {
				if ( block[1][k] > block[0][i] && block[2][k] > block[1][i]) {
					adj_mat[k+zero_up][i+two_up] = block[0][k];
				}
				if ( block[0][k] > block[0][i] && block[1][k] > block[1][i]) {
					adj_mat[k+two_up][i+two_up] = block[2][k];
				}
				if ( block[0][k] > block[1][i] && block[1][k] > block[2][i]) {
					adj_mat[k+two_up][i+zero_up] = block[0][k];
				}
				if ( block[1][i] > block[0][k] && block[2][i] > block[1][k]) {
					adj_mat[i+zero_up][k+two_up] = block[0][i];
				}
				if ( block[0][i] > block[0][k] && block[1][i] > block[1][k]) {
					adj_mat[i+two_up][k+two_up] = block[2][i];
				}
				if ( block[0][i] > block[1][k] && block[1][i] > block[2][k]) {
					adj_mat[i+two_up][k+zero_up] = block[0][i];
				}
			}
		}

		for (int k = 0; k < V; ++k) {
			for (int i = 0; i < V; ++i) {
				for (int j = 0; j < V; ++j) {
					if (adj_mat[i][k] != -1 && adj_mat[k][j] != -1) {
						adj_mat[i][j] = max(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
					}
				}
			}
		}
		int max_num = -1;
		int max_start;
		int		max_end;
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				int last_block;
				if (j/30 == zero_up) {
					last_block = block[2][j%30];
				} else {
					last_block = block[0][j%30];
				}
//				max_num = max(max_num, adj_mat[i][j]);// + last_block);
				if (max_num < adj_mat[i][j] + last_block) {
					max_start = i;
					max_end = j;
				}
				max_num = max(max_num, adj_mat[i][j] + last_block);
				adj_mat[i][j] += last_block;
			}
		}
		int last_block, last_block2;
		if (max_start/30 == zero_up) {
			last_block = block[2][max_start%30];
		} else {
			last_block = block[0][max_start%30];
		}
		if (max_end/30 == zero_up) {
			last_block2 = block[2][max_end%30];
		} else {
			last_block2 = block[0][max_end%30];
		}
		for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if( adj_mat[i][j] == -1 ) {
				cout << "- ";
			} else {
				cout << adj_mat[i][j] << " ";
			}
		}
		cout << endl;
		}
		cout << "Case " << case_num++ << ": maximum height = " << max_num  << endl;
		/* solve */
		cin >> lines;
	}
	return 0;
}
