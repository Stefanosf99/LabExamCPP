#include "Portfolio.h"

Portfolio::Portfolio(string _fullName, string _address, string _phone, string _AFM) {
	fullName = _fullName;
	address = _address;
	phone = _phone;
	AFM = _AFM;
	valid = true;
}

// Marks a portfolio as deleted
void Portfolio::markDeleted() {
	valid = false;
}

bool Portfolio::isValid() {
	return valid;
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
int Portfolio::addSecurity(fstream& file) {
	string sLine;
	int totalAdded = 0;

	while (file.good()) {
		getline(file, sLine);
		struct fileMap cr = mapToStruct(sLine);

		if (cr.isStock) securities.push_back(new Stock(cr.company, cr.price, cr.amount, cr.acquired, cr.startingPrice));
		else securities.push_back(new Bond(cr.company, cr.price, cr.amount, cr.acquired, cr.deadline, cr.intRate));

		totalAdded++;
	}

	return totalAdded;
}

struct Portfolio::fileMap Portfolio::mapToStruct(string line) {
	stringstream ss(line);
	string token;
	int tokenIndex = 0;

	struct fileMap cr;

	while (getline(ss, token, '|')) {
		switch (tokenIndex++) {
		case 0:
			if (token == "M" || token == "Ì") {
				cr.isStock = true;
			}
			else cr.isStock = false;
			break;
		case 1:
			cr.company = token;
			break;
		case 2:
			cr.price = stod(token);
			break;
		case 3:
			cr.amount = stoi(token);
			break;
		case 4:
			cr.acquired = stoi(token);
			break;
		case 5:
			if (cr.isStock) {
				cr.startingPrice = stod(token);
			}
			else cr.deadline = token;
			break;
		case 6:
			cr.intRate = stoi(token);
			break;
		}
	}

	return cr;
}

// Gets the highest price of a single security
double Portfolio::countMaxWorth() {
	Security* maxSecurity = securities[max_element(securities.begin(), securities.begin(),
		[](Security* left, Security* right) {return left->calculatePrice() < right->calculatePrice(); }) - securities.begin()];
	return maxSecurity->calculatePrice();
}

// Calculates the total price of the portfolio
double Portfolio::countTotalWorth() {
	double sum = 0;
	for (int i = 0; i < securities.size(); i++) {
		sum += securities[i]->calculatePrice();
	}

	return sum;
}

#pragma region "Getters/Setters"
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