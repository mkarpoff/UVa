/* UVa problem: 11330
 *
 * Topic: Combinatorixs
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Andy has n pairs of shoes in n different colors. At the end of the day he 
 *	likes to put them back on his shoe rack. He has learned to always put a left
 *	shoe together with a right shoe. However, he has not learned about putting 
 *	pairs of shoes with the same color together. Papa's job is to pair up the 
 *	shoes. Since Papa is tired from work at the algorithm factory, he wants to 
 *	do this in the minimal number of steps. One step means to swap two shoes.  
 *
 * Solution Summary:
 *
 *   DP recursive soln
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

const int MAX = 10010;

int LS[MAX];
int RS[MAX];

int rec(int cur, int N) {
	if (cur == N) return 0;
	if (LS[cur] == RS[cur]) return rec(cur+1, N);
	int spot;
	for(spot = cur; spot < N; ++spot) {
		if (LS[cur] == RS[spot]) break;
	}
	swap(RS[cur], RS[spot]);
	return 1 + rec(cur+1,N);

}

int main() {
	int tests, N;
	cin >> tests;
	while(tests--) {
		cin >> N;
		for(int i = 0; i < N; ++i) {
			cin >> LS[i] >> RS[i];
			LS[i]--;RS[i]--;
		}
		cout << rec(0,N) << endl;
	}
	return 0;
}
