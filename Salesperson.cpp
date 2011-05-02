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

