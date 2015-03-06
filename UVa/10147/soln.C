/* UVa problem: 10147
 *
 * Topic: Graph Algorithms
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
#include <tuple>

using namespace std;

typedef pair<float, float> coor;

const int MAX_N = 750;
const int MAX_M = 1000;
coor pos[MAX_N];

int N, M;

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			float t1, t2;
			cin >> t1 >> t2;
			pos[i] = make_pair(t1,t2);
		}
		cin >> M;
		for (int i = 0; i < M; ++i) {
			int t1, t2;
			cin >> t1 >> t2;
		}

		if (tests) { cout <<endl;}
	}
	return 0;
}
