/* UVa problem:: 10034
 *
 * Topic: 
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   Find the minimum spanning tree on a coordinate system
 *
 * Solution Summary:
 *
 *   Kruskals Alg
 *
 * Used Resources:
 *
 *   book
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;

double frec[100][2];
int UF[100];
vector <pair <double, ii> > adj_list;
int V;

bool lt(const pair<double, ii>& f, const pair<double, ii> s);
void makeSameSet(int, int);

int main() {
	int test = 0;
	cin >> test;
	while(test--) {
		cin >> V;
		for (int i = 0; i < V; ++i) {
			UF[i] = i;
			cin >> frec[i][0] >> frec[i][1];
		}
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				if (i != j) {
					adj_list.push_back(make_pair(sqrt( 
						pow(frec[i][0]-frec[j][0], 2)+
						pow(frec[i][1]-frec[j][1], 2)), ii(i,j)));
				}
			}
		}
		sort(	adj_list.begin(), adj_list.end(), lt);
		double cost = 0;
		for (auto &front: adj_list) {
			if (UF[front.second.first] != UF[front.second.second]) {
				cost += front.first;
				makeSameSet(front.second.first, front.second.second);
			}
		}
		printf("%0.2f\n", cost);
		adj_list.clear();
		if (test) cout <<endl;
	}
	return 0;
}


bool lt(const pair<double, ii>& f, const pair<double, ii> s) {
	return f.first < s.first;
}

void makeSameSet(int f, int s) {
	int fs = UF[f], ss = UF[s];
	for (int i = 0; i < V; ++i) {
		if (UF[i] == ss) {
			UF[i] = fs;
		}
	}
}
