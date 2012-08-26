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
#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include "Salesperson.h"

class Manager: public Employee
{
	public:
		Manager();
		virtual ~Manager();
		virtual int isManager(void) { return -1; };	// return -1, is a manager
		void addSalesperson(Salesperson *p); // Add a Salesperson to salespersonList
		virtual void calcCommission(void);	// Calculate the total salary
		virtual unsigned int getNumSalesperson(void);
		virtual Employee *getSalesperson(unsigned int p);
	private:
    // The salespersonList contains pointers to the employees that are assigned
		// to work under this manager, and is assigned by the user.
		// The actual salesperson object is in another vector maintained
    // by the PolicyManager.
    vector<Salesperson *> salespersonList;	// list of all salespeople
};

#endif
