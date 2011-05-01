#include "PolicyManager.h"

PolicyManager::PolicyManager()
{
	this->employees.clear();
	this->policies.clear();
	return;
}

PolicyManager::~PolicyManager()
{
	unsigned int a;
	// Go through all employees and policies and delete them
	for(a = 0; a < this->employees.size(); a++) delete(this->employees.at(a));
	for(a = 0; a < this->policies.size(); a++) delete(this->policies.at(a));
	return;
}

// List of employees only
void PolicyManager::showAllEmployees(void)
{
	unsigned int e;
	cout << endl << "          List of Employees" << endl;
	cout << "-----------------------------------------" << endl;
	for(e = 0; e < this->employees.size(); e++)
	{
		cout << "  " << e + 1 << ") " << *this->employees.at(e) << endl;
	}
	return;
}

//  List of all sales only
void PolicyManager::showAllSales(void)
{
	unsigned int p;
	cout << endl << "          List of Policies" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "          Name of Insured |          Commission" << endl;
	for(p = 0; p < this->policies.size(); p++)
	{
		cout << "  " << p + 1 << ") " << *this->policies.at(p) << endl;
	}
	return;
}

// List all sales by all employees in tabular
void PolicyManager::showTabularSales(void)
{
	return;
}

//  List all sales by one employee
// e is index to employee, and employee must NOT be a manager
void PolicyManager::showEmployeeSales(int e)
{
	return;
}

// List all sales by employees of one manager
// e is index to employee, and employee must be a manager
void PolicyManager::showManagerSales(int e)
{
	return;
}

// Display menu, create, and append policy to vector
void PolicyManager::policyMenu(void)
{
	char c = 0;
	Policy *p = 0;
	while(c == 0)
	{
		cout << "Add New Policy" << endl;
		cout << "  1) Auto Policy" << endl;
		cout << "  2) Home Policy" << endl;
		cout << "  3) Life Policy" << endl;
		cout << "  Enter selection: ";
		cin >> c;
		switch(c)
		{
			case '1':
				p = new AutoPolicy();
			break;
			case '2':
				p = new HomePolicy();
			break;
			case '3':
				p = new LifePolicy();
			break;
			default:
				c = 0;
				cout << "Invalid selection" << endl;
			break;
		}
	}
	if(p)
	{
		this->policies.push_back(p);
		p->inputPolicy();
		this->assignPolicy(p);
	}
	return;
}

// Display the employees and user selects one
int PolicyManager::selectEmployee(void)
{
	unsigned int e = 0;
	while(e == 0)
	{
		this->showAllEmployees();
		cout << "  Enter selection: ";
		cin >> e;
		if(e > this->employees.size())
		{
			e = 0;
			cout << "Invalid selection" << endl;
		}
	}
	return e;
}

// Display employees to assign the policy
void PolicyManager::assignPolicy(Policy *p)
{
	unsigned int c = 0;
	while(c == 0)
	{
		cout << "Assign Policy To Employee" << endl;
		c = this->selectEmployee();
	}
	this->employees.at(c - 1)->addPolicy(p);
	return;
}

// Display menu, create, append employee to vector
void PolicyManager::employeeMenu(void)
{
	char c = 0;
	Employee *e = 0;
	while(c == 0)
	{
		cout << "Add Employee" << endl;
		cout << "  1) Salesperson" << endl;
		cout << "  2) Manager" << endl;
		cout << "  Enter selection: ";
		cin >> c;
		switch(c)
		{
			case '1':
				e = new Salesperson();
			break;
			case '2':
				e = new Manager();
			break;
			default:
				c = 0;
			break;
		}
	}
	if(e)
	{
		this->employees.push_back(e);
		e->inputEmployee();
	}
	return;
}

