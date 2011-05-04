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
