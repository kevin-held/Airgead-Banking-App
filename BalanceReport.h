/*
 * BalanceReport.h
 *
 *  Created on: Nov 29, 2019
 *      Author: Kevin Held
 */

#ifndef BALANCEREPORT_H_
#define BALANCEREPORT_H_

class BalanceReport {
public:
	BalanceReport(); // default constructor
	BalanceReport(double t_initialInvestment, double t_monthlyDeposit,
			double t_annualInterest, int t_numYears); // constructor for testing purposes only.
	virtual ~BalanceReport(); // destructor

	void displayBalanceReport(bool additionalDeposits); // display results (with or without additional deposits)
	void getInput(); // get input from user
	void displayInput(); // display user input
	bool checkInput(); // check input for validity.

private:
	double initialInvestment; // opening investment must be >= 0
	double monthlyDeposit; // additional deposits must be >= 0
	double annualInterest; // interest must be >= 0
	int numYears; // number of years must be > 0
};

#endif /* BALANCEREPORT_H_ */
