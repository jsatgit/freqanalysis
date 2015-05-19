#include <iostream>
#include <cctype>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	int max;

	// command line args
	if (argc > 1) {
		stringstream ss(argv[0]);
		ss >> max;
	}
	
	map<string, int> words;
	
	// read words
	string w;
	while (cin >> w) {
		if (words.count(w) == 0) {
			words[w] = 1;
		}
		else {
			++words[w];
		}
	}

	

	return 0;
}
