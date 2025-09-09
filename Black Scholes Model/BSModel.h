#pragma once
class BSModel
{
	BSModel();
	virtual ~BSModel();

private:
	double optionPrice;
	double timeToMaturity;
	double volatility;
	double riskFreeRate;

public:
	double K_;
	double d1;
	double d2;
	double strikePrice;

private:
	struct OptionGreeks
	{
		double delta;
		double gamma;
		double theta;
		double vega;
		double rho;
	};

private:
	//Getter Functions for the Black-Scholes Model
	double getOptionPrice() const;		double getTTM() const;
	double getVolatility() const;		double getRFR() const;


	double getD1() const;		double getD2() const;
	double getK() const;		double getStrikePrice() const;

	//Setter Functions for the Black-Scholes Model
	void setOptionPrice(const double& value) const;		void setTTM(const double& value) const;
	void setVolatility(const double& value) const;		void setRFR(const double& value) const;
	void setK(const double& value) const;		

	void setStrikePrice(const double& value) const;
	void setD1(const double& value) const;
	void setD2(const double& value) const;

	//Calculator Functions for the Black-Scholes Model
	double calculateD1(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);
	double calculateD2(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);


private:
	//Calculate probability value
	double normalCDF(double d) const;

public:
	enum OptionType
	{
		CALL, PUT
	} optionType;


public:
	//Final call and put functions
	double callPrice();		double putPrice();

};

