#include "Span.hpp"

int main()
{
    try
    {
        unsigned int N = 15000;
        std::srand(time(0));
        Span sp = Span(N);

        std::vector<int> vec;
        for (unsigned int i = 0; i < N; i++)
            vec.push_back(std::rand());

        sp.range_call(vec.begin(), vec.end());
    
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
