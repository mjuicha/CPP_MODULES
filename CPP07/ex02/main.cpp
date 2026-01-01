#include <iostream>
#include "Array.hpp"
#include "Array.tpp"

int main()
{
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i] = i + 1;
	std::cout << "Array elements:" << std::endl;
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	try
	{
		std::cout << "Accessing out of range index:" << std::endl;
		std::cout << arr[10] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	Array<char> arr2(5);
	for (unsigned int i = 0; i < arr2.size(); ++i)
		arr2[i] = 'a' + i;
	std::cout << "Array elements:" << std::endl;
	for (unsigned int i = 0; i < arr2.size(); ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	try
	{
		std::cout << "Accessing out of range index:" << std::endl;
		std::cout << arr2[10] << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}