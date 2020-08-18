#include <cstdlib>
#include <ctime>
#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;


void Fleet::deployFleet() {

	for (int deployedShips = 0; deployedShips < fleetSize; deployedShips++) {

		bool index = true;
		Location tmp;

		do {
			Ship myShip;
			Location tmp;
			tmp.pick();
			myShip.match(tmp);
		} while (index != true);

		ships[deployedShips].setLocation(tmp);
	}
}

Location::Location() {
	x_ = -1;
	y_ = '*';
}


bool Ship::match(const Location &tmp) const {
	bool a = false;
	Ship ship;
	if (compare(ship.loc, tmp)) {
		a = true;
	}
	else {
		a = false;
	}
	return a;
}

bool compare(const Location &tmp, const Location& tmp2) {
	return tmp.x_ == tmp2.x_ && tmp.y_ == tmp2.y_;
}

void Location::pick() {
	x_ = (rand() % fieldSize) + 1;
	int randomNumber = (rand() % fieldSize) + 1;

	char coordinate = 'x';
	switch (randomNumber) {
	case 1: coordinate = 'a';
		break;
	case 2: coordinate = 'b';
		break;
	case 3: coordinate = 'c';
		break;
	case 4: coordinate = 'd';
		break;
	case 5: coordinate = 'e';
		break;
	case 6: coordinate = 'f';
		break;
	}
	y_ = coordinate;
}

void Location::fire() {
	cout << "Please input the coordinates of your next shot, number first then letter." << endl;
	cin >> x_;
	cin >> y_;
}

void Ship::sink() {
	bool tmpsunk = isSunk();
	tmpsunk = true;
}

void Location::print() const {
	cout << "the location of your this ship is" << endl;
	cout << x_ << endl;
	cout << y_ << endl;
}

void Ship::setLocation(const Location& tmp) {
	loc = tmp;
}

void Ship::printShip() const {
	loc.print();
	bool isSunkVar = isSunk();
	cout << isSunkVar << endl;
}

Ship::Ship() : sunk(false) {}

void Fleet::printFleet() const {
	Fleet tmp;
	for (int i = 0; i < fleetSize; i++) {
		cout << "the location of ship " << i << " is";
		tmp.ships[i].printShip();
	}
}

bool Fleet::operational() const {
	Fleet tmp;
	bool t = true;
	for (int i = 0; i < fleetSize; i++) {
		if (tmp.ships[i].isSunk() == false) {
			t = true;
			break;
		}
		else {
			t = false;
		}
	}
	return t;
}
bool Fleet::isHitNSink(const Location& tmp) {
	Ship tmpShip;
	bool r = tmpShip.match(tmp);
	return r;
}

int Fleet::check(const Location& tmp) const {

	for (int i = 0; i < fleetSize; i++) {
		int num = 0;
		bool r = ships[i].match(tmp);
		if (r == false) {
			num = -1;
			return num;
		}
		else {
			return i;
		}
	}
}
