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
			// 적립 포인트를 1 포인트 증가
			frequentRenterPoints++;

			// 최신물을 이틀 이상 대여하면 보너스 포인트 지급
			if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
				each.getDaysRented() > 1)
				frequentRenterPoints++;

			// 이번에 대여하는 비디오 정보와 대여료를 출력
			result << "\t" << each.getMovie().getTitl() << "\t" << thisAmount << endl;

			// 현재까지 누적된 총 대여료
			totalAmount += thisAmount;
		}

		// 푸터 행 추가
		result << "누적 대여료: " << totalAmount << endl;
		result << "적립 포인트: " << frequentRenterPoints << endl;

		return result.str();
	}
};

