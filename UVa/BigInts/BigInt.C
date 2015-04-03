#include <iostream>
#include <iomanip>
#include <vector>
#include <climits>

struct Bint {
	static const long long SEG_MAX = 1000000000;
	std::vector<unsigned long> num;
	bool is_neg;

	Bint(long i) {
		num.push_back(i);
		is_neg = i < 0;
	};
	
	Bint & operator= (const Bint & oth) {
		num = oth.num;
		is_neg = oth.is_neg;
	}
	
	friend std::ostream& operator<< (std::ostream & stream, const Bint & pnum) {
		if (pnum.is_neg) stream << '-';
		stream << pnum.num[0];
		for (int i = 1; i < pnum.num.size(); ++i ) {
			stream << std::setfill('0') << std::setw(9) << pnum.num[i];
		}return stream;
	};

	Bint operator *= (const long & l) {
		if (l == 0) {
			num.clear(); num.push_back(0);
			is_neg = false;
		}
		is_neg ^= l < 0;
		long long o = abs(l); 
		int start = 0;
		if ( ((long long) num[0]) * o >= SEG_MAX) {
			start = 1; num.insert(num.begin(),0);
		}
		for (int i = start; i < num.size(); ++i) {
			long long t = ((long long) num[i]) * o;	
			if (t >= SEG_MAX) {num[i-1] += (t/SEG_MAX); }
			num[i] = t % SEG_MAX;
		}
		return *this;
	};
	
	Bint operator * (const long & l) {
		if (l == 0) {
			return Bint(0);
		}
		Bint n = *this;
		n.is_neg ^= l < 0;
		long long o = abs(l); 
		int start = 0;
		if ( ((long long) n.num[0]) * o >= SEG_MAX) {
			start = 1; n.num.insert(n.num.begin(),0);
		}
		for (int i = start; i < n.num.size(); ++i) {
			long long t = ((long long) n.num[i]) * o;	
			if (t >= SEG_MAX) {n.num[i-1] += (t/SEG_MAX); }
			n.num[i] = t % SEG_MAX;
		}
		return n;
	};

};

using namespace std;
int main() {
	Bint a(1000000);
	cout << a << endl;
	int n = 10;
	for (int i = 1; i < 20; ++i) {
		a*=10;
		cout << a << endl;
		cout << a*40<<endl;
	}
	return 0;
}
