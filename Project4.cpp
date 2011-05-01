#include "Project4.h"

char showMainMenu(void)
{
	char c;
	cout << endl << "            ----- Main Menu -----" << endl;
	cout << "  1) Show All Employees" << endl;
	cout << "  2) Show All Sales" << endl;
	cout << "  3) Show Sales by Employees in Tabular Format" << endl;
	cout << "  4) Show All Sales for One Employee" << endl;
	cout << "  5) Show All Sales for Employees Reporting to One Manager" << endl;
	cout << "  6) Add a New Employee" << endl;
	cout << "  7) Add a New Policy" << endl;
	cout << "  8) Exit" << endl;
	cout << "  Enter Selection: ";
	cin >> c;
	return c;
}

int main(void)
{
//	AutoPolicy *autoPolicy;
//	HomePolicy *homePolicy;
//	LifePolicy *lifePolicy;
//
//	autoPolicy = new AutoPolicy;
//	autoPolicy->inputPolicy();
//	cout << *autoPolicy;
//
//	homePolicy = new HomePolicy;
//	homePolicy->inputPolicy();
//	cout << *homePolicy;
//
//	lifePolicy = new LifePolicy;
//	lifePolicy->inputPolicy();
//	cout << *lifePolicy;
//
//	delete autoPolicy;
//	delete homePolicy;
//	delete lifePolicy;

	PolicyManager insurance;
	char c = 1;
	insurance = PolicyManager();
	while(c != 0)
	{
		c = showMainMenu();
		switch(c)
		{
			case '1':
				insurance.showAllEmployees();
			break;
			case '2':
				insurance.showAllSales();
			break;
			case '3':
				insurance.showTabularSales();
			break;
			case '4':
				insurance.showEmployeeSales(insurance.selectEmployee());
			break;
			case '5':
				insurance.showManagerSales(insurance.selectEmployee());
			break;
			case '6':
				insurance.employeeMenu();
			break;
			case '7':
				insurance.policyMenu();
			break;
			case '8':
				c = 0;
			break;
			default:
				cout << "Invalid selection" << endl;
			break;
		}
	}
	return 0;
}

