/* UVa problem: 11837
 *
 * Topic: String
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Find out if the musical transitions from one set exists in another.
 *
 * Solution Summary:
 *
 *   Convert the changes to a unique char for each and then run kmp alg. To 
 *   find pathern.
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
#include <cstring>
#include <string>

using namespace std;

const int MAX_O = 100000;
const int MAX_S = 10000;

int M, T;
char ori[MAX_O];
char sus[MAX_S];
int back[MAX_O];

int map_look(string s);
char to_semi(int f, int s);
bool match_str();
void kmpPreprocess();
bool kmpSearch();

int main() {
	cin >> M >> T;
	while (M || T) {
		memset(ori, 0, MAX_O * sizeof('c'));
		memset(sus, 0, MAX_S * sizeof('c'));
		{
		int t_list[M];
		for (int i = 0; i < M; ++i) {
			string c;
			int note;
			cin >> c;
			note = map_look(c);
			t_list[i] = note;
		}
		for (int i = 1; i < M; ++i) {
			ori[i-1] = to_semi(t_list[i-1], t_list[i]);
		}}
		{
		int t_list[T];
		for (int i = 0; i < T; ++i) {
			string c;
			int note;
			cin >> c;
			note = map_look(c);
			t_list[i] = note;
		}
		for (int i = 1; i < T; ++i) {
			sus[i-1] = to_semi(t_list[i-1], t_list[i]);
		}}
		if (match_str() || T == 1) {
			cout << 'S' << endl; 
		} else {
			cout << 'N' << endl;
		}
		cin >> M >> T;
	}
	return 0;
}

bool match_str() {
	kmpPreprocess();
	return kmpSearch();
}

void kmpPreprocess() {
	int i = 0, j = -1;
	back[0] = -1;
	while (i < T-1) {
		while (j >= 0 && sus[i] != sus[j]) { j = back[j]; }
		++i, ++j;
		back[i] = j;
	}
}

bool kmpSearch() {
	int i = 0, j = 0;
	while (i < M-1) {
		while (j >=0 && ori[i] != sus[j]) {j = back[j]; }
		++i; ++j;
		if (j == T-1) { return true; }
	}
	return false;
}

int map_look(string s) {
	int mod = 0;
	int out;
	if (s.size() == 2) {
		if (s[1] == '#') {
			mod = 1;
		} else {
			mod = -1;
		}
	}
	switch(s[0]) {
	case 'A': out = 1; break;
	case 'B': out = 3; break;
	case 'C': out = 4; break;
	case 'D': out = 6; break;
	case 'E': out = 8; break;
	case 'F': out = 9; break;
	case 'G': out = 11; break;
	}
	return ((out + mod) % 12);
}

char to_semi(int f, int s) {
	switch (f - s) {
	case   0: return 'a';
	case   1:
	case -11: return 'b';
	case   2:
	case -10: return 'c';
	case   3:
	case  -9: return 'd';
	case   4:
	case  -8: return 'e';
	case   5:
	case  -7: return 'f';
	case   6:
	case  -6: return 'g';
	case   7:
	case  -5: return 'h';
	case   8:
	case  -4: return 'i';
	case   9:
	case  -3: return 'j';
	case  10:
	case  -2: return 'k';
	case  11:
	case  -1: return 'l';
	}
}
