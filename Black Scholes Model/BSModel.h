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
	double setD1();		double getD1();
	double setD2();		double getD2();

	double getStrikePrice();

private:
	double normalPDF();
	double normalCDF();

public:
	double callPrice();		double putPrice();

};

