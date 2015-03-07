/* UVa problem: 10354
 *
 * Topic: Graph Algorithms
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   find all shortest paths and then remove vertecies they use
 *
 * Solution Summary:
 *
 *   Floyd Warshall then find all the points along the graph that would equal
 *	 The shortest path.
 *
 * Used Resources:
 *
 *   
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 102;
const int INT_MAX = 200;

int P,R,BH,OF,YH,M;

int adj_mat_b[MAX_N][MAX_N];
int adj_mat_y[MAX_N][MAX_N];
bool on_a_path[MAX_N];

void read_input();
void zero_arrays();
void fw_boss();
void fw_yours();
void killBP();

int main() {
	cin >> ws;
	while (! cin.eof() ) {
		zero_arrays();
		read_input();
		fw_boss();
		killBP();
		fw_yours();

		if (adj_mat_y[YH][M] != INT_MAX && !on_a_path[YH] && !on_a_path[M]) {
			cout << adj_mat_y[YH][M] << endl;
		} else {
			cout << "MISSION IMPOSSIBLE." << endl;
		}
		cin >> ws;
	}
	return 0;
}

void read_input() {
	cin >> P >> R >> BH >> OF >> YH >> M;
	for (int i = 0; i < R; ++i) {
		int t1,t2,t3;
		cin >> t1 >> t2 >> t3;
		if (t1 != t2) {
			adj_mat_b[t1][t2] = t3;
			adj_mat_b[t2][t1] = t3;
			adj_mat_y[t1][t2] = t3;
			adj_mat_y[t2][t1] = t3;
		}
	}
}

void zero_arrays() {
	for (int i = 0; i < MAX_N; ++i ) {
		for (int j = 0; j < MAX_N; ++j ) {
			adj_mat_b[i][j] = INT_MAX;
			adj_mat_y[i][j] = INT_MAX;
		}
		adj_mat_b[i][i] = 0;
		adj_mat_y[i][i] = 0;
		on_a_path[i] = false;
	}
}

void fw_boss() {
	for (int k = 1; k <= P; ++k ) {
	for (int i = 1; i <= P; ++i ) {
	for (int j = 1; j <= P; ++j ) {
		adj_mat_b[i][j] = min(adj_mat_b[i][j], adj_mat_b[i][k] + adj_mat_b[j][k]);
	}}}
}

void fw_yours() {
	for (int k = 1; k <= P; ++k ) { if (!on_a_path[k]) {
	for (int i = 1; i <= P; ++i ) { if (!on_a_path[i]) {
	for (int j = 1; j <= P; ++j ) { if (!on_a_path[j]) {
		adj_mat_y[i][j] = min(adj_mat_y[i][j], adj_mat_y[i][k] + adj_mat_y[j][k]);
	}}}}}}
}

void killBP() {
	for (int k = 0; k <= P; ++k ) {
		if (adj_mat_b[BH][k] + adj_mat_b[k][OF] == adj_mat_b[BH][OF] ) {
			on_a_path[k] = true;
		}
	}
}
