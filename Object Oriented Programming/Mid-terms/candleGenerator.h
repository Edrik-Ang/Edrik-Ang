//candlegenerator.h implementation
#pragma once
#include "WeatherDataEntry.h"
#include "Candlestick.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

class CandleGenerator {
    public:
        static std::vector<Candlestick> computeCandlesticks(const std::vector<WeatherDataEntry>& entries, const std::string& country);
  
        static std::map<std::string, std::vector<Candlestick>> computeCandlesticks(
             const std::vector<WeatherDataEntry>& entries,
             const std::vector<std::string>& countries);
    
        // //function to group the data yearly from the vector of WeatherDataEntry objects
        // static std::vector<Candlestick> groupDataYearly(const std::vector<WeatherDataEntry>& entries, const std::string& country);
        // //function to calculate avereage, high, low, open, close from the vector of WeatherDataEntry objects
        // static Candlestick calculateCandlestick(const std::vector<WeatherDataEntry>& entries, const std::string& country);
        // // Function to generate candles from a vector of Candlestick objects
        static void generateCandles(const std::vector<Candlestick>& candlesticks) ;
};