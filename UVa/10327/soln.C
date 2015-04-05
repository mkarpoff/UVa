/* UVa problem: 10327
 *
 * Topic: Sorting
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Count number of flips needed to sort an array of intest swaping only 
 *	 adjacent integers
 *
 * Solution Summary:
 *
 *   Same idea as 00612 but simpler
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

using namespace std;

int array[1005];

int calc(int len) {
	int ret = 0;
	for (int i = 0; i < len; ++i) {
	for (int j = i+1; j < len; ++j) {
	if (array[i] > array[j]) {
		++ret;
	} } }
	return ret;
}

int main() {
	int N;
	cin >> ws;
	while (! cin.eof() ) {
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> array[i];
		int flips = calc(N);
		cout << "Minimum exchange operations : " << flips << endl;
		cin >> ws;
	}
	return 0;
}
