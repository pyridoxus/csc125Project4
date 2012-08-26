//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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

