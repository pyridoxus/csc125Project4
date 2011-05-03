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
