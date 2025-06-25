//candlefilter.cpp implementation
// This file contains the implementation of the CandleFilter class, which provides methods to filter candlestick data by country and year range.
// It includes the necessary headers and uses the Candlestick class to represent individual candlestick data.
// The filterByCountry method retrieves candlesticks for a specific country, while the filterByYearRange method filters candlesticks based on a specified year range.
//own code
#include "CandleFilter.h"
#include <vector>
#include <string>
#include "candlestick.h"


//function to filter candlesticks by country
//Takes in a map of all candlesticks and a country code
//Returns a vector of Candlestick objects for the specified country
//If the country is not found, it returns an empty vector
std::vector<Candlestick> CandleFilter::filterByCountry(const std::map<std::string,
                                                             std::vector<Candlestick>>& allCandles,
                                                       const std::string& country ){
    if (allCandles.find(country) != allCandles.end()) { // Check if the country exists in the map
        return allCandles.at(country); // Return the vector of Candlestick objects for the specified country
    } else {
        return {}; // Return empty vector if country not found
    }
}
//function to filter candlesticks by year range
//Takes in a vector of Candlestick objects and a start and end year
//Returns a vector of Candlestick objects that fall within the specified year range
std::vector<Candlestick> CandleFilter::filterByYearRange(const std::vector<Candlestick>& candles,
                                                               int startYear,
                                                               int endYear) {
    std::vector<Candlestick> results;
    for (const auto& candle : candles) {
        if (candle.time_key >= startYear && candle.time_key <= endYear) {
            results.push_back(candle);
        }
    }
    return results;
}
//end of own code