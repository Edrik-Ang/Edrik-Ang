//own code
//regresion.cpp implementation
#include "regression.h"
#include "CSV.h"
#include "Candlestick.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>

//Formula for linear regression line: https://www.ncl.ac.uk/webtemplate/ask-assets/external/maths-resources/statistics/regression-and-correlation/simple-linear-regression.html#:~:text=The%20simple%20linear%20regression%20line%2C%20%5Ey%3Da%2Bb,every%20unit%20change%20in%20x%20.
//function to calculate the linear regression line using the least-squares method
//Takes in a vector of Candlestick objects and a region string
//Returns a vector of Point objects representing the regression line and actual data points
//The x value is the year, and the y value is the temperature for the region
//The symbol is used to differentiate between actual ('x') and predicted ('o') values
std::vector<Point> regression::calculateRegression(const std::vector<Candlestick>& candles, std::string region)
{
    //year_max is used to find the maximum year in the dataset
    auto year_max = std::numeric_limits<int>::min();;

    std::vector<Point> results;
    auto x_total = 0.0;
    auto y_total = 0.0;

    auto n = candles.size();

    // Calculate the total X (year) and total Y (temperature) of the dataset
    for (auto candle : candles)
    {
        int x = candle.time_key;
        double y = candle.close; // Assuming 'close' is the temperature for the region

        x_total += x;
        y_total += y;
        if (x > year_max) year_max = x;

    }
    auto x_mean = x_total / n;
    auto y_mean = y_total / n;

    auto numerator = 0.0, denominator = 0.0;
    // Calculate the least-squares numerator and denominator of the dataset
    for (const auto candle : candles)
    {
        int x = candle.time_key;
        double y = candle.close; // Assuming 'close' is the temperature for the region
        numerator += (x - x_mean) * (y - y_mean);
        denominator += std::pow(x - x_mean, 2);
    }

    // With the previously calculated values,
    // Generate the a, b coefficients for the least-squares algorithm
    auto b = numerator / denominator;
    auto a = y_mean - (b * x_mean);

    std::cout << "Fitted data with least squares regression line of coefficients a = " << a << ", b = " << b << std::endl;

    std::vector<Point> result;

    // Actual data points
    for (const auto& candle : candles) {
        result.emplace_back(candle.time_key, candle.close, 'x');
    }

    // Predict next 12 years
    for (int i = 1; i <= 12; ++i) {
        int future_year = year_max + i;
        double prediction = a + b * future_year;
        result.emplace_back(future_year, prediction, 'o');
    }

    return result;
}
//end of own code