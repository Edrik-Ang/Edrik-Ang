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
        //function to compute a vector of candlesticks for a country from a vector of WeatherDataEntry objects
        // takes in a vector of WeatherDataEntry objects and a country code
        // output is a vector of Candlestick objects for the specified country
        static std::vector<Candlestick> computeCandlesticks(const std::vector<WeatherDataEntry>& entries, const std::string& country);
        // function to compute candlesticks for i
        static std::map<std::string, std::vector<Candlestick>> computeCandlesticks(
             const std::vector<WeatherDataEntry>& entries,
             const std::vector<std::string>& countries);


        // // Function to generate candles values from a vector of Candlestick objects
        //takes in vector of WeatherDataEntry objects
        //output is prints out the candlestick values: year, open, close, high, low
        static void generateCandles(const std::vector<Candlestick>& candlesticks) ;
};