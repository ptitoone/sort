#include "Sorter.hpp"
#include "Parser.hpp"

void error(const std::string &msg)
{
    std::cerr << msg << std::endl;
    std::cerr << "Type 'sort -h' for help" << std::endl;
    exit(0);
}

void printHelp(void)
{
    std::cout << "This program takes a list of words as input and outputs the words sorted." << std::endl;
    std::cout << "By default, input is read on stdin, the output is written to stdout and the words are sorted in ascending order." << std::endl;
    std::cout << std::endl;
    std::cout << "Available options are:" << std::endl;
    std::cout << "\t-o <outfile>\t:\tWrite to specified outfile." << std::endl;
    std::cout << "\t-d\t\t:\tSort words in descending order." << std::endl;
    std::cout << "\t-u\t\t:\tRemove duplicates." << std::endl;
    exit(0);
}

int main(int ac, char **av)
{
    Parser parser(ac, av);

    Sorter sort(
        parser.getSortingOrder(),
        parser.getDuplicateOption(),
        parser.getInfileName(),
        parser.getOutfileName());
    
    return 0;
}