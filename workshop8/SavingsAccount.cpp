/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include <iostream>
#include <iomanip>
#include "Account.h"
#include "SavingsAccount.h"

using namespace std;
using namespace seneca;

namespace seneca {
	
	SavingsAccount::SavingsAccount(double initBalance, double interestRate) 
		: Account(initBalance), m_interestRate(interestRate >= 0 ? interestRate : 0.0 ) {}

	void SavingsAccount::monthEnd() {
		double interest = Account::balance() * m_interestRate;
		Account::credit(interest);
	}

	void SavingsAccount::display(ostream& ostr) const {
		ostr << "Account type: Savings" << endl;
		ostr << "Balance: $" << fixed << setprecision(2) << Account::balance() << endl;
		ostr << "Interest Rate (%): " << fixed << setprecision(2) << m_interestRate * 100 << endl;
	}
}