//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "AutoPolicy.h"

AutoPolicy::AutoPolicy():Policy()
{
	this->make = "";
	this->model = "";
	this->VIN = "";
	this->liability = 0.0;
	this->collision = 0.0;
	this->policyType = POLICY_AUTO;
	return;
}

void AutoPolicy::calculateCommission(void)
{
//	Base sales commission is based on the formula:
//	commission = (liability + collision) * 30%
	this->commission = (this->liability + this->collision) * 0.3;
	return;
}

ostream &operator<<(ostream &s, const AutoPolicy &p)
{
  s << p.nameOfInsured << " ";
  s << p.make << " ";
  s << p.model << " ";
  s << p.VIN << " ";
  s << p.liability << " ";
  s << p.collision;
  return s;
}

void AutoPolicy::inputPolicy(void)
{
	// name is input from the parent Policy class
	this->inputNameOfInsured();

	cout << "Enter make: ";
	cin >> this->make;

	cout << "Enter model: ";
	cin >> this->model;

	cout << "Enter VIN: ";
	cin >> this->VIN;

	cout << "Enter liability: ";
	cin >> this->liability;

	cout << "Enter collision: ";
	cin >> this->collision;

	// Now calculate the commission amount stored in the Policy parent class.
	this->calculateCommission();
	return;
}
