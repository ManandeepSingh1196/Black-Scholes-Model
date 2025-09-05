#include<iostream>
#include<cmath>

#include "BSModel.h"

BSModel::BSModel()
{
    BSModel::optionPrice = 0.0;
    BSModel::timeToMaturity = 0.0;
    BSModel::volatility = 0.0;
    BSModel::riskFreeRate = 0.0;
    optionType = OptionType::CALL;
}

BSModel::~BSModel()
{
}

