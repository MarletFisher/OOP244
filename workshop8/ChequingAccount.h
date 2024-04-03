/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

using namespace std;
using namespace seneca;

namespace seneca {

	class ChequingAccount : public Account {
		double m_transacfee;
		double m_monthlyfee;

	public:
		ChequingAccount(double initBal, double transacfee, double monthlyfee);

		bool credit(double funds);

		bool debit(double funds);

		void monthEnd();

		void display(ostream&) const;

	};

}

#endif