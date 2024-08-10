// #include <iostream>
// #include <algorithm>

// int main() {
//     // Declare three variables for the sides
//     double a, b, c;

//     // Input the values of the sides
//     std::cout << "Enter the lengths of the three sides: ";
//     std::cin >> a >> b >> c;

//     // Sort the sides so that c is the largest
//     double sides[] = {a, b, c};
//     std::sort(sides, sides + 3);

//     // Check if it forms a right-angle triangle
//     if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
//         std::cout << "The sides form a right-angle triangle." << std::endl;
//     } else {
//         std::cout << "The sides do not form a right-angle triangle." << std::endl;
//     }

//     return 0;
// }
#include <iostream>

void drawRightAngleTriangle(int height) {
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int height;

    std::cout << "Enter the height of the right-angle triangle: ";
    std::cin >> height;

    drawRightAngleTriangle(height);

    return 0;
}
