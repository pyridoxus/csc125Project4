#ifndef SALESPERSON_H_
#define SALESPERSON_H_

#include "Employee.h"

class Salesperson: public Employee
{
	public:
		Salesperson();
		virtual ~Salesperson();
		virtual int isManager(void) { return 0; };	// return 0, not a manager
		void addPolicy(Policy *p); // Add a policy to the policyList
		virtual void calcCommission(void);	// Calculate the total salary
	private:
    // The policyList contains pointers to the policy and is assigned by
    // the user. The actual policy object is in another vector maintained
    // by the PolicyManager.
    vector<Policy *> policyList;	// list of all sales made
};

#endif
