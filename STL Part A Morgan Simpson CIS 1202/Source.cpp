// Morgan Simpson
// CIS 1202 M01
// April 29th 2024

#include <iostream>
#include <stdexcept>

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw std::invalid_argument("InvalidCharacterException: start is not a letter.");
    }

    char result = start + offset;

    if (!isalpha(result)) {
        throw std::invalid_argument("InvalidRangeException: target is not a letter.");
    }

    return result;
}

int main() {
    try {
        std::cout << "character('a', 1): " << character('a', 1) << std::endl;
        std::cout << "character('a', -1): ";
        std::cout << character('a', -1) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout << "character('Z', -1): " << character('Z', -1) << std::endl;
        std::cout << "character('?', 5): ";
        std::cout << character('?', 5) << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}