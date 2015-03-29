/* UVa problem: 00674
 *
 * Topic: Dynamic Programming
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   ...
 *
 * Solution Summary:
 *
 *   Algorithmic idea, data structures ...
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
#include <cassert>

using namespace std;

typedef long long ll;
typedef const long long cll;


template<ll T> struct C: integral_constant<ll, 0> {};
template<> struct C<4> { static cll v = 50;};
template<> struct C<3> { static cll v = 25; };
template<> struct C<2> { static cll v = 10; };
template<> struct C<1> { static cll v = 5; };
template<> struct C<0> { static cll v = 1; };


template<ll T, ll V, bool isNeg>
struct rec { 
	static cll r = rec<T,V,(V<0)>::r; 
};

template<ll T, ll V> struct rec <T, V, true>{ 
	static cll r = 0;
};

template<ll T, ll V>
struct rec<T,V,false> {
	static cll r = rec<T+1,V,(V<0)>::r + rec<T,V-C<T>::v,(V-C<T>::v<0)>::r;
};

template<ll V> struct rec<0,V, false> {
	static cll r = rec<1,V,(V<0)>::r + rec<0,V-C<0>::v,(V-C<0>::v<0)>::r;
	static void add_values(ll * v) {
		if (v[V] != 0) return;
		rec<0,V-C<0>::v,(V-C<0>::v<0)>::add_values(v);
		v[V] = rec<0,V, false>::r;
	};
};

template<> struct rec<0,0,false> {
	static cll r = 1;
	static void add_values(ll * v) {
		v[0] = 1;
	};
};

template<ll T> struct rec<T, 0, false>{	static cll r = 1; };
template<ll V> struct rec<5, V, false> { 	static cll r = 0; };

ll memo[8000];

int main() {
	memset(memo, 0, sizeof(memo[0]) * 8000);
	rec<0, 800,false>::r;
	rec<0,1600,false>::r;
	rec<0,2400,false>::r;
	rec<0,3200,false>::r;
	rec<0,4000,false>::r;
	rec<0,4800,false>::r;
	rec<0,5600,false>::r;
	rec<0,6400,false>::r;
	rec<0,7200,false>::r;
	rec<0,8000,false>::r;
	rec<0,7500,false>::r;
	ll end = rec<0,8000,false>::r;
	rec<0, 800,false>::add_values(memo);
	rec<0,1600,false>::add_values(memo);
	rec<0,2400,false>::add_values(memo);
	rec<0,3200,false>::add_values(memo);
	rec<0,4000,false>::add_values(memo);
	rec<0,4800,false>::add_values(memo);
	rec<0,5600,false>::add_values(memo);
	rec<0,6400,false>::add_values(memo);
	rec<0,7200,false>::add_values(memo);
	rec<0,8000,false>::add_values(memo);
	rec<0,7500,false>::add_values(memo);
	rec<0,8000,false>::add_values(memo);
	assert(memo[8000] == end);
	ll target;
	while (!cin.eof()) {
		cin >> target >> ws;
		cout << memo[target] << endl;
	}
	return 0;
}
