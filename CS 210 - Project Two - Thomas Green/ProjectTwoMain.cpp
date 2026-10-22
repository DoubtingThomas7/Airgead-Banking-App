/*
Thomas Green
2026/09/30
Project Two: Banking App
*/

#include "Functions.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	char userChoice = 'y';
	double initialInvestment = 0.0;
	double monthlyDeposit = 0.0;
	double annualInterest = 0.0;
	int numberOfYears = 0;

	// While loop to allow the user to run multiple reports
	while (userChoice == 'y' || userChoice == 'Y') {
		initialInvestment = 0.0;
		monthlyDeposit = 0.0;
		annualInterest = 0.0;
		numberOfYears = 0;
		
		// Display the welcome message and prompt the user for input
		cout << setfill('*') << setw(50) << "" << endl;
		cout << setfill('*') << setw(18) << "";
		cout << "  Data Input  ";
		cout << setfill('*') << setw(18) << "" << endl;

		cout << "Initial Investment Amount: $";
		cin >> initialInvestment;

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;

		cout << "Annual Interest: %";
		cin >> annualInterest;

		cout << "Number of Years: ";
		cin >> numberOfYears;

		// Create an InvestmentAccount object with the user input
		InvestmentAccount account(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

		// Display the report headers and call the functions to calculate and display the balances and interest
		// Without additional monthly deposits
		cout << setfill('=') << setw(64) << "" << endl;
		cout << "    Balance and Interest Without Additional Monthly Deposits   " << endl;
		cout << setfill('=') << setw(64) << "" << endl;
		cout << setfill(' ');
		cout << setw(6) << left << "Year" << setw(23) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
		cout << setfill('-') << setw(64) << "" << endl;
		account.calculateBalanceWithoutMonthlyDeposit();

		// With additional monthly deposits
		cout << endl;
		cout << setfill('=') << setw(64) << "" << endl;
		cout << "     Balance and Interest With Additional Monthly Deposits   " << endl;
		cout << setfill('=') << setw(64) << "" << endl;
		cout << setfill(' ');
		cout << setw(6) << left << "Year" << setw(23) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest" << endl;
		cout << setfill('-') << setw(64) << "" << endl;
		account.calculateBalanceWithMonthlyDeposit();

		// Prompt the user to run another report or exit the program
		cout << endl << "Would you like to run another report? (y/n): ";
		cin >> userChoice;
		cout << endl;
	}

	// Display the exit message and return 0 to indicate successful completion
	cout << "Thank you for using the Airgead Banking App. Goodbye!" << endl;
	return 0;
} 