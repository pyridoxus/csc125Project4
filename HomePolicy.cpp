#include "HomePolicy.h"

HomePolicy::HomePolicy():Policy()
{
	sqFootage = 0.0;
	dwelling = 0.0;
	contents = 0.0;
	liability = 0.0;
	return;
}

void HomePolicy::calculateCommission(void)
{
//	Base sales commission is based on the formula:
//	commission = (liability * 30%) + ( (dwelling + contents) * 20% )
	this->commission = (this->liability * 0.3) + (( this->dwelling + \
			this->contents) * 0.2);
	return;
}

ostream &operator<<(ostream &s, const HomePolicy &p)
{
  s << p.nameOfInsured << " ";
  s << p.sqFootage << " ";
  s << p.dwelling << " ";
  s << p.contents << " ";
  s << p.liability << endl;
  return s;
}

void HomePolicy::inputPolicy(void)
{
	// name is input from the parent Policy class
	this->inputNameOfInsured();

	cout << "Enter square footage: ";
	cin >> this->sqFootage;

	cout << "Enter dwelling: ";
	cin >> this->dwelling;

	cout << "Enter contents: ";
	cin >> this->contents;

	cout << "Enter liability: ";
	cin >> this->liability;

	// Now calculate the commission amount stored in the Policy parent class.
	this->calculateCommission();
	return;
}
