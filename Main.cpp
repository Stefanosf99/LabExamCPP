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

void customSort(vector<Portfolio*>&);
void printTenMostExpensive(vector<Portfolio*>&);
void showMoreThanXPrice(vector<Portfolio*>&, double);
void showSingleMoreThanXPrice(vector<Portfolio*>&, double);

Portfolio* addSecurities(Portfolio*);
Portfolio* createPortfolio();
void statisticMenu(vector<Portfolio*>&);
void menu(vector<Portfolio*>&);

int main(int argc, char** argv) {
	vector<Portfolio*> portfolios;
	menu(portfolios);

	cout << portfolios[0]->getFullName();

	system("PAUSE > NUL");
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
void customSort(vector<Portfolio*>& portfolios) {
	sort(portfolios.begin(), portfolios.end(), [](Portfolio* left, Portfolio* right) {
		return left->countTotalWorth() < right->countTotalWorth();
	});
}
void printTenMostExpensive(vector<Portfolio*>& portfolios) {
	int portfoliosToShow;

	if (portfolios.size() >= 10) portfoliosToShow = 10;
	else portfoliosToShow = portfolios.size();

	customSort(portfolios);
	header("Top " + to_string(portfoliosToShow) + " most expensive Portfolios");

	for (int i = 0; i < portfoliosToShow; i++) {
		cout << i << ". " << portfolios[i]->getFullName() << endl << " (" << portfolios[i]->countTotalWorth() << "$)";
	}

	system("pause");
}
void showMoreThanXPrice(vector<Portfolio*>& portfolios, double price) {
	int sum = 0;
	header("Portfolios with higher than " + to_string(price) + "$ cost");
	for (int i = 0; i < portfolios.size(); i++) {
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
	for (int i = 0; i < portfolios.size(); i++) {
		if (portfolios[i]->countMaxWorth() > price) {
			sum++;
		}
	}
	cout << "Portfolios with a single security with higher cost than " << price << "$ : " << sum << endl << endl;
	system("pause");
}
#pragma endregion

#pragma region "Menus"
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
		case 3:
			statisticMenu(portfolios);
			break;
		}
	} while (choice < 4 && choice > 0);
}
#pragma endregion