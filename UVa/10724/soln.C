/* UVa problem: 10724
 *
 * Topic: Graph Algorithms
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   Figure out the best edge to add to reduce total shortest path cost
 *
 * Solution Summary:
 *
 *   Floyd-Warshall N*logN times... I know that is O(N^5*logN) but it is good
 *   enough to not get TLE...
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
#include <tuple>
#include <cmath>

using namespace std;

typedef pair<double, double> coor;

const int MAX = 50;
const int INF = 10000;

int N, M;
double cost = 0.0;
coor pos_list[MAX];
double adj_mat[MAX][MAX];
double adj_mat_b[MAX][MAX];
double adj_mat_p[MAX][MAX];
bool has_road[MAX][MAX];

double eucl_dist(coor&, coor&);
double calc_change();
void reset();
void read_input();
void FW();
void FW_p();
void cp_mat();

int main() {
	cin >> N >> M;
	while ( N || M) {
		reset();
		read_input();
		FW();
		int rf = INF, rs = INF;
		double cur_max = 0;
		for (int i = 0; i < N; ++i ) {
		for (int j = 0; j < i; ++j ) {
		if (!has_road[i][j] && i != j) {
			cp_mat();
			adj_mat_p[i][j] = adj_mat_p[j][i] = eucl_dist(pos_list[i], pos_list[j]);
			FW_p();
			double t_ch = calc_change();
			if (t_ch > cur_max && t_ch > 1.0) {
				rf = j;
				rs = i;
				cur_max = t_ch;
			}
		}}}

		if ( rf == INF || rs == INF ) {
			cout << "No road required" << endl;
		} else {
			cout << rf+1 << " " << rs+1 << endl;
		}
		cin >> N >> M;
	}
	return 0;
}

void read_input() {
	for (int i = 0; i < N; ++i) {
		double t1, t2;
		cin >> t1 >> t2;
		pos_list[i] = make_pair(t1,t2);
	}

	for (int i = 0; i < M; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		double cost = eucl_dist(pos_list[--t1], pos_list[--t2]);
		has_road[t1][t2] = has_road[t2][t1] = true;
		adj_mat[t1][t2] = adj_mat[t2][t1] = cost;
		adj_mat_b[t1][t2] = adj_mat_b[t2][t1] = cost;
	}
}

void FW() {
	for (int k = 0; k < N; ++k ) {
	for (int i = 0; i < N; ++i ) {
	for (int j = 0; j < N; ++j ) {
		adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
	}}}
}

void FW_p() {
	for (int k = 0; k < N; ++k ) {
	for (int i = 0; i < N; ++i ) {
	for (int j = 0; j < N; ++j ) {
		adj_mat_p[i][j] = min(adj_mat_p[i][j], adj_mat_p[i][k] + adj_mat_p[k][j]);
	}}}
}

void cp_mat() {
	for (int i = 0; i < N; ++i ) {
		memcpy(adj_mat_p[i], adj_mat_b[i], N*sizeof(double));
	}
}

double calc_change() {
	double total = 0;
	for (int i = 0; i < N; ++i ) {
	for (int j = 0; j < i; ++j ) {
		total += adj_mat[i][j] - adj_mat_p[i][j];
	}}
	return total;
}

double eucl_dist(coor& f, coor& s) {
	return sqrt( pow(f.first - s.first, 2) + pow(f.second - s.second, 2));
}

void reset() {
	for ( int i = 0; i < MAX; ++i ) {
		for ( int j = 0; j < MAX; ++j ) {
			adj_mat[i][j] = INF;
			adj_mat_b[i][j] = INF;
			has_road[i][j] = false;
		}
		adj_mat[i][i] = 0;
		adj_mat_b[i][i] = 0;
	}
}
