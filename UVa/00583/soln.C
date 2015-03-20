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
 *	http://2π.com/09/12/brent-pollard-rho-factorisation
 *
 * I hereby certify that I have produced the foullowing solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * coullaboration policy.
 *
 * --- Marcus Karpoff
 */
#define CACHE

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef unsigned long long ull;

map<ull, int>	factors;
#ifdef CACHE
map<ull, vector<ull>> cache;
#endif

ull mulmod(ull a, ull c);
ull gcd(ull a, ull b);
ull udiff(ull a, ull b);
ull find_factors(ull n);
ull pollard_rho(ull n);
void rec_factor(ull n);
void print(long long n);

int main() {
	int tests;
	long long n;
	cin >> n;
	while (n) {
		factors.clear();
		rec_factor(abs(n));
		print(n);
		cin >> n;
		}
	return 0;
}

void rec_factor(ull n) {
	ull p;
#ifdef CACHE
	auto c = cache.find(n);
	if ( c != cache.end()) {
		for (auto x: (*c).second) {
			if (factors.find(x) != factors.end() ) {
				++factors[x];
			} else {
				factors[x] = 1;
			}
		}
		return;
	} 
#endif
	p = find_factors(n);
	p = max(n/p,p);
	if (n/p != 1 && p != 1) {
		rec_factor(n/p);
	#ifdef CACHE
		cache[n].insert(cache[n].end(), cache[n/p].begin(), cache[n/p].end());
	#endif
		if (p != 1) {
			rec_factor(p);
		#ifdef CACHE
			cache[n].insert(cache[n].end(), cache[p].begin(), cache[p].end());
		#endif
		}
		return;
	} else {
#ifdef CACHE
	cache[n].push_back(p);
#endif
	if (factors.find(p) != factors.end()) {
		++factors[p];
	} else {
		factors[p] = 1;
	}}
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

ull gcd(ull a, ull b) {
	return !b? a : gcd(b, a % b);
}

ull udiff(ull a, ull b) {
	return ((a > b)?(a - b):(b - a));
}

/* Pollard Rho from Book */
ull pollard_rho(ull n) {
	if (n % 2 == 0) return 2;
	if (n % 3 == 0) return 3;
	int i = 0, k = 2;
	ull x = 3, y = 3, d = 1;
	while (d == 1 ) {
		++i;
		x = (mulmod(x, n) + 3) % n;
		d = gcd(udiff(y, x), n);
		if (d != 1 && d != n) return d;
		if (i == k) y = x, k <<= 1;
	}
	return d;
}

void print(long long n) {
	bool first = true;
	cout << n << " =";
	if (n < 0) {
		cout << " -1";
		first = false;
	}
	for( auto f: factors) {
		if (!first) cout << " x ";
		else cout << " ";
		for(int i = 0; i < f.second; ++i) {
			if(i) cout << " x ";
			cout << f.first;
		}
		first = false;
	}
	cout << endl;
}

ull find_factors(ull n) {
	return pollard_rho(n);
}

