
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

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}





void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << std::endl;
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
   _nbDeposits++;
   std::cout << ";amount:" <<_amount << ";nb_deposits:" << _nbDeposits << std::endl; 
   _totalAmount += deposit;
   _totalNbDeposits++;
}

int		Account::checkAmount( void ) const
{
    if (_amount < 0)
    {
        std::cout << "refused" << std::endl;
        return 0;
    }
    return 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
   _displayTimestamp();
   std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
   << ";withdrawal:";
   _amount -= withdrawal;
    if (!checkAmount())
    {
        _amount += withdrawal;
        return 0;
    }
   _totalAmount -= withdrawal;
   _nbWithdrawals++;
   std::cout << withdrawal << ";amount:" <<_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
   _totalNbWithdrawals++;
   return 1;
}



// int main()
// {
//     Account Accounts(2); 
//     Account Accountz(16);
//     Accounts.displayAccountsInfos();
//     Accounts.displayStatus();
//     Accountz.displayStatus();
//     Accounts.makeDeposit(500);
//     Accountz.makeDeposit(980);
//     Accounts.displayStatus();
//     Accountz.displayStatus();
//     Accounts.makeWithdrawal(9787968);
//     Accountz.makeWithdrawal(139);
//     Accounts.displayStatus();
//     Accountz.displayStatus();
//     Accounts.displayAccountsInfos();
//     return (0);
// }