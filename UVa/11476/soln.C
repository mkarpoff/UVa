/* UVa problem: 11476
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  find the prime factors of really freaking big numbers 
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

const ull s_size = 10000000;
const ull num_primes = 5761455; 
const int Cs[] = {-1, 1, 3};

map<ull, int>	factors;
vector<ull> primes;

void rec_factor(ull n);
void generate_primes();
void print(ull n);
void increase(ull n);

ull pollard_rho(ull n, ull c);


int main() {
	int tests;
	cin >> tests;
	generate_primes();
	while (tests--) {
		ull n;
		cin >> n;
		// Reset vars
		factors.clear();

		// Recursively find all factors
		rec_factor(n);

		// Print output
		print(n);
	}
	return 0;
}


void rec_factor(ull n) {
	if (n == 1) { return; }
	if (n < s_size*s_size) {
	for (auto largest_found: primes) {
		if ( n < largest_found*largest_found) { break; }
		while (!(n % largest_found)) {
			increase(largest_found);
			n /= largest_found;
		}
	}
	if (n != 1) {
		increase(n);
		return;
	}
	} else {
	ull p = n;
	for (int c = 0; p == n&&c < 3; ++c) {
		p = pollard_rho(n, Cs[c]);
	}
	if ( p == n) {
		increase(p);
		return;
	}
	rec_factor(p);
	rec_factor(n/p);
	}
}


// Use a sieve of Eratosthenes
void generate_primes() {
	bitset<s_size> *sieve = new bitset<s_size>();
	sieve->set();
	primes.reserve(num_primes);
	for(ull i = 2; i < s_size; ++i) {
		if (sieve->test(i)) {
			primes.push_back(i);
			for (ull c = i*i; c < s_size; c += i) { sieve->set(c,0); }
		}
	}
	delete sieve;
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

void increase(ull n) {
	if (factors.find(n) != factors.end()) {
		++factors[n];
	} else {
		factors[n] = 1;
	}
}


ull g(ull a, ull c, ull n) {
	ull b = a, x =0;
	a %= n;
	while (b > 0 ) {
		if (b & 1) { x = (x + a) % n; }
		b >>= 1;
		a = (a <<1) % n;
	}
	return (x+c)  % n;
}

ull gcd( ull a, ull b) {
	return !b ? a : gcd(b, a % b);
}

ull pollard_rho(ull n, ull c) {
	ull x = 2, y = 2;
	while(1) {
		x = g(x, c, n);
		y = g(y, c, n);
		y = g(y, c, n);
		long long d = gcd(x-y, n);
		if (d > 1) return d;
	}
	return n;
//	ull x_fixed = 2;
//	ull cycle_size = 2;
//	ull x = 2;
//	ull h = 1;
//	
//	while (h == 1) {
//		int count = 1;
//		while (count <= cycle_size && h == 1) {
//			x = (g(x, n) + c) % n ;
//			count = count + 1;
//			h = gcd(x - x_fixed, n);
//		}
//	
//	 	if (h != 1)
//			break;
//	
//		cycle_size *=2;
//		x_fixed = x;
//	}
//	return h;
}
