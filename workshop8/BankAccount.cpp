#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "BankAccount.h"

using namespace std;
using namespace seneca;

namespace seneca {

	double BankAccount::getBalance() const {
		return m_balance;
	}

	void BankAccount::setBalance(double balance) {
		m_balance = balance;
	}

	void BankAccount::writeCurrency(ostream& out, double amount) const {
		out << "$" << fixed << setprecision(2) << amount;
	}

	BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance) : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
		strcpy(m_name, name);
	}

	ostream& BankAccount::write(ostream& out) const {
		out << m_name << " | ";
		writeCurrency(out, m_balance);
		out << " | " << m_openDate << " | " << m_depInfo;
		return out;
	}

	istream& BankAccount::read(istream& in) {
		cout << "Name: ";
		in.getline(m_name, 51, '\n');
		in.clear();

		cout << "Opening Balance: ";
		in >> m_balance;

		cout << "Date Opened (year month day): ";
		m_openDate.read(in);

		cout << "Transit #: ";
		in >> m_depInfo.m_transit;

		cout << "Institution #: ";
		in >> m_depInfo.m_institution;

		cout << "Account #: ";
		in >> m_depInfo.m_account;
		in.clear();

		in.ignore();

		return in;
	}

	istream& operator>>(istream& in, BankAccount& acct) {
		return acct.read(in);
	}

	ostream& operator<<(ostream& out, const BankAccount& acct) {
		return acct.write(out);
	}


}