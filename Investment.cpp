#include <iostream>
using namespace std;

#include "Investment.h"

//set the initial investment 
void Investment::setInitialInvestment(double user_initialInvestment) {
	this->calc_initialInvestment = user_initialInvestment;
}
//set the monthly deposit amount
void Investment::setMonthlyDeposit(double user_monthlyDeposit) {
	this->calc_monthlyDeposit = user_monthlyDeposit;
}
//set the annual interest
void Investment::setAnnualInterest(double user_annualInterest) {
	this->calc_annualInterest = user_annualInterest;
}
//set number of years
void Investment::setNumOfYears(int user_numOfYears) {
	this->calc_numOfYears = user_numOfYears;
}
//calculating interest without deposits
double Investment::calcInterestWithoutDeposits() {
	return((this->calc_totalWithoutDeposits) * ((this->calc_annualInterest / 100) / 12));
}
//calculating interest with deposits
double Investment::calcInterestWithDeposits() {
	return((this->calc_totalWithDeposits) * ((this->calc_annualInterest / 100) / 12));
}
//set the total without deposits
void Investment::setTotalWithoutDeposits(double user_amount) {
	this->calc_totalWithoutDeposits += user_amount;
}
//set the total with deposits
void Investment::setTotalWithDeposits(double user_amount) {
	this->calc_totalWithDeposits += user_amount;
}
//get the total without deposits
double Investment::getTotalWithoutDeposits() {
	return this->calc_totalWithoutDeposits;
}
//get the total with deposits
double Investment::getTotalWithDeposits() {
	return this->calc_totalWithDeposits;
}

