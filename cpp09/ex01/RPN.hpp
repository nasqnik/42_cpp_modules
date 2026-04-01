#pragma once

#include <stack>
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <string>
#include <sstream>

class RPN {

    private:
        std::stack<long double> _values;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void RPNcalculation(const std::string& str);
};