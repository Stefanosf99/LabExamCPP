#pragma once
#include "Security.h"
#include <string>

using namespace std;
class Bond :
	public Security {
public:
	Bond(string, double, int, int, string, int);
	//Sets a new value to intRate
	void setIntRate(int newIntRate);
	//Gets the new value for startingPrice
	int getIntRate() const;
	//Sets a new value to deadline
	void setDeadline(string newDeadline);
	//Gets the new value for deadline
	string getDeadline() const;
private:
	string deadline;
	int intRate;
};

