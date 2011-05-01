#include "Employee.h"

Employee::Employee()
{
  this->name = "";
  this->baseSalary = 0.0;
  this->commissions = 0.0;
  this->totalSalary = 0.0;
  this->policyList.clear();
  return;
}

Employee::~Employee()
{
	// TODO Auto-generated destructor stub
}

void Employee::inputEmployee(void)
{
	cout << "Enter name: ";
	cin >> this->name;

	cout << "Enter base salary: ";
	cin >> this->baseSalary;

	return;
}

void Employee::addPolicy(Policy *p) // Add a policy to the policyList
{
	this->policyList.push_back(p);
	return;
}

// return the name of the employee
string Employee::getName(void)
{
	return this->name;
}

ostream &operator<<(ostream &s, const Employee &e)
{
  s << e.name << endl;
  return s;
}

