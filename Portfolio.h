#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Security.h"
#include "Stock.h"
#include "Bond.h"

using namespace std;
class Portfolio {
private:
	string fullName;
	string address;
	string phone;
	string AFM;
	vector<Security*> securities;
	bool valid;
	double totalWorth;
	double maxWorth;
public:
	Portfolio(string, string, string, string);
	void addSecurity(string, double, int, int, string, int); //Adds Bond
	void addSecurity(string, double, int, int, double);		 //Adds Stock
	void addSecurity(fstream*);								 //Adds Securities from file
	void markDeleted();										 //Marks a portfolio as deleted
	void update();											 //Menu and caller for portfolio data updates
	double countTotalWorth();								 //Calculates the total price of the portfolio
	double countMaxWorth();									 //Gets the highest price of a single security
	void setTotalWorth(double newTotal);					 //Sets a new value to totalWorth
	double getTotalWorth() const;							 //Gets the new value for totalWorth
	void setMaxWorth(double newMax);						 //Sets a new value to maxWorth
	double getMaxWorth() const;								 //Gets the new value for maxWorth
	void setFullName(string newName);						 //Sets a new value to fullName
	string getFullName() const;								 //Gets the new value for fullName
	void setAddress(string newAddress);						 //Sets a new value to address
	string getAddress() const;								 //Gets the new value for address
	void setPhone(string newPhone);							 //Sets a new value to phone
	string getPhone() const;								 //Gets the new value for phone
	void setAFM(string newAFM);								 //Sets a new value to AFM
	string getAFM() const;									 //Gets the new value for AFM
private:
	void editInfo();										 //Edits portfolio user info for update()
	void editSecurities();									 // Edits portfolio securities for update()
};

