//candlefilter.h implementation
//will handle all the filtering logic of the candlesticks based on user input, e.g press 2, then choose country then filter only country
#pragma once
#include "Candlestick.h"
#include <vector>
#include <string>
#include <map>

class CandleFilter {
    public:
        // Function to filter candlesticks by country
        static std::vector<Candlestick> filterByCountry(const std::map <std::string, std::vector<Candlestick>>& allCandles, const std::string& country);

        // Function to filter candlesticks by year range
        static std::vector<Candlestick> filterByYearRange(const std::vector<Candlestick>& candles, int startYear, int endYear);

};