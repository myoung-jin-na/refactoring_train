#pragma once

#include "Movie.h"

class Rental
{
private:
	Movie _movie;
	int _daysRented;

public:	
	Rental(Movie movie, int daysRented) {
		_movie = movie;
		_daysRented = daysRented;
	}
	int getDaysRented() {
		return _daysRented;
	}

	Movie getMovie() {
		return _movie;
	}
};

