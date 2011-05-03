#include "Manager.h"

Manager::Manager()
{
  this->salespersonList.clear();
}

Manager::~Manager()
{
	return;
}

// Add a Salesperson to the salespersonList
void Manager::addSalesperson(Salesperson *p)
{
	this->salespersonList.push_back(p);
	return;
}

// Calculate the total salary
void Manager::calcCommission(void)
{
	return;
}
