/* UVa problem: 00598
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Printout the unique variouse sets that can be produced from a bunch of 
 *	strings order doesn't matter
 *
 * Solution Summary:
 *
 *  print using backtracking 
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
#include <vector>

using namespace std;

void print(int pos, int toprint, string out, vector<string> & l) {
	if (toprint == 1)	{ cout << out << l[pos] << endl; return;}
	for (int i = pos+1; i < l.size(); ++i) {
		print(i, toprint-1, (out + l[pos] + ", "), l);
	}
	
}

int main() {
	int tests;
	cin >> tests >> ws;
	while (tests--) {
		string cline;
		getline(cin, cline);
		vector<string> papers;
		string np; 
		getline(cin, np);
		while (np != "") {
			papers.push_back(np);
			getline(cin, np);
		}
		int start, end;
		if (cline == "*") {	start = 1; end = papers.size(); }
		else if (cline.size() <= 2) { start = end = stoi(cline); } 
		else { 
			start = stoi(cline.substr(0,2)); 
			end = stoi(cline.substr(2,cline.size())); 
		}
		for (; start <= end; ++start) {
			cout << "Size " << start << endl;
			for (int i = 0; i < papers.size(); ++i ) {
				print(i, start, "", papers);
			}
			cout << endl;
		}
		if (tests) cout << endl;
	}
	return 0;
}
