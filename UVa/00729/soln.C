/* UVa problem: 729
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  find all numbers that have a hamming number n with bitwise length of l
 *	print in sorted binary rep
 *
 * Solution Summary:
 *
 *  DP recursion
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
#include <bitset>

using namespace std;

vector<int> ret;
void rec( int h, int l, int cur_mask) {
	if (h > l) return;
	if (l == 0) { ret.push_back(cur_mask); return; }
	if (h == 0) { ret.push_back(cur_mask << l); return; }
	rec(h, l-1, cur_mask<<1);
	rec(h-1, l-1, cur_mask<<1|1);
}
void print(int l, int n) {
	switch (l) {
	case 1:  cout << (bitset<1> ) n << endl; return;
	case 2:  cout << (bitset<2> ) n << endl; return;
	case 3:  cout << (bitset<3> ) n << endl; return;
	case 4:  cout << (bitset<4> ) n << endl; return;
	case 5:  cout << (bitset<5> ) n << endl; return;
	case 6:  cout << (bitset<6> ) n << endl; return;
	case 7:  cout << (bitset<7> ) n << endl; return;
	case 8:  cout << (bitset<8> ) n << endl; return;
	case 9:  cout << (bitset<9> ) n << endl; return;
	case 10: cout << (bitset<10>) n << endl; return;
	case 11: cout << (bitset<11>) n << endl; return;
	case 12: cout << (bitset<12>) n << endl; return;
	case 13: cout << (bitset<13>) n << endl; return;
	case 14: cout << (bitset<14>) n << endl; return;
	case 15: cout << (bitset<15>) n << endl; return;
	case 16: cout << (bitset<16>) n << endl; return;
	}
}

int main() {
	int tests, h, l;
	cin >> tests;
	while (tests--) {
		ret.clear();
		cin >> l >> h;
		rec(h, l, 0);
		sort(ret.begin(), ret.end());
		for (auto i: ret) print(l, i);
		if (tests) cout << endl;
	}
	return 0;
}
