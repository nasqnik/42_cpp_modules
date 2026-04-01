#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    
    if (argc <= 1) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        PmergeMe obj;
        obj.parseCheck(argc, argv);
        obj.algorithm();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}