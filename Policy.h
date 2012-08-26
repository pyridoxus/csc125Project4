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
#ifndef POLICY_H_
#define POLICY_H_
#include <iostream>
using namespace std;

#define POLICY_AUTO		0
#define POLICY_HOME		1
#define POLICY_LIFE		2

class Policy
{
	public:
		Policy();
		virtual void inputPolicy(void);
		friend ostream &operator<<(ostream &s, const Policy &p);
		float getCommission(void);	// Return the commission amount
		int getType(void);	//Return the type of the policy
	protected:
		virtual void calculateCommission(void);
		void inputNameOfInsured(void);
		string nameOfInsured;
		float commission;
		int policyType;
};

#endif
