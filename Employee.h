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
		virtual void addSalesperson(Salesperson *p) {};	// Add a salesperson to list
		virtual int isManager(void) { return 0; };	// return 0, not a manager
		virtual void calcCommission(void); // Calc commission, depends on employee
		float accumulateCommission(void);	// Accumulate commissions from all sales
		void addPolicy(Policy *p); // Add a policy to the policyList
		unsigned int getNumPolicies(void);	// Return the number of policies
		Policy *getPolicy(unsigned int p);	// Return pointer to policy at p
		float getCommissions(void);	// Return commissions of this employee
		virtual Employee *getManager(void) { return 0; };	// Get pointer to manager
		virtual void setManager(Employee *) {};	// Set pointer to manager (link)
		virtual unsigned int getNumSalesperson(void) { return 0; };
		virtual Employee *getSalesperson(unsigned int p) { return 0; };
	protected:
		void calcTotalSalary(void);	// Calculate total salary
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
