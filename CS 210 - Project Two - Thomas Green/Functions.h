/*
Thomas Green
2026/09/30
Project Two Header File
*/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Class definition for InvestmentAccount
class InvestmentAccount {

public:

	// Constructor
	InvestmentAccount(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears);

	// Setters
	void setInitialInvestment(double initialInvestment);
	void setMonthlyDeposit(double monthlyDeposit);
	void setAnnualInterest(double annualInterest);
	void setNumberOfYears(int numberOfYears);

	// Getters
	double getInitialInvestment();
	double getMonthlyDeposit();
	double getAnnualInterest();
	int getNumberOfYears();

	// Functions for displaying the reports
	double calculateBalanceWithoutMonthlyDeposit();
	double calculateBalanceWithMonthlyDeposit();
	void printDetails(int yearIndex, double balance, double interestEarnedThisYear);

private:

	double initialInvestmentDollars;
	double monthlyDepositDollars;
	double annualInterestRatePercentage;
	int numberOfYearsTotal;
};

#endif