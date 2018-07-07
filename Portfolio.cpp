#include "Portfolio.h"

Portfolio::Portfolio(string _fullName, string _address, string _phone, string _AFM) {
	fullName = _fullName;
	address = _address;
	phone = _phone;
	AFM = _AFM;
	totalWorth = 0.0;
	maxWorth = 0.0;
}

// Marks a portfolio as deleted
void Portfolio::markDeleted() {
	valid = false;
}

//Adds a single bond
void Portfolio::addSecurity(string company, double price, int amount, int acquired, string deadline, int intRate) {
	securities.push_back(new Bond(company, price, amount, acquired, deadline, intRate));
}

//Adds a single stock
void Portfolio::addSecurity(string company, double price, int amount, int acquired, double startingPrice) {
	securities.push_back(new Stock(company, price, amount, acquired, startingPrice));
}

//Adds all securities from a file
void Portfolio::addSecurity(fstream* file) {
	//TODO:: ADD CODE
}

// Edits portfolio user info for update()
void Portfolio::editInfo() {
	// TODO: Add your implementation code here.
}

// Menu and caller for portfolio data updates
void Portfolio::update() {
	// TODO: Add your implementation code here.
}

// Edits portfolio securities for update()
void Portfolio::editSecurities() {
	// TODO: Add your implementation code here.
}

// Calculates the total price of the portfolio
double Portfolio::countMaxWorth() {
	// TODO: Add your implementation code here.
	return 0.0;
}

#pragma region "Getters/Setters"

//Sets a new value to totalWorth
void Portfolio::setTotalWorth(double newTotal) {
	totalWorth = newTotal;
}

//Gets the new value for totalWorth
double Portfolio::getTotalWorth()const {
	return totalWorth;
}

//Sets a new value to maxWorth
void Portfolio::setMaxWorth(double newMax) {
	maxWorth = newMax;
}

//Gets the new value for maxWorth
double Portfolio::getMaxWorth()const {
	return maxWorth;
}

//Sets a new value to fullName
void Portfolio::setFullName(string newName) {
	fullName = newName;
}

//Gets the new value for fullName
string Portfolio::getFullName()const {
	return fullName;
}

//Sets a new value to address
void Portfolio::setAddress(string newAddress) {
	address = newAddress;
}

//Gets the new value for address
string Portfolio::getAddress()const {
	return address;
}

//Sets a new value to phone
void Portfolio::setPhone(string newPhone) {
	phone = newPhone;
}

//Gets the new value for phone
string Portfolio::getPhone()const {
	return phone;
}

//Sets a new value to AFM
void Portfolio::setAFM(string newAFM) {
	AFM = newAFM;
}

//Gets the new value for AFM
string Portfolio::getAFM()const {
	return AFM;
}

#pragma endregion;