#include "replace.hpp"


int error(int err)
{
    if (err == 0)
        std::cerr << "Invalid Input!" << std::endl;
    else if (err == 1)
        std::cerr << "Error opening file!" << std::endl;
    else if (err == 2)
        std::cerr << "Error: Search string cannot be empty!" << std::endl;
    return 1;
}



void    _replace(char **av, std::string& line)
{
    size_t i = 0;
    std::string old = av[2];
    std::string new_s = av[3];
    while (1)
    {
        if ((i = line.find(old, i)) == std::string::npos)
            return ;
        std::string p1 = line.substr(0, i);
        std::string p2 = line.substr(i + old.length());
        line = p1 + new_s + p2;
    } 
}


int    run(char **av)
{
    if (std::string(av[2]).empty())
        return error(2);
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     line;
    std::string     replace = ".replace";
    bool            found = false;

    replace = av[1] + replace;
    infile.open(av[1]);
    if (!infile.is_open())
        return error(1);
    outfile.open(replace.c_str());
    if (!outfile.is_open())
    {
        infile.close();
        return error(1);
    }
    while (std::getline(infile, line, '\0'))
    {
        if (found)
            outfile << std::endl;
        _replace(av, line);
        outfile << line;
        found = true;
    }
    infile.close();
    outfile.close();
    return 0;
}
