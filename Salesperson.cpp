#include "Salesperson.h"

Salesperson::Salesperson()
{
  this->policyList.clear();
  return;
}

Salesperson::~Salesperson()
{
	return;
}

void Salesperson::addPolicy(Policy *p) // Add a policy to the policyList
{
	this->policyList.push_back(p);
	return;
}

// Calculate the total salary
void Salesperson::calcCommission(void)
{
	int p;
	float s = 0.0;
	for(p = 0; p < this->policyList.size(); p++)
	{
		s += this->policyList.at(p)->getCommission();
	}
	//commission =  commission total from all sales +
	//						( commissions total from all sales * 5% )
	s *= 1.05;
	this->commissions = s;
	this->calcTotalSalary();
	return;
}
