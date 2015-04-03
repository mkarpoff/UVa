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
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */

#include <iostream>
#include <bitset>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

typedef unsigned long long ll;

const ll s_size = 1<<16;//sqrt of max U value
const ll d_size = 1000010;

bitset<s_size> sieve;
bitset<d_size> segsieve;

void generate_primes();
void generate_segprimes(ll,ll);
void f_adj_primes(ll&,ll&,ll&,ll&,ll,ll);

int main() {
	ll L, U;
	generate_primes();
	cin >> ws;
	while (!cin.eof()) {
		cin >> L >> U >> ws;
		if ( L >= U ) {
			printf("There are no adjacent primes.\n");
			continue;
		}
		generate_segprimes(L, U);
		ll C1 = 0, C2 = INT_MAX, D1 = 0, D2 = 0;
		f_adj_primes(C1,C2,D1,D2,L,U);
		if (C1 != 0 && C2 != INT_MAX && D1 != 0 && D2 != 0) {
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", C1,C2,D1,D2);
		} else {
			printf("There are no adjacent primes.\n");
		}
	}
	return 0;
}

void f_adj_primes(ll & C1, ll & C2, ll & D1, ll & D2, ll L, ll U) {
	ll lp;
	for(ll i = 0; i <= U-L; ++i) {
		if (segsieve.test(i)) {lp = i; break; }
	}
	for(ll i = lp+1; i <= U-L; ++i) { 
		if (!segsieve.test(i)) continue;
		ll delta = i - lp;
		if (delta < C2 - C1) {
			C2 = i+L; C1 = lp+L;
		}
		if ( delta > D2 - D1) {
			D2 = i+L; D1 = lp+L;
		}
		lp = i;
	}
}

ll start(ll L, ll n) {
	if (L % n) return max(L+(n-L%n),n*n);
	return max(L,n*n);
}

// Use a sieve of Eratosthenes
void generate_segprimes(ll L, ll U) {
	segsieve.set();
	ll SU = sqrt(U);
	if (L == 1) { segsieve.set(0,0); }
	for(ll i = 0; i <= SU; ++i) {
		if (sieve.test(i)) {
			for (ll c = start(L, i); c <= U ; c += i) { segsieve.set(c-L,0); 
} } } }

void generate_primes() {
	sieve.set();
	sieve.set(0,0);
	sieve.set(1,0);
	for(ll i = 4; i < s_size; i+=2) { sieve.set(i, 0); }
	for(ll i = 3; i < s_size; i+=2) {
		if (sieve.test(i)) {
			for (ll c = i*i; c < s_size ; c += i) { sieve.set(c,0);
}	} } }
