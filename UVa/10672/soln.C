/* UVa problem: 10672
 *
 * Topic: Graph Traversal
 *
 * Level: trivial
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
#include <cmath>
#include <vector>
#include <map>

using namespace std;

const int MAX = 11000;

int V;
int count[MAX] = {0};
int parent[MAX] = {0};
vector<int> children[MAX];
int TOP;

int dfsolv(int);

int main() {
	cin >> V;
	while (V) {
		for(int i = 0; i <= V; ++i) {
			children[i].clear();
		}
		for(int i = 0; i < V; ++i) {
			int v, num, d, child;
			cin >> v >> num >> d;
			count[v] = num;
			if (!i) TOP = v;
			for(int j = 0; j < d; ++j) {
				cin >> child;
				children[v].push_back(child);
				parent[child] = v;
			}
			int count = 0;
		}
		cout << dfsolv(TOP) << endl;
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
