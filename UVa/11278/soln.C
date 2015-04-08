/* UVa problem: 11278
 *
 * Topic: String
 *
 * Level: trivial
 * 
 * Brief problem description: 
 *
 *   Convert input from a regular keyboard and output as a custom format
 *
 * Solution Summary:
 *
 *   Giant switch statement
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

char get_replace(char);

int main() {
	char cur;
	while (cin >> noskipws >> cur ) {
		cout << get_replace(cur);
	}

	return 0;
}



char get_replace(char in) {
	switch (in) {
	case '`': return '`';
	case '1': return '1';
	case '2': return '2';
	case '3': return '3';
	case '4': return 'q';
	case '5': return 'j';
	case '6': return 'l';
	case '7': return 'm';
	case '8': return 'f';
	case '9': return 'p';
	case '0': return '/';
	case '-': return '[';
	case '=': return ']';

	case '~': return '~';
	case '!': return '!';
	case '@': return '@';
	case '#': return '#';
	case '$': return 'Q';
	case '%': return 'J';
	case '^': return 'L';
	case '&': return 'M';
	case '*': return 'F';
	case '(': return 'P';
	case ')': return '?';
	case '_': return '{';
	case '+': return '}';

	case 'q': return '4';
	case 'w': return '5';
	case 'e': return '6';
	case 'r': return '.';
	case 't': return 'o';
	case 'y': return 'r';
	case 'u': return 's';
	case 'i': return 'u';
	case 'o': return 'y';
	case 'p': return 'b';
	case '[': return ';';
	case ']': return '=';
	case '\\': return '\\';

	case 'Q': return '$';
	case 'W': return '%';
	case 'E': return '^';
	case 'R': return '>';
	case 'T': return 'O';
	case 'Y': return 'R';
	case 'U': return 'S';
	case 'I': return 'U';
	case 'O': return 'Y';
	case 'P': return 'B';
	case '{': return ':';
	case '}': return '+';
	case '|': return '|';

	case 'a': return '7';
	case 's': return '8';
	case 'd': return '9';
	case 'f': return 'a';
	case 'g': return 'e';
	case 'h': return 'h';
	case 'j': return 't';
	case 'k': return 'd';
	case 'l': return 'c';
	case ';': return 'k';
	case '\'': return '-';

	case 'A': return '&';
	case 'S': return '*';
	case 'D': return '(';
	case 'F': return 'A';
	case 'G': return 'E';
	case 'H': return 'H';
	case 'J': return 'T';
	case 'K': return 'D';
	case 'L': return 'C';
	case ':': return 'K';
	case '"': return '_';
	
	case 'z': return '0';
	case 'x': return 'z';
	case 'c': return 'x';
	case 'v': return ',';
	case 'b': return 'i';
	case 'n': return 'n';
	case 'm': return 'w';
	case ',': return 'v';
	case '.': return 'g';
	case '/': return '\'';

	case 'Z': return ')';
	case 'X': return 'Z';
	case 'C': return 'X';
	case 'V': return '<';
	case 'B': return 'I';
	case 'N': return 'N';
	case 'M': return 'W';
	case '<': return 'V';
	case '>': return 'G';
	case '?': return '"';
	default: return in;
	}
}
