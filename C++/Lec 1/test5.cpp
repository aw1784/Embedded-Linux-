#include <iostream>

void printMultiplicationTable(int number, int range) {
    for (int i = 1; i <= range; ++i) {
        std::cout << number << " x " << i << " = " << number * i << std::endl;
    }
}

int main() {
    int number, range;

    // Input the number and the range for the multiplication table
    std::cout << "Enter the number for the multiplication table: ";
    std::cin >> number;

    std::cout << "Enter the range for the multiplication table: ";
    std::cin >> range;

    // Print the multiplication table
    printMultiplicationTable(number, range);

    return 0;
}
