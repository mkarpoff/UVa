/* UVa problem: 10815
 *
 * Topic: Data structures
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *  Parse a bunch of text for unique sequences.
 *
 * Solution Summary:
 *
 * 	Use a set and set all words to lower case before adding to set
 *
 * Used Resources:
 *
 *  http://en.cppreference.com/w/
 *  http://www.cplusplus.com/reference/ 
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */

#include <string>
#include <algorithm>
#include <iostream>
#include <regex>
#include <set>

using namespace std;

void parse_text(string &input, set<string> &words);

int main() {

	string input;
	string s;
	
	do {
		cin >> input;
		s.append(input);
		s.append(" ");
	}
	while (cin);

	set<string> dict;
	parse_text(s, dict);
	for (auto x:dict) {
		cout << x << endl;
	}

	return 0; // Exit safely
}

void parse_text(string &input, set<string> &words)
{
	string s(input);
	smatch sm;
 
	try	{
		regex rx ("[A-Za-z]+", regex_constants::extended);
	
		while (regex_search(s ,sm,rx) ) {
				string ns(sm.str());
				transform(ns.begin(), ns.end(), ns.begin(), ::tolower);
				words.insert(ns);
				s = sm.suffix().str();
		}

	} catch (const regex_error& e) {
		cerr << "Regex error with code: "<<  e.code() << endl;
		exit(1); // Error
	}
}
