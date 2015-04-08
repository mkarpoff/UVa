/* UVa problem: 00437
 *
 * Topic: Graph Traversal
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Typical Tower of Babalon problem
 *
 * Solution Summary:
 *
 *   Treat every block as three vertecies in a dag. The outward edges all have a
 *	 weight of the height of the block in a given orientation and the node can 
 *	 only have an incoming edge if the preceding fertecy has a smaller width and
 *	 depth. Then it's simple longest path.
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

const static int V = 90;
const	static int zero_up = 0;
const	static int one_up = 30;
const	static int two_up = 60;

int case_num = 1;
int block[3][30];
int adj_mat[V][V];

void print(int line);
void add_block(int i, int f, int s, int t);
void add_all_cons(int from, int to);
void add_con(int from, int to, int f_ori, int t_ori);

int main() {
	int lines = 0 ;
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
			add_block(i,f,s,t);
		}
		for (int i = 0; i < lines; ++i) {
			for (int k = 0; k < lines; ++k) {
				add_all_cons(i, k);
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
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				if ( adj_mat[i][j] != -1) {
					int last_block;
					if (j >= two_up) {
						last_block = block[2][j%30];
					} else if (j >= one_up ) {
						last_block = block[1][j%30];
					} else {
						last_block = block[0][j%30];
					}
					max_num = max(max_num, adj_mat[i][j] + last_block);
					adj_mat[i][j] += last_block;
				}
			}
		}
		cout << "Case " << case_num++ << ": maximum height = " << max_num  << endl;
		cin >> lines;
	}
	return 0;
}
void add_all_cons(int from, int to) {
	add_con(from,to,zero_up,zero_up);
	add_con(from,to,zero_up,one_up);
	add_con(from,to,zero_up,two_up);
	add_con(from,to,one_up,zero_up);
	add_con(from,to,one_up,one_up);
	add_con(from,to,one_up,two_up);
	add_con(from,to,two_up,zero_up);
	add_con(from,to,two_up,one_up);
	add_con(from,to,two_up,two_up);
}
	
void add_con(int from, int to, int f_ori, int t_ori) {
	int f_x, f_y, f_z, t_x, t_y;
	switch (f_ori) {
		case zero_up:
			f_x = 2; f_y = 1; f_z = 0; break;
		case one_up:
			f_x = 2; f_y = 0; f_z = 1; break;
		case two_up:
			f_x = 1; f_y = 0; f_z = 2; break;
	}	
	switch (t_ori) {
		case zero_up:
			t_x = 2; t_y = 1; break;
		case one_up:
			t_x = 2; t_y = 0; break;
		case two_up:
			t_x = 1; t_y = 0; break;
	}

	if ( block[f_x][from] > block[t_x][to] && block[f_y][from] > block[t_y][to]) {
		adj_mat[from+f_ori][to+t_ori] = block[f_z][from];
	}
}

void add_block(int i, int f, int s, int t) {
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

void print(int lines) {
	for (int ii = 0; ii < 90; ii += 30) {
	for (int i = ii; i < lines+ii; ++i) {
		for (int jj = 0; jj < 90; jj += 30) {
		for (int j = jj; j < lines+jj; ++j) {
			if( adj_mat[i][j] == -1 ) {
				cout << "- ";
			} else {
				cout << adj_mat[i][j] << " ";
			}
		}
		cout << "||";
		}
		cout << endl;
	}
	}
	cout << endl;
}
