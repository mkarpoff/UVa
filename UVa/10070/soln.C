/* UVa problem: 10070
 *
 * Topic: Arithmatics
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Find out if a number is can be modded by {4, 100, 400, 15, 55 } numbers
 *  can be larger than cin can handle
 *
 * Solution Summary:
 *
 *  read in segments and pass of the overflow. Used LCD toreduce number of 
 *	computations
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
#include <string>
#include <cmath>

using namespace std;

unsigned long long M;
const int RW = 10;
const int LCD = 13200;
const int mod[5] = {4, 100, 400, 15, 55};

int main() {
	bool first = true;
	M = pow(10, RW);
	while (!cin.eof()) {
		if (!first) cout << endl;

		unsigned long long year[5] = {0};
		bool flags[3] = {false};
		string numbers;
		getline(cin, numbers);
		cin >> ws;

		const int si = numbers.size();
		unsigned long long cn =0;
		for ( int pos = 0; pos < si; pos+=RW) {
			if (si-pos > RW) {
				string sp_year = numbers.substr(pos, RW);
				unsigned long long p_year = stoull(sp_year);
			cn = ((p_year + cn * M) % LCD);
			} else {
				int rw = si-pos;
				unsigned long long m = pow(10, rw);
				string sp_year = numbers.substr(pos, rw);
				unsigned long long p_year = stoull(sp_year);
				cn = ((p_year + cn * m ) % LCD);
			}
		}


		if (! (cn % mod[0])) {
			flags[0] = true;
			if (! (cn % mod[1])) {
				flags[0] = false;
				if (! (cn % mod[2])) {
					flags[0] = true;
		}	}	}
		if (! (cn % mod[3])) flags[1] = true;
		if (! (cn % mod[4])) flags[2] = true;

		if (flags[0]) {	
			cout << "This is leap year." << endl; 
			if (flags[1]) { cout << "This is huluculu festival year." << endl; }
			if (flags[2]) { 
				cout << "This is bulukulu festival year." << endl;
			}
		} else if (flags[1]) {
			cout << "This is huluculu festival year." << endl;
		} else {
			cout << "This is an ordinary year." << endl;
		}
		first = false;
	}
	return 0;
}
