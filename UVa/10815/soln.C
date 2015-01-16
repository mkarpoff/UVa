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
 * 	Sanitize the input words and store in a set to make it so you don't have to 
 * 	check if they have already been found.
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
#include <set>

using namespace std;

void read_input(set<string> &words);
void sanitize_word(string & orig, string & clean);
void strip_punc(string &input, string &output);
void print_soln(set<string> & words);

int main() {
	set<string> dict;
	read_input(dict);
	print_soln(dict);
	return 0; 
}

void read_input(set<string> &words) {
	do {
		string input;
		string clean;
		
		cin >> input;

		sanitize_word(input, clean);
		if (clean.size() > 0) {
			words.insert(clean);
		}
	}
	while (cin);
}

void sanitize_word(string &orig, string & clean) {
 	transform( orig.begin(), orig.end(), orig.begin(), ::tolower);
 	strip_punc(orig, clean);
}

void strip_punc(string &input, string &output) {
	for( auto x:input) {
		if( ((int) x) <= ((int) 'z') && ((int) 'a') <= ((int) x)) {
			output.push_back(x);
		}
	}
}

void print_soln(set<string> &words) {
	for (auto x:words) {
		cout << x << endl;
	}
}
