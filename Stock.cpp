#include "Stock.h"

Stock::Stock(string company, double _price, int _amount, int _acquired, double _startingPrice) :
	Security(company, _price, _amount, _acquired) {
	startingPrice = _startingPrice;
}

double Stock::calculatePrice() {
	return 0.02 * startingPrice;
}

//Sets a new value to startingPrice
void Stock::setStartingPrice(double newStartingPrice) {
	startingPrice = newStartingPrice;
}

//Gets the new value for startingPrice
double Stock::getStartingPrice()const {
	return startingPrice;
}