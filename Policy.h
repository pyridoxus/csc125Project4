#ifndef POLICY_H_
#define POLICY_H_
#include <iostream>
using namespace std;

class Policy
{
	public:
		Policy();
		virtual void inputPolicy(void);
		friend ostream &operator<<(ostream &s, const Policy &p);
		float getCommission(void);	// Return the commission amount
	protected:
		virtual void calculateCommission(void);
		void inputNameOfInsured(void);
		string nameOfInsured;
		float commission;
};

#endif
