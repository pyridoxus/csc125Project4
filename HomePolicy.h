#ifndef HOMEPOLICY_H_
#define HOMEPOLICY_H_

#include "Policy.h"

class HomePolicy: public Policy
{
	public:
		HomePolicy();
		void inputPolicy(void);	// User enters all data and commission is calc'd
		friend ostream &operator<<(ostream &s, const HomePolicy &p);
	protected:
		void calculateCommission(void);
	private:
		float sqFootage;
		float dwelling;
		float contents;
		float liability;
};

#endif
