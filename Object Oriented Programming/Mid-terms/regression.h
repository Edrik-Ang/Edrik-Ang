//own code
// regression.h implementation
// This file contains the declaration of the regression class, which provides methods to calculate linear regression for candlestick data.
// It includes the necessary headers and uses the Candlestick and Point classes to represent individual data points and regression results.
#pragma once
#include <vector>
#include <string>
#include "point.h"
#include "Candlestick.h"

class regression {
    public:
        static std::vector<Point> calculateRegression(const std::vector<Candlestick>& candles, std::string region);
};