#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

// ── Orthodox Canonical Form ───────────────────────────────────────────────────

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

// ── Operator application ──────────────────────────────────────────────────────

double RPN::applyOp(char op, double a, double b) const
{
    switch (op)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0.0)
            throw std::runtime_error("Error: division by zero.");
        return a / b;
    default:
        throw std::runtime_error("Error: unknown operator.");
    }
}

// ── Evaluation ────────────────────────────────────────────────────────────────

void RPN::evaluate(const std::string &expression)
{
    // Clear any leftover state
    while (!_stack.empty())
        _stack.pop();

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        // Token is an operator: pop two operands, compute, push result
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            double b = _stack.top(); _stack.pop(); // right operand
            double a = _stack.top(); _stack.pop(); // left  operand
            _stack.push(applyOp(token[0], a, b));
        }
        // Token must be a single digit (numbers < 10 per the subject rules)
        else if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            _stack.push(static_cast<double>(token[0] - '0'));
        }
        else
        {
            // Any other token (multi-digit number, bracket, unknown symbol) is invalid
            throw std::runtime_error("Error");
        }
    }

    // A valid RPN expression leaves exactly one value on the stack
    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _stack.top() << "\n";
}
