#include "Command.h"
#include <iostream>

PriceChanger::PriceChanger(Iterator& iter)
	: currentMusicClip(iter), newPrice(0.0)
{
}

void PriceChanger::promptPrice()
{
	cout << "\tNew price: ";
	cin >> newPrice;

	string cr;
	getline(cin, cr);

	cout << endl << "# Price changed for Appliance with ID " << currentMusicClip->getData()->getID() << endl;
}

void PriceChanger::execute()
{
	promptPrice();

	currentMusicClip->getData()->setPrice(newPrice);
}
