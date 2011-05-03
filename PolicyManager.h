#ifndef POLICYMANAGER_H_
#define POLICYMANAGER_H_
#include <vector>
#include "Policy.h"
#include "AutoPolicy.h"
#include "HomePolicy.h"
#include "LifePolicy.h"
#include "Employee.h"
#include "Salesperson.h"
#include "Manager.h"

#define EMPLOYEE_ALL 			0
#define EMPLOYEE_MANAGER		1
#define EMPLOYEE_SALESPERSON	2

// Contain and manage the policies through an instance of this class.
class PolicyManager
{
	public:
		PolicyManager();
		virtual ~PolicyManager();
		void showAllEmployees(int isManagers);	// List of employees only
		void showAllSales(void);	//  List of all sales only
		void showTabularSales(void);	// List all sales by all employees in tabular
		void showEmployeeSales(int e);	//  List all sales by one employee
		void showManagerSales(int e);	// List all sales by employees of one manager
		void policyMenu(void);	// Display menu, create, and append policy to vector
		void employeeMenu(void);	// Display menu, create, append employee to vector
		int selectEmployee(int isManager); // Display employees and select
	private:
		vector<Policy *> policies;
		vector<Employee *> employees;
		void assignPolicy(Policy *p);	// Display employees to assign the policy
		void assignManager(Manager *m);	// Display managers to assign employees
};

#endif
