/* UVa problem: 00811
 *
 * Topic: Geometry
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *  Find the minimum number of nodes to remove to create a perimter around the
 *	rest
 *
 * Solution Summary:
 *
 *  US CH to calculate the cost to surround a bunch of points and use 
 *	backtracking to find the best solution
 *
 * Used Resources:
 *
 *  http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cmath> 

using namespace std;
typedef long long ll;

struct point {
	double x, y;
	inline bool operator== (const point & o) const {return x == o.x && y == o.y;}
};

struct tree {
	ll v, l;
	point p;
};

struct vec { // Vector as in magnitude and direction vector
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {} 
};

vec toVec(point, point);
double CH(vector<point>);
bool angle_cmp(point, point);
bool ccw(point, point, point);
bool collinear(point, point, point);
double dist(point, point);
double cross(vec, vec);

const double EPS = 0.0000000001;
bool bs = false;

point pivot;
tree statis_list[20];
int main() {
	int n, test = 0;
	cout.precision(2);
	cin >> n;
	while (n) {
		for (int i = 0; i < n; ++i) {
			cin >> statis_list[i].p.x >> statis_list[i].p.y;
			cin >> statis_list[i].v >> statis_list[i].l;
			point t = statis_list[i].p;
			if (!(i-1) || pivot.x > t.x || (pivot.x == t.x && pivot.y > t.y)) {
				pivot = t;
			}
		}
		double best_cost = numeric_limits<double>::max();
		int best_mask;
		double best_bounds = 0;
		double best_CH = 0;
		vector<point> forest;
		for(int mask = (1<<n)-1; mask > 0; --mask) {
			forest.clear();
			double bounds = 0, cost = 0;
			int size = 0;
			for (int i = 0; i < n; ++i) {
				if ((mask>>i)&1) {
					bounds += statis_list[i].l;
					cost += statis_list[i].v;
				} else {
					forest.push_back(statis_list[i].p);
				}
			}
			if ( cost < best_cost ) {

				double ch = CH(forest);
				if (ch <= bounds ) {
					best_cost = cost;
					best_bounds = bounds;
					best_mask = mask;
					best_CH = ch;
				}
			}
		}
		if (test++) cout << endl;
		cout << "Forest " << test << endl;
		cout << "Cut these trees:";
		for (int i = 0; i < n; ++i) {
			if ((best_mask>>i)&1) { cout << " " << i+1; }
		}
		cout << endl << "Extra wood: " << fixed << best_bounds-best_CH << endl;
		cin >> n;
	}
	return 0;
}	


double CH(vector<point> P) {
	// Code from wikibooks start
	int n = P.size(), k = 0;
	vector<point> S(2*n);
	sort(P.begin(), P.end(), angle_cmp);

	for( int i = 0; i < n; ++i) {
		while (k >= 2 && cross(toVec(S[k-2], S[k-1]),toVec(S[k-2], P[i])) <= 0) k--;
		S[k++] = P[i];
	}
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(toVec(S[k-2], S[k-1]), toVec(S[k-2],P[i])) <= 0) k--;
		S[k++] = P[i];
	}
	// Code from wikibooks end
	double length = 0;
	if (S.size()) {
		S.resize(k);
		for (int i = 1; i < S.size(); ++i) {
			length += dist(S[i-1], S[i]);
		}
	}
	return length;
}


bool angle_cmp(point a, point b) {
	if (collinear(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
	int d1x(a.x - pivot.x), d1y(a.y - pivot.y);
	int d2x(b.x - pivot.x), d2y(b.y - pivot.y);
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}


bool collinear(point  a, point  b, point  c) {
	return fabs(cross( toVec(a,b), toVec(a,c))) < 0; 
}


bool ccw(point a, point b, point c) { return cross(toVec(a,b), toVec(a,c)) > 0;}
double dist(point  a, point  b) { return hypot(a.x - b.x, a.y - b.y); }
double cross( vec a, vec b) {	return a.x * b.y - a.y * b.x; }
vec toVec(point  a, point  b) {	return vec(b.x - a.x, b.y - a.y); }
