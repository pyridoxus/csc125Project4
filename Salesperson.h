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
};

#endif
