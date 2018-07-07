#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
	//Adds bonds and stocks
	void addSecurity(string, double, int, int, string, int);
	void addSecurity(string, double, int, int, double);
	void addSecurity(fstream*);
	// Marks a portfolio as deleted
	void markDeleted();
	// Menu and caller for portfolio data updates
	void update();
	// Calculates the total price of the portfolio
	double countMaxWorth();
	//Sets a new value to totalWorth
	void setTotalWorth(double newTotal);
	//Gets the new value for totalWorth
	double getTotalWorth() const;
	//Sets a new value to maxWorth
	void setMaxWorth(double newMax);
	//Gets the new value for maxWorth
	double getMaxWorth() const;
	//Sets a new value to fullName
	void setFullName(string newName);
	//Gets the new value for fullName
	string getFullName() const;
	//Sets a new value to address
	void setAddress(string newAddress);
	//Gets the new value for address
	string getAddress() const;
	//Sets a new value to phone
	void setPhone(string newPhone);
	//Gets the new value for phone
	string getPhone() const;
	//Sets a new value to AFM
	void setAFM(string newAFM);
	//Gets the new value for AFM
	string getAFM() const;
private:
	// Edits portfolio user info for update()
	void editInfo();
	// Edits portfolio securities for update()
	void editSecurities();
};

