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
		unsigned int showAllEmployees(int isType);	// List of employees only
		void showAllSales(void);	//  List of all sales only
		void showTabularSales(void);	// List all sales by all employees in tabular
		void showEmployeeSales(Employee *emp);	//  List all sales by one employee
		void showManagerSales(Employee *manager);	// List sales by employees of manager
		void policyMenu(void);	// Display menu, create, and append policy to vector
		void employeeMenu(void);	// Display menu, create, append employee to vector
		Employee *selectEmployee(int isType); // Display employees and select
	private:
		vector<Policy *> policies;
		vector<Employee *> employees;
		void assignPolicy(Policy *p);	// Display employees to assign the policy
		void assignManager(Salesperson *e);	// Display managers to assign employee
		int getNumberEmployees(int isType);	// Return number of type of employees
		void printPolicyHeader(void);	// Just to not have duplicate code
};

#endif
