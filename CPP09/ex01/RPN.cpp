#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    this->numbers = other.numbers;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->numbers = other.numbers;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

void RPN::makeOperation(char op)
{
    if (numbers.size() < 2)
        throw std::runtime_error("Error");

    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();

    switch (op)
    {
        case '+':
            numbers.push(a + b);
            break;
        case '-':
            numbers.push(a - b);
            break;
        case '*':
            numbers.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            numbers.push(a / b);
            break;
        default:
            throw std::runtime_error("Error");
    }
}

int RPN::calculate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.empty())
            continue;
        if (token.length() != 1)
            throw std::runtime_error("Error");
        char c = token[0];

        if (isNumber(c))
            numbers.push(c - '0');
        else if (isOperator(c))
            makeOperation(c);
        else
            throw std::runtime_error("Error");
    }
    if (numbers.size() != 1)
        throw std::runtime_error("Error");
    return numbers.top();
}