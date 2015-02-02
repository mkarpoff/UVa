/* UVa problem: 00202
 *
 * Topic: Arithmetic
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   Implement long division and find repeating decimals return number of digits
 *   in repition
 *
 * Solution Summary:
 *
 *   Used a vector to store the current division and anouther for the ramainder
 *   if the remainder existed before then we found the repitition
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
#include <vector>

using namespace std;

vector<int> part_num;
vector<int> past_rem;

void reset();
void calc(int,int);
void print(int,int);

int main() {
	int num,den;
	while (!cin.eof()) {
		cin >> num >> ws >> den >> ws;
		reset();
		calc(num, den);
		print(num, den);
	}
	return 0;
}

void reset() {
	part_num.clear();
	past_rem.clear();
}

void calc(int num, int den) {
	int rem, cal;
	bool rep_not_found = true;
	while(rep_not_found) {
		rem = num % den;
		cal = num / den;
		num = rem * 10;
		part_num.push_back(cal);
		if (rem == 0) {rep_not_found = false;}
		for (auto x = past_rem.begin(); x != past_rem.end(); ++x) {
			if (*x == rem){	
				rep_not_found = false;
			}
		}
		past_rem.push_back(rem);
	}
}

void print(int num, int den) {
	cout << num << '/' << den << " = " << part_num[0] << '.';
	int last_rem = past_rem.back();
	int rep_len = 0;
	for(int i =1; i < part_num.size(); ++i) {
		if (rep_len) ++rep_len;
		if (past_rem[i-1] == last_rem ) { 
			cout << '(' << part_num[i];
			++rep_len;
		}	else if(rep_len <= 50) {
			 cout << part_num[i]; 
		}
	}
	if (last_rem == 0 ) {++rep_len; cout << "(0";}
	if (rep_len >= 50) {cout << "...";}
	cout << ')' << endl;
	cout << "   " << rep_len  << " = number of digits in repeating cycle" << endl;
	cout << endl;
}
