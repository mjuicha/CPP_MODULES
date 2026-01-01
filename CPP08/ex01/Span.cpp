#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &other) : N(other.N), span_numbers(other.span_numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N = other.N;
        span_numbers = other.span_numbers;
    }
    return *this;
}

Span::~Span() {}




void    Span::addNumber(int number)
{
    if (N == 0)
        throw std::runtime_error("Span size is zero");
    else if (span_numbers.size() < N)
        span_numbers.push_back(number);
    else 
        throw std::out_of_range("Span is full");
}


unsigned int Span::shortestSpan()
{
    if (N <= 1 || span_numbers.size() < 2)
        throw std::runtime_error("Not enough span_numbers to find a span");
    
    std::vector<int> sorted_numbers = span_numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    unsigned int shortestSpan = sorted_numbers[1] - sorted_numbers[0];
    for (size_t i = 1; i < sorted_numbers.size() - 1; ++i)
    {
        shortestSpan = std::min(shortestSpan, static_cast<unsigned int>(sorted_numbers[i + 1] - sorted_numbers[i]));
    }
    return shortestSpan;
}

unsigned int Span::longestSpan()
{
    if (N <= 1 || span_numbers.size() < 2)
        throw std::runtime_error("Not enough span_numbers to find a span");
    int max = *std::max_element(span_numbers.begin(), span_numbers.end());
    int min = *std::min_element(span_numbers.begin(), span_numbers.end());
    return max - min;
}

void    Span::range_call(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (start > end)
        throw std::runtime_error("Invalid range");

    unsigned int size = std::distance(start, end) + span_numbers.size();

    if (size > N)
        throw std::out_of_range("Span is full");
    span_numbers.insert(span_numbers.end(), start, end);
}
