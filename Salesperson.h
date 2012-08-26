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
		void setManager(Employee *manager);	// Set the manager pointer
		Employee *getManager(void);	// Get the manager pointer
	private:
		// Update the manager's salary if this employee's commissions change
		Employee *manager;
};

#endif
