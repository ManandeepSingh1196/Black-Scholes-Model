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
	double N;
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
	double getD1() const;
	double getD2() const;
	double getStrikePrice() const;

	//Setter Functions for the Black-Scholes Model
	void setD1(const double& value) const;
	void setD2(const double& value) const;

	//Calculator Functions for the Black-Scholes Model
	void calculateD1(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);
	void calculateD2(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);


private:
	//Calculate probability values
	double normalPDF();
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

