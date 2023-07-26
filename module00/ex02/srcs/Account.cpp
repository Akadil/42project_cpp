/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:22:07 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/26 18:09:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

/*	For some reason I have to do it			*/
/*	Although, it is really strange for me	*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * ----------------------------------------------------
 * @brief Construct a new Account:: Default constructor
 * ----------------------------------------------------
 */
Account::Account(void)
{
	this->_amount = 0;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
	_nbAccounts += 1;
	_totalAmount += this->_amount;
	_displayTimestamp();                              // Not sure though
	std::cout << " index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
	_nbAccounts += 1;
	_totalAmount += this->_amount;
	_displayTimestamp();                              // Not sure though
	std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

/*  Put space after!    */
void Account::_displayTimestamp(void)
{
	time_t t = time(0);
	struct tm * now = localtime(&t);

	std::cout << '[' << (now->tm_year + 1900);
	std::cout.width(2);
	std::cout << std::setfill('0') << (now->tm_mon + 1);
	std::cout.width(2);
	std::cout << std::setfill('0') << now->tm_mday << '_';
	std::cout.width(2);
	std::cout << std::setfill('0') << now->tm_hour;
	std::cout.width(2);
	std::cout << std::setfill('0') << now->tm_min;
	std::cout.width(2);
	std::cout << std::setfill('0') << now->tm_sec << "] ";
}

/**
 * --------------
 * @brief Getters
 * -------------- 
 */
int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

/**
 * @brief Display all accounts info
 */
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
    this->_nbDeposits += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
    if (withdrawal > this->_amount)
        return (std::cout << "refused\n", false);
	else
		std::cout << withdrawal;
	this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
    return (true);
}

int	 Account::checkAmount(void) const
{
	return (this->_amount);
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}
