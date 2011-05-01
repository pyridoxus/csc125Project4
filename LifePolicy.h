#ifndef LIFEPOLICY_H_
#define LIFEPOLICY_H_

#include "Policy.h"

class LifePolicy: public Policy
{
	public:
		LifePolicy();
		void inputPolicy(void);	// User enters all data and commission is calc'd
		friend ostream &operator<<(ostream &s, const LifePolicy &p);
	protected:
		void calculateCommission(void);
	private:
    int age;
    string nameOfDependent;
    float termLife;
};

#endif
