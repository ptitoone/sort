#include "Sorter.hpp"


Sorter::Sorter(
    const bool &sortDsc,
    const bool &removeDups,
    const std::string &infile_name,
    const std::string &outfile_name)
:
_sort_DSC(sortDsc),
_remove_dups(removeDups),
_infile_name(infile_name),
_outfile_name(outfile_name)
{
    _mapWordlist();

    if (!this->_outfile_name.length())
        _writeResultToStdout();
    else
        _writeResultToOutfile();
}

Sorter::Sorter(const Sorter &copy)
: 
_sort_DSC(copy._sort_DSC),
_remove_dups(copy._remove_dups),
_infile_name(copy._infile_name),
_outfile_name(copy._outfile_name)
{}

Sorter::~Sorter()
{

}

void    Sorter::_mapWordlist()
{
    if (!this->_infile_name.length())
    {
        for (std::string line; std::getline(std::cin, line);)
        {
            if (this->_remove_dups) 
                this->_uniqueWordList.insert(line);
            else
                this->_wordList.insert(line);
        }
    }
    else
    {
        std::ifstream infile(_infile_name);
        
        if (!infile.is_open())
        {
            std::cerr << "Error opening infile" << std::endl;
            exit(0);
        }

        for (std::string line; std::getline(infile, line);)
        {
            if (this->_remove_dups) 
                this->_uniqueWordList.insert(line);
            else
                this->_wordList.insert(line);
        }
        infile.close();
    }
}

void Sorter::_writeResultToStdout()
{
    if (this->_remove_dups)
    {
        if (this->_sort_DSC)
            for (auto it = _uniqueWordList.rbegin(); it != _uniqueWordList.rend(); it++)
                std::cout << *it << std::endl;
        else
            for (auto it = _uniqueWordList.begin(); it != _uniqueWordList.end(); it++)
                std::cout << *it << std::endl;
    }
    else
    {
        if (this->_sort_DSC)
            for (auto it = _wordList.rbegin(); it != _wordList.rend(); it++)
                std::cout << *it << std::endl;
        else
            for (auto it = _wordList.begin(); it != _wordList.end(); it++)
                std::cout << *it << std::endl;
    }
}

void Sorter::_writeResultToOutfile()
{
    std::ofstream outfile(this->_outfile_name);

    if (!outfile.is_open())
    {
        std::cerr << "Error opening outfile" << std::endl;
        exit(0);
    }

    if (this->_remove_dups)
    {
        if (this->_sort_DSC)
            for (auto it = _uniqueWordList.rbegin(); it != _uniqueWordList.rend(); it++)
                outfile << *it << std::endl;
        else
            for (auto it = _uniqueWordList.begin(); it != _uniqueWordList.end(); it++)
                outfile << *it << std::endl;
    }
    else
    {
        if (this->_sort_DSC)
            for (auto it = _wordList.rbegin(); it != _wordList.rend(); it++)
                outfile << *it << std::endl;
        else
            for (auto it = _wordList.begin(); it != _wordList.end(); it++)
                outfile << *it << std::endl;
    }
    outfile.close();
}