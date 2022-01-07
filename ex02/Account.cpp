#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

void
    Account::_displayTimestamp()
{
    time_t  now = time(0);
    tm      *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year;
    std::cout << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec;
    std::cout << "] ";
}

Account::Account():
    _accountIndex(Account::_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
    << ";created" << std::endl;
}

Account::Account(int initial_deposit):
    _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
    << ";created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
    << ";closed" << std::endl;
    Account::_nbAccounts--;
    Account::_totalAmount -= this->_amount;
    Account::_totalNbDeposits -= this->_nbDeposits;
    Account::_totalNbWithdrawals -= this->_nbWithdrawals;
}

int
    Account::getNbAccounts()
{
    return (Account::_nbAccounts);
}

int
    Account::getTotalAmount()
{
    return (Account::_totalAmount);
}

int
    Account::getNbDeposits()
{
    return (Account::_totalNbDeposits);
}

int
    Account::getNbWithdrawals()
{
    return (Account::_totalNbWithdrawals);
}

void
    Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << \
    ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void
    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool
    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (this->_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    else
    {
        std::cout << withdrawal;
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        return (true);
    }
}

int
    Account::checkAmount() const
{
    return (this->_amount);
}

void
    Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
    << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
