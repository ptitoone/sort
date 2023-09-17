#include "Parser.hpp"

Parser::Parser(int ac, char **av)
:
_sort_DSC(false),
_remove_dups(false),
_infile_name(""),
_outfile_name("")
{
    for (int i = 1; i < ac; ++i)
        _args.push_back(av[i]);
    this->_parseOptions();
}

Parser::~Parser()
{}

Parser::Parser(const Parser &copy)
:
_sort_DSC(copy._sort_DSC),
_remove_dups(copy._remove_dups),
_infile_name(copy._infile_name),
_outfile_name(copy._outfile_name)
{
    (void)copy;
}

const Parser &Parser::operator=(const Parser &rhs)
{
    this->_sort_DSC = rhs.getSortingOrder();
    this->_remove_dups = rhs.getDuplicateOption();
    this->_infile_name = rhs.getInfileName();
    this->_outfile_name = rhs.getOutfileName();
    return *this;    
}


const std::string &Parser::getInfileName() const
{
    return this->_infile_name;    
}

const std::string &Parser::getOutfileName() const
{
    return this->_outfile_name;    
}

const bool &Parser::getSortingOrder() const
{
    return this->_sort_DSC;    
}

const bool &Parser::getDuplicateOption() const
{
    return this->_remove_dups;    
}

void    Parser::_parseOptions()
{
    for (auto it = _args.begin(); it != _args.end(); ++it)
    {
        if ((*it)[0] == '-')
        {
            if (it->length() > 2)
                error("invalid option: " + *it);
            switch ((*it)[1])
            {
                case 'd':
                    this->_sort_DSC = true;
                    break;
                case 'u':
                    this->_remove_dups = true;
                    break;
                case 'h':
                    printHelp();
                    break;
                case 'o':
                    if (++it != _args.end() && (*it)[0] != '-')
                        this->_outfile_name = *it;
                    else
                        error("Missing outfile name");
                    break;
                default:
                    error("Unrecognised option: " + *it);
            }
        }
        else
            _infile_name = *it;
    }
}
