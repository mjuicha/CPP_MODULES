#include <iostream>
#include <fstream>

int error(int err)
{
    if (err == 0)
        std::cerr << "Invalid Input!" << std::endl;
    else if (err == 1)
        std::cerr << "Error opening file!" << std::endl;
    return 1;
}

void    _replace(char **av, std::string &line)
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
    if (!av[1] || !av[2] || !av[3])
        return error(0);

    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     line;
    std::string     replace = "_replace";

    replace = av[1] + replace;
    infile.open(av[1]);
    outfile.open(replace.c_str());
    if (!infile.is_open() || !outfile.is_open())
        return error(1);
    while (std::getline(infile, line))
    {
        _replace(av, line);
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return error(0);
    return run(av);
}