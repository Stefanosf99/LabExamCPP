#include "Security.h"

Security::Security(string company, double _price, int _amount, int _acquired) {
	compName = company;
	price = _price;
	amount = _amount;
	acquired = _acquired;
}

//Sets a new value to price
void Security::setPrice(double newPrice){
	price = newPrice;
}

//Gets the new value for price
double Security::getPrice()const {
	return price;
}

//Sets a new value to amount
void Security::setAmount(int newAmount) {
	amount = newAmount;
}

//Gets the new value for amount
int Security::getAmount()const {
	return amount;
}

//Sets a new value to acquired
void Security::setAcquired(int newAcquired) {
	acquired = newAcquired;
}

//Gets the new value for aquired
int Security::getAcquired()const {
	return acquired;
}