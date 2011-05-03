#include "Policy.h"

Policy::Policy()
{
	this->nameOfInsured = "";
	this->commission = 0.0;
	return;
}

void Policy::inputNameOfInsured(void)
{
	cout << "Enter name of insured: ";
	cin >> this->nameOfInsured;
	return;
}

void Policy::calculateCommission(void)
{
	return;
}

void Policy::inputPolicy(void)
{
	return;
}

// Return the commission amount
float Policy::getCommission(void)
{
	return this->commission;
}

ostream &operator<<(ostream &s, const Policy &p)
{
	s.width(20);
  s << p.nameOfInsured;
  s << " |";
	s.width(20);
  s << p.commission << endl;
  return s;
}

