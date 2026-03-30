#pragma once

#include <stack>
#include <string>

// RPN: evaluates a Reverse Polish Notation expression passed as a single string.
// Tokens must be space-separated; numbers must be single digits (0-9).
// Supported operators: + - * /
class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    // Evaluate the expression and print the result.
    // Throws std::runtime_error on any invalid input.
    void evaluate(const std::string &expression);

private:
    // std::stack is used here (LIFO — perfect for RPN evaluation)
    std::stack<double> _stack;

    // Apply an operator to two operands (a op b)
    double applyOp(char op, double a, double b) const;
};
