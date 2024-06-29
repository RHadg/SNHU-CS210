#pragma once

class Investment {
public: //set the public classes
	void setInitialInvestment(double user_initialinvestment);
	void setMonthlyDeposit(double user_monthlyDeposit);
	void setAnnualInterest(double user_annualInterest);
	void setNumOfYears(int user_years);
	void setTotalWithDeposits(double user_amount);
	void setTotalWithoutDeposits(double user_amount);

	double getInitialInvestment() {
		return calc_initialInvestment;
	}
	double getMonthlyDeposit() {
		return calc_monthlyDeposit;
	}
	double getAnnualInterest() {
		return calc_annualInterest;
	}
	int getNumOfYears() {
		return calc_numOfYears;
	}
	double getTotalWithDeposits();
	double getTotalWithoutDeposits();
	double calcInterestWithDeposits();
	double calcInterestWithoutDeposits();

private: //set private classes
	double calc_initialInvestment = 0.0;
	double calc_monthlyDeposit = 0.0;
	double calc_annualInterest = 0.0;
	int calc_numOfYears = 0;
	double calc_totalWithDeposits = 0.0;
	double calc_totalWithoutDeposits = 0.0;
};