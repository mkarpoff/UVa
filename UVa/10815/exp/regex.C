#include <string>
#include <iostream>
#include <regex>

using namespace std;


int main() {

	string s( "Split me up! Please work.");
	smatch sm;
	cout << s << endl;
	try {
		regex rx ("[A-Za-z]+", regex_constants::extended);
		while (regex_search(s,sm,rx) ) {
				cout << sm.str() << endl;
				s = sm.suffix().str();
			
		}
	} catch (const regex_error& e) {
		cerr << "Regex error with code: "<<  e.code() << endl;
		cerr << e.what() << endl;
		return 1; // Error
	}

	return 0; // Exit safely
}
