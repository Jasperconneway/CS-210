#ifndef BANKINGAPP_H
#define BANKINGAPP_H
#include <string>
#include <vector>
#include <conio.h>
#include "Investment.h"

// BankingApp header file
class BankingApp {
	public:
		// Display new customer menu
		void DisplayMenu();
		/*
		* Display balance and interest reports
		* Based on @param Investment account, and a bool depos
		*/
		void DisplayReports(Investment account, bool depos);
		// Change account information depending on @param option
		void ChangeAccount(int option);
		// Account settings menu
		void AccountMenu();
	private:
		Investment account;

};

#endif
