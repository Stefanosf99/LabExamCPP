#pragma once
#include "Security.h"
#include <string>

using namespace std;
class Bond :
	public Security {
public:
	Bond(string, double, int, int, string, int);
	double calculatePrice();			  //Bond price calculation
	void setIntRate(int newIntRate);	  //Sets a new value to intRate
	int getIntRate() const;				  //Gets the value for startingPrice
	void setDeadline(string newDeadline); //Sets a new value to deadline
	string getDeadline() const;			  //Gets the new value for deadline
private:
	string deadline;
	int intRate;
};