/* UVa problem: 00612
 *
 * Topic: Sorting
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *	sort a bunch of strings by the number of bubble sort swaps it would take to 
 *	sort it
 *
 * Solution Summary:
 *
 *  The number of swaps can be caluculated the number of items and how far out 
 *	of place they are, then do a simple sort base off how broken they are
 *
 * Used Resources:
 *
 *   http://www.algorithmist.com/index.php/UVa_612
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<string,int> dna;

char seq[110];

bool lt(const dna & a, const dna & b) {
	return a.second < b.second;
}

short charCon(char c) {
	switch (c) {
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
} }

int rec(string & seq, int len) {
	int ret = 0;
	for (int i = 0; i < len; ++i) {
	for (int j = i+1; j < len; ++j) {
	if (charCon(seq[i]) > charCon(seq[j])) {
		++ret;
	} } }
	return ret;
}

int main() {
	int tests, len, N;
	cin >> tests;
	while (tests--) {
		cin >> len >> N;
		vector<dna> list;
		for(int i = 0; i < N; ++i) {
			string seq;
			cin >> seq;
			list.push_back(dna(seq,rec(seq, len)));
		}
		stable_sort(list.begin(), list.end(), lt);
		for (auto s: list) cout << s.first << endl;
		if (tests) cout << endl;
	}
	return 0;
}
