//============================================================================
// Name        : AirgeadBankingApp.cpp
// Author      : Kevin Held
// Version     :
// Copyright   : N/A
// Description : Banking App to show students the importance of investing.
//============================================================================

#include <iostream>
#include "BalanceReport.h"
using namespace std;

int main() {

	BalanceReport Report = BalanceReport(); // create BalanceReport class instance
	try {
		Report.getInput(); // Prompt user for input
		if (Report.checkInput() == false) {
			// indicate errors for invalid parameters
			cout << "Invalid Entry, must be a positive number, please restart." << endl;
			return 0;
		}
		Report.displayInput(); // show input results

		Report.displayBalanceReport(false); // Balance and interest report without additional deposits
		Report.displayBalanceReport(true); // Balance and interest report with additional deposits
	} catch (const exception &e) {
		// catch all, prompt restart
		cout << "Error: Invalid Entry, please restart." << endl;
	}
	return 0;
}
