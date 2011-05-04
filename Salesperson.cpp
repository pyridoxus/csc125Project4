#include "Salesperson.h"

Salesperson::Salesperson()
{
  this->policyList.clear();
  this->manager = 0;
  return;
}

Salesperson::~Salesperson()
{
	return;
}

// Calculate the total salary
void Salesperson::calcCommission(void)
{
	//commission =  commission total from all sales +
	//						( commissions total from all sales * 5% )
	this->commissions = this->accumulateCommission() * 1.05;
	this->calcTotalSalary();
	return;
}

// Set the manager pointer
void Salesperson::setManager(Employee *manager)
{
	this->manager = manager;
}

// Get the manager pointer
Employee *Salesperson::getManager(void)
{
	return this->manager;
}

