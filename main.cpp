#include <iostream>
#include "string.hpp"

void test1() {
    non_std::string text_1;
    non_std::string text_2;
    non_std::string text_3;
    non_std::string text_4;

    std::cout << "text 1: ";
    std::getline(std::cin, text_1);
    std::cout << "text 2: ";
    std::getline(std::cin, text_2);

    text_3 = text_1 ^ text_2;
    text_4 = text_1;
    text_4 ^= "/text";

    std::cout << "text 1: " << text_1 << std::endl;
    std::cout << "text 2: " << text_2 << std::endl;
    std::cout << "text 3: " << text_3 << std::endl;
    std::cout << "text 4: " << text_4 << std::endl;
}

void test2() {
    non_std::string text_1;
    non_std::string text_2;

    std::cout << "text 1: ";
    std::getline(std::cin, text_1);
    std::cout << "text 2: ";
    std::getline(std::cin, text_2);

    std::swap(text_1, text_2);

    std::cout << text_1 << std::endl;
    std::cout << text_2 << std::endl;
}

void test3() {
    non_std::string text_1;
    std::string text_2;

    std::cout << "text 1: ";
    std::getline(std::cin, text_1);
    std::cout << "text 1: " << text_1 << std::endl;

    std::cout << "text 2: ";
    std::getline(std::cin, text_2);
    text_1 = text_2;

    std::cout << "text 1: " << text_1 << std::endl;
    std::cout << "text 2: " << text_2 << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    return EXIT_SUCCESS;
}
