/* UVa problem: 00527
 *
 * Topic: Geometry
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *	There is a box that is being cut and you need to cut the output partitions
 *
 * Solution Summary:
 *
 *  Count the unique lines and then count the intersection points 
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
#include <map>
#include <set>
#include <tuple>
#include <cmath>

using namespace std;

typedef pair<double, double> coor;

const double EPS = 0.00000000001;
const double max_x = 1000, min_x = 0;
const double max_y = 1000, min_y = 0;


struct line {double a,b,c;};
line lines[8];
map<coor, set<int>> inter;

bool add_line(coor,coor,int);
bool are_parallel(int,int);
bool are_same(int,int);
bool are_intersect(int,int);
int eql(double,double);

int main() {
	int test;
	cin >> test;
	while (test--) {
		inter.clear();
		int cuts;
		cin >> cuts;

		for( int i = 0; i < cuts;) {
			coor c1, c2;
			cin >> c1.first >> c1.second >> c2.first >> c2.second;
			if (!add_line(c1,c2, i)) {
				--cuts;
			} else {
				++i;
			}
		}

		int count = cuts+1;
		for( int i = 0; i < cuts; ++i) {
			for( int j = 0; j < i; ++j) {
				are_intersect(i, j);
			}
		}
		for (auto x : inter) {
			count += x.second.size()-1;
		}
		cout << count << endl;
		if (test) {cout << endl;}
	}
	return 0;
}

bool add_line(coor p1, coor p2, int p) {
	if (eql(p1.first, p2.first)) {
		lines[p].a = 1.0; lines[p].b = 0.0; lines[p].c = - p1.first;
	} else {
		lines[p].a = - (double)(p1.second - p2.second) / (p1.first - p2.first);
		lines[p].b = 1.0;
		lines[p].c = - (lines[p].a * p1.first) - p1.second;
	}
	for (int i = 0; i < p; ++i) {
		if (are_same(i, p)) 
			return false;
	}
	return true;
}

bool are_parallel(int p1, int p2) {
	return eql(lines[p1].a, lines[p2].a) && eql(lines[p1].b, lines[p2].b);
}

bool are_same(int p1, int p2) {
	return are_parallel(p1,p2) && eql(lines[p1].c, lines[p2].c);
}

bool are_intersect(int p1, int p2) {
	coor p;
	if (are_parallel(p1, p2)) return false;
	p.first = (lines[p2].b * lines[p1].c - lines[p1].b * lines[p2].c) /
						(lines[p2].a * lines[p1].b - lines[p1].a * lines[p2].b);
	if (!eql(lines[p1].b, 0.0)) {
		p.second = -(lines[p1].a * p.first + lines[p1].c);
	}	else {
		p.second = -(lines[p2].a * p.first + lines[p2].c);
	}
	if (min_x+1 <= p.first && p.first <= max_x-1 &&
			min_y+1 <= p.second && p.second <= max_y-1) {
		inter[p].insert(p1);
		inter[p].insert(p2);
		return true;
	} else {
		return false;
	}
}

int eql(double l, double r) {
	if (fabs(l - r) < EPS) return 1; 
	return 0;
}
