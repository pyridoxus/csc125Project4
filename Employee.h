#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <vector>
#include "Policy.h"

using namespace std;

class Salesperson;

class Employee
{
	public:
		Employee();
		virtual ~Employee();
		void inputEmployee(void);	// Input the employee data
		string getName(void);	// return the name of the employee
		friend ostream &operator<<(ostream &s, const Employee &e);
		virtual void addPolicy(Policy *p) {};	// Add a policy to the policy list
		virtual void addSalesperson(Salesperson *p) {};	// Add a salesperson to list
		virtual int isManager(void) { return 0; };	// return 0, not a manager
	protected:
    string name;
    float baseSalary;
    float commissions;
    float totalSalary;
};

#endif
