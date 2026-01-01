#include "iter.hpp"

int main()
{
    std::cout << "=== Test with int array ===" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original array: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    iter(numbers, 5, increment<int>);
    std::cout << "After incrementing: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test with char array ===" << std::endl;
    char letters[] = {'A', 'B', 'C', 'D'};

    std::cout << "Original array: ";
    iter(letters, 4, print<char>);
    std::cout << std::endl;

    iter(letters, 4, increment<char>);
    std::cout << "After incrementing: ";
    iter(letters, 4, print<char>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Test with std::string array ===" << std::endl;
    std::string words[] = {"hello", "world", "!"};

    std::cout << "Original array: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;
    return 0;
}
