#include <iostream>

bool isVowel(char ch) {
    // Convert the character to lowercase for simplicity
    ch = tolower(ch);
    // Check if the character is a vowel
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char ch;

    // Input the character
    std::cout << "Enter a letter: ";
    std::cin >> ch;

    // Check if the input is a vowel
    if (isVowel(ch)) {
        std::cout << ch << " is a vowel." << std::endl;
    } else {
        std::cout << ch << " is not a vowel." << std::endl;
    }

    return 0;
}
