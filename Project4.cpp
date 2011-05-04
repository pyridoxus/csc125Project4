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
	PolicyManager insurance;
	char c = 1;
	Employee *e;
	insurance = PolicyManager();
	while(c != 0)
	{
		c = showMainMenu();
		switch(c)
		{
			case '1':
				insurance.showAllEmployees(EMPLOYEE_ALL);
			break;
			case '2':
				insurance.showAllSales();
			break;
			case '3':
				insurance.showTabularSales();
			break;
			case '4':
				e = insurance.selectEmployee(EMPLOYEE_ALL);
				if(e) insurance.showEmployeeSales(e);
			break;
			case '5':
				e = insurance.selectEmployee(EMPLOYEE_MANAGER);
				if(e) insurance.showManagerSales(e);
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

