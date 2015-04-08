/* UVa problem: 10672
 *
 * Topic: Graph Traversal
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *  Balance a tree and calculate the number of moves it takes to balance it.
 *	Move is defined as each object moved counts as a move
 *
 * Solution Summary:
 *
 *  DFS and add to parents positive or negative moves total abs(of a move) is 
 *	added to total
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
#include <cmath>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int MAX = 11000;

int V;
int count[MAX];
int parent[MAX];
vector<int> children[MAX];
int TOP;

int dfsolv(int);

int main() {
	int v, num, d, child;
	cin >> V;
	while (V) {
		memset(count, -1, sizeof count);
		memset(parent, -1, sizeof parent);
		for(int i = 0; i <= V; ++i) {
			children[i].clear();
		}
		for(int i = 0; i < V; ++i) {
			cin >> v >> num >> d;
			count[v] = num;
			for(int j = 0; j < d; ++j) {
				cin >> child;
				children[v].push_back(child);
				parent[child] = v;
			}
			int count = 0;
		}
		while (parent[v] != -1) {
			v = parent[v];
		}
		cout << dfsolv(v) << endl;
		cin >> V;
	}
	return 0;
}

int dfsolv(int cur) {
	int total = 0;
	for (auto v: children[cur]) {
		total += dfsolv(v);
	}
	int move = -(1 - count[cur]);
	count[cur] = 1;
	count[parent[cur]] += move;
	return abs(move) + total;
}
