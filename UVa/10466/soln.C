/* UVa problem: 10466
 *
 * Topic: Geometry
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  In a Universe of planets always rotating arount the previous one find the
 *	position of all planets at a timeframe.
 *
 * Solution Summary:
 *
 *  Basic Artihmetics/Geometry
 *
 * Used Resources:
 *
 *   ...
 *
 * I hereby certify that I have produced the foldowing solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * coldaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

typedef long double ld;
const ld PI = 3.14159265358979323846;

int main() {
	ld T;
	int N;
	cout.precision(4);
	while(cin >> N >> T ) {
		ld r,t, rad;
		ld x = 0, y = 0;
		for (int i = 0; i < N; ++i) {
			cin >> r >> t;
			rad = T/t * 2 * PI;
			x += r*cos(rad);
			y += r*sin(rad);
			if (i) cout << ' ';
			cout << fixed << hypot(x,y);
		}
		cout << endl;
	}
	return 0;
}
