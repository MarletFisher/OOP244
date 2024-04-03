/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "Account.h"
#include "ChequingAccount.h"

using namespace std;
using namespace seneca;

namespace seneca {

	ChequingAccount::ChequingAccount(double initBal, double transacfee, double monthlyfee) 
		: Account(initBal), m_transacfee(transacfee > 0 ? transacfee : 0.0 ), m_monthlyfee( monthlyfee > 0 ? monthlyfee : 0.0 ) {}

	bool ChequingAccount::credit(double funds) {
		//cout << "ChequingAccount::credit() called." << endl;
		if (Account::credit(funds)) {
			//cout << "Account::credit() success. Attemping debit of transac fee" << endl;
			if (Account::debit(m_transacfee)) {
				return true;
			}
		}
		return false;
	}

	bool ChequingAccount::debit(double funds) {
		if (Account::debit(funds)) {
			if (Account::debit(m_transacfee)) {
				return true;
			}
		}
		return false;
	}

	void ChequingAccount::monthEnd() {
		Account::debit(m_monthlyfee);
	}

	void ChequingAccount::display(ostream& ostr) const {
		ostr << "Account type: Chequing" << endl;
		ostr << "Balance: $" << Account::balance() << endl;
		ostr << "Per Transaction Fee: " << fixed << setprecision(2) << m_transacfee << endl;
		ostr << "Monthly Fee: " << fixed << setprecision(2) << m_monthlyfee << endl;
	}


}