/* UVa problem: 100
 *
 * Topic: <topic>
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  implement an algorithm and count how many iterations it must make to solv. 
 *
 * Solution Summary:
 *
 *  I cached calculation data to reduce the number of times a transform must be
 *  applied to any number to only one
 *
 * Used Resources:
 *
 *   None
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

typedef pair<long, int> ii;

int alg(long n);
map<long, int> times;

int main() {
	string line;
	getline(cin, line);
	while (! line.empty()) {
		int l, j, max = 0;
		istringstream iss(line);
		iss >> l;
		iss >> j;
		if (j > l) {
			for(int i = l; i <= j; ++i) {
					int t =	alg(i);
					max =  t> max? t: max;
			}
		} else {	
			for(int i = j; i <= l; ++i) {
					int t =	alg(i);
					max =  t> max? t: max;
			}
		}
		cout << l << ' ' << j << ' ' << max << endl;
		getline(cin, line);
	}	

	return 0;
}

int alg(long n) {
	map<long, int> past;	
	int c = 1;
	past.insert(ii(n, 1));
	while  (n != 1) {
		past.insert(ii(n, c));
		if (times.find(n) != times.end()) {
			c += times[n];
			n = 1;
		}	else {
			if (n % 2) { n = 3*n + 1;}
			else {n /= 2;}
			++c;
		}
	}
	for( auto x: past) {
		times.insert(ii(get<0>(x), c-past[get<0>(x)]));
	}
	return c;
}
