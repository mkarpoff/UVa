/* UVa problem: 11321
 *
 * Topic: Sorting
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Sort numbers by thier modulo and some other wonky rules
 *
 * Solution Summary:
 *
 *   Use built in sorting alg and wrote custom compare function
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
#include <vector>

using namespace std;

struct num {
	int o;
	int m;
	num(int _o, int _m): o(_o), m(_m) {};
};

bool cmp( const num & a, const num & b) {
	if (a.m != b.m) return a.m < b.m;
	if (a.o&1 xor b.o&1) return a.o&1;
	if (a.o&1 and b.o&1) return a.o > b.o;
	return a.o < b.o;
}

int main() {
	int N, M;
	cin >> N >> M;
	while ( N or M ) {
		vector<num> list;
		for (int i = 0; i < N; ++i) {
			int t;
			cin >> t;
			list.push_back(num(t, t%M));
		}
		sort(list.begin(), list.end(), cmp);
		cout << N << " " << M << endl;
		for (auto i: list) cout << i.o << endl;
		cin >> N >> M;
	}
	cout << "0 0" << endl;
	return 0;
}
