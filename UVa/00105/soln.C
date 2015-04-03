/* UVa problem: 00105
 *
 * Topic: Other
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   given a bunch of coords that match a skyline create a silloette of the
 *	skyline only showing where there is a change in line and where it goes to
 *
 * Solution Summary:
 *
 *  linear two pass iteration
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
#include <cstring>
#include <climits>

using namespace std;

int sky_line[10000];

int main() {
	memset(sky_line, 0, sizeof(sky_line[0]) * 10000);
	int start = INT_MAX, height = 0, end;
	while (!cin.eof()) {
		int s,e,t;
		cin >> s >> height >> e;
		t = min(s, e);
		e = max(s, e);
		s = t;
		start = min(start,s);
		end = max(end,e);

		for (int i = s; i < e; ++i)
			sky_line[i] = max(sky_line[i], height);
	}	
	if( start != INT_MAX) {
	cout << start << " " << sky_line[start];
	for (int i = start+1; i <= end; ++i) {
		if (sky_line[i] != sky_line[i-1])
			cout << " " << i << " " << sky_line[i];
	}	}
	cout << endl;
	return 0;
}
		
