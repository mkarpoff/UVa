/* UVa problem: 00101
 *
 * Topic: Data Structures
 *
 * Level: non-trivial
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
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int MAX = 0;
vector<int> stacks[24];
int lookup[24];
enum ops { MOVE=0, PILE=1, QUIT=2, ops_size=3 };
const string opn[] = {"move", "pile", "quit"};
enum tgts { ONTO=0, OVER=1, tgts_size=2 };
const string tgtn[] = {"onto", "over"};

void solv();

bool isLegal(int a, int b);

void mon(int a, int b);
void mov(int a, int b);
void pon(int a, int b);
void pov(int a, int b);

int readOp();
int readTgt();
int readInt();

template <class T>
void reset_vars(int t, T it, T end);
void print();

int main() {
	cin >> MAX;
	for(int i = 0; i < MAX; ++i) {
		stacks[i].push_back(i);
		lookup[i] = i;
	}
	solv();
	print();
	return 0;
}

void solv() {
	int op;
	int tgt;
	int a;
	int b;
	while (true) {
		op = readOp();
		if (op == QUIT) { return;	}
		a = readInt();
		tgt = readTgt();
		b = readInt();
		if (isLegal(a,b)) {
			if (op == MOVE) {
				if (tgt == ONTO) { mon(a,b);}
				else { mov(a,b);}
			} else {
				if (tgt == ONTO) { pon(a,b);}
				else { pov(a,b);}
			}
		}
	}
}

bool isLegal(int a, int b) {
	return (a != b) && (lookup[a] != lookup[b]);
}

void mon(int a, int b) {
	int a_stack = lookup[a], b_stack = lookup[b];
	auto a_it = find(stacks[a_stack].begin(), stacks[a_stack].end(), a);
	auto b_it = find(stacks[b_stack].begin(), stacks[b_stack].end(), b);
	auto t_it(a_it);
	reset_vars(a_stack, ++t_it, stacks[a_stack].end());
	reset_vars(b_stack, ++b_it, stacks[b_stack].end());
	stacks[a_stack].erase(a_it);
	stacks[b_stack].push_back(a);
	lookup[a] = b_stack;
}

void mov(int a, int b) {
	int a_stack = lookup[a], b_stack = lookup[b];
	auto a_it = find(stacks[a_stack].begin(), stacks[a_stack].end(), a);
	auto t_it(a_it);
	reset_vars(a_stack, ++t_it, stacks[a_stack].end());
	stacks[a_stack].erase(a_it);
	stacks[b_stack].push_back(a);
	lookup[a] = b_stack;
}

void pon(int a, int b) {
	int a_stack = lookup[a], b_stack = lookup[b];
	auto a_it = find(stacks[a_stack].begin(), stacks[a_stack].end(), a);
	auto b_it = find(stacks[b_stack].begin(), stacks[b_stack].end(), b);
	reset_vars(b_stack, ++b_it, stacks[b_stack].end());
	auto t_it(a_it);
	stacks[b_stack].insert(stacks[b_stack].end(), a_it, stacks[a_stack].end());
	for (; t_it != stacks[a_stack].end(); ++t_it) {
		lookup[*t_it] = b_stack;
	}
	stacks[a_stack].erase(a_it, stacks[a_stack].end());
}

void pov(int a, int b) {
	int a_stack = lookup[a], b_stack = lookup[b];
	auto a_it = find(stacks[a_stack].begin(), stacks[a_stack].end(), a);
	auto t_it(a_it);
	stacks[b_stack].insert(stacks[b_stack].end(), a_it, stacks[a_stack].end());
	for (; t_it != stacks[a_stack].end(); ++t_it) {
		lookup[*t_it] = b_stack;
	}
	stacks[a_stack].erase(a_it, stacks[a_stack].end());
}

template <class T>
void reset_vars(int t, T it, T end) {
	T it2(it);
	for(; it != end; ++it) {
		stacks[*it].push_back(*it);
		lookup[*it] = *it;
	}
	stacks[t].erase(it2, end);
}

int readOp() {
	string t;
	cin >> t;
	for (int x = 0; x < ops_size; ++x) {
		if(t.compare(opn[x]) == 0) {
			return x;
		}
	}
	return QUIT;
}

int readTgt() {
	string t;
	cin >> t;
	for (int x = 0; x < tgts_size; ++x) {
		if(t.compare(tgtn[x]) == 0) {
			return x;
		}
	}
	return OVER;
}
int readInt() {
	int t;
	cin >> t;
	return t;
}

void print() {
	for(int i = 0; i < MAX; ++i) {
		cout << i << ':';
		for (auto x: stacks[i]) {
			cout << ' ' << x;
		}
		cout << endl;
	}
}
