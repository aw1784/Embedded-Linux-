#include <iostream>

int main() {
    // Declare three variables
    int a, b, c;

    // Input the values
    std::cout << "Enter three numbers: ";
    std::cin >> a >> b >> c;

    // Find the maximum value
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    // Output the maximum value
    std::cout << "The maximum value is: " << max << std::endl;

    return 0;
}
