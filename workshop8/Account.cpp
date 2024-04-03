/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include <iostream>
#include "Account.h"
#include "iAccount.h"

using namespace std;
using namespace seneca;

namespace seneca {

	double Account::balance() const {
		return m_balance;
	}

	Account::Account(double initBalance) : m_balance(initBalance >= 0.0 ? initBalance : 0.0) {}

	bool Account::credit(double credit) {
		//cout << "Account::credit() called" << endl;
		if (credit > 0) {
			m_balance += credit;
			return true;
		}
		return false;
	}

	bool Account::debit(double debit) {
		if (debit > 0) {
			m_balance -= debit;
			return true;
		}
		return false;
	}

}