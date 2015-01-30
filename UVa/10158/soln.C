/* UVa problem: 10158
 *
 * Topic: Data Structures and Libraries
 *
 * Level: non-trivial
 * 
 * Brief problem description: 
 *
 *   There are a bunch of people in the room... its a UFDS problem
 *
 * Solution Summary:
 *
 *   Two arrays doing UFDS
 *
 * Used Resources:
 *
 *   Text Book
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Marcus Karpoff
 */
#include <iostream>
#include <iomanip>

using namespace std;
int pop;
int fri[10000];
int ene[10000];

void set_friends(int,int);
void set_enemies(int,int);
void are_friends(int,int);
void are_enemies(int,int);
void print_list();

int main() {
	int c, l,r;
	cin >> pop >> ws;
	for(int i = 0; i < pop; ++i) {
		fri[i] = i;
		ene[i] =-i-1;
	}
	cin >> c >> ws >> l >> ws >> r >> ws;
#ifdef DEBUG
	print_list();
	cout << endl;
#endif
	while (c||l||r) {
		switch(c) {
			case 1://Set Friends
#ifdef DEBUG
				cout << "Set " << l << " & " << r << " friends" << endl;
#endif
				set_friends(l,r);
				break;
			case 2://Set Enemies
#ifdef DEBUG
				cout << "Set " << l << " & " << r << " enemies" << endl;
#endif
				set_enemies(l,r);
				break;
			case 3://Are Friends?
#ifdef DEBUG
				cout << "Are " << l << " & " << r << " friends" << endl;
#endif
				are_friends(l,r);
				break;
			case 4://Are Enemies?
#ifdef DEBUG
				cout << "Are " << l << " & " << r << " enemies" << endl;
#endif
				are_enemies(l,r);
				break;
			default:
				break;
		}
#ifdef DEBUG
	print_list();
	cout << endl;
#endif
		cin >> c >> ws >> l >> ws >> r >> ws;
	}
	return 0;
}

void set_friends(int left,int right){
	if (fri[left] == ene[right]) { cout << -1 << endl; return;}
	int lf = fri[left], rf = fri[right];
	int le = ene[left], re = ene[right];
	if (le < 0 && re >= 0) {
		swap(le, re);
		swap(lf, rf);
	}
	for( int i = 0; i < pop; ++i) {
		if (fri[i] == rf || ene[i] == re) {
			fri[i] = lf; ene[i] = le;
		} else if (fri[i] == re || ene[i] == rf) {
			fri[i] = le; ene[i] = lf;
		}
	}
}

void set_enemies(int left,int right){
	if (fri[left] == fri[right]) { cout << -1 << endl; return; }
	int lf = fri[left], rf = fri[right];
	int le = ene[left], re = ene[right];
	if (le < 0 && re < 0) {
		le = rf;
		re = lf;
	}
	if (le < 0 && re >= 0) {
		swap(le, re);
		swap(lf, rf);
	}
	for (int i = 0; i < pop; ++i) {
		if (fri[i] == re || ene[i] == rf) {
			fri[i] = lf;
			ene[i] = le;
		} else if (fri[i] == rf || ene[i] == re) {
			fri[i] = le;
			ene[i] = lf;
		}
	}
}

void are_friends(int left,int right){
	if (fri[left] == fri[right]) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return;
}

void are_enemies(int left,int right){
	if (fri[left] == ene[right]) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return;
}

void print_list() {
	cout << "Fri["; 
	for( int i = 0; i < pop; ++i) {
		cout << setw(3) <<  fri[i] << ' ';
	} cout << ']' << endl;
	cout << "Ene["; 
	for( int i = 0; i < pop; ++i) {
		cout << setw(3) <<  ene[i] << ' ';
	} cout << ']' << endl;


}
