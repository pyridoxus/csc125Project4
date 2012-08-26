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
#include "HomePolicy.h"

HomePolicy::HomePolicy():Policy()
{
	this->sqFootage = 0.0;
	this->dwelling = 0.0;
	this->contents = 0.0;
	this->liability = 0.0;
	this->policyType = POLICY_HOME;
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
  s << p.liability;
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
