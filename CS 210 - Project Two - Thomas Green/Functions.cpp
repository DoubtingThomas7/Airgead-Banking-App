/*
Thomas Green
2026/09/30
Function Definitions
*/

#include "Functions.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor
InvestmentAccount::InvestmentAccount(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {

	if (initialInvestment >= 0.0) {
		initialInvestmentDollars = initialInvestment;
	}

	else {
		initialInvestmentDollars = 0.0;
	}

	if (monthlyDeposit >= 0) {
		monthlyDepositDollars = monthlyDeposit;
	}

	else {
		monthlyDepositDollars = 0.0;
	}

	if (annualInterest >= 0.0) {
		annualInterestRatePercentage = annualInterest;
	}

	else {
		annualInterestRatePercentage = 0.0;
	}

	if (numberOfYears > 0) {
		numberOfYearsTotal = numberOfYears;
	}

	else {
		numberOfYearsTotal = 1;
	}
}

// Setters
void InvestmentAccount::setInitialInvestment(double initialInvestment) {
	if (initialInvestment >= 0.0) {
		initialInvestmentDollars = initialInvestment;
	}
}

void InvestmentAccount::setMonthlyDeposit(double monthlyDeposit) {
	if (monthlyDeposit >= 0.0) {
		monthlyDepositDollars = monthlyDeposit;
	}
}

void InvestmentAccount::setAnnualInterest(double annualInterest) {
	if (annualInterest >= 0.0) {
		annualInterestRatePercentage = annualInterest;
	}
}

void InvestmentAccount::setNumberOfYears(int numberOfYears) {
	if (numberOfYears > 0) {
		numberOfYearsTotal = numberOfYears;
	}
}

// Getters
double InvestmentAccount::getInitialInvestment() {
	return initialInvestmentDollars;
}

double InvestmentAccount::getMonthlyDeposit() {
	return monthlyDepositDollars;
}

double InvestmentAccount::getAnnualInterest() {
	return annualInterestRatePercentage;
}

int InvestmentAccount::getNumberOfYears() {
	return numberOfYearsTotal;
}

// Prints the details
void InvestmentAccount::printDetails(int yearIndex, double balance, double interestEarnedThisYear) {
	cout << yearIndex;
	cout << "\t\t$" << fixed << setprecision(2) << balance;
	cout << "\t\t$" << fixed << setprecision(2) << interestEarnedThisYear << endl;
}

// Balance withouth monthly deposit
double InvestmentAccount::calculateBalanceWithoutMonthlyDeposit() {
	double accountBalance = initialInvestmentDollars;
	double monthlyRate = (annualInterestRatePercentage / 100.0) / 12;
	double interestForTheYear = 0.0;
	double interest = 0.0;
	int year = 1;
	int month = 1;

	for (year = 1; year <= numberOfYearsTotal; ++year) {
		interestForTheYear = 0.0;

		for (month = 1; month <= 12; ++month) {
			interest = accountBalance * monthlyRate;
			interestForTheYear = interestForTheYear + interest;
			accountBalance = accountBalance + interest;
		}

		printDetails(year, accountBalance, interestForTheYear);
	}

	return accountBalance;
}

// balance with monthly deposits
double InvestmentAccount::calculateBalanceWithMonthlyDeposit() {
	double accountBalance = initialInvestmentDollars;
	double monthlyRate = (annualInterestRatePercentage / 100.0) / 12.0;
	double interestForTheYear = 0.0;
	double total = 0.0;
	double interest = 0.0;
	int year = 1;
	int month = 1;

	for (year = 1; year <= numberOfYearsTotal; ++year) {
		interestForTheYear = 0.0;

		for (month = 1; month <= 12; ++month) {
			total = accountBalance + monthlyDepositDollars;
			interest = total * monthlyRate;
			interestForTheYear = interestForTheYear + interest;
			accountBalance = total + interest;
		}

		printDetails(year, accountBalance, interestForTheYear);
	}

	return accountBalance;
}