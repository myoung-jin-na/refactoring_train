#include <iostream>
#include <string>
#include <vector>
#include "customer.h"

using namespace std;

vector<Customer> g_Customers;

int select_menu()
{
	char nSelectedMenu = 0;
	cout << "============= menu =============== " << endl;
	cout << "1 : create account" << endl;
	cout << "2 : view customer" << endl;
	cout << "3 : add rent" << endl;
	cout << "q : quit" << endl;
	cout << "place choice menu num (1~3) : ";
	cin >> nSelectedMenu;
	cout << endl;

	return nSelectedMenu;
}

int main(int argc, const char* argv[])
{
MENU_SELECT:
	int nSelectedMenu = select_menu();

	if (nSelectedMenu == '1') {
		string sName;
		cout << "pleace customer name : ";
		cin >> sName;
		Customer customer(sName);
		g_Customers.push_back(customer);
		goto MENU_SELECT;
	}
	else if (nSelectedMenu == '2') {
		string sName;
		cout << "pleace customer name : ";
		cin >> sName;
		for (auto each : g_Customers) {
			if (sName == each.getName())
			{
				cout << each.statement() << endl;
			}
		}
		goto MENU_SELECT;
	}
	else if (nSelectedMenu == '3') {
		string sName;
		cout << "pleace customer name : ";
		cin >> sName;
		for (auto it = g_Customers.begin(); it != g_Customers.end(); it++) {
			if (sName == (*it).getName())
			{
				string sMovieTitle;
				int nPriceCode;
				int nDayRented;
				cout << "pleace enter movie title : ";
				cin >> sMovieTitle;				
				cout << endl;

				cout << "pleace enter privce code (0:REGUAL , 1:NEW_RELEASE, 2:CHILDRENS ) : ";
				cin >> nPriceCode;
				cout << endl;

				cout << "pleace enter rented day : ";
				cin >> nDayRented;
				cout << endl;

				Movie a_movie(sMovieTitle, nPriceCode);
				Rental aRental(a_movie, nDayRented);
				(*it).addRental(aRental);
			}
		}
		goto MENU_SELECT;
	}
	else if (nSelectedMenu == 'q' || nSelectedMenu == 'Q') {
		goto PROGRM_END;
	}
	else {
		cout << "it is not correct munu. (1~3)" << endl;
		goto MENU_SELECT;
	}

PROGRM_END:

	return 0;
}

