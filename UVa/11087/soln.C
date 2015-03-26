/* UVa problem: 11087
 *
 * Topic: Number Theory
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
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;

ll sigma(ll n) {
	return (n*(n-1))/2;
}

int main() {
	int tests;
	cin >> tests;
	for (int run = 1; run <= tests; ++run) {
		list<int>  u[505];

		int N, k;
		cin >> N >> k;
		// Read in numbers
		for(int i = 0; i < N; ++i) {
			ll t, spot;
			cin >> t;
			spot = abs(t)%k;
			if (t < 0) spot = (k-spot)%k;
			u[spot].push_back(t);
		}
	
		// Calc all combos for numbers that are already divisble
		u[0].sort();
		list<int> to = u[0];
		u[0].unique();
		for (auto i = u[0].begin(); i != u[0].end();++i) {
			auto j = find(to.begin(), to.end(), (*i));
			if (j != to.end()) to.erase(j);
		}
		to.unique();
		ll za = u[0].size();
		ll zo = to.size();
		ll ans = sigma(za) + zo;

		// Calc all the numbers for center points
		if (!(k&1)) {
			u[k/2].sort();
			list<int> to = u[k/2];
			u[k/2].unique();
			for (auto i = u[k/2].begin(); i != u[k/2].end();++i) {
				auto j = find(to.begin(), to.end(), (*i));
				if (j != to.end()) to.erase(j);
			}
			to.unique();
			ll sa = u[k/2].size();
			ll so = to.size();
			ans += sigma(sa) + so;
		}

		// get the combos for the end and begin as the move to the center
		for(int i = 1, j = k-1; i < j; ++i, --j) {
			u[i].sort(); u[j].sort();
			u[i].unique(); u[j].unique();
			ans += u[i].size() * u[j].size();
		}

		cout << "Case " << run << ": " << ans << endl;
	}
	return 0;
}
