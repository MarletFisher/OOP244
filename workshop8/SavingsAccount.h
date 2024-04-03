/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author:  
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;
using namespace seneca;

namespace seneca {

	class SavingsAccount : public Account {

		double m_interestRate;

	public:

		SavingsAccount(double initialBalance, double interestRate);

		void monthEnd();

		void display(std::ostream&) const;

	};
}