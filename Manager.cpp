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
