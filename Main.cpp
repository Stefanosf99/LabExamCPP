#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Portfolio.h"
#include "Bond.h"
#include "Stock.h"

using namespace std; 

void header() {
	cout << "---------------------------------------------" << endl << endl;
	cout << "--Object-Oriented Programming, Final Project" << endl;
	cout << "--Kalaitzis Dimosthenis & Stefanos Fatsios" << endl << endl;
	cout << "--Banking Portfolio Manager" << endl << endl;
	cout << "---------------------------------------------" << endl << endl << endl;
}

void header(string headName) {
	system("cls");
	cout << "---------------------------------------------" << endl << endl;
	cout << "--Object-Oriented Programming, Final Project" << endl;
	cout << "--Kalaitzis Dimosthenis & Stefanos Fatsios" << endl << endl;
	cout << "--Banking Portfolio Manager" << endl << endl;
	cout << "---------------------------------------------" << endl << endl;
	cout << "-" << headName << endl << endl;
}

Portfolio* addSecurities(Portfolio* portfolio) {
	int choice = 0;
	do {
		header("Add a new Portfolio (Add Securities)");

		string company;
		double price;
		int amount, acquired;

		if (choice == 1 || choice == 2) {
			cout << "Security added successfully!" << endl << endl;
		}

		cout << "Choose your prefered option:" << endl;
		cout << "1. Add a new Bond" << endl;
		cout << "2. Add a new Stock" << endl;
		cout << "3. Add stocks and bonds from file" << endl;
		cout << "Any other number for cancellation" << endl << endl;
		cin >> choice;

		cin.clear();
		cin.ignore();

		switch (choice) {
		case 1:
		case 2:
			header("Add a new Portfolio (Add Securities)");
			cout << "Company: ";
			getline(cin, company);
			cout << "Security price: ";
			cin >> price;
			cout << "Amount of securities: ";
			cin >> amount;
			cout << "Year of acquisition: ";
			cin >> acquired;

			cin.clear();
			cin.ignore();

			break;
		case 3:
			break;
		}

		switch (choice) {
		case 1: {
				string deadline;
				int intRate;
				cout << "Bond deadline: ";
				getline(cin, deadline);
				cout << "Interest rate: ";
				cin >> intRate;
				portfolio->addSecurity(company, price, amount, acquired, deadline, intRate);
				break;
			}
		case 2: {
				double startingPrice;
				cout << "Stock starting price: ";
				cin >> startingPrice;
				portfolio->addSecurity(company, price, amount, acquired, startingPrice);
				break;
			}
		}
	} while (choice < 4 && choice > 0);

	return portfolio;
}

Portfolio* createPortfolio() {
	string name, address, phone, AFM;

	cin.clear();
	cin.ignore();

	header("Add a new Portfolio");
	cout << "Full customer name: ";
	getline(cin, name);
	cout << "Address of residence: ";
	getline(cin, address);
	cout << "Phone number: ";
	getline(cin, phone);
	cout << "Tax registration number: ";
	getline(cin, AFM);

	return addSecurities(new Portfolio(name, address, phone, AFM));
}

void menu(vector<Portfolio*> &portfolios) { //The basic menu. Calls all other functions and its used by main.
	int choice;
	do {
		system("cls");
		header();
		cout << "Choose your desired action: " << endl << endl;
		cout << "1. Add Portfolio" << endl;
		cout << "2. Edit A Portfolio" << endl;
		cout << "3. View Statistics" << endl;
		cout << "Any other button to exit" << endl << endl;
		cout << "Action: ";

		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			portfolios.push_back(createPortfolio());
			break;
		case 2:
		case 3:
			break;
		}
	} while (choice < 4 && choice > 0);
}

int main(int argc, char** argv) {
	vector<Portfolio*> portfolios;
	menu(portfolios);

	cout << portfolios[0]->getFullName();

	system("PAUSE > NUL");
	return 0;
}
