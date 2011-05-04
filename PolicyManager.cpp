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
// If isType == 0, then show all employees.
// If isType == 1, only show managers.
// If isType == 2, only show salespeople.
// The index shown will be the index in the main list, and not the numerical
// order that one would expect to see on the screen.
void PolicyManager::showAllEmployees(int isType)
{
	Employee *emp;
	unsigned int e;
	string s;
	switch(isType)
	{
		case EMPLOYEE_ALL:
			s = "Employees";
		break;
		case EMPLOYEE_MANAGER:
			s = "Managers";
		break;
		case EMPLOYEE_SALESPERSON:
			s = "Salespeople";
		break;
		default:
			s = "";
		break;
	}
	cout << endl << "          List of " << s << endl;
	cout << "------------------------------------------------" << endl;
	cout << "    ----        Name      |  Total Salary   ----" << endl;
	for(e = 0; e < this->employees.size(); e++)
	{
		emp = this->employees.at(e);
		switch(isType)
		{
			case 0:	// Print all
				cout << "  " << e + 1 << ") " << *emp << endl;
			break;
			case 1:	// Print if manager
				if(emp->isManager())
					cout << "  " << e + 1 << ") " << *emp << endl;
			break;
			case 2:	// Print if salesperson
				if(!emp->isManager())
					cout << "  " << e + 1 << ") " << *emp << endl;
			break;
		}
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
	Employee *emp;
	Policy *policy;
	unsigned int e, p, n;	// List indices
	float f[3];	// Policy accumulators
	cout << "                  Table of Commissions" << endl;
	cout << "|       Employee       |   Auto   |   Home   |   Life   |" << endl;
	cout << "---------------------------------------------------------" << endl;
	for(e = 0; e < this->employees.size(); e++)
	{
		emp = this->employees.at(e);
		cout << "| ";
		cout.width(20);
		cout << emp->getName();
		cout << " | ";
		for(n = 0; n < 3; n++) f[n] = 0.0;
		for(p = 0; p < emp->getNumPolicies(); p++)
		{
			policy = emp->getPolicy(p);	// Returns 0 if invalid for some reason
			if(policy)	// Check to make sure it's valid
			{
				switch(policy->getType())
				{
					case POLICY_AUTO:
						f[POLICY_AUTO] += policy->getCommission();
					break;
					case POLICY_HOME:
						f[POLICY_HOME] += policy->getCommission();
					break;
					case POLICY_LIFE:
						f[POLICY_LIFE] += policy->getCommission();
					break;
				}
			}
		}
		for(n = 0; n < 3; n++)
		{
			cout.width(8);
			cout << f[n];
			cout << " | ";
		}
		cout << endl;
	}
	return;
}

//  List all sales by one employee
// e is index to employee
void PolicyManager::showEmployeeSales(int e)
{
	Employee *emp;
	unsigned int n;
	emp = this->employees.at(e - 1);
	cout << "Sales for Employee" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "----        Name      |  Total Salary   ----" << endl;
	cout << *emp << endl;
	cout << endl << "          List of Policies" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "          Name of Insured |          Commission" << endl;
	for(n = 0; n < emp->getNumPolicies(); n++)
	{
		cout << *emp->getPolicy(n) << endl;
	}
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
	if(this->getNumberEmployees(EMPLOYEE_ALL) == 0)
	{
		cout << "Cannot create a policy. Must create employee first." << endl;
		return;
	}
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
// Display employees to assign the policy
void PolicyManager::assignPolicy(Policy *p)
{
	Employee *emp;
	Employee *manager;
	unsigned int c = 0;
	while(c == 0)
	{
		cout << endl << "Assign Policy To Employee" << endl;
		c = this->selectEmployee(EMPLOYEE_ALL);
	}
	emp = this->employees.at(c - 1);
	emp->addPolicy(p);	// Add policy to list inside salesperson
	emp->calcCommission();	// Update their commissions and salary
	if(!emp->isManager())	// If salesperson, then update manager's salary
	{
		manager = emp->getManager();
		manager->calcCommission();
	}
	return;
}

// Display employees and select.
unsigned int PolicyManager::selectEmployee(int isType)
{
	unsigned int e = 0;
	while(e == 0)
	{
		this->showAllEmployees(isType);
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
				if(this->getNumberEmployees(EMPLOYEE_MANAGER) == 0)
				{
					cout << "Must create a manager before creating a salesperson" << endl;
				}
				else
				{
					e = new Salesperson();
				}
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
		e->calcCommission();
		if(!e->isManager()) this->assignManager((Salesperson *)e);
	}
	return;
}

// Display managers to assign employees
// Employee must be a Salesperson object before calling this function
void PolicyManager::assignManager(Salesperson *e)
{
	Employee *manager;
	unsigned int m;
	m = this->selectEmployee(EMPLOYEE_MANAGER);
	manager = this->employees.at(m - 1);
	manager->addSalesperson(e);
	e->setManager(manager);
	return;
}

// Return the number of employees in vector depending on isType parameter.
// If isType == EMPLOYEE_ALL, return total number of employees.
// If isType == EMPLOYEE_MANAGER, return number of managers.
// If isType == EMPLOYEE_SALESPERSON, return number of salespeople.
int PolicyManager::getNumberEmployees(int isType)
{
	Employee *emp;
	int e, s, c = 0;
	s = this->employees.size();
	if(isType == EMPLOYEE_ALL) return s;
	for(e = 0; e < s; e++)
	{
		emp = this->employees.at(e);
		switch(isType)
		{
			case EMPLOYEE_MANAGER:
				if(emp->isManager()) c++;
			break;
			case EMPLOYEE_SALESPERSON:
				if(!emp->isManager()) c++;
			break;
		}
	}
	return c;
}

