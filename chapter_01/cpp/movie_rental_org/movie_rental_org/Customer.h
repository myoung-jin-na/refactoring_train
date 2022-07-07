#pragma once

#include <vector>
#include <string>
#include <sstream>

#include "Rental.h"
#include "Movie.h"

using namespace std;

class Customer
{
private:
	string _name;
	vector<Rental> _rentals;

public:
	Customer(string name) {
		_name = name;
	}
	void addRental(Rental arg) {
		_rentals.push_back(arg);
	}
	string getName() {
		return _name;
	}

	string statement() {
		double totalAmount = 0;
		int frequentRenterPoints = 0;
		vector<Rental> rentals = _rentals;
		stringstream result;

		for (auto each : rentals) 
		{
			double thisAmount = 0;

			switch (each.getMovie().getPriceCode())
			{
			case Movie::REGUAL:
				thisAmount += 2;
				if (each.getDaysRented() > 2)
					thisAmount += (each.getDaysRented() - 2) * 1.5;
				break;
			case Movie::NEW_RELEASE:
				thisAmount += each.getDaysRented() * 3;
				break;
			case Movie::CHILDRENS:
				thisAmount += 1.5;
				if (each.getDaysRented() > 3)
					thisAmount += (each.getDaysRented() - 3) * 1.5;
				break;
			}
			// ���� ����Ʈ�� 1 ����Ʈ ����
			frequentRenterPoints++;

			// �ֽŹ��� ��Ʋ �̻� �뿩�ϸ� ���ʽ� ����Ʈ ����
			if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
				each.getDaysRented() > 1)
				frequentRenterPoints++;

			// �̹��� �뿩�ϴ� ���� ������ �뿩�Ḧ ���
			result << "\t" << each.getMovie().getTitl() << "\t" << thisAmount << endl;

			// ������� ������ �� �뿩��
			totalAmount += thisAmount;
		}

		// Ǫ�� �� �߰�
		result << "���� �뿩��: " << totalAmount << endl;
		result << "���� ����Ʈ: " << frequentRenterPoints << endl;

		return result.str();
	}
};

