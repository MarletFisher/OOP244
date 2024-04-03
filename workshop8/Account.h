/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include <iostream>
#include "iAccount.h"

namespace seneca {
	class Account : public iAccount {

		double m_balance;

	protected:

		double balance() const;

	public:
		
		Account(double initBalance = 0.0);

		virtual bool credit(double credit) override;

		virtual bool debit(double debit) override;

	};
}

#endif