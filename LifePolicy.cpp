#include "LifePolicy.h"

LifePolicy::LifePolicy():Policy()
{
	this->age = 0;
	this->nameOfDependent = "";
	this->termLife = 0.0;
	this->policyType = POLICY_LIFE;
	return;
}

void LifePolicy::calculateCommission(void)
{
//	Base sales commission is based on the following formula:
//	commission = term life * 20%
	this->commission = this->termLife * 0.2;
	return;
}

ostream &operator<<(ostream &s, const LifePolicy &p)
{
  s << p.nameOfInsured << " ";
  s << p.age << " ";
  s << p.nameOfDependent << " ";
  s << p.termLife;
  return s;
}

void LifePolicy::inputPolicy(void)
{
	// name is input from the parent Policy class
	this->inputNameOfInsured();

	cout << "Enter age: ";
	cin >> this->age;

	cout << "Enter name of dependent: ";
	cin >> this->nameOfDependent;

	cout << "Enter amount of term life: ";
	cin >> this->termLife;

	// Now calculate the commission amount stored in the Policy parent class.
	this->calculateCommission();
	return;
}
