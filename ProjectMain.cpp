/*
Project Two 
Ryan Hadginikitas
6/8/2024
CS-210
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "Investment.h"
#include "Calculations.h"

void UserInterface() {
	//create object userInvestment
	Investment userInvestment;
	//create object dataCalculate
	Calculations dataCalculate;

	//set type for user input
	double initialAmount;
	double monthlyDeposit;
	double interest;
	int years;
	string choice;
	bool keepRunning = true;

	do {
		//set the format for the table for the user input
		system("cls");
		cout << setfill('*') << setw(34) << '*' << endl;
		cout << "*\t" << "Data Input" << "\t *" << endl;
		cout << setfill('-') << setw(34) << '-' << endl;
		//get the user input for the calculations
		cout << "Initial Investment Amount: $";
		cin >> initialAmount;
		cout << endl;

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
		cout << endl;

		cout << "Annual Interest: %";
		cin >> interest;
		cout << endl;

		cout << "Number of Years: ";
		cin >> years;
		cout << endl;

		//set the data obtained from user
		userInvestment.setInitialInvestment(initialAmount);
		userInvestment.setMonthlyDeposit(monthlyDeposit);
		userInvestment.setAnnualInterest(interest);
		userInvestment.setNumOfYears(years);

		//display the user data
		cout << "Initial INvestment Amount: " << setfill(' ') << right << setw(10) << "$" << userInvestment.getInitialInvestment() << endl;
		cout << "Monthly Deposit: " << setfill(' ') << right << setw(20) << "$" << userInvestment.getMonthlyDeposit() << endl;
		cout << "Annual Interest: " << setfill(' ') << right << setw(20) << " " << userInvestment.getAnnualInterest() << "%" << endl;
		cout << "Number of Years: " << setfill(' ') << right << setw(20) << " " << userInvestment.getNumOfYears() << endl;

		cout << endl;

		system("pause");

		//calling the methods to calculate and display the data
		try {
			dataCalculate.dataWithoutDeposits(userInvestment);
		}
		catch (const std::exception& exc) {
			cout << exc.what() << endl;
			cout << "Error withdataWithoutDeposits" << endl;
			keepRunning = false;
		}

		try {
			dataCalculate.dataWithDeposits(userInvestment);
		}

		catch (const std::exception& exc) {
			cout << exc.what() << endl;
			cout << "Error with dataWithDeposits" << endl;
			keepRunning = false;
		}

		cout << endl;

		//ask if they want to continue with inputs
		cout << "Continue? y/n" << endl;
		cin >> choice;
		if (choice == "n") {
			keepRunning = false;
		}
		else {
			continue;
		}
	} while (keepRunning == true);
}

int main() {
	try {
		UserInterface();
	}
	catch (const std::exception& exc) {
		cout << exc.what() << endl;
		cout << "Error with UserInterface" << endl;
		system("pause");
	}
}