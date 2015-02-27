/* UVa problem: 11512
 *
 * Topic: String
 *
 * Level: trivial
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
#include <algorithm>
#include <iostream>

#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 1000
string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];

void countingSort(int k);
void constructSA();
void computeLCP();

int main() {
	int cases;
	cin >> cases >> ws;
	while (cases--) {
		getline(cin, T);
		n = T.size();
		T[n++] = '$';
		T[n] = 0;
		constructSA();
		computeLCP();
		for (int i = 0; i < n; ++i ) {
			printf( "i: %d SA: %d LCP: %d Suffix: %s\n", i, SA[i], LCP[i],  T.c_str() + SA[i]);
		}
		for (int i = 0; i < n; ++i ) {
			printf( "i: %d Phi: %d PLCP: %d Suffix: %s\n", i, Phi[i], PLCP[i], T.c_str()+i);
		}
		int pos = 0;
		for (int i = 0; i < n; ++i ) {
			if (PLCP[i] > PLCP[pos]) {
				for (int j = 0; j < PLCP[i]; ++j) {
					if ( ((int)T[j+i]) < ((int) T[j+pos]) ) {
						pos = i;
					}
				}
			}
		}
		int length = PLCP[pos];
		if (length > 0 ) {
			bool found = false;
			int count = 0;
			int cur = pos;
			while (!found) {
				if (PLCP[cur] == length) {
					cur = Phi[cur];
				} else {
					found = true;	
				}
				++count;
			}
			for (int i = pos; i < pos + length; ++i) {
				cout << T[i];
			}
			cout << " ";
			cout << count;
			cout << endl;
		} else {
			cout << "No repetitions found!" << endl;
		}

	}
	return 0;
}

void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; ++i) {
		c[i + k < n? RA[i + k] : 0]++;
	}
	for (i = sum = 0; i < maxi; ++i) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < n; ++i) {
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	}
	for (i = 0; i < n; ++i) {
		SA[i] = tempSA[i];
	}
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; ++i) RA[i] = T[i];
	for (i = 0; i < n; ++i) SA[i] = i;
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; ++i) {
			tempRA[SA[i]] = 
			(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r: ++r;
		}
		for (i = 0; i < n; ++i) {
			RA[i] = tempRA[i];
		}
		if (RA[SA[n-1]] == n-1) break;
	}
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < n; ++i) {
		Phi[SA[i]] = SA[i-1];
	}
	for (i = L = 0; i < n; ++i) {
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }
		while (T[i + L] == T[Phi[i] + L]) ++L;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i=0; i < n; ++i) {
		LCP[i] = PLCP[SA[i]];
	}
}
