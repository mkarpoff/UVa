/* UVa problem: 11340
 *
 * Topic: Data Structure and Libraries
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *  News agency pays money for articles according to some rules. Each character
 *	has its own value (some characters may have value equals to zero). Author 
 *	gets his payment as a sum of all character's values in the article. You 
 *	have to determine the amount of money that news agency must pay to an 
 *	author.
 *
 * Solution Summary:
 *
 *  Count occurences of chars in a string store in map
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
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
	long cases, lcount, k, total;
	char c;
	string line;
	map<char, long> cost;
	cin >> cases >> ws;
	while (cases--) {
		total=0;
		cin >> lcount >> ws;
		cost.clear();
		while ( lcount-- ) {
			cin >> c >> ws >> k >> ws;
			cost.insert(pair<char, long>(c, k));
		}
		cin >> lcount;
		getline(cin, line);
		while (lcount--) {
			line.clear();
			getline(cin, line);
			for (auto c: line) {
				total += cost[c];
			}
		}	
		cout << fixed;
		cout << setprecision(2) << (((double) total) /100) << '$' << endl;
	}
	return 0;
}
