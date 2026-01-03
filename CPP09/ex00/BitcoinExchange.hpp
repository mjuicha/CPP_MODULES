#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        float getExchangeRate(const std::string &date) const;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadData(const std::string &filename);
        void processInput(const std::string &filename);

};

std::string trim(const std::string &str);

#endif