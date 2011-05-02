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

