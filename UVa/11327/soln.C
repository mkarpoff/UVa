/* UVa problem: 11327
 *
 * Topic: Number Theory
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   find the k-th rational number in a sequence
 *
 * Solution Summary:
 *
 *   Use EulerPhi from book to find the number of relative primes for any 
 *	 denominator between 1 and 200000 which is the largest as shown by the 
 *	 Example intut and exapmle output then use gcd to find the numerator
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
#include <vector>

using namespace std;
typedef long long ll;

const ll MAX_K = 12158598919;
const ll MAX = 200005; // promblem shows max size
ll ep_range[MAX];

vector<ll> primes;

void Sieve() {
	bool sieve[MAX];
	memset(sieve, true, sizeof sieve);
	for(int i = 4; i < MAX; i+=2) { sieve[i] = false;}
	primes.push_back(2);
	for(int i = 3; i < MAX; i+=2) {
		if (sieve[i]) {
			primes.push_back(i);
			for (int k = i*i; k < MAX; k+=i) sieve[i]=false;
}	} }

ll EulerPhi(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;	// start from ans = N
	while (PF * PF <= N) {
		if (N % PF == 0) ans -= ans / PF;	// only count unique factor
		while (N % PF == 0) N /= PF;
		PF = primes[++PF_idx];
	}
	if (N != 1) ans -= ans / N;	// last factor
	return ans;
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

int main() {
	Sieve();
	memset(ep_range, 0, sizeof ep_range);
	ep_range[1] = 2;
	for (ll i = 2, tot = 2; i < MAX; ++i) {
		ll t = EulerPhi(i);
		tot+= t;
		ep_range[i] = tot;
	}
	ll k;
	cin >> k;
	while (k) {
		if (k < 3) {
			cout << k-1 << "/1" << endl;
			cin >> k;
			continue;
		}
		ll den = 1;
		for (; ep_range[den] < k; ++den) ;;
		ll num = 1;
		for (ll i = ep_range[den-1]+1; i < k; ++i) {
			while (gcd(++num, den) != 1) ;
		}
		cout << num << "/" << den << endl;	
		cin >> k;
	}
	return 0;
}
