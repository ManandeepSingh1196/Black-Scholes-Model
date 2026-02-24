#include<iostream>
#include<cmath>
#include<numbers>

#include "BSModel.h"

BSModel::BSModel()
{
    optionPrice = 0.0;
    timeToMaturity = 0.0;
    volatility = 0.0;
    riskFreeRate = 0.0;
    K_ = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    strikePrice = 0.0;
}

BSModel::BSModel(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility)
    : optionPrice(optionPrice), strikePrice(strikePrice), timeToMaturity(timeToMaturity), 
      riskFreeRate(riskFreeRate), volatility(volatility)
{
    K_ = 1.0 / (1.0 + 0.2316419 * abs(optionPrice)); // Standard approximation for K
    d1 = calculateD1(optionPrice, strikePrice, timeToMaturity, riskFreeRate, volatility);
    d2 = calculateD2(optionPrice, strikePrice, timeToMaturity, riskFreeRate, volatility);
}

BSModel::~BSModel() 
{
    // No dynamic memory allocation, so destructor can be empty
}


double BSModel::normalCDF(double d) const
{
    const double a[] = { 0.31938153, -0.356563782, 1.781477937, -1.821255978, 1.330274429 };

    double L = abs(d);
    double K = getK();

    double result = 1.0 - 1.0 / sqrt(2 * std::numbers::pi) * exp(-L * L / 2.0)
        * (a[0] * K + a[1] * K * K + a[2] * pow(K, 3.0) + a[3] * pow(K, 4.0) + a[4] + pow(K, 5.0));

    // Return the result based on the sign of 'd'.
    return d < 0 ? 1.0 - result : result;
}

double BSModel::calculateD1(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility)
{
    return (log(optionPrice / strikePrice)
        + (riskFreeRate + 0.5 * volatility * volatility) * timeToMaturity)
		/ (volatility * sqrt(timeToMaturity));
}

double BSModel::calculateD2(double optionPrice, double strikePrice, double timeToMaturity, double riskFreeRate, double volatility)
{
	return getD1() - volatility * sqrt(timeToMaturity);
}

double BSModel::callPrice()
{
    double N_d1 = normalCDF(d1);
    double N_d2 = normalCDF(d2);
    return optionPrice * N_d1 - strikePrice * exp(-riskFreeRate * timeToMaturity) * N_d2;
}

double BSModel::putPrice()
{
    double N_neg_d1 = normalCDF(-d1);
    double N_neg_d2 = normalCDF(-d2);
    return strikePrice * exp(-riskFreeRate * timeToMaturity) * N_neg_d2 - optionPrice * N_neg_d1;
}

/*

X-------------------------------------------------------------X
| *---------------------------------------------------------* |
| |                 Setter Functions                        | |
| *---------------------------------------------------------* |
X-------------------------------------------------------------X

*/

void BSModel::setOptionPrice(const double& value)
{
    optionPrice = value;
}

void BSModel::setTTM(const double& value)
{
    timeToMaturity = value;
}

void BSModel::setVolatility(const double& value)
{
    volatility = value;
}

void BSModel::setRFR(const double& value)
{
    riskFreeRate = value;
}

void BSModel::setK(const double& value)
{
    K_ = value;
}

void BSModel::setStrikePrice(const double& value)
{
    strikePrice = value;
}

void BSModel::setD1(const double& value)
{
    d1 = value;
}

void BSModel::setD2(const double& value)
{
    d2 = value;
}

/*

X-------------------------------------------------------------X
| *---------------------------------------------------------* |
| |                 Getter Functions                        | |
| *---------------------------------------------------------* |
X-------------------------------------------------------------X

*/

double BSModel::getOptionPrice() const
{
    return optionPrice;
}

double BSModel::getTTM() const
{
    return timeToMaturity;
}

double BSModel::getVolatility() const
{
    return volatility;
}

double BSModel::getRFR() const
{
    return riskFreeRate;
}

double BSModel::getD1() const
{
    return d1;
}

double BSModel::getD2() const
{
    return d2;
}

double BSModel::getK() const
{
    return K_;
}

double BSModel::getStrikePrice() const
{
    return strikePrice;
}
