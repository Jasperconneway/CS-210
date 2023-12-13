#ifndef INVESTMENT_H
#define INVESTMENT_H

// Investment header file
class Investment {
	public:
		/*
		* Default constructor
		* @param open amount, monthly deposit, number of years, interest rate
		* with default values
		*/
		Investment(double openAmt = 99.9, double mnthlyDepo = 99.9, int numYears = 1, int intrstRate = 1);
		
		/*
		* Get and Setters for open amount, monthly deposit,
		* number of years, and interest rate
		*/
		void SetOpenAmt(double amt);
		double GetOpenAmt();
		void SetMnthlyDepo(double amt);
		double GetMnthlyDepo() const;
		void SetNumYears(int years);
		int GetNumYears() const;
		int GetNumMonths() const;
		void SetIntrstRate(int intrstRate);
		int GetIntrstRate();
	private:
		/*
		* private members
		*/
		double openAmt;
		double mnthlyDepo;
		int intrstRate;
		int numYears;
		int numMonths;
};

#endif

