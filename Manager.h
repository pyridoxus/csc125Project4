#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include "Salesperson.h"

class Manager: public Employee
{
	public:
		Manager();
		virtual ~Manager();
		virtual int isManager(void) { return -1; };	// return -1, is a manager
		void addSalesperson(Salesperson *p); // Add a Salesperson to salespersonList
		virtual void calcCommission(void);	// Calculate the total salary
	private:
    // The salespersonList contains pointers to the employees that are assigned
		// to work under this manager, and is assigned by the user.
		// The actual salesperson object is in another vector maintained
    // by the PolicyManager.
    vector<Salesperson *> salespersonList;	// list of all salespeople
};

#endif
