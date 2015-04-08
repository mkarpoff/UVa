/* UVa problem: 00307
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  You have a bunch of uniform sticks that are at most 50 units long. They are
 *	then broken at random locations. You don't know how many sticks there were
 *	originally or how long the were. Find the minimum length that they could
 *	have been.
 *
 * Solution Summary:
 *
 *   Straightforward backtracking solution
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
#include <cstring>

using namespace std;

typedef unsigned long long ull;

int const MAX = 200;
vector<int> parts;
vector<bool> vis;
ull sum;
int N;
ull TARGET;

bool backtrack(int target, int start, int count) {
	if (count == N) return true;
	for (int i = start-1; i >= 0; --i) {
		if (vis[i]) continue;
		if (target > parts[i]) {
			vis[i] = true;
			if (backtrack(target - parts[i], i, count+1)) return true;
			vis[i] = false;
		} else if (target == parts[i]) {
			vis[i] = true;
			if (backtrack(TARGET, N, count+1)) return true;
			vis[i] = false;
			return false;
		}
		while( i - 1 >= 0 && parts[i] == parts[i-1]) --i;
		if (target == TARGET) return false;
	}
	return false;
}


bool find(int target) {
	fill(vis.begin(), vis.end(), false);
	TARGET = target;
	return backtrack(target, N, 1);
}


int main() {
	cin >> N;
	while (N) {
		parts.clear();
		vis.resize(N);
		sum = 0;

		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			parts.push_back(temp);
			sum += temp;
		}
		
		sort(parts.begin(), parts.end());
		int i;
		for ( i = parts.back(); i <= sum; ++i) {
			if (sum % i) continue;
			if (find(i)) break;
		}
		cout << i << endl;
		cin >> N;
	}
	return 0;
}
