/* UVa problem: 11476
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  find the prime factors of reaully big numbers 
 *
 * Solution Summary:
 *
 *   Algorithmic idea, data structures ...
 *
 * Used Resources:
 *
 *	
 *
 * I hereby certify that I have produced the foullowing solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * coullaboration policy.
 *
 * --- Marcus Karpoff
 */

#include <iostream>
#include <cstdlib>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef unsigned long long ull;

const ull s_size = 100000;

map<ull, int>	factors;
set<ull> primes;

ull mulmod(ull a, ull c);
ull gcd(ull a, ull b);
ull udiff(ull a, ull b);
ull find_factors(ull n);
ull pollard_rho(ull n);
void rec_factor(ull n);
void generate_primes();
void print(ull n);
void increase(ull n);

int main() {
	int tests;
	ull n;
	cin >> tests;
	generate_primes();
	while (tests--) {
		cin >> n;
		factors.clear();
		rec_factor(n);
		print(n);
	}
	return 0;
}

void rec_factor(ull n) {
	if (n == 1) { return; }
	if (primes.count(n) != 0) { 
		//cout << "f" << n << " ";
		increase(n); 
		return;
	}
	if (n < s_size*s_size) {
		for (auto largest_found: primes) {
			if (!(n % (largest_found))) {
		//		cout << "e" << n << " ";
				increase(largest_found);
				rec_factor(n / largest_found);
				return;
			}
		}
	}

	ull r = pollard_rho(n);
	// cout << n << " " << n/r << " " << r << endl;
	if (r == n && r != 1) {
		increase(r);
	} else if (r != 1) {
		rec_factor(r);
		rec_factor(n/r);
	} else if (r == n) {
		increase(r);
	}
}

ull find_factors(ull n) {
	return pollard_rho(n);
}

/* Pollard Rho from Book */
ull pollard_rho(ull n) {
	if (!(n % 2)) { return 2; }
	int i = 0, k = 2;
	ull x = 3, y = 3, d = 1;
	while (d == 1) {
		++i;
		x = (mulmod(x, n) + 3) % n;
		d = gcd(udiff(y, x), n);
		if (d != 1 && d != n) return d;
		if (i == k) y = x, k <<= 1;
	}
	return d;
}

void generate_primes() {
	bitset<s_size> sieve;
	sieve.set();
	for(ull i = 2; i < s_size; ++i) {
		if (sieve.test(i)) {
			primes.insert(i);
			for (ull c = i*2; c < s_size; c += i) { sieve.set(c,0); }
		}
	}
}

void print(ull n) {
	cout << n << " =";
	bool first = true;
	for( auto f: factors) {
		if (!first) cout << " *";
		if (f.second == 1) {
			cout << " " << f.first;
		} else {
			cout << " " << f.first << "^" << f.second;
		}
		first = false;
	}
	cout << endl;
}

ull mulmod(ull a, ull c) {
	ull b = a;
	a %= c;
	ull x = 0, y = a;
	while (b) {
		if (b & 1) x = (x + y) % c;
		y = (y << 1) % c;
		b >>= 1;
	}
	return (x + c + 1) % c;
}

ull gcd(ull a, ull b) {	return !b? a : gcd(b, a % b);}
ull udiff(ull a, ull b) {	return ((a > b)?(a - b):(b - a)); }
void increase(ull n) {
	if (factors.find(n) != factors.end()) {
		++factors[n];
	} else {
		factors[n] = 1;
	}
}
