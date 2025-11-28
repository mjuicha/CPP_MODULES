#include "Span.hpp"


int main()
{
    Span sp = Span(10000);

    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}