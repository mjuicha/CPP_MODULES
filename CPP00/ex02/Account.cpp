
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string form(int number, int size)
{
    std::stringstream sd;
    sd << std::setw(size) << std::setfill('0') << number;
    return sd.str();
}


void	Account::_displayTimestamp()
{
    time_t timeg = time(0);
    tm *timex = localtime(&timeg);
    int YYYY = 1900 + timex->tm_year;
    int MM = 1 + timex->tm_mon;
    int DD = timex->tm_mday;
    int hh = timex->tm_hour;
    int mm = timex->tm_min;
    int ss = timex->tm_sec;
    std::cout << '[' << form(YYYY, 4) << form(MM, 2) << form(DD, 2);
    std::cout << '_' << form(hh, 2) << form(mm, 2) << form(ss, 2) << "] ";
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
                            << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
                            << ";closed" << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
        << ";deposits:" << _nbDeposits << ";withdrawals:"
        << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
   _displayTimestamp();
   std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
   << ";deposit:" << deposit;
   _amount += deposit;
   std::cout << ";amount:" <<_amount << ";nb_deposits:" << 1 << std::endl; 
}

bool	Account::makeWithdrawal( int withdrawal )
{
   _displayTimestamp();
   std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
   << ";withdrawal:" << withdrawal;
   _amount -= withdrawal;
   std::cout << ";amount:" <<_amount << ";nb_withdrawals:" << 1 << std::endl; 
   return 0;
}



int main()
{
    Account Accounts(2); 
    // Account Accountz(16);
    Accounts.displayAccountsInfos();
    Accounts.displayStatus();
    // Accountz.displayStatus();
    Accounts.makeDeposit(500);
    Accounts.displayStatus();
    Accounts.makeWithdrawal(100);
    Accounts.displayStatus();
    Accounts.displayAccountsInfos();
    return (0);
}