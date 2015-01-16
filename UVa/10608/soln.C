/* UVa problem: 10608
 *
 * Topic: Data Structures
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   It is essentially finding the largest connected graph segment
 *
 * Solution Summary:
 *
 *   Implemented an adjacency list sacrificing time in favour of space over 
 *   an adjacency matrix which is faster.
 *
 * Used Resources:
 *
 *   "Competitive Programming 3" - Steven Halim (pg 49-50)
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */

#include <iostream>
#include <set>

using namespace std;

typedef set<int> si;

int getInt();
int runTest();

si * createAdjacencyList(int numPairs);
void populateAdjacencyList(int numPairs, si * list);

int findLargestGroupSize(int size, si * list);
int getFloodSize(int start, int size, bool * varray, si * list);

int main() {
	int testToRun = getInt();
	for( int i = 0; i < testToRun; ++i) {
		int testResult = runTest();	
		cout << testResult << endl;
	}
	return 0;
}

/*
 * A simple function to read in an integer
 */
int getInt() {
	int test;
	cin >> test;
	return test;
}

int runTest() {
	int villageSize = getInt();
	int numberOfPairs = getInt();
	int largestGroup = 0;
	si * AdjList = createAdjacencyList(villageSize);
	populateAdjacencyList(numberOfPairs, AdjList);
	largestGroup = findLargestGroupSize(villageSize, AdjList);	
	delete [] AdjList;
	return largestGroup;
}

/*
 * initializes and Adjacency List
 */
si * createAdjacencyList(int numPairs) {
#ifdef debug
	cout << "Creating Adjacency List: ";
#endif
	si * list = new si[numPairs];
#ifdef debug
	cout << "Done" <<endl;
#endif
	return list;
}

/*
 * Populates the list by reading in numPairs pairs and adding them to list
 */
void populateAdjacencyList(int numPairs, si * list) {
#ifdef debug
	cout << "Populating list: ";
#endif
	int t1, t2;	
	for(int i = 0; i < numPairs; ++i) {
		t1 = getInt() - 1;
		t2 = getInt() - 1;
		list[t1].insert(t2);
		list[t2].insert(t1);
	}
#ifdef debug
	cout << "Done" << endl;
#endif
}

int findLargestGroupSize(int size, si * list) {
	int largestfound = 0;
#ifdef debug
	cout << "Finding Largest group size: ";
#endif
	bool * visited = new bool[size];
	for( int i = 0; i < size; ++i ) {
		visited[i] = false;
	}
	for( int i = 0; i < size; ++i ) {
		if (! visited[i]) {
			int found = getFloodSize(i, size, visited, list);
			if (found > largestfound) {
				largestfound = found;
			}
		}
	}
	delete [] visited;
#ifdef debug
	cout << "Done" << endl;
#endif
	return largestfound;
}

int getFloodSize(int start, int size, bool * varray, si * list) {
	int floodsize = 0;
	int cur;
	set<int> openset;
	openset.insert(start);
	while(openset.size() > 0) {
		++floodsize;
		cur = (*openset.begin());
		openset.erase(cur);
		varray[cur] = true;
		for( auto neighbor:list[cur]) {
			if (!varray[neighbor]) {
				openset.insert(neighbor);
			}
		}
	}	
	return floodsize;
}
