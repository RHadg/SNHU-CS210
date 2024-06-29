#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

#include "Calculations.h"

//display without monthyl deposits
void Calculations::dataWithoutDeposits(Investment user_userInvestment) {
	//set local variables to the user data input
	double initialInvestment = user_userInvestment.getInitialInvestment();
	int years = user_userInvestment.getNumOfYears();

	//configuring the layout of the table for enhanced user experience
	int screenWidth = 80;
	string heading = "Balance and Interest Without Additional Monthly Deposits";
	int centerScreen = heading.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;
	cout << endl;

	//heading for the data table
	cout << setfill(' ') << setw(sizeToCenter) << heading << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(26) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	//calculating and adding the interest to the total 
	user_userInvestment.setTotalWithoutDeposits(initialInvestment);
	double interestYTD = 0.0;

	unsigned int yearCount;
	unsigned int monthCount;

	for (yearCount = 1; yearCount <= years; ++yearCount) {
		for (monthCount = 1; monthCount <= 12; ++monthCount) {
			interestYTD += user_userInvestment.calcInterestWithoutDeposits();
		}
		user_userInvestment.setTotalWithoutDeposits(interestYTD);
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setprecision(2) << interestYTD;
		cout << right << setw(35) << "$" << fixed << setprecision(2) << user_userInvestment.getTotalWithoutDeposits() << endl;

		interestYTD = 0;
	}

}

//display with monthly deposits
void Calculations::dataWithDeposits(Investment user_userInvestment) {
	//set local variables to the user data input
	double initialInvestment = user_userInvestment.getInitialInvestment();
	double monthlyDeposit = user_userInvestment.getMonthlyDeposit();
	int years = user_userInvestment.getNumOfYears();

	//configuring the layout of the table for enhanced user experience
	int screenWidth = 80;
	string heading = "Balance and Interest With Additional Monthly Deposits";
	int centerScreen = heading.length() / 2;
	int halfWidth = screenWidth / 2;
	int sizeToCenter = halfWidth + centerScreen;
	cout << endl;

	//heading for the data table
	cout << setfill(' ') << setw(sizeToCenter) << heading << setfill(' ') << setw(sizeToCenter) << endl;
	cout << setfill('=') << setw(80) << '=' << endl;
	cout << setfill(' ') << left << setw(26) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(80) << '-' << endl;

	//calculating and adding the interest to the total 
	user_userInvestment.setTotalWithDeposits(initialInvestment);
	double interestYTD = 0.0;

	unsigned int yearCount;
	unsigned int monthCount;

	for (yearCount = 1; yearCount <= years; ++yearCount) {
		for (monthCount = 1; monthCount <= 12; ++monthCount) {
			//adds monthly deposit to total
			user_userInvestment.setTotalWithDeposits(monthlyDeposit);
			//gets the interest and adds it to the total
			double interest = user_userInvestment.calcInterestWithDeposits();
			user_userInvestment.setTotalWithDeposits(interest);
			interestYTD += interest;
		}
		user_userInvestment.setTotalWithoutDeposits(interestYTD);
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setprecision(2) << interestYTD;
		cout << right << setw(35) << "$" << fixed << setprecision(2) << user_userInvestment.getTotalWithDeposits() << endl;

		interestYTD = 0;
	}

}