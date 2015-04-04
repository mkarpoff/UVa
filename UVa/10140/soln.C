/* UVa problem: 11476
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Find the two farthest adjacent primes and two closes adjacent primes in a
 *	range
 *
 * Solution Summary:
 *
 *   Because we know the size of the range is <= 1000000 and the max number will
 *	 be 2^31 we can find all the primes <= sqrt(MAX). all the numbers in any 
 *	 range between 0 -> 2^31, we know that all non primes will have on of the 
 *	 first set of primes as a factor. This allows us to find all primes in that
 *	 range without computing all primes <= 2^31
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

typedef long long ll;

const ll s_size = (1<<16);// s_size > sqrt of max U value
const ll d_size = 1000010;

vector<ll> primes;
vector<ll> segprimes;

void generate_primes();
void generate_segprimes(ll,ll);
void print(ll,ll);

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
		if (segprimes.size() > 1) {
			print(L,U);
		} else {
			printf("There are no adjacent primes.\n");
		}
	}
	return 0;
}

void print(ll L, ll U) {
	ll C1 = 0, C2 = INT_MAX, D1 = 0, D2 = 0;
	for (int i = 1; i < segprimes.size(); ++i) {
		ll delta = segprimes[i] - segprimes[i-1];
		if ( delta < C2 - C1) {
			C1 = segprimes[i-1]; C2 = segprimes[i];
		}
		if ( delta > D2 - D1) {
			D1 = segprimes[i-1]; D2 = segprimes[i];
		}
	}
	printf("%lld,%lld are closest, %lld,%lld are most distant.\n", C1,C2,D1,D2);
}

ll start(ll L, ll n) {
	if (L % n) return max(L+(n-L%n),n*n);
	return max(L,n*n);
}

void generate_segprimes(ll L, ll U) {
	bitset<d_size> segsieve;
	segsieve.set();
	segprimes.clear();
	ll SU = sqrt(U);
	if (L == 1) { segsieve.set(0,0); }
	for (auto i: primes) {
		if (i > U) break;
		for (ll c = start(L, i); c <= U ; c += i) { 
			segsieve.set(c-L,0); 
	} }
	for (ll i = 0; i <= U-L; ++i){
		if (segsieve.test(i)) segprimes.push_back(i+L);
	}
}

void generate_primes() {
	bitset<s_size> sieve;
	sieve.set();
	sieve.set(0,0);
	sieve.set(1,0);
	for(ll i = 4; i < s_size; i+=2) { sieve.set(i, 0); }
	for(ll i = 3; i < s_size; i+=2) {
		if (sieve.test(i)) {
			for (ll c = i*i; c < s_size ; c += i) { 
				sieve.set(c,0);
	}	} } 

	primes.reserve(6550);
	for(int i = 0; i < s_size; ++i) {
		if (sieve.test(i)) primes.push_back(i);
	}
}
