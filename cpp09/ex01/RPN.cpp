#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN& other) : _values(other._values) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        _values = other._values;
    return *this;
}

RPN::~RPN() {}


static void checkString(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(str[i]);

        if (std::isdigit(c) || c == ' ' || c == '+' || c == '-' || c == '*' || c == '/')
            continue;
            
        throw std::runtime_error("Error");
    }
}

static bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

static void pushParsedNumber(const std::string& token, std::stack<long double>& values) {
    if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0]))) {
        values.push(token[0] - '0');
        return;
    }
    throw std::runtime_error("Error");
}

static void applyOperation(const std::string& token, std::stack<long double>& values) {
    if (values.size() < 2)
        throw std::runtime_error("Error");

    long double right = values.top();
    values.pop();
    long double left = values.top();
    values.pop();

    if (token == "+")
        values.push(left + right);
    else if (token == "-")
        values.push(left - right);
    else if (token == "*")
        values.push(left * right);
    else {
        if (right == 0)
            throw std::runtime_error("Error");
        values.push(left / right);
    }
}

void RPN::RPNcalculation(const std::string& str) {
    checkString(str);

    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        if (isOperator(token))
            applyOperation(token, _values);
        else
            pushParsedNumber(token, _values);
    }

    if (_values.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _values.top() << std::endl;
}