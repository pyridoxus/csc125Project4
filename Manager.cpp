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
//	commission =   commission total from all sales + ( commissions total from all sales * 30% ) +
//	                       ( commission total from all reporting salespeople * 5% )
	this->commissions = this->accumulateCommission() * 1.3;
	this->calcTotalSalary();
	return;
}
