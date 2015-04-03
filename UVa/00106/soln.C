/* UVa problem: 00106
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *    Given a positive integer N, you are to write a program that computes two
 *		quantities regarding the solution of 
 *				x^2 + y^2 = z^2
 *		where x, y, and z are constrained to be positive integers less than or 
 *		equal to N. You are to compute the number of triples (x,y,z) such that 
 *		x<y< z, and they are relatively prime, i.e., have no common divisor larger
 *		than 1. You are also to compute the number of values
 *				0 < p <= N 
 *		such that p is not part of any triple (not just relatively prime triples).
 *
 * Solution Summary:
 *
 *		using intermediary numbers r and s we can use the ralations of x, y, and z
 *		to generate the numbers byt turning each into equations that are the
 *		result of r and s
 *
 * Used Resources:
 *
 *		http://www.algorithmist.com/index.php/UVa_106
 *			-- provided key insite into problem solution
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef unsigned long long int ll;

const int MAX = 1000010;

bool vis[MAX];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool is_valid(int x, int y, int z) { return x*x + y*y == z*z; }


bool find_sols(int r, int s, int N) {
	int x = (r*r)-(s*s);
	int y = 2*(r*s);
	int z = (r*r)+(s*s);
	if (is_valid(x,y,z) && z <= N) {
	if (gcd(x,y) == 1) {
		for(int i = 1; i * z <= N; ++i)
			vis[i*x] = vis[i*y] = vis[i*z] = true; 
		return true;
	} }
	return false;
}

int main() {
	cin >> ws;
	while(!cin.eof()) {
		memset(vis, false, sizeof(vis[0]) * MAX);
		int N;
		cin >> N >> ws;
		int RN = sqrt(N);
		if (RN*RN < N) ++RN;
		int triples = 0;
		for(int r = 1; r <= RN; ++r) {
		for(int s = 1; s <= min(N-r*r,r-1); ++s) {
			if (find_sols(r,s,N)) ++triples;
		} }
		int total = 0;
		for (int i = 1; i <= N; ++i) {
			if (!vis[i]) ++total;
		}
		cout << triples << " " << total << endl;
	}
	
	return 0;
}
