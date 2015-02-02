/* UVa problem: 10815
 *
 * Topic: Data structures and Libraries
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
void sanitize_word(string & orig, vector<string> & clean);
void strip_punc(string &input, vector<string> &output);
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
		vector<string> clean;
		
		cin >> input;

		sanitize_word(input, clean);
		for (auto w: clean) {
			words.insert(w);
		}
	}
	while (cin);
}

void sanitize_word(string &orig, vector<string> & clean) {
 	transform( orig.begin(), orig.end(), orig.begin(), ::tolower);
 	strip_punc(orig, clean);
}

void strip_punc(string &input, vector<string> &output) {
	string clean;
	for( auto x:input) {
		if( ((int) x) <= ((int) 'z') && ((int) 'a') <= ((int) x)) {
			clean.push_back(x);
		} else {
			if (clean.size() > 0) {
				output.push_back(clean);
				clean = string();
			}
		}
		
		/*else	if( ((int) x) <= ((int) '9') && ((int) '0') <= ((int) x)) {
			output.push_back(x);
		}*/
	}
	if (clean.size() > 0) {
		output.push_back(clean);
	}
}

void print_soln(set<string> &words) {
	for (auto x:words) {
		cout << x << endl;
	}
}
