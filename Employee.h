#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <vector>
#include "Policy.h"

using namespace std;

class Employee
{
	public:
		Employee();
		virtual ~Employee();
		void inputEmployee(void);	// Input the employee data
		void addPolicy(Policy *p); // Add a policy to the policyList
		string getName(void);	// return the name of the employee
		friend ostream &operator<<(ostream &s, const Employee &e);
	protected:
    string name;
    float baseSalary;
    float commissions;
    float totalSalary;
    // The policyList contains pointers to the policy and is assigned by
    // the user. The actual policy object is in another vector maintained
    // by the PolicyManager.
    vector<Policy *> policyList;	// list of all sales made

};

#endif
