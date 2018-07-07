#pragma once
#include <string>
#include <fstream>

using namespace std;
class Security {
public:
	Security(string, double, int, int);
	void setPrice(double newPrice);     //Sets a new value to price
	double getPrice() const;	        //Gets the new value for price
	void setAmount(int newAmount);     	//Sets a new value to amount
	int getAmount() const;	            //Gets the new value for amount
	void setAcquired(int newAcquired);	//Sets a new value to acquired
	int getAcquired() const;         	//Gets the new value for aquired
private:
	string compName;
	double price;
	int amount;
	int acquired;
};

