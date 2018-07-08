#pragma once
#include "Security.h"
#include <string>

using namespace std;
class Stock :
	public Security {
public:
	Stock(string, double, int, int, double);
	double calculatePrice();						//Stock price calulation
	void setStartingPrice(double newStartingPrice); //Sets a new value to startingPrice
	double getStartingPrice() const;                //Gets the new value for startingPrice
private:
	double startingPrice;
};

