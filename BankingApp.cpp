#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include "BankingApp.h"
using namespace std;

/*
* Display new customer menu
*/
void BankingApp::DisplayMenu() {
	// local variables for Investment account
	double initialAmt;
	double deposit;
	int intrst;
	int years;
	char key;

	// Print to customer what information is needed
	cout << setfill('*') << setw(40) << "" << endl;
	cout << setw(14) << "";
	cout << setfill(' ');
	cout << setw(12) << " Data Input " << setfill('*') << setw(14) << "" << endl;
	cout << setfill(' ');
	cout << "Initial Investment: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	cout << "Press any key to continue . . . " << endl;
	cout << setfill('*') << setw(40) << "" << endl;
	cout << "\n" << endl;

	// Read customers input for initial investment.
	cout << "Initial Investment: $";
	cin >> initialAmt;

	// While amount is invalid. Get customer input.
	while (initialAmt < 0.0) {
		cout << "Must be greater than zero... try again\n" << endl;
		cout << "Initial Investment: $";
		cin >> initialAmt;
	}

	// Read customers input for monthly deposit
	cout << "Monthly Deposit: $";
	cin >> deposit;

	// While amount is invalid. Get customer input.
	while (deposit < 0.0) {
		cout << "Must be greater than zero... try again\n" << endl;
		cout << "Monthly Deposit: $";
		cin >> deposit;
	}

	// Read customers input for annual interest rate
	cout << "Annual Interest: %";
	cin >> intrst;

	// While interest rate is invalid. Get customer input.
	while (intrst < 1) {
		cout << "Must be greater than zero... try again\n" << endl;
		cout << "Annual Interest: %";
		cin >> intrst;
	}

	// Read customers input for number of years
	cout << "Number of Years: ";
	cin >> years;

	// While amount is invalid. Get customer input.
	while (years < 1) {
		cout << "Must be greater than zero... try again\n" << endl;
		cout << "Number of Years: ";
		cin >> years;
	}

	// Tell customer to press key to continue
	cout << "Press any key to continue . . . " << endl;
	cout << "\n" << endl;

	// Set customer values to account
	account.SetOpenAmt(initialAmt);
	account.SetMnthlyDepo(deposit);
	account.SetIntrstRate(intrst);
	account.SetNumYears(years);

	// If customer presses ANY key, get it and call DisplayReports
	key = _getch();
	DisplayReports(account, false);
	DisplayReports(account, true);

}

// Change information on account depending on customers decision
void BankingApp::ChangeAccount(int option) {
	// local variables for new values
	double amount;
	int rate;
	int time;

	// Switch customers decision
	switch (option) {
		// Change the monthly deposit
		case 1:
			cout << "Monthly Deposit: $";
			cin >> amount;

			// While amount is invalid. Get customer input.
			while (amount < 0.0) {
				cout << "Must be greater than zero... try again\n" << endl;
				cout << "Monthly Deposit: $";
				cin >> amount;
			}
			// Set new deposit to the account
			account.SetMnthlyDepo(amount);
			// Call DisplayReports
			DisplayReports(account, false);
			DisplayReports(account, true);
			// Call menu until customer quits
			AccountMenu();
			break;
		case 2:
			// Change annual interest rate
			cout << "Annual Interest: %";
			cin >> rate;

			// While amount is invalid. Get customer input.
			while (rate < 1) {
				cout << "Must be greater than zero... try again\n" << endl;
				cout << "Annual Interest: %";
				cin >> rate;
			}

			// Set new interest rate to the account
			account.SetIntrstRate(rate);
			// Call DisplayReports
			DisplayReports(account, false);
			DisplayReports(account, true);
			// Call menu until customer quits
			AccountMenu();
			break;
		case 3:
			// Change number of years
			cout << "Number of Years: ";
			cin >> time;

			// While time is invalid. Get customer input.
			while (time < 1) {
				cout << "Must be greater than zero... try again\n" << endl;
				cout << "Number of Years: ";
				cin >> time;
			}

			// Set number of years to account
			account.SetNumYears(time);
			// Call DisplayReports
			DisplayReports(account, false);
			DisplayReports(account, true);
			// Call menu until customer quits
			AccountMenu();
			break;
		case 0:
			// Customer quit, end program
			cout << "Goodbye . . ." << endl;
			break;
		default:
			// Customer chose wrong. Print error statement
			cout << "Not an option . . .Try again . . .\n" << endl;
			// Call menu until customer quits
			AccountMenu();
			break;
	}
}

/*
* Account settings
* Customer can choose an option
*/
void BankingApp::AccountMenu() {
	int option;
	cout << setw(23) << right << "Account Menu" << setw(23) << "" << endl;
	cout << setfill('-') << setw(42) << "" << endl;
	cout << endl;
	cout << "\nOptions:" << endl;
	cout << setw(10) << "" << endl;
	cout << "\nChange Deposit Amount? - Enter 1\n" << endl;
	cout << "Change Annual Interest? - Enter 2\n" << endl;
	cout << "Change Number of Years? - Enter 3\n" << endl;
	cout << "Quit? - Enter 0\n" << endl;

	cin >> option;
	// Call ChangeAccount with customer's option
	ChangeAccount(option);
}

/*
* Display Reports given customers account information
* @param bool depos, true for a monthly deposit
* false for no monthly deposit
*/
void BankingApp::DisplayReports(Investment account, bool depos) {
	/*
	* totalIntrst will track accumulated interest for each year
	* get number of months the investment will last
	* get interest rate, make double for easier conversion
	* local variables for deposit, total balance, intrst, year
	*/
	double totalIntrst = 0.0;
	int months = account.GetNumMonths();
	double open = account.GetOpenAmt();
	double intRate = static_cast<double>(account.GetIntrstRate());
	double deposit = 0.0;
	double total = open;
	double intrst = 0.0;
	int year = 0;

	// With monthly deposits
	if (depos) {
		cout << setw(59) << "   Balance and Interest With Additional Monthly Deposits   " << endl;
		cout << setfill('=') << setw(59) << "" << endl;
		deposit = account.GetMnthlyDepo();
		total = open + deposit;
	}
	// Without monthly deposits
	else {
		cout << setw(59) << "       Balance and Interest Without Monthly Deposits       " << endl;
	}
	cout << setfill('=') << setw(59) << "" << endl;
	cout << setfill(' ');
	cout << setw(12) << left << " Year";
	cout << setw(19) << left << " Year End Balance";
	cout << setw(12) << left << "  Year End Earned Interest" << endl;
	cout << setfill('-') << setw(59) << "" << endl;
	cout << setfill(' ');

	// For each month of the investment
	for (int i = 1; i <= months; ++i) {
		// Calculate the interest
		intrst = total * ((intRate / 100.0) / 12.0);
		// Add to totalIntrst tracker
		totalIntrst += intrst;
		total += intrst; // Add interest for the month
		// If its been a year
		if (i % 12 == 0) {
			// Increment the year
			year += 1;
			/*
			* Print the year, total ending balance, and total interest accumulated
			*/
			cout << setw(5) << right << year;
			cout << fixed << setprecision(2) << setw(17) << right << "$" << total;
			cout << setw(21) << "$" << totalIntrst << endl;
			cout << endl;
			// Reset total interest tracker
			totalIntrst = 0.0;
		}
		// With monthly deposits
		if (i != months && depos == true) {
			total += deposit; // Now add deposit for next month
		}
	}
	cout << setfill('-') << setw(59) << "" << endl;
	cout << setfill(' ');
	cout << "\n" << endl;
}