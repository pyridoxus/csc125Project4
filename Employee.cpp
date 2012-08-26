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
#include "Employee.h"

Employee::Employee()
{
  this->name = "";
  this->baseSalary = 0.0;
  this->commissions = 0.0;
  this->totalSalary = 0.0;
  return;
}

Employee::~Employee()
{
	return;
}

void Employee::inputEmployee(void)
{
	cout << "Enter name: ";
	cin >> this->name;

	cout << "Enter base salary: ";
	cin >> this->baseSalary;

	return;
}

// return the name of the employee
string Employee::getName(void)
{
	return this->name;
}

ostream &operator<<(ostream &s, const Employee &e)
{
	s.width(20);
	s << e.name;
	s << " | " << e.totalSalary;
	return s;
}

// Calculate total salary only after the commissions and base salary are known.
void Employee::calcTotalSalary(void)
{
	this->totalSalary = this->baseSalary + this->commissions;
	return;
}

// Accumulate the commissions from all sales
float Employee::accumulateCommission(void)
{
	unsigned int p;
	float s = 0.0;
	for(p = 0; p < this->policyList.size(); p++)
	{
		s += this->policyList.at(p)->getCommission();
	}
	return s;
}

// Add a policy to the policyList
void Employee::addPolicy(Policy *p)
{
	this->policyList.push_back(p);
	return;
}

// Calc commission, depends on employee
void Employee::calcCommission(void)
{
	return;
}

// Return the number of policies
unsigned int Employee::getNumPolicies(void)
{
	return this->policyList.size();
}

// Return pointer to policy at p
Policy *Employee::getPolicy(unsigned int p)
{
	if(p >= this->policyList.size()) return 0;
	return this->policyList.at(p);
}

// Return commissions of this employee
float Employee::getCommissions(void)
{
	return this->commissions;
}
