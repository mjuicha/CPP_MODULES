#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector<int> span_numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        void    range_call(std::vector<int>::iterator start, std::vector<int>::iterator end);

};

#endif