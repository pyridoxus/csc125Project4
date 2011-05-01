#ifndef AUTOPOLICY_H_
#define AUTOPOLICY_H_

#include "Policy.h"

class AutoPolicy: public Policy
{
	public:
		AutoPolicy();
		void inputPolicy(void);	// User enters all data and commission is calc'd
		friend ostream &operator<<(ostream &s, const AutoPolicy &p);
	protected:
		void calculateCommission(void);
	private:
		string make;
		string model;
		string VIN;
		float liability;
		float collision;
};

#endif
