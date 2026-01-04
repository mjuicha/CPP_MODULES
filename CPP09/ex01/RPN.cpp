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

bool    multipleOverflow(int a, int b)
{
    if (a == 0 || b == 0)
        return false;
    if (a > 0 && b > 0 && a > INT_MAX / b)
        return true;
    if (a < 0 && b < 0 && -a > INT_MAX / -b)
        return true;
    if ((a > 0 && b < 0 && b < INT_MIN / a) || (a < 0 && b > 0 && a < INT_MIN / b))
        return true;
    return false;
}

void RPN::isOperationValid(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a))
                throw std::runtime_error("Error");
            break;
        case '-':
            if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
                throw std::runtime_error("Error");
            break;
        case '*':
            if (multipleOverflow(a, b))
                throw std::runtime_error("Error");
            break;
        case '/':
            if (a == INT_MIN && b == -1)
                throw std::runtime_error("Error");
            break;
    }
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
            isOperationValid(a, b, op);
            numbers.push(a + b);
            break;
        case '-':
            isOperationValid(a, b, op);
            numbers.push(a - b);
            break;
        case '*':
            isOperationValid(a, b, op);
            numbers.push(a * b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            isOperationValid(a, b, op);
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