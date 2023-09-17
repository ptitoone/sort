#pragma once
#include <iostream>
#include <vector>
#include "Helpers.hpp"

class Parser {
    public:
        Parser(int ac, char **av);
        ~Parser();

        const std::string &getInfileName() const;
        const std::string &getOutfileName() const;
        const bool &getSortingOrder() const;
        const bool &getDuplicateOption() const;

    private:

        Parser(const Parser &copy);
        const Parser &operator=(const Parser &rhs);

        void    _parseOptions();

        std::vector<std::string> _args;

        bool _sort_DSC;
        bool _remove_dups;
        std::string _infile_name;
        std::string _outfile_name;
};