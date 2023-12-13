#include <iostream>
#include <iomanip>
using namespace std;


#include "BankingApp.h"
// Testing AirgeadBankingApp
int main() {
	// Create Banking App object to test class
	BankingApp test;

	// Display menu
	test.DisplayMenu();
	// Display account settings
	test.AccountMenu();

	return 0;
}