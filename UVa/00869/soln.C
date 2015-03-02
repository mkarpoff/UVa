/* UVa problem: 00869
 *
 * Topic: Graph Algorithms
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   Find out if two graphs have the same span
 *
 * Solution Summary:
 *
 *   Warshall's Alg
 *
 * Used Resources:
 *
 *   
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cstring>

int N, M;

using namespace std;

int flight_f[26][26];
int flight_s[26][26];
int stripChar(char c);

void print() {
return;
	cout << "Flight_f" << endl;
	for (int i = 0; i < 26; ++i) {
	for (int j = 0; j < 26; ++j) {
		cout << flight_f[i][j] << " ";
	} cout << endl;}
	cout << endl;
	cout << "Flight_s" << endl;
	for (int i = 0; i < 26; ++i) {
	for (int j = 0; j < 26; ++j) {
		cout << flight_s[i][j] << " ";
	} cout << endl;}
	cout << endl;
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			flight_f[i][j] = 0;
			flight_s[i][j] = 0;
		}}
		cin >> N; 
		for (int i = 0; i < N; ++i) {
			char t1,t2;
			cin >> t1 >> t2;
			flight_f[stripChar(t1)][stripChar(t2)] = 1;
		}
		cin >> M;
		for (int i = 0; i < M; ++i) {
			char t1,t2;
			cin >> t1 >> t2;
			flight_s[stripChar(t1)][stripChar(t2)] = 1;
		}
		print();
		for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			flight_f[i][j] |= (flight_f[i][k] & flight_f[k][j]);
			flight_s[i][j] |= (flight_s[i][k] & flight_s[k][j]);
		}}}
		bool equal = true;
		for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if ( flight_f[i][j] != flight_s[i][j]) {
				equal = false;
				i = 26; j =26;
			}
		}}
		print();
		if (equal) {cout << "YES" << endl; }
		else { cout << "NO" << endl;}

		if (tests) {
			cout << endl;
		}
	}
	return 0;
}

int stripChar(char c) {
	return (c -'A');
}
