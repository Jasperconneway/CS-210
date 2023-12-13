#include <iostream>
#include "Investment.h"
using namespace std;
/*
* Default constructor
* Use set methods for open amount, monthly deposit, number of years, and interest rate
* When given values
*/
Investment::Investment(double openAmt, double mnthlyDepo, int numYears, int intrstRate) {
	SetOpenAmt(openAmt);
	SetMnthlyDepo(mnthlyDepo);
	SetNumYears(numYears);
	SetIntrstRate(intrstRate);
}

// set open amount to @param amt value
void Investment::SetOpenAmt(double amt) {
	openAmt = amt;
}
// return open amount
double Investment::GetOpenAmt() {
	return openAmt;
}
// set monthly deposit to @param amt value
void Investment::SetMnthlyDepo(double amt) {
	mnthlyDepo = amt;
}
// return monthly deposit
double Investment::GetMnthlyDepo() const {
	return mnthlyDepo;
}
// set number of years to @param years
void Investment::SetNumYears(int years) {
	/* 
	* while setting number of years
	* set number of months
	*/
	numYears = years;
	numMonths = years * 12;
}
// return number of years
int Investment::GetNumYears() const {
	return numYears;
}
// return number of months
int Investment::GetNumMonths() const {
	return numMonths;
}
// set interest rate to @param intrstRate value
void Investment::SetIntrstRate(int intrstRate) {
	this->intrstRate = intrstRate;
}
// return interest rate
int Investment::GetIntrstRate() {
	return intrstRate;
}