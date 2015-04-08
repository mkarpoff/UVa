/* UVa problem: 10026
 *
 * Topic: Sorting
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   There are a bunch of tasks that have costs for being late and take a 
 *	 certain amount of time to complete find the smallest cost
 *
 * Solution Summary:
 *
 *   Stable sort base of compparing the cost of doing one task before the other
 *
 * Used Resources:
 *
 *   http://www.algorithmist.com/index.php/UVa_10026
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

struct task {
	int pos;
	int time;
	int cost;
};

bool cmp( const task & a, const task & b) {
	int dtc = a.time + b.time;
	return (a.cost*dtc) + (b.cost*b.time) > (b.cost*dtc) + (a.cost*a.time);
}

int main() {
	int tests, n;
	cin >> tests;
	while(tests--) {
		cin >> n;
		vector<task> tasklist;
		for (int i = 1; i <= n; ++i) {
			task t;
			t.pos = i;
			cin >> t.time >> t.cost;
			tasklist.push_back(t);
		}
		stable_sort(tasklist.begin(), tasklist.end(), cmp);
		bool f = false;
		for (auto t: tasklist) {
			if (f) cout << " ";
			cout << t.pos;
			f = true;
		}
		cout << endl;
		if (tests) cout << endl;
	}
	return 0;
}
