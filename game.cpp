/// Mikhail Nesterenko
/// tests battleship with classes implementation 
/// 10/20/2013 

#include "battleship.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

//declare an object of class fleet
//call deployFleet() method on it
//prompt the user if ships' positions and status need to be printed


//loop while method operational() returns true - i.e.at least one ship is not sunk.
//Inside the loop,
//declare an object of class location,
//invoke fire() on it to get the location of the user's shot,
//pass this object to isHitNSink() method of
//your fleet object
//analyze the return value of this method and report a hit or a miss
//if requested printing ships' status
//invoke printFleet()
/// this is main function
int main() {

	srand(time(nullptr)); // random seed
	
	Fleet myFleet;
	myFleet.deployFleet();
	cout << "Would you like your fleet's locations and status to be printed? y/n" << endl;
	char answer = 'p';
	cin >> answer;
	if (answer == 'y' || answer == 'Y') {
		myFleet.printFleet();
	}

	bool a;

	do {
		Location tmp;
		tmp.fire();
		bool t = myFleet.isHitNSink(tmp);
		if (t == true) {
			cout << "you got one!" << endl;
			cout << "Would you like your fleet's locations and status to be printed? y/n" << endl;
			char answer2 = 'p';
			cin >> answer2;
			if (answer2 == 'y' || answer2 == 'Y') {
				myFleet.printFleet();
			}
		}
		a = myFleet.operational();
	} while (a = !false);

	system("pause");
}
