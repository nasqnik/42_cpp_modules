#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
        
PmergeMe::PmergeMe(const PmergeMe& other) : _unsortedVector(other._unsortedVector), _unsortedDeque(other._unsortedDeque) {}
    
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _unsortedVector = other._unsortedVector;
        _unsortedDeque = other._unsortedDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Input Validation

static bool checkDigits(const char *s) {
    if (!s || !*s)
        return false;
    for (size_t i = 0; s[i] != '\0'; ++i) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

void PmergeMe::parseCheck(int argc, char **argv) {

    for (int i = 1; i < argc; ++i) {
        if (!checkDigits(argv[i]))
            throw std::runtime_error("Error");

        errno = 0;
        char *end = NULL;
        long value = std::strtol(argv[i], &end, 10);

        if (errno == ERANGE || *end != '\0' || value <= 0 || value > INT_MAX)
            throw std::runtime_error("Error");

        int number = static_cast<int>(value);

        _unsortedVector.push_back(number);
        _unsortedDeque.push_back(number);
    }
}

// Algorithm Helpers


static size_t jacobsthal(size_t n)
{
    // J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    size_t a = 0;
    size_t b = 1;
    for (size_t i = 2; i <= n; ++i) {
        size_t c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

static std::vector<size_t> jacobsthalInsertionOrder(size_t m)
{
    std::vector<size_t> order;
    if (m <= 1)
        return order;

    size_t prev = 1; // index 1 (pending[0]) already inserted

    for (size_t k = 3; prev < m; ++k) {
        size_t cur = jacobsthal(k);
        if (cur > m) 
            cur = m;
        // add (cur, cur-1, ..., prev+1) in 1-based,
        // convert to 0-based (minus 1)
        for (size_t oneBased = cur; oneBased > prev; --oneBased)
            order.push_back(oneBased - 1);

        prev = cur;
    }
    return order;
}

static void boundedInsertVect(std::vector<int>& chain, int value, int boundA)
{
    std::vector<int>::iterator bound =
        std::lower_bound(chain.begin(), chain.end(), boundA);

    std::vector<int>::iterator pos =
        std::lower_bound(chain.begin(), bound, value);

    chain.insert(pos, value);
}

static void boundedInsertDeq(std::deque<int>& chain, int value, int boundA)
{
    std::deque<int>::iterator bound =
        std::lower_bound(chain.begin(), chain.end(), boundA);

    std::deque<int>::iterator pos =
        std::lower_bound(chain.begin(), bound, value);

    chain.insert(pos, value);
}


// Algorithm
static void mergePairs(std::vector< std::pair<int,int> >& v,
    size_t left, size_t mid, size_t right)
{
    std::vector<std::pair<int,int> > tmp;
    tmp.reserve(right - left);

    size_t i = left;
    size_t j = mid;

    while (i < mid && j < right) {
        if (v[i].first <= v[j].first) 
            tmp.push_back(v[i++]);
        else
            tmp.push_back(v[j++]);
    }
    while (i < mid)   
        tmp.push_back(v[i++]);
    while (j < right) 
        tmp.push_back(v[j++]);

    // copy back
    for (size_t k = 0; k < tmp.size(); ++k)
        v[left + k] = tmp[k];
}

static void mergeSortPairs(std::vector< std::pair<int, int> >& v, size_t left, size_t right)
{
    if (right - left <= 1) // right index is not included
        return;
    size_t middle = (left + right) / 2;
    mergeSortPairs(v, left, middle);
    mergeSortPairs(v, middle, right);
    mergePairs(v, left, middle, right);
}

std::vector<int> PmergeMe::FJAVector(const std::vector<int>& input) {
    const size_t size = input.size();
    if (size <= 1)
        return input;

    std::vector<std::pair<int,int> > pairs;
    pairs.reserve(size / 2);  // reserve memory, so the vector doesn't need to constanty reallocate -> perfomance >

    bool hasStraggler = (size % 2 != 0);
    int straggler = 0; // last element without a pair

    size_t limit = size;

    if (hasStraggler) {
        straggler = input.back();
        limit = size - 1;
    }

    for (size_t i = 0; i < limit; i += 2)
    {
        int a = input[i];
        int b = input[i + 1];

        if (a < b)
            std::swap(a, b); // a > b

        pairs.push_back(std::make_pair(a, b));
    }

    // (a, b) where a >= b; in pairs: left elements - sorted leaders, right elements - to insert later
    mergeSortPairs(pairs, 0, pairs.size());

    // build 2 chains
    std::vector<int> mainChain;
    std::vector<int> pending;

    mainChain.reserve(pairs.size() + (hasStraggler ? 1 : 0));
    pending.reserve(pairs.size());

    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    // optimization: insert straight away, because the first in pairs is always smaller then main chain
    if (!pending.empty())
        boundedInsertVect(mainChain, pending[0], pairs[0].first);

    std::vector<size_t> order = jacobsthalInsertionOrder(pending.size());

    for (size_t t = 0; t < order.size(); ++t) {
        size_t idx = order[t]; 
        boundedInsertVect(mainChain, pending[idx], pairs[idx].first);
    }

    if (hasStraggler) {
        VectIt pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }
    return mainChain;
}

std::deque<int> PmergeMe::FJADeque(const std::deque<int>& input)
{
    const size_t size = input.size();
    if (size <= 1)
        return input;

    std::vector<std::pair<int,int> > pairs;
    pairs.reserve(size / 2);

    bool hasStraggler = (size % 2 != 0);
    int straggler = 0;

    size_t limit = size;
    if (hasStraggler) {
        straggler = input.back();
        limit = size - 1;
    }

    ConstDeqIt it = input.begin();
    for (size_t i = 0; i < limit; i += 2) {
        int a = *it; ++it;
        int b = *it; ++it;

        if (a < b)
            std::swap(a, b); // ensure a >= b

        pairs.push_back(std::make_pair(a, b));
    }

    mergeSortPairs(pairs, 0, pairs.size());

    std::deque<int> mainChain;
    std::vector<int> pending;
    pending.reserve(pairs.size());

    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    if (!pending.empty())
        boundedInsertDeq(mainChain, pending[0], pairs[0].first);

    std::vector<size_t> order = jacobsthalInsertionOrder(pending.size());

    for (size_t t = 0; t < order.size(); ++t) {
        size_t idx = order[t]; 
        boundedInsertDeq(mainChain, pending[idx], pairs[idx].first);
    }

    if (hasStraggler) {
        DeqIt pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    return mainChain;
}

void PmergeMe::algorithm() {

    std::cout << "Before: ";
    for (VectIt it = _unsortedVector.begin(); it != _unsortedVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    clock_t startVect = clock();
    _sortedVector = FJAVector(_unsortedVector);
    clock_t endVect = clock();

    clock_t startDeque = clock();
    _sortedDeque = FJADeque(_unsortedDeque);
    clock_t endDeque = clock();

    std::cout << "After: ";
    for (VectIt it = _sortedVector.begin(); it != _sortedVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    double timeSpentVect = static_cast<double>(endVect - startVect) * 1000000.0 / CLOCKS_PER_SEC;
    double timeSpentDeque = static_cast<double>(endDeque - startDeque) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << _unsortedVector.size() << " elements with std::vector : " << std::fixed 
        << std::setprecision(5) << timeSpentVect << " us" << std::endl;
    std::cout << "Time to process a range of " << _unsortedDeque.size() << " elements with std::deque : " << std::fixed 
        << std::setprecision(5) << timeSpentDeque << " us" << std::endl;
}