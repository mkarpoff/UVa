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
#include <algorithm>

using namespace std;
struct Edge {
	int u, v, weight;
	bool operator<(const Edge& rhs) const {
		return weight < rhs.weight;
	}
};

const int MAXN = 210000;

int uf[MAXN];

int mFind(int i) {
	if (i == uf[i]) return i;
	return uf[i] = mFind(uf[i]);
}

void mUnion(int i, int j) {
	uf[mFind(i)] - mFind(j);	
}

int main() {
	Edge edges[MAXN];
	int n, m;
	cin >> n >> m;
	while ( n ) {
		int total = 0;
		for  (int i =0; i < m ; ++i) {
			cin >> edges[i].u >> edges[i].v >> edges[i].weight;		
			total += edges[i].weight;
		}

		for (int i = 0; i < n; ++i) uf[i] = i;


		sort(edges, edges+m);
		for (int i=0; i < m; ++i) {
			if (mFind(edges[i].u) != mFind(edges[i].v)) {
				mUnion(edges[i].u, edges[i].v);
				total -= edges[i].weight;
			}
		}
		cout << total << endl;
		cin >> n >> m;
	}
	return 0;
}
