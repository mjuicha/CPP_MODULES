#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void    Span::addNumber(int number)
{
    if (numbers.size() < N)
        numbers.push_back(number);
    else 
        throw std::runtime_error("Span is full");
}

int Span::shortestSpan()
{
    if (N <= 1 || numbers.empty() || numbers.size() == 1)
        throw std::runtime_error("Not enough numbers to find a span");
    int cmp;
    int cmp2;
    int shortestSpan = Span::longestSpan();
    for (size_t i = 0; i < numbers.size(); i++)
    {
        cmp = numbers.at(i);
        std::cout << "cmp: " << cmp << std::endl;
        for (size_t j = 0; j < numbers.size(); j++)
        {
            
            if (i == j)
                continue ;
            cmp2 = numbers.at(j);
            std::cout << "\t\tcmp2: " << cmp2 << std::endl;
            if (cmp < cmp2)
                continue ;
            if (shortestSpan > cmp - cmp2)
                shortestSpan = cmp - cmp2;
        }
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    if (N <= 1 || numbers.empty() || numbers.size() == 1)
        throw std::runtime_error("Not enough numbers to find a span");
    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return max - min;
}

