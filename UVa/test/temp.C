#include <iostream>
#include <bitset>

using namespace std;

typedef unsigned long long ll;

template<ll M, ll N>
ll p(bitset<M> & b) {
	return p<M, N-1>(b) + 1;	
}

template<ll M, ll 2>
ll p(bitset<M> & b) { return 2;}

int main() {
	bitset<2> b;
	cout << "E " << p<2, 2>(b);
	return 0;	
}
