#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // for getopt


// Output completely random printable ASCII characters
// If -l <length> is specified, output a newline char after <length> characters
// Otherwise, include newlines in the character set and output them randomly

void printRandomCharacters(int length) {
	const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()-_=+[]{}|;:,.<>?/~`";
	const int charsetSize = sizeof(charset) - 1;

	while (true) {
		for (int i = 0; i < length; ++i) {
			std::cout << charset[rand() % charsetSize];
		}
		std::cout << std::endl;
	}
}

void printRandomCharactersWithNewlines() {
	const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()-_=+[]{}|;:,.<>?/~`\n";
	const int charsetSize = sizeof(charset) - 1;

	while (true) {
		std::cout << charset[rand() % charsetSize];
	}
}

int main(int argc, char* argv[]) {
	// getopt
	int length = 0;
	int opt;
	while ((opt = getopt(argc, argv, "l:h")) != -1) {
		switch (opt) {
			case 'l':
				length = std::atoi(optarg);
				break;
			case 'h':
				[[ fallthrough ]];
			default:
				std::cerr << "Usage: " << argv[0] << " [-l <length>]" << std::endl;
				return 1;
		}
	}
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
	if (length > 0) {
		printRandomCharacters(length);
	} else {
		printRandomCharactersWithNewlines();
	}
	return 0;
}
