//candlegenerator.h implementation
#pragma once
#include "WeatherDataEntry.h"
#include "Candlestick.h"
#include <vector>
#include <string>
#include <iostream>

class CandleGenerator {
    public:
        static std::vector<Candlestick> computeCandlesticks(const std::vector<WeatherDataEntry>& entries, const std::string& country);

    
        // //function to group the data yearly from the vector of WeatherDataEntry objects
        // static std::vector<Candlestick> groupDataYearly(const std::vector<WeatherDataEntry>& entries, const std::string& country);
        // //function to calculate avereage, high, low, open, close from the vector of WeatherDataEntry objects
        // static Candlestick calculateCandlestick(const std::vector<WeatherDataEntry>& entries, const std::string& country);
        // // Function to generate candles from a vector of Candlestick objects
        void generateCandles(const std::vector<Candlestick>& candlesticks) {
            for (const auto& candle : candlesticks) {
                std::cout << "Candlestick - Open: " << candle.open 
                          << ", Close: " << candle.close 
                          << ", High: " << candle.high 
                          << ", Low: " << candle.low 
                          << std::endl;
            }
        }


};