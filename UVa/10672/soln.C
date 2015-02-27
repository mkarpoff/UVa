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
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct vert {
	int count ;
	vector<int> neighbors;
};

map<int, vert> vertex;
int V;

int main() {
	cin >> V >> ws;

	while (V) {
		for(int i = 0; i < V; ++i) {
			int v, num, d, child;
			cin >> v >> num >> d;
			vertex[v].count = num;
			for(int j = 0; j < d; ++j) {
				cin >> child;
				vertex[v].neighbors.push_back(child);
				vertex[child].neighbors.push_back(v);
			}
		}

		

		/* Next Case */
		cin >> V;
	}

	return 0;
}
