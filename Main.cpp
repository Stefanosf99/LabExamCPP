#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Portfolio.h"
#include "Bond.h"
#include "Stock.h"

using namespace std;

void header();
void header(string);

int getNonDeletedPortfolioCount(vector<Portfolio*>&);
void customSort(vector<Portfolio*>&);
void printTenMostExpensive(vector<Portfolio*>&);
void showMoreThanXPrice(vector<Portfolio*>&, double);
void showSingleMoreThanXPrice(vector<Portfolio*>&, double);

Portfolio* addSecurities(Portfolio*, bool);
Portfolio* createPortfolio();
Portfolio* editMenu(Portfolio*);
void statisticMenu(vector<Portfolio*>&);
void menu(vector<Portfolio*>&);

int main(int argc, char** argv) {
	vector<Portfolio*> portfolios;
	menu(portfolios);
	return 0;
}

#pragma region "headers"
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
#pragma endregion

#pragma region "Statistics"
int getNonDeletedPortfolioCount(vector<Portfolio*>& portfolios) {
	int sum = 0;
	for (int i = 0; i < portfolios.size(); i++) {
		if (portfolios[i]->isValid()) sum++;
	}
	cout << sum;
	return sum;
}
void customSort(vector<Portfolio*>& portfolios) {
	sort(portfolios.begin(), portfolios.end(), [](Portfolio* left, Portfolio* right) {
		if (!right->isValid()) return false;
		return left->countTotalWorth() < right->countTotalWorth();
	});
}
void printTenMostExpensive(vector<Portfolio*>& portfolios) {
	int portfoliosToShow;

	if (getNonDeletedPortfolioCount(portfolios) >= 10) portfoliosToShow = 10;
	else portfoliosToShow = getNonDeletedPortfolioCount(portfolios);

	header("Top " + to_string(portfoliosToShow) + " most expensive Portfolios");

	customSort(portfolios);

	for (int i = 0; i < portfoliosToShow; i++) {
		cout << i+1 << ". " << portfolios[i]->getFullName() << " (" << portfolios[i]->countTotalWorth() << "$)" << endl;
	}

	system("pause");
}
void showMoreThanXPrice(vector<Portfolio*>& portfolios, double price) {
	int sum = 0;
	header("Portfolios with higher than " + to_string(price) + "$ cost");

	customSort(portfolios);

	for (int i = 0; i < getNonDeletedPortfolioCount(portfolios); i++) {
		if (portfolios[i]->countTotalWorth() > price) {
			sum++;
		}
	}
	cout << "Portfolios with cost higher than " << price << "$ : " << sum << endl << endl;
	system("pause");
}
void showSingleMoreThanXPrice(vector<Portfolio*>& portfolios, double price) {
	int sum = 0;
	header("Portfolios with a single security with higher cost than " + to_string(price) + "$");

	customSort(portfolios);

	for (int i = 0; i < getNonDeletedPortfolioCount(portfolios); i++) {
		if (portfolios[i]->countMaxWorth() > price) {
			sum++;
		}
	}
	cout << "Portfolios with a single security with higher cost than " << price << "$ : " << sum << endl << endl;
	system("pause");
}
#pragma endregion

#pragma region "Menus"
Portfolio* addSecurities(Portfolio* portfolio, bool editing = false) {
	int choice = 0;
	do {
		if (editing) header("Add an extra security to '" + portfolio->getFullName() + "'s portfolio");
		else header("Add a new Portfolio (Add Securities)");

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
			if (editing) header("Add an extra security to '" + portfolio->getFullName() + "'s portfolio");
			else header("Add a new Portfolio (Add Securities)");
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
			//security from files
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

void editMenu(vector<Portfolio*>& portfolios) {
	int choice, selection;
	Portfolio* portfolio;
	do {
		header("Edit A Portfolio");

		cout << "Choose your prefered option:" << endl;
		cout << "1. Edit a portfolio" << endl;
		cout << "2. Delete a portfolio" << endl;
		cout << "Any other number for cancellation" << endl << endl;
		cin >> choice;

		cin.clear();
		cin.ignore();
		system("cls");

		if (choice == 1 || choice == 2) {
			do {
				cout << "Select the number of the portfolio you want to edit:" << endl;

				for (int i = 0; i < portfolios.size(); i++) {
					cout << i + 1 << ". " << portfolios[i]->getFullName() << endl;
				}

				cout << "Portfolio number: ";
				cin >> selection;
			} while (selection < 1 || selection > portfolios.size());

			portfolio = portfolios[selection - 1];

			switch (choice) {
			case 1:
				int choice;
				header("Edit A Portfolio");

				cout << "Choose your prefered option:" << endl;
				cout << "1. Edit client information" << endl;
				cout << "2. Add securities to a portfolio" << endl;
				cout << "2. Add an extra security" << endl;
				cout << "Any other number for cancellation" << endl << endl;
				cin >> choice;
				system("cls");

				switch (choice) {
				case 1: {
					int selection, portfoliosToShow;
					string newName, newAddress, newPhone, newAFM;
					header("Edit client '" + portfolio->getFullName() + "' information");

					cout << "New customer name: ";
					getline(cin, newName);
					portfolio->setFullName(newName);
					cout << "New address of residence: ";
					getline(cin, newAddress);
					portfolio->setAddress(newAddress);
					cout << "New phone number: ";
					cin >> newPhone;
					portfolio->setPhone(newPhone);
					cout << "New tax registration number: ";
					cin >> newAFM;
					portfolio->setAFM(newAFM);
					break;
				}
				case 2: {
					bool rightHeader = 1;
					addSecurities(portfolio, rightHeader);
				}
				case 3:
					portfolio->markDeleted();
					break;
				}
			}
		}
	} while (choice < 3 && choice > 0);
}

void statisticMenu(vector<Portfolio*> &portfolios) {
	int choice;
	do {
		system("cls");
		header("Portfolio Statistics");
		cout << "Choose your desired statistic: " << endl << endl;
		cout << "1. Show portfolios with more than X cost" << endl;
		cout << "2. Show portfolios that own a single Security with more than X cost" << endl;
		cout << "3. Show top 10 most expensive portfolios" << endl;
		cout << "Any other button to cancel" << endl << endl;
		cout << "Action: ";

		cin >> choice;
		system("cls");
		switch (choice) {
		case 1: {
			double price;
			do {
				cout << "Input minimum portfolio cost: ";
				cin >> price;
			} while (price < 0);
			showMoreThanXPrice(portfolios, price);
			break;
		}
		case 2: {
			double price;
			do {
				cout << "Input minimum security cost: ";
				cin >> price;
			} while (price < 0);
			showSingleMoreThanXPrice(portfolios, price);
			break;
		}
		case 3:
			printTenMostExpensive(portfolios);
			break;
		}
	} while (choice < 4 && choice > 0);
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
			editMenu(portfolios);
			break;
		case 3:
			statisticMenu(portfolios);
			break;
		}
	} while (choice < 4 && choice > 0);
}