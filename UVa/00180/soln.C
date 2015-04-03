/* UVa problem: 00180
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Josephesus inverse problem with a range
 *
 * Solution Summary:
 *
 *  Originally I ran the function to calculate the position of the survivor
 *	of the typical problem to figure out who would be chief for every position
 *	in the circle. I realized that this would not be fast enough. I then 
 *	realized that the position of the survivor is based of the same problem with
 *	one less person but is an offset of that problem. This lead to a way to 
 *	calculate all cheif positions for a set cycle in linear time.
 *
 * Used Resources:
 *
 *  http://webspace.ship.edu/deensley/mathdl/Joseph.html
 *	http://www.algorithmist.com/index.php/UVa_180
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <list>

using namespace std;

const int CMAX = 1000001;
int lookup[CMAX];
bitset<CMAX> could_die;

void print_sol(int MIN) {
	for (int i = 1; i < MIN/2; ++i) {
		if (!could_die.test(i)) {
			cout << i << endl;
			return;
	} }
	cout << "Better estimate needed" << endl;
}

int main() {
	int MIN, MAX,t;
	lookup[0] = 0;
	lookup[1] = 0;
	for (int i = 2; i < CMAX; ++i) { lookup[i] = ( lookup[i-1] + 15) % i; }
	cin >> MIN >> MAX;
	t = min(MIN, MAX);
	MAX = max(MIN,MAX);
	MIN = t;
	while (MIN && MAX) {
		could_die.reset();
		for (int j = MIN; j <= MAX; ++j) {
			if (lookup[j] < j/2) {
				could_die.set(lookup[j]);
			} else {
				could_die.set(j-lookup[j]);
			}
		}
		print_sol(MIN);
		cin >> MIN >> MAX;
		t = min(MIN, MAX);
		MAX = max(MIN,MAX);
		MIN = t;
	}
	return 0;
}
