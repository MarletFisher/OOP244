#pragma once
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"

using namespace std;
using namespace seneca;

#define NAME_MAX_LEN 50

namespace seneca {

	class BankAccount {
		char m_name[NAME_MAX_LEN];
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance;

	protected:
		double getBalance() const;
		void setBalance(double balance);
		void writeCurrency(ostream& out, double amount) const;

	public:
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		ostream& write(ostream& out) const;
		istream& read(istream& in);

		friend istream& operator>>(istream& in, BankAccount& acct);
		friend ostream& operator<<(ostream& out, const BankAccount& acct);
	};

}

#endif