#include "Bond.h"

Bond::Bond(string company, double _price, int _amount, int _acquired, string _deadline, int _intRate) :
	Security(company, _price, _amount, _acquired) {
	deadline = _deadline;
	intRate = _intRate;
}

double Bond::calculatePrice() { //Bond price calculation
	return amount * (0.03 * price + 0.01 * (stoi(deadline)) + 0.01 * intRate);
}

//Sets a new value to intRate
void Bond::setIntRate(int newIntRate) {
	intRate = newIntRate;
}

//Gets the new value for intRate
int Bond::getIntRate()const {
	return intRate;
}

//Sets a new value to deadline
void Bond::setDeadline(string newDeadline) {
	deadline = newDeadline;
}

//Gets the new value for deadline
string Bond::getDeadline()const {
	return deadline;
}