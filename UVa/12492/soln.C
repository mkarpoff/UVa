/* UVa problem: 12492
 *
 * Topic: Combinatorics
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   For a set of commands to execute on a rubics. Find the number of time that
 *	 you must execute the whole series until it returns to the original stats
 *
 * Solution Summary:
 *
 *   I simulated. This is a very bad question because it takes alot of time and
 *	 I would skip this in a competition.
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

using namespace std;

int cube[50];

void rotate(const int f[5][4], bool upper) {
	int d = 1, s=0, e=3;
	if (!upper) { d = -1; s=3;e=0; }
	int s0 = cube[f[0][s]];
	int s1 = cube[f[1][s]];
	int s2 = cube[f[2][s]];
	int s3 = cube[f[3][s]];
	int s4 = cube[f[4][s]];
	for (int i = s; i != e; i+=d) {
		cube[f[0][i]] = cube[f[0][i+d]];
		cube[f[1][i]] = cube[f[1][i+d]];
		cube[f[2][i]] = cube[f[2][i+d]];
		cube[f[3][i]] = cube[f[3][i+d]];
		cube[f[4][i]] = cube[f[4][i+d]];
	}
	cube[f[0][e]] = s0;
	cube[f[1][e]] = s1;
	cube[f[2][e]] = s2;
	cube[f[3][e]] = s3;
	cube[f[4][e]] = s4;
}

/*
          1  2  3
          4     5
          6  7  8
 9 10 11 12 13 14 15 16 17
18    19 20    21 22    23
24 25 26 27 28 29 30 31 32
         33 34 35
         36    37
         38 39 40
         41 42 43
         44    45
         46 47 48
*/

const int F[5][4] = {
	{12,14,29,27},
	{13,21,28,20},
	{ 6,15,35,26},
	{ 7,22,34,19},
	{ 8,30,33,11}};
const int B[5][4] = {
	{41,43,48,46},
	{42,45,47,44},
	{38,32, 3, 9},
	{39,23, 2,18},
	{40,17, 1,24}};
const int D[5][4] = {
	{ 1, 3, 8, 6},
	{ 2, 5, 7, 4},
	{46,17,14,11},
	{47,16,13,10},
	{48,15,12, 9}};
const int U[5][4] = {
	{33,35,40,38},
	{34,37,39,36},
	{27,30,43,24},
	{28,31,42,25},
	{29,32,41,26}};

/*
          1  2  3
          4     5
          6  7  8
 9 10 11 12 13 14 15 16 17
18    19 20    21 22    23
24 25 26 27 28 29 30 31 32
         33 34 35
         36    37
         38 39 40
         41 42 43
         44    45
         46 47 48
*/
const int L[5][4] = {
	{ 9,11,26,24},
	{10,19,25,18},
	{ 1,12,33,41},
	{ 4,20,36,44},
	{ 6,27,38,46}};
const int R[5][4] = {
	{15,17,32,30},
	{16,23,31,22},
	{ 8,48,40,29},
	{ 5,45,37,21},
	{ 3,43,35,14}};

void move_cube(char c) {
	switch(c) {
		case 'F': return rotate(F,true);
		case 'f': return rotate(F,false);

		case 'B': return rotate(B,true);
		case 'b': return rotate(B,false);

		case 'U': return rotate(U,true);
		case 'u': return rotate(U,false);

		case 'D': return rotate(D,true);
		case 'd': return rotate(D,false);

		case 'L': return rotate(L,true);
		case 'l': return rotate(L,false);

		case 'R': return rotate(R,true);
		case 'r': return rotate(R,false);
		default: return;
	}
}

bool is_valid() {
	for (int i = 1; i <=48; ++i) {
		if (cube[i] != i) return false;
	}
	return true;
}

void reset_cube() {
	for (int i = 1; i <=48; ++i) {
		cube[i] = i;
} }


void exec_command(string &s) {
	
	for (auto c: s) {
		move_cube(c);
} }

int main() {
	string commands;
	while(!cin.eof()) {
		getline(cin, commands);
		reset_cube();
		int count = 0;
		do {
			exec_command(commands);
			++count;
		}	while (!is_valid());
		cin >> ws;
		cout << count << endl;
	}
	return 0;
}
