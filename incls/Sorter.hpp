#pragma once
#include <iostream>
#include <fstream>
#include <set>

class Sorter {
    public:
        Sorter(
            const bool &sortDsc,
            const bool &removeDups,
            const std::string &infile_name,
            const std::string &outfile_name);

        ~Sorter();
        

    private:
        Sorter(const Sorter &copy);

        void _mapWordlist();
        void _writeResultToStdout();
        void _writeResultToOutfile();

        const bool &_sort_DSC;
        const bool &_remove_dups;
        const std::string &_infile_name;
        const std::string &_outfile_name;

        std::set<std::string> _uniqueWordList;
        std::multiset<std::string> _wordList;

};