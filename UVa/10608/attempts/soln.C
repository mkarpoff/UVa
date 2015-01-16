/* UVa problem: 10608
 *
 * Topic: Data structures
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Transitivity of friends ie finding interconnected graph segments
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
#include <vector>
#include <set>

using namespace std;

int runTest();

int main() {

	int numTests = 0;

	cin >> numTests; 
	for (int run = 0; run < numTests; ++run ) {
		int max = runTest();
		cout << max << endl;
	}
	return 0;
}

int runTest() {

	int gsize;
	int lines;
	cin >> gsize >> lines;
	set<int> isAdj[gsize];
	for (int i =0; i < gsize; ++i) { isAdj[i] = set<int>();	}
//	bool adjMat[gsize][gsize]; // TODO change to working with sets

/*	for( int i = 0; i < gsize; ++i) {
		for( int j = 0; j < gsize; ++j) {
			adjMat[i][j] = false; // TODO change
		}
	}
	*/
	int t1,t2;
	for(int i = 0; i < lines; ++i ) {
		cin >> t1 >> t2;
		--t1; --t2;
//		adjMat[t1][t2] = true; // TODO change
//		adjMat[t2][t1] = true; // TODO change
		isAdj[t1].insert(t2);
		isAdj[t2].insert(t1);
	}

	vector<vector<int>> groups;
	bool visited[gsize];
	for (int i=0; i < gsize; ++i) {
		visited[i] = false;
	}

	for (int i=0; i < gsize; ++i) {
		if (! visited[i]) {
			set<int> openset;
			openset.insert(i);
			vector<int> ngroup;
			while (openset.size() > 0) {
				int cur = *(openset.begin()); 
				openset.erase(cur);
				visited[cur] = true;
				ngroup.push_back(cur);
				for (int j = 0; j < gsize; ++j) {
					//if (adjMat[cur] && ! visited[j]) openset.insert(j); // TODO change
					if (! visited[j]) {
						if (isAdj[cur].find(j) != isAdj[cur].end()) {
							 openset.insert(j);
						}
					}
				}
			}
			groups.push_back(ngroup);
		}
	}
	int max = 0;
	for (auto x: groups) {
		if (x.size() > max) max = x.size();
	}
	return max;
}
