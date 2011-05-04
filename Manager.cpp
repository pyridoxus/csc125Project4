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
	unsigned int e;
//	commission =   commission total from all sales + ( commissions total from all sales * 30% ) +
//	                       ( commission total from all reporting salespeople * 5% )
	this->commissions = this->accumulateCommission() * 1.3;
	this->calcTotalSalary();
	for(e = 0; e < this->salespersonList.size(); e++)
	{
		this->totalSalary += this->salespersonList.at(e)->getCommissions() * 0.05;
	}
	return;
}

// Return the number of salespeople reporting to this manager
unsigned int Manager::getNumSalesperson(void)
{
	return this->salespersonList.size();
}

// Return the pointer to sales person in the salespersonList
Employee *Manager::getSalesperson(unsigned int p)
{
	return this->salespersonList.at(p);
}
