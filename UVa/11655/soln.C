/* UVa problem: 11655
 *
 * Topic: Graph Algorithms
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Find the numper of paths in a graph and the number of paths that go through 
 *	every vertex
 *
 * Solution Summary:
 *
 *  Run Topological sort then run two both path counding Algorithms then find 
 *	thier cross
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
#define PRINT if (R_PRINT) {\
for (ll i = 1; i <= L; ++i ) {\
	cout << i << ": ";\
	for(auto j: adjmat[i]) {\
		cout << j << " ";\
	} cout << endl;\
}\
\
for (int i = 1; i <= L; ++i ) {\
	cout << num_path1[i] << " ";\
} cout << endl;\
for (int i = 1; i <= L; ++i ) {\
	cout << num_path2[i] << " ";\
} cout << endl;\
}
 
#define R_PRINT false

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
const ll MAX = 5005;
const ll MOD = 100000;

int main() {
	ll cur = 0, tests, L, T, num_path, num_team;
	cin >> tests;
	while (cur++ < tests) {
		cin >> L >> T;
		if ( L == 1 ) {
			num_team =1;
			num_path =1;
			for( ll i = 1; i <= T; ++i ) {
				ll t1,t2;
				cin >> t1 >> t2;
			}
		} else {
	
			vector<int> adjmat[MAX];
			vector<int> order;
			ll indeg[MAX];
			ll num_path1[MAX];
			ll num_path2[MAX];
			memset(num_path1, 0, sizeof(num_path1[0]) * MAX);
			memset(num_path2, 0, sizeof(num_path2[0]) * MAX);
			memset(indeg, 0, sizeof(indeg[0]) * MAX);
			num_path1[1] = 1;
			num_path2[L] = 1;
			num_team = 0;
PRINT


			for( ll i = 1; i <= T; ++i ) {
				ll t1,t2;
				cin >> t1 >> t2;
				adjmat[t1].push_back(t2);
				indeg[t2] +=1;
			}
PRINT


		// Topological sort
		int runs = L;
		while (runs--) {
			for (int i = 1; i <=L;++i) {
				if (indeg[i] == 0) {
					--indeg[i];
					order.push_back(i);
					for (auto j: adjmat[i]) {
						--indeg[j];
					}
					break;
				}
			}
		}

		// rest is easy
			for(auto i: order) {
				for(auto j: adjmat[i]) {
					num_path1[j] = (num_path1[j]+num_path1[i])%MOD;
				}
			}
PRINT
			for(auto k=order.rbegin(); k != order.rend(); ++k) {
				int i = *k;
				for( auto j: adjmat[i]) {
					num_path2[i] = (num_path2[i] + num_path2[j])%MOD;
				}
			}
PRINT
			for( ll i = 2; i <= L; ++i ) {
				num_team = (num_team+(num_path2[i] * num_path1[i]))%MOD;
			}
PRINT
			num_path = num_path1[L]%MOD;
		}
		cout << "Case " << cur << ": " << num_team<< " " << num_path<< endl;
	}
	return 0;
}

