#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

unsigned count(unsigned* a, unsigned n) {
	unsigned sum = 0;
	for (unsigned i = 0; i < n; ++i) {
		sum += a[i];
	}
	return sum;
}

void display(unsigned n) {
	for (unsigned i = 0; i < n; ++i) {
		cout << "*";
	}
}

int main(int argc, char* argv[]) {
	unsigned dots = 200;
	
	// command line args
	if (argc > 1) {
		stringstream ss(argv[0]);
		ss >> dots;
	}

	// initialize ascii
	unsigned ascii[256];
	for (unsigned i = 0; i < 256; ++i) {
		ascii[i] = 0;
	}

	// get input from stdin
	char c;
	while (1) {
		char c = getchar();
		if (c == EOF) {
			break;
		}
		if (isalpha(c)) {
			++ascii[c];
		}
	}
	
	// add uppercase counts to lowercase
	for (unsigned i = 65; i < 91; ++i) {
		unsigned temp = ascii[i];
		ascii[i] = 0;
		ascii[i + 32] += temp;
	}
	
	unsigned ratios[256];
	unsigned tot = count(ascii, 256);
	// calculate ratio
	for (unsigned i = 0; i < 256; ++i) {
		if (islower((char)i))
			ratios[i] = (dots * ascii[i]) / tot;
	}

	// display output
	for (unsigned i = 0; i < 256; ++i) {
		if (islower((char)i)) {
			cout << (char)i << " (" << ascii[i] << " - " << (double)ascii[i]/(double)tot << ")" << "\t";
			display(ratios[i]);
			cout << endl;
		}
	}
	return 0;
}
