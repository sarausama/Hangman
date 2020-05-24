// hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>


void hanged_man(int lives) {
	if (lives == 0) {
		std::cout << "   ___________" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          (_)" << std::endl;
		std::cout << "  |          \\|/" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          / \\" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "__|__" << std::endl;
	}
	else if (lives == 1) {
		std::cout << "   ___________" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          (_)" << std::endl;
		std::cout << "  |          \\|/" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          / " << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "__|__" << std::endl;
	}
	else if (lives == 2) {
		std::cout << "   ___________" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          (_)" << std::endl;
		std::cout << "  |          \\|/" << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "__|__" << std::endl;
	}
	else if (lives == 3) {
		std::cout << "   ___________" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          (_)" << std::endl;
		std::cout << "  |          \\|" << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "__|__" << std::endl;
	}
	else if (lives == 4) {
		std::cout << "   ___________" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |          (_)" << std::endl;
		std::cout << "  |          " << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "__|__" << std::endl;
	}
	else {
		std::cout << "   ___________" << std::endl;
		std::cout << "  |           |" << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |           " << std::endl;
		std::cout << "  |          " << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "__|__" << std::endl;
	}
}
void random_word(std::string* word) {
	std::string food[12] = { "avengers","harry potter","joker","the lion king","toy story","avatar","frozen","maze runner","divergent","inception","the lord of rings","the matrix" };
	srand(time(NULL));
	*word = food[std::rand() % 12];
}//generates a movie name from a list. A possible update will be to add a database
int main() {
	hanged_man(5);
	std::string word = "";
	random_word(&word);
	std::string looking = word;
	for (unsigned int i = 0; i < word.length(); ++i) {
		if (looking[i] == ' ') {
			looking[i] = ' ';
		}
		else {
			looking[i] = '-';
		}
	}
	bool solved = false;
	char letter{};
	int lives = 5;
	for (unsigned int i = 0; i < word.length(); ++i) {
		if (looking[i] == ' ') {
			std::cout << " ";
		}
		std::cout << "-";
	}
	std::cout << std::endl;
	while (!solved && lives != 0) {
		std::cout << "Enter a letter: ";
		bool repeated = false;
		do {
			repeated = false;
			std::cin >> letter;
			for (unsigned int i = 0; i < word.length(); ++i) {
				if (letter == looking[i]) {
					repeated = true;
					std::cout << "You already entered that letter please choose a different one: ";
				}
			}
		} while (repeated);
		bool remove = true;
		for (unsigned int i = 0; i < word.length(); ++i) {
			if (letter == word[i]) {
				looking[i] = letter;
				remove = false;
			}
		}
		if (remove) {
			--lives;
		}
		solved = true;
		system("CLS");
		hanged_man(lives);
		for (unsigned int i = 0; i < word.length(); ++i) {
			std::cout << looking[i];
			if (looking[i] == '-') {
				solved = false;
			}
		}
		std::cout << std::endl;
	}
	if (lives == 0) {
		std::cout << "The solution is " << word;
	}
	else {
		std::cout << "Alive";
	}

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

