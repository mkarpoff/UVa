/* UVa problem: 10065
 *
 * Topic: Geometry
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   There are tiles that fit in a box canculate how much space is wasted
 *
 * Solution Summary:
 *
 *   Delta in area between Convex hull and the area of the polygon
 *
 * Used Resources:
 *
 *   Source code from book for area and convect hull
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

struct point { double x, y;
  point() { x = y = 0.0; }
  point(double _x, double _y) : x(_x), y(_y) {}
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct vec { double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y); }

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); }

double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }

bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

point pivot;
bool angleCmp(point a, point b) {
  if (collinear(pivot, a, b))
    return dist(pivot, a) < dist(pivot, b);
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }

vector<point> CH(vector<point> P) {
  int i, j, n = (int)P.size();
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]);
    return P;
  }

  int P0 = 0;
  for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;

  point temp = P[0]; P[0] = P[P0]; P[P0] = temp;

  pivot = P[0];
  sort(++P.begin(), P.end(), angleCmp);

  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
  i = 2;
  while (i < n) {
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
    else S.pop_back(); }
  return S; }

int main() {
	int N, test = 1;
	cin >> N;
	while (N) {
		vector<point> tile;
		for(int i = 0; i < N; ++i) {
			double t1,t2; cin >> t1 >> t2;
			tile.push_back(point(t1,t2));
		}
		tile.push_back(tile.front());
		double ta = area(tile);
		vector<point> box = CH(tile);
		double ba = area(box);
		double waste = 100 * (ba-ta)/ba;
		cout << "Tile #" << test++ << endl;
		cout << "Wasted Space = " << fixed << setprecision(2) << waste << " %";
		cout << endl << endl;
		cin >> N;
	}
  return 0;
}
