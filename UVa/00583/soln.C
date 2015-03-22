/* UVa problem: 11476
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  find the prime factors of numbers 
 *
 * Solution Summary:
 *
 *   sieve of Eratosthenes
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

typedef long long ull;

const ull s_size = 50000;
const ull num_primes = 10000; 

map<ull, int>	factors;
vector<ull> primes;

void factor(ull n);
void generate_primes();
void print(ull n);
void increase(ull n);


int main() {
	int tests;
	long long n;
	cin >> n;
	generate_primes();
	while (n) {
		factors.clear();
		factor(abs(n));
		print(n);
		cin >> n;
		}
	return 0;
}

void factor(ull n) {
	if (n == 1) { return; }
	for (auto largest_found: primes) {
		if ( n < largest_found*largest_found) { break; }
		while (!(n % largest_found)) {
			increase(largest_found);
			n /= largest_found;
		}
	}
	if (n != 1) {
		increase(n);
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

void increase(ull n) {
	if (factors.find(n) != factors.end()) {
		++factors[n];
	} else {
		factors[n] = 1;
	}
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
