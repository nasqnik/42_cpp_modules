// vector + deque

#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <utility>



class PmergeMe {

    private:
        std::vector<int> _unsortedVector;
        std::vector<int> _sortedVector;
        std::deque<int> _unsortedDeque;
        std::deque<int> _sortedDeque;


    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        typedef std::vector<int>::iterator VectIt;
        typedef std::deque<int>::const_iterator ConstDeqIt;
        typedef std::deque<int>::iterator DeqIt;

        void parseCheck(int argc, char **argv);
        void algorithm();

        std::vector<int> FJAVector(const std::vector<int>& input);
        std::deque<int> FJADeque(const std::deque<int>& input);

};

