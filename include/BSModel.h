#pragma once
class BSModel
{
public:
	BSModel();
	BSModel(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);
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
	void setOptionPrice(const double& value);		void setTTM(const double& value);
	void setVolatility(const double& value);		void setRFR(const double& value);
	void setK(const double& value);		

	void setStrikePrice(const double& value);
	void setD1(const double& value);
	void setD2(const double& value);

	//Calculator Functions for the Black-Scholes Model
	double calculateD1(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);
	double calculateD2(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility);


private:
	//Calculate probability value
	double normalCDF(double d) const;

public:
	//Final call and put functions
	double callPrice();		double putPrice();

};

