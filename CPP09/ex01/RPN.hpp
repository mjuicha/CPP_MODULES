#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> numbers;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int calculate(const std::string &expression);
        void makeOperation(char op);

        bool isOperator(char c);
        bool isNumber(char c);
};

#endif