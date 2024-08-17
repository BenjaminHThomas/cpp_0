/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:49:13 by bthomas           #+#    #+#             */
/*   Updated: 2024/08/17 13:13:08 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex = _nbAccounts++;
	if (initial_deposit > 0) {
		this->_amount = initial_deposit;
		_totalAmount += initial_deposit;
	}
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << this->checkAmount() << ";created\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << this->checkAmount() << ";closed\n";
	Account::_nbAccounts--;
}

int	Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout 
		<< "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";p_amount:" << this->checkAmount() - deposit
		<< ";deposit:" << deposit
		<< ";amount;" << this->checkAmount()
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	bool	retval = true;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << this->checkAmount();
	if (this->_amount < withdrawal) {
		retval = false;
		std::cout << ";withdrawal:refused\n";
		return (retval);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
		<< ";amount;" << this->checkAmount()
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t	now = time(0);
	struct tm *time = std::localtime(&now);
	if (!time) {
		std::cerr << "Error: could not get time.\n";
		return ;
	}
	std::cout << "["
		<< (time->tm_year + 1900) 
		<< std::setw(2) << std::setfill('0') << (time->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << time->tm_mday << "_"
		<< std::setw(2) << std::setfill('0') << time->tm_hour
		<< std::setw(2) << std::setfill('0') << time->tm_min
		<< std::setw(2) << std::setfill('0') << time->tm_sec
		<< "] ";
}