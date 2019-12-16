/*
 * BalanceReport.cpp
 *
 *  Created on: Nov 29, 2019
 *      Author: Kevin Held
 */

#include "BalanceReport.h"
#include <iostream>
using namespace std;
// initialize all values to 0.
BalanceReport::BalanceReport() {

	initialInvestment = 0;
	monthlyDeposit = 0;
	annualInterest = 0;
	numYears = 0;
}

// initialize values to hard coded input. FOR TESTING PURPOSES ONLY.
BalanceReport::BalanceReport(double t_initialInvestment,
		double t_monthlyDeposit, double t_annualInterest, int t_numYears) {
	initialInvestment = t_initialInvestment;
	monthlyDeposit = t_monthlyDeposit;
	annualInterest = t_annualInterest;
	numYears = t_numYears;
}

BalanceReport::~BalanceReport() {
	// Auto-generated destructor stub
}

// Prompt user for input values
void BalanceReport::getInput() {
	// must me positve numbers. numYears cannot be 0.
	cout << "Initial Investment Amount: " << endl;
	cin >> initialInvestment;
	cout << "Monthly Deposit: " << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: " << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> numYears;
	//cout << "Press any key to continue..." << endl;
	system("pause");
}

// check input values for validity.
bool BalanceReport::checkInput() {
	if (initialInvestment < 0 || monthlyDeposit < 0 || annualInterest < 0) {
		return false; // no negative values allowed
	}
	if (numYears <= 0) {
		return false; // numYears must be greater than 0.
	}
	return true;
}

// Display user input values.
void BalanceReport::displayInput() {
	cout << "Initial Investment Amount: $" << initialInvestment << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << "Annual Interest: " << annualInterest << "%" << endl;
	cout << "Number of years: " << numYears << endl;
}

// Print Balance Report (with or without additional deposits.
void BalanceReport::displayBalanceReport(bool t_additionalDeposits) {
	double additionalDeposit = monthlyDeposit; // local variable for monthly deposits, set to 0 if t_additionalDeposits is false.
	if (t_additionalDeposits == false) {
		// no additional deposits
		additionalDeposit = 0;
		cout << "=========================================================" << endl;
		cout << "Balance and Interest Without Additional Monthly Deposits"
				<< endl;
	} else {
		// yes additional deposits
		cout << "=========================================================" << endl;
		cout << "  Balance and Interest With Additional Monthly Deposits"
				<< endl;
	}

	int monthsRemaining = numYears * 12; // number of months to calculate
	int month = 1; // current month iteration
	double openingAmount = initialInvestment; // opening amount
	double depositedAmount = additionalDeposit; // deposit amount (zero if no additional deposits).
	double total = openingAmount + depositedAmount; // total deposits
	double interest = total * ((annualInterest / 100.0) / 12.0); // interest earned per month.
	double closingBalance = total + interest; // total closing balance of interest and deposits.
	double lastYearBalance = openingAmount; // last year balance placeholder for calculating year end earned interest.
	double yearEndEarnedInterest; // cumulative interest over the past year.

	// display header
	cout << "=========================================================" << endl;
	cout << " Year\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "---------------------------------------------------------" << endl;
	// loop through each month, only displaying year end results.
	while (monthsRemaining > 0) {

		if (month % 12 == 0) { // calculate year end interest and display only on 12th month of the year
			yearEndEarnedInterest = (closingBalance - lastYearBalance
					- (depositedAmount * 12)); // this years closing balance - last years balance - deposits = interest earned for the year
			printf("%d\t$%*.2f%\t\t$%*.2f\n", month / 12, 9, closingBalance, 9,
					yearEndEarnedInterest); // display results with proper formatting.
			lastYearBalance = closingBalance; // save closing balance for next year interest calculation.
		}
		// increment/decrement month counters
		monthsRemaining -= 1;
		month += 1;

		// re-calculate variables for next year
		openingAmount = closingBalance;
		total = openingAmount + depositedAmount;
		interest = total * ((annualInterest / 100.0) / 12.0);
		closingBalance = total + interest;
	}
}

