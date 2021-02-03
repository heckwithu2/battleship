#pragma once
// class definitions for battleship assignment
// Jeremiah Heck
// 10/28/2017

#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef BATTLESHIP_HPP_
#define BATTLESHIP_HPP_

// coordinates (location) of the ship and shots
class Location {
public:
	Location(); // void constructor, assigns -1 to X coord, and * to Y coord 
	void pick(); // picks a random location
	void fire(); // asks the user to input coordinates of the next shot
	void print() const; // prints location in format "a1"

						// predicate returns true if the two locations match
	friend bool compare(const Location&, const Location&);

private:
	static const int fieldSize = 6; // the field (ocean) is fieldSize X fieldSize
	int x_;  // 1 through fieldSize
	char y_; // 'a' through fieldSize
};

//// contains ship's coordinates (location) and whether is was sunk
class Ship {
public:
	Ship(); // void constructor, sets sunk=false
	bool match(const Location&) const; // returns true if this location matches
									   // the ship's location
	bool isSunk() const { return sunk; } // checks to see if the ship is sunk
	void sink();       // sets "sunk" member variable of the ship to true
	void setLocation(const Location&); // deploys the ship at the specified location
	void printShip() const; // prints location and status of the ship

private:
	Location loc;
	bool sunk;
};

// contains the fleet of the deployed ships
class Fleet {
public:
	void deployFleet(); // deploys the ships in random locations
						// of the ocean
	bool operational() const; // predicate returns true if at least
							  // one ship in the fleet is not sunk
	bool isHitNSink(const Location &); // returns true if there was a deployed
									   // ship at this location (hit) and sinks it
									   // otherwise returns false (miss)
	void printFleet() const; // prints out locations of ships in fleet

private:
	static const int fleetSize = 6; // number of battleships
	int check(const Location &) const;  // returns index of the ship 
										// that matches location
										// -1 if none match
	Ship ships[fleetSize];        // battleships of the fleet
};

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

#endif /* BATTLESHIP_H_ */


