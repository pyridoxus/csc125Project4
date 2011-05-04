#ifndef SALESPERSON_H_
#define SALESPERSON_H_

#include "Employee.h"

class Salesperson: public Employee
{
	public:
		Salesperson();
		virtual ~Salesperson();
		virtual int isManager(void) { return 0; };	// return 0, not a manager
		virtual void calcCommission(void);	// Calculate the total salary
		void setManager(Employee *manager);	// Set the manager pointer
		Employee *getManager(void);	// Get the manager pointer
	private:
		// Update the manager's salary if this employee's commissions change
		Employee *manager;
};

#endif
