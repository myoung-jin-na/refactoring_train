#pragma once

#include <string>

using namespace std;

class Movie
{
public:
	static const int CHILDRENS = 2;
	static const int REGUAL = 0;
	static const int NEW_RELEASE = 1;
private:
	string _title;
	int _priceCode;

public:
	Movie() {
		_title="";
		_priceCode = REGUAL;
	}
	Movie(string title, int priceCode) {
		_title = title;
		_priceCode = priceCode;
	};

	Movie(const Movie& src) {
		_title     = src._title;
		_priceCode = src._priceCode;
	}

	const Movie& operator=(const Movie& src) {
		if (&src == this) return *this;		
		_title = src._title;
		_priceCode = src._priceCode;		
		return *this;
	}

	int getPriceCode() {
		return _priceCode;
	}

	void setPriceCode(int arg) {
		_priceCode = arg;
	}

	string getTitl() {
		return _title;
	}
};

